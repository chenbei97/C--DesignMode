这里还是闯关游戏作为例子，现在需要实现同一家族成员聊天的功能

依然是战斗者，每个战斗者都有唯一的ID，可以重复的昵称，以及家族ID
家族ID是唯一的，同一家族的聊天信息可以互相被看到，如果没有加入家族战斗者默认Id-1
具体的定义可见FighterV1.h，衍生的Warrior和Mage类也被定义

玩家信息一般都存储在数据库中，这里使用一个全局容器模拟，存储了所有玩家信息

然后实现聊天功能，还需要定义speak()函数，一种比较低效的实现方式
就是通过遍历容器，然后获取他们的家族ID，判断是否相等，如果相同就发送
不过这种方法玩家多了就变得很低效，所以需要引入观察者模式，即V2版本

观察者模式是行为型模式，它用于这样的场景：需要高效的将当前对象状态的变化通知其它相关的对象
如果能够只把一个家族的放在一起，就不需要遍历所有玩家了，所以需要一个通知类Notify
这个类提供添加和移除通知对象，以及通知的功能，都是虚函数，子类负责实现具体的功能
定义在Notify.h中，配套的Fighter也略有修改，定义在FighterV2.h中

Notify的子类实现定义在ChatLineNotify.h中

观察者模式的其它场景：
1）某个玩家被攻击，同一家族的玩家都去营救
    Fighterx->beAttacked(Notify*);
        Notify->notify(Fighter*f);
            flist = Notify.mFamilyList[f->getFamilyId()] 同一家族的所有成员
            for(auto fx: flist) fx->assist(f); 其它玩家fx去营救此玩家f
2）数据表的数据和各种图（饼图、折线图、直方图等）有关联关系
    DataSheet->changeData(); 数据表一旦改变
    Chartx->setDataSheet(DataSheet*); 更新数据表
        clist = DataSheet.mChartList 获取数据表维护的图列表
        for (auto cx: clist) cx->replot(); 每张图重新绘制
3）炮塔攻击指定范围内(30m)的所有玩家，30m内的玩家可以随时加入和移除，炮塔维护一个30m的玩家列表即可


