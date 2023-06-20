/*
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-06-20 16:42:21
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-06-20 16:49:54
 * @FilePath: \CPPDesignMode\代理模式(Proxy)\Proxy.h
 * @Description: 代理模式的示例
 */
#ifndef Proxy_H
#define Proxy_H

class WebAddr {
    public:
        virtual void visit() = 0;
        virtual ~WebAddr() {}
};


class Proxy : public WebAddr {
    private:
        WebAddr * mWeb;
    public:
        Proxy(WebAddr* web) : mWeb(web){}
        virtual void visit() override
        {
            mWeb->visit();
            // ... 这里可以增加额外的代码对访问网站进行限制,其实就是装饰模式,很相似
        }
};

#endif