#ifndef _COMPOSITE_H
#define _COMPOSITE_H
#include <iostream>
#include <string>
#include <list>
using std::string;
using std::list;
using std::cout;

namespace V1
{
    class File
    {
        private:
            string mFileName;
        public:
            File(const string& name) : mFileName(name) {}
            void showName(const string& sep = "")// sep是间隔符,默认是""没有间隔
            {
                cout << sep <<" - " << mFileName<<"\n"; 
            }
    };

    class Dir
    {
        private:
            string mDirName;
            list<Dir*> mChildDir;
            list<File*> mChildFile; // 1个目录可以有文件和子目录
        public:
            Dir(const string& name) : mDirName(name) {}
            void addFile(File*file) { mChildFile.push_back(file); }
            void addDir(Dir*dir) { mChildDir.push_back(dir); }

            void showName(const string& sep = "")// sep是间隔符,默认是""没有间隔
            {
                // 1) 先打印本目录的名称
                cout << sep <<" + " << mDirName<<"\n";
                // 2) 然后打印本目录下的文件名称
                for(auto iter = mChildFile.begin(); iter != mChildFile.end(); ++iter)
                    (*iter)->showName(sep+"\t"); // \t增加适当的缩进
                // 3) 然后打印本目录下的子目录名称,内部实际上进行了递归操作,每个子目录都会继续对子目录和文件打印
                for(auto iter = mChildDir.begin(); iter != mChildDir.end(); ++iter)
                    (*iter)->showName(sep+"\t");
            }
    };

    static void test()
    {
        Dir * root = new Dir("root");
        File * file1 = new File("intro.doc");
        File * file2 = new File("process.md");
        File * file3 = new File("include.h");
        Dir * dir1 = new Dir("communication");
        Dir * dir2 = new Dir("login");
        Dir * dir3 = new Dir("log");
        root->addFile(file1);
        root->addFile(file2);
        root->addFile(file3);
        root->addDir(dir1);
        root->addDir(dir2);
        root->addDir(dir3);

        File * file4 = new File("communication.h");
        File * file5 = new File("communication.c");
        dir1->addFile(file4);
        dir1->addFile(file5);

        File * file6 = new File("login.h");
        File * file7 = new File("login.c");
        File * file8 = new File("createAccount.h");
        File * file9 = new File("createAccount.c");
        File * file10 = new File("retrieve.h");
        File * file11 = new File("retrieve.c");
        dir2->addFile(file6);
        dir2->addFile(file7);
        dir2->addFile(file8);
        dir2->addFile(file9);
        dir2->addFile(file10);
        dir2->addFile(file11);

        File * file12 = new File("log.h");
        File * file13 = new File("log.c");
        File * file14 = new File("log.csv");
        File * file15 = new File("log.txt");
        dir3->addFile(file12);
        dir3->addFile(file13);
        dir3->addFile(file14);
        dir3->addFile(file15);

        root->showName(">");
    }
}

namespace V2 {
    class FileSystem{
        public:
            virtual void showName(int level = 0) = 0;
            virtual int add(FileSystem*) = 0;
            virtual int remove(FileSystem*) = 0;
            virtual ~FileSystem(){}
    };

    class File : public FileSystem
    {
        private:
            string mFileName;
        public:
            File(const string&name) : mFileName(name){}
            virtual void showName(int level) override
            {
                for(int i = 0; i < level; ++i) cout<<"\t";
                cout << " - " << mFileName << "\n";
            }
            // 文件不能添加和移除,所以返回-1
            virtual int add(FileSystem* pf) override {return -1;}
            virtual int remove(FileSystem* pf) override {return -1;}
    };

    class Dir : public FileSystem
    {
        private:
            string mDirName;
            list<FileSystem*> mChild;
        public:
            Dir(const string& name) : mDirName(name){}
            virtual void showName(int level) override
            {
                for(int i = 0; i < level; ++i) cout<<"\t";
                // 1) 目录名
                cout <<" + "<< mDirName << "\n";
                ++level; // 多1层缩进
                // 2) 子目录或者文件名
                for(auto iter = mChild.begin(); iter != mChild.end(); ++iter)
                    (*iter)->showName(level);
            }
            virtual int add(FileSystem* pf) override {
                mChild.push_back(pf); return 0;
            }
            virtual int remove(FileSystem* pf) override {
                mChild.remove(pf); return 0;
            }
    };

