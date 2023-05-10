#ifndef FlyWeight_H
#define FlyWeight_H
#include <list>
#include <map>
#include <string>
#include <iostream>
using std::list;
using std::map;
using std::string;
using std::cout;
using std::to_string;
using::std::make_pair;
typedef unsigned short uint16_t;

enum class PieceColor
{
    White,
    Black
};

struct PiecePosition
{
    uint16_t x;
    uint16_t y;
    PiecePosition(uint16_t tx,uint16_t ty): x(tx),y(ty){}
};

#define WHITE_COLOR "white"
#define BLACK_COLOR "black"
#define WHITE_PIECE_POS(cstr,pos) (string(cstr)+string(" piece is in (")+to_string(pos.x)+","+to_string(pos.y)+")")
#define BLACK_PIECE_POS(cstr,pos) (string(cstr)+string(" piece is in (")+to_string(pos.x)+","+to_string(pos.y)+")")
#define DESCRIPTION_PIECE(color,pos) ((color==PieceColor::White)?(WHITE_PIECE_POS(WHITE_COLOR,pos)):(BLACK_PIECE_POS(BLACK_COLOR,pos)))
#define PLAY_CHESS(color,pos) (cout<<DESCRIPTION_PIECE(color,pos)<<"\n")

namespace V1 { // 非享元模式
    class Piece { // 棋子有颜色和位置属性
        private:
            PieceColor mColor;
            PiecePosition mPos;
        public:
            Piece(PieceColor color, PiecePosition pos):mColor(color),mPos(pos){}
            void play() { PLAY_CHESS(mColor,mPos);}
    };
}

namespace V2 { // 享元模式的优化
    class Piece{  // 使用父类,2个子类继承还可以去掉颜色信息在构造函数的耦合
        public:
            virtual ~Piece(){}
            virtual void play(PiecePosition) = 0; // 位置不要作为棋子的私有属性被共享,也不放在构造函数
    };
    class BlackPiece: public Piece
    {
        public:
            virtual void play(PiecePosition pos) override {PLAY_CHESS(PieceColor::Black,pos);}
    };
    class WhitePiece: public Piece
    {
        public:
            virtual void play(PiecePosition pos) override {PLAY_CHESS(PieceColor::White,pos);}
    };
    class PieceFactory{ // 再使用棋子工厂,内部利用map只存放最多2个对象,黑棋和白棋
        private:
            map<PieceColor,Piece*> mPiece;
        public:
            ~PieceFactory() {
                for(auto iter = mPiece.begin(); iter!= mPiece.end();++iter)
                {
                    Piece* p = iter->second;
                    delete p;
                }
            }
            Piece* getPiece(PieceColor color) // 颜色属性转移到普通函数这里
            {
                auto ret = mPiece.find(color); // 查找此颜色对应的棋子
                if (ret == mPiece.end()) // 如果没找到
                {
                    Piece * p = nullptr;
                    // p = (color == PieceColor::White) ? (new WhitePiece()):(new BlackPiece()); // 提示类型不兼容
                    if (color == PieceColor::White) p = new WhitePiece();
                    else p = new BlackPiece();
                    mPiece.insert(make_pair(color,p));
                    return p;
                }
                else return ret->second; 
            }
    };
}

#endif