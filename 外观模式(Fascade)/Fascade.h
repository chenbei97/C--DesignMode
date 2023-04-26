#ifndef _FASCADE_H_
#define _FASCADE_H_
#include "GameConfig.h"

class Fascade
{
    friend V2::Singleton<Fascade>;
    public:
        void lowConfigPc() // 低配置电脑对外接口
        {
            V2::Graphic& g = V2::Singleton<V2::Graphic>::getInstance();
            g.fullScreen(true);
            g.antiAliasing(1000);
            g.setResolution(1000);
            g.specialEffect(true);
        }
        void highConfigPc() // 高配置电脑对外接口
        {
            V2::Graphic& g = V2::Singleton<V2::Graphic>::getInstance();
            g.fullScreen(true);
            g.antiAliasing(10);
            g.setResolution(10);
            g.specialEffect(false);
        }
};
#endif