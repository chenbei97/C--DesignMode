/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 16:19:34
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-18 17:31:57
 * @FilePath: \CPPDesignMode\中介者模式(Mediator)\Mediator.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#ifndef Mediator_H
#define Mediator_H

#include <string>
#include <map>
#include <iostream>

using std::string;
using std::map;
using std::cout;
class Widget;

typedef map<string,Widget*> WidgetList;
typedef const map<string,Widget*>& CWidgetList;

class Mediator {
    public:
        virtual ~Mediator(){}
        virtual void createWidgets() = 0;
        virtual void widgetChanged(Widget*) = 0;
};

class Widget {
    public:
        Widget(Mediator* m,string text):mMediator(m),mCaption(text){}
        virtual ~Widget(){}
        virtual void change() {
            mMediator->widgetChanged(this); // 借助中介者实现
        };
        virtual void setEnable(bool enable) = 0;
    protected:
        Mediator * mMediator;
        string mCaption;
};

class PushButton :public Widget {
    public:
        PushButton(Mediator* m,string text):Widget(m,text){}
        virtual void setEnable(bool enable) override {
            enable?cout<<"pushbutton is enable\n":cout<<"pushbutton is disable\n";
        };
};

class RadioButton :public Widget {
    public:
        RadioButton(Mediator* m,string text):Widget(m,text){}
        virtual void setEnable(bool enable) override {
            enable?cout<<"radiobutton is enable\n":cout<<"radiobutton is disable\n";
        };
};

class LineEdit :public Widget {
    public:
        LineEdit(Mediator* m,string text):Widget(m,text){}
        virtual void setEnable(bool enable) override {
            enable?cout<<"lineedit is enable\n":cout<<"lineedit is disable\n";
        };
        bool isEmpty() {
            return mText.empty();
        }
    private:
        string mText;
};

class LoginMediator : public Mediator
{
private:
    PushButton * mloginbtn = nullptr;
    PushButton * mquitbtn = nullptr;
    RadioButton * mradio1 = nullptr;
    RadioButton * mradio2 = nullptr;
    LineEdit * musername = nullptr;
    LineEdit * mpassword = nullptr;
public:
    void login() {
        mloginbtn->change(); // 模拟点击登录操作
    }
    virtual void createWidgets() {
        mloginbtn = new PushButton(this,"登录"); // 可以看出Qt的每个QWidget既是控件也是中介者
        mquitbtn = new PushButton(this,"退出");
        mradio1 = new RadioButton(this,"游客登陆");
        mradio2 = new RadioButton(this,"账号登陆");
        musername = new LineEdit(this,"username");
        mpassword = new LineEdit(this,"password");
        // 初始化状态
        mloginbtn->setEnable(true);
        mquitbtn->setEnable(true);
        mradio1->setEnable(true);
        mradio2->setEnable(false);
        musername->setEnable(false);
        mpassword->setEnable(false);
    }

    virtual void widgetChanged(Widget * widget) override {
        if (widget == mloginbtn) {
            cout<<"login\n";
        } else if (widget == mquitbtn) {
            cout<<"quit\n";
        } else if (widget == mradio1) { // 游客登陆
            mradio1->setEnable(true);
            mradio2->setEnable(false);
            musername->setEnable(false);
            mpassword->setEnable(false);
            cout<<"radio1\n";
        } else if (widget == mradio2) {
            mradio1->setEnable(false);
            mradio2->setEnable(true);
            musername->setEnable(true);
            mpassword->setEnable(true);
            if (musername->isEmpty() || mpassword->isEmpty()) {
                mloginbtn->setEnable(false); // 账号密码均不为空才能登陆
            }
            cout<<"radio2\n";
        } else if (widget == musername || widget == mpassword) {
            if (musername->isEmpty() || mpassword->isEmpty()) 
                mloginbtn->setEnable(false);
            else mloginbtn->setEnable(true);
        }
    }
};
#endif