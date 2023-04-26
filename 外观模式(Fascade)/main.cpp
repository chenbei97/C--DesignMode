// #include "GameConfig.h"
#include "Fascade.h"

int main()
{
    V1::Graphic & g1 = V1::Graphic::getInstance();
    g1.fullScreen(true);
    g1.antiAliasing(1);
    g1.setResolution(100);
    g1.specialEffect(true);

    V2::Graphic & g2 = V2::Singleton<V2::Graphic>::getInstance();
    g2.fullScreen(true);
    g2.antiAliasing(10);
    g2.setResolution(200);
    g2.specialEffect(false);

    // 以上都是客户端直接调用业务类,下方使用外观类

    Fascade& f = V2::Singleton<Fascade>::getInstance();
    f.highConfigPc(); // 使用外观类提供的统一接口
    f.lowConfigPc();
    return 0;
}

/*
g++ main.cpp -o main
.\main
*/