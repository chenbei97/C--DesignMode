#include "FlyWeight.h"

int main()
{
    // 非享元模式,棋子需要反复被创建,实际上除了位置不同其它都是相似的,内存占用太多
    V1::Piece * p1 = new V1::Piece(PieceColor::White,{2,2});
    V1::Piece * p2 = new V1::Piece(PieceColor::Black,{3,4});
    V1::Piece * p3 = new V1::Piece(PieceColor::White,{5,3});
    V1::Piece * p4 = new V1::Piece(PieceColor::Black,{4,1});
    list<V1::Piece*> pieceList;
    pieceList.push_back(p1);
    pieceList.push_back(p2);
    pieceList.push_back(p3);
    pieceList.push_back(p4);
    for(auto iter = pieceList.begin(); iter!= pieceList.end();++iter)
    {
        (*iter)->play();
    }

    // 享元模式
    V2::PieceFactory * fac = new V2::PieceFactory();
    auto w1 = fac->getPiece(PieceColor::Black);
    auto w2 = fac->getPiece(PieceColor::White);
    auto w3 = fac->getPiece(PieceColor::Black);
    auto w4 = fac->getPiece(PieceColor::White);
    cout << w1 <<"  "<< w3<<"\n"; // 1个地址
    cout << w2 <<"  "<< w4<<"\n"; // 1个地址
    w1->play({9,7});
    w2->play({8,3});
    w3->play({5,1});
    w4->play({6,4});
    return 0;
}

/*
cd C:\Users\chenb\Desktop\CPPDesignMode\享元模式(FlyWeight)
g++ main.cpp -o main
.\main
*/