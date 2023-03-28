#ifndef Singleton_H
#define Singleton_H

#include <mutex>
#include <atomic>

namespace V1 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance()
            {
                if (mLogConfig == nullptr) // 多线程下可能造成多次创建静态实例的问题
                {
                    mLogConfig = new LogConfig();
                }
                return mLogConfig;
            }
        private:
            static LogConfig * mLogConfig;
    };
    LogConfig * LogConfig::mLogConfig = nullptr;//需给出定义,一般是.cpp内给出定义
}

namespace V2 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance() // 加锁，下个线程必须等待上个线程执行完，但是多线程频繁的调用实例时资源消耗过大
            {
                std::lock_guard<std::mutex> lg(mMutex);
                if (mLogConfig == nullptr)
                {
                    mLogConfig = new LogConfig();
                }
                return mLogConfig;
            }
        private:
            static LogConfig * mLogConfig;
            static std::mutex mMutex;
    };
    LogConfig * LogConfig::mLogConfig = nullptr;
    std::mutex LogConfig::mMutex;
}

namespace V3 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance()
            {
                if (mLogConfig == nullptr) // 双重判断
                {
                    std::lock_guard<std::mutex> lg(mMutex);
                    if (mLogConfig == nullptr)
                    {
                        mLogConfig = new LogConfig();
                    }
                }
                return mLogConfig;
            }
        private:
            static LogConfig * mLogConfig;
            static std::mutex mMutex;
    };
    LogConfig * LogConfig::mLogConfig = nullptr;
    std::mutex LogConfig::mMutex;
}

namespace V4 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance()
            {
                LogConfig * tmp = mLogConfig.load(std::memory_order_relaxed);
                std::atomic_thread_fence(std::memory_order_acquire); // 内存有序,禁止重排序
                if (tmp == nullptr) // 一个解决双重判断失效的可能方案,禁止内存重排序即可
                {
                    std::lock_guard<std::mutex> lock(mMutex);
                    tmp = mLogConfig.load(std::memory_order_relaxed);
                    if (tmp == nullptr)
                    {
                        tmp = new LogConfig();
                        std::atomic_thread_fence(std::memory_order_release);
                        mLogConfig.store(tmp,std::memory_order_relaxed);
                    }
                }
                return tmp;
            }
        private:
            static std::atomic<LogConfig*> mLogConfig;
            static std::mutex mMutex;
    };
    std::atomic<LogConfig*> LogConfig::mLogConfig;
    std::mutex LogConfig::mMutex;
}

namespace V5 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance()
            {
                return mLogConfig; // 饿汉式,实例化静态变量时直接创建对象而不是赋值nullptr
            }
        private:
            static LogConfig * mLogConfig;
    };
    LogConfig * LogConfig::mLogConfig = new LogConfig();//这里直接创建1个对象
}

namespace V6 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance()
            {
                if (mLogConfig == nullptr)
                {
                    mLogConfig = new LogConfig();
                }
                return mLogConfig;
            }
            static void freeInstance() // 基于V1增加此函数,需要外部手工调用释放对象
            {
                if (mLogConfig != nullptr)
                {
                    delete LogConfig::mLogConfig;
                    LogConfig::mLogConfig = nullptr;
                }
            }
        private:
            static LogConfig * mLogConfig;
    };
    LogConfig * LogConfig::mLogConfig = nullptr;
}

namespace V7 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance()
            {
                return mLogConfig; // 基于V5增加1个嵌套类,静态实例的内存释放自动调用(饿汉式)
            }
        private:
            static LogConfig * mLogConfig;
        private:
            class Garbo // 嵌套类
            {
                public:
                    ~Garbo()
                    {
                        if (LogConfig::mLogConfig != nullptr)
                        {
                            delete LogConfig::mLogConfig;
                            LogConfig::mLogConfig = nullptr;
                        }
                    }
            };
            static Garbo garbo;
    };
    LogConfig * LogConfig::mLogConfig = new LogConfig();//饿汉式
    LogConfig::Garbo LogConfig::garbo; // 资源释放对象也是静态的,只能有1个
}

namespace V8 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance()
            {
                if (mLogConfig == nullptr) // 基于V1增加1个嵌套类,静态实例的内存释放自动调用(懒汉式)
                {
                    mLogConfig = new LogConfig();
                    static Garbo obj; // obj释放时会调用析构函数自动释放
                }
                return mLogConfig;
            }
        private:
            static LogConfig * mLogConfig;
        private:
            class Garbo
            {
                public:
                    ~Garbo()
                    {
                        if (LogConfig::mLogConfig != nullptr)
                        {
                            delete LogConfig::mLogConfig;
                            LogConfig::mLogConfig = nullptr;
                        }
                    }
            };
    };
    LogConfig * LogConfig::mLogConfig = nullptr;//懒汉式
}

namespace V9 {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig* getInstance()
            {
                return &mLogConfig; // 直接返回静态对象的引用而非指针类型
            }
        private:
            static LogConfig mLogConfig;
    };
    LogConfig LogConfig::mLogConfig; // 本质上也是懒汉模式
}

namespace VA {
    class LogConfig
    {
        private:
            LogConfig(){}
            LogConfig(const LogConfig&);
            LogConfig operator= (const LogConfig&);
            ~LogConfig(){}
        public:
            static LogConfig& getInstance()// 直接返回局部静态对象的引用
            {
                static LogConfig instance;// 首次调用getInstance()时会被创建
                return instance; 
            }
    };
}
#endif