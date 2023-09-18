/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 15:04:37
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-18 15:42:03
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
                printf("draw\n");
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
 