    static void test()
    {
        FileSystem * root = new Dir("root");
        FileSystem * file1 = new File("intro.doc");
        FileSystem * file2 = new File("process.md");
        FileSystem * file3 = new File("include.h");
        FileSystem * dir1 = new Dir("communication");
        FileSystem * dir2 = new Dir("login");
        FileSystem * dir3 = new Dir("log");
        root->add(file1);
        root->add(file2);
        root->add(file3);
        root->add(dir1);
        root->add(dir2);
        root->add(dir3);

        FileSystem * file4 = new File("communication.h");
        FileSystem * file5 = new File("communication.c");
        dir1->add(file4);
        dir1->add(file5);

        FileSystem * file6 = new File("login.h");
        FileSystem * file7 = new File("login.c");
        FileSystem * file8 = new File("createAccount.h");
        FileSystem * file9 = new File("createAccount.c");
        FileSystem * file10 = new File("retrieve.h");
        FileSystem * file11 = new File("retrieve.c");
        dir2->add(file6);
        dir2->add(file7);
        dir2->add(file8);
        dir2->add(file9);
        dir2->add(file10);
        dir2->add(file11);

        FileSystem * file12 = new File("log.h");
        FileSystem * file13 = new File("log.c");
        FileSystem * file14 = new File("log.csv");
        FileSystem * file15 = new File("log.txt");
        dir3->add(file12);
        dir3->add(file13);
        dir3->add(file14);
        dir3->add(file15);

        root->showName();
        root->remove(dir2);
        root->showName(1);

    }
}

namespace V3 {
    class Dir; // 需要声明

    class FileSystem{
        public:
            virtual void showName(int level = 0) = 0;
            virtual Dir* isDir() {return nullptr;}
            virtual int fileCount() = 0;
            virtual ~FileSystem(){}
    };

    class File : public FileSystem
    {
        private:
            string mFileName;
        public:
            File(const string&name) : mFileName(name){}
            virtual int fileCount() {return 1;}
            virtual void showName(int level) override
            {
                for(int i = 0; i < level; ++i) cout<<"\t";
                cout << " - " << mFileName << "\n";
            }
    };

    class Dir : public FileSystem
    {
        private:
            string mDirName;
            list<FileSystem*> mChild;
        public:
            Dir(const string& name) : mDirName(name){}
            virtual int fileCount() {
                int count = 0;
                for(auto iter = mChild.begin(); iter!=mChild.end(); ++iter)
                    count += (*iter)->fileCount();
                return count;
            }
            virtual Dir* isDir() {return this;}
            virtual void showName(int level = 0) override
            {
                for(int i = 0; i < level; ++i) cout<<"\t";
                // 1) 目录名
                cout <<" + "<< mDirName << "\n";
                ++level; // 多1层缩进
                // 2) 子目录或者文件名
                for(auto iter = mChild.begin(); iter != mChild.end(); ++iter)
                    (*iter)->showName(level);
            }
            int add(FileSystem* pf) { // 只属于Dir的接口函数add和remove
                mChild.push_back(pf); return 0;
            }
            int remove(FileSystem* pf) {
                mChild.remove(pf); return 0;
            }
    };

    static void test()
    {
        Dir * root = new Dir("root"); // 这里不能再用FileSystem,直接用Dir,提供add/remove接口
        FileSystem * file1 = new File("intro.doc");
        FileSystem * file2 = new File("process.md");
        FileSystem * file3 = new File("include.h");
        Dir * dir1 = new Dir("communication");
        Dir * dir2 = new Dir("login");
        Dir * dir3 = new Dir("log");
        root->add(file1);
        root->add(file2);
        root->add(file3);
        root->add(dir1);
        root->add(dir2);
        root->add(dir3);

        FileSystem * file4 = new File("communication.h");
        FileSystem * file5 = new File("communication.c");
        dir1->add(file4);
        dir1->add(file5);

        FileSystem * file6 = new File("login.h");
        FileSystem * file7 = new File("login.c");
        FileSystem * file8 = new File("createAccount.h");
        FileSystem * file9 = new File("createAccount.c");
        FileSystem * file10 = new File("retrieve.h");
        FileSystem * file11 = new File("retrieve.c");
        dir2->add(file6);
        dir2->add(file7);
        dir2->add(file8);
        dir2->add(file9);
        dir2->add(file10);
        dir2->add(file11);

        FileSystem * file12 = new File("log.h");
        FileSystem * file13 = new File("log.c");
        FileSystem * file14 = new File("log.csv");
        FileSystem * file15 = new File("log.txt");
        dir3->add(file12);
        dir3->add(file13);
        dir3->add(file14);
        dir3->add(file15);

        root->showName(1);
        root->remove(dir1);
        dir2->remove(file10);
        dir3->remove(file15);
        root->showName(2);
        if (dir2->isDir()) 
            printf("dir2's fileCount = %d\n",dir2->fileCount()); // 5
        if (dynamic_cast<Dir*>(dir3) != nullptr) 
            printf("dir3's fileCount = %d\n",dir3->fileCount());//3
    }
}
#endif