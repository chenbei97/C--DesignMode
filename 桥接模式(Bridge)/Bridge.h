/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 15:04:37
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-18 16:04:06
 * @FilePath: \CPPDesignMode\桥接模式(Bridge)\Bridge.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
 #include "stdio.h"

 namespace V1
 { // 第一种写法,处理图像类和操作系统类耦合
    class Image {
        public:
            void draw(const char* filename) {
                int len = 0;
                auto pdata = parsefile(filename,len);
            }
            virtual ~Image(){}
        private:
            virtual char* parsefile(const char* filename, int & len) = 0;
    };
    class JPGImage: public Image{
        private:
            virtual char* parsefile(const char* filename, int & len) override
            {
                printf("read from jpg\n"); // 模拟读取数据
                len = 100;
                char * res = new char[len];
                return res;
            }
    };
    class PNGImage: public Image{
        private:
            virtual char* parsefile(const char* filename, int & len) override
            {
                printf("read from png\n");// 模拟读取数据
                len = 100;
                char * res = new char[len];
                return res;
            }
    };

    class JPGImageWindow: public JPGImage
    {
        private:
            virtual char* parsefile(const char* filename, int & len) override
            {
                printf("read from jpg on window\n");// 模拟读取数据
                len = 100;
                char * res = new char[len];
                return res;
            }
    };
    class JPGImageMacos: public JPGImage
    {
        private:
            virtual char* parsefile(const char* filename, int & len) override
            {
                printf("read from jpg on macos\n");// 模拟读取数据
                len = 100;
                char * res = new char[len];
                return res;
            }
    };
    class JPGImageLinux: public JPGImage
    {
        private:
            virtual char* parsefile(const char* filename, int & len) override
            {
                printf("read from jpg on linux\n");// 模拟读取数据
                len = 100;
                char * res = new char[len];
                return res;
            }
    };

    class PNGImageWindow: public PNGImage
    {
        private:
            virtual char* parsefile(const char* filename, int & len) override
            {
                printf("read from png on window\n");// 模拟读取数据
                len = 100;
                char * res = new char[len];
                return res;
            }
    };
    class PNGImageMacos: public PNGImage
    {
        private:
            virtual char* parsefile(const char* filename, int & len) override
            {
                printf("read from png on macos\n");// 模拟读取数据
                len = 100;
                char * res = new char[len];
                return res;
            }
    };
    class PNGImageLinux: public PNGImage
    {
        private:
            virtual char* parsefile(const char* filename, int & len) override
            {
                printf("read from png on linux\n");// 模拟读取数据
                len = 100;
                char * res = new char[len];
                return res;
            }
    };
 } // namespace V1
 

 namespace V2 {
    class ImageOS {
        public:
            virtual void draw(char* data,int len) = 0;
            virtual ~ImageOS(){}
    };
    class ImageOSWin: public ImageOS {
        public:
            virtual void draw(char* data,int len) override
            {
                printf("load pix on win\n");
            };
    };
    class ImageOSLinux: public ImageOS {
        public:
            virtual void draw(char* data,int len) override
            {
                printf("load pix on linux\n");
            };
    };
    class ImageOSMacos: public ImageOS {
        public:
            virtual void draw(char* data,int len) override
            {
                printf("load pix on macos\n");
            };
    };
    class ImageFormat{
        public:
            ImageFormat(ImageOS * os):mOS(os) {}
            virtual void parsefile(const char* filename) = 0;
            virtual ~ImageFormat(){}
        protected:
            ImageOS * mOS;
    };
    class JPGImage : public ImageFormat{
        public:
            JPGImage(ImageOS * os):ImageFormat(os) {}
            virtual void parsefile(const char* filename) override {
                printf("parse jpg\n");
                int len = 100;
                char * res = new char[len];
                mOS->draw(res,len);
                delete res;
            };
    };
    class PNGImage : public ImageFormat{
        public:
            PNGImage(ImageOS * os):ImageFormat(os) {}
            virtual void parsefile(const char* filename) override {
                printf("parse png\n");
                int len = 100;
                char * res = new char[len];
                mOS->draw(res,len);
                delete res;
            };
    };
 }