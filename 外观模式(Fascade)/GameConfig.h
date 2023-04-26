#ifndef _GAME_CONFIG_
#define _GAME_CONFIG_
#include "stdio.h"

namespace V1 {
    class Graphic
    {
        private:
            Graphic(){};
            Graphic(const Graphic& obj);
            Graphic& operator=(const Graphic& obj);
            ~Graphic(){};
        public:
            static Graphic& getInstance()
            {
                static Graphic instance;
                return instance;
            }
        public:
            void fullScreen(bool enable){printf("fullScreen enable = %d\n",enable);}
            void specialEffect(bool enable){printf("specialEffect enable = %d\n",enable);}
            void setResolution(int resolution){printf("set Resolution = %d\n",resolution);}
            void antiAliasing(bool enable){printf("antiAliasing enable = %d\n",enable);}
    };

    class Sound
    {
        private:
            Sound(){};
            Sound(const Sound& obj);
            Sound& operator=(const Sound& obj);
            ~Sound(){};
        public:
            static Sound& getInstance()
            {
                static Sound instance;
                return instance;
            }
        public:
            void backgroundSound(bool enable){}
            void environmentSound(bool enable){}
            void emoticonSound(bool enable){}
            void setVolume(int volume){}
    };

    class Chat
    {
        private:
            Chat(){};
            Chat(const Chat& obj);
            Chat& operator=(const Chat& obj);
            ~Chat(){};
        public:
            static Chat& getInstance()
            {
                static Chat instance;
                return instance;
            }
        public:
            void setMicrophoneVolume(int volume){}
            void setMicrophoneSense(int sense){}
            void setChatVolume(int volume){}
    };
}

namespace V2 {
    template <typename T>
    class Singleton // 使用单例类模板
    {
        private:
            // Singleton(){};
            // ~Singleton(){};
            // Singleton(const Singleton& obj);
            // Singleton& operator=(const Singleton& obj);

            Singleton() = default; // 2种写法都可以
            ~Singleton() = default;
            Singleton(T&&) = delete;
            Singleton(const T&) = delete;
            void operator= (const T&) = delete;      
        public:
            static T& getInstance()
            {   
                static T instance;
                return instance;
            }
    };
    class Graphic
    {
        private:
            friend class Singleton<Graphic>; // 使用时声明为单例类的友元类即可
        public:
            void fullScreen(bool enable){printf("fullScreen enable = %d\n",enable);}
            void specialEffect(bool enable){printf("specialEffect enable = %d\n",enable);}
            void setResolution(int resolution){printf("set Resolution = %d\n",resolution);}
            void antiAliasing(bool enable){printf("antiAliasing enable = %d\n",enable);}
    };
}
#endif