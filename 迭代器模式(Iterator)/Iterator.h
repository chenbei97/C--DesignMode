#ifndef _ITERATOR_H
#define _ITERATOR_H
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Iterator{
    public:
        virtual void first() = 0; //指向容器第1个元素
        virtual void next() = 0; // 指向下一元素
        virtual bool isDone() = 0; // 是否遍历完
        virtual T& value() = 0; // 当前元素
        virtual ~Iterator(){}
};

template<typename T>
class Container{
    public:
        virtual Iterator<T>* iterator() = 0; // 方便用于容器直接创建自己的迭代器
        virtual T& value(int index) = 0; //当前元素
        virtual int size() = 0; // 容器元素数量
        virtual ~Container(){}
};

template<typename T>
class ArrayIterator : public Iterator<T> // 1个具体的固定大小数组迭代器
{
    private:
        Container<T> * mArray; // 依赖倒转,容器使用迭代器那么迭代器就用容器类作为聚合
        int mCurrentIndex; // 当前迭代器指向的元素索引
    public:
        ArrayIterator(Container<T>* array) 
            : mArray(array),mCurrentIndex(0){} // 构造函数传参来实现迭代器对要遍历容器的指向
        
        virtual void first() override
        {
            mCurrentIndex = 0; // 让当前索引指向首元素的下标0
        }

        virtual void next() override
        {
            ++mCurrentIndex;
        }

        virtual bool isDone() override
        {
            if (mCurrentIndex >= mArray->size()) // 当前指向了mArray末尾元素的下一个
                return true;
            return false;
        }

        virtual T& value() override
        {
            return mArray->value(mCurrentIndex);
        }
};

template<typename T>
class Array : public Container<T>{
    private:
        T mElems[10]; // 简化代码,固定数组大小10
    public:
        Array() {for(int i=1;i<=10;++i)mElems[i-1]=10-i;}
        virtual int size() override {return 10;}
        virtual T& value(int index) override {return mElems[index];}
        virtual Iterator<T>* iterator() override
        {
            return new ArrayIterator<T>(this);
        }
};

static void test()
{
    Container<int> * array = new Array<int>();
    Iterator<int> * iter = array->iterator();

    for(iter->first(); !iter->isDone(); iter->next())
    {
        cout << iter->value()<<" ";
    }
    cout<<endl;
}
#endif