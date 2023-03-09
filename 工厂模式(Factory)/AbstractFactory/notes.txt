假设现在游戏中的怪物种类不变，还是亡灵、元素以及机械类怪物，但是场景变多了
原来只有城镇，现在增加了山脉和沼泽地图的场景，
不同场景同一类怪物的属性能力是不同的，那么可以通过下表来展示这种关系

场景    亡灵怪物    元素怪物    机械怪物 按行:有3类产品族分属不同场景
城镇    城镇亡灵    城镇元素    城镇机械   
山脉    山脉亡灵    山脉元素    山脉机械
沼泽    沼泽亡灵    沼泽元素    沼泽机械
按列:同类怪物

抽象工厂的核心思想是: 如果一个工厂子类能够生产不止一种具有相同规则的怪物对象，
那么就可以有效减少所创建的工厂子类对象

那么这里为了减少工厂子类对象，按行来看，每个工厂依然可以生成全部的怪物对象
如果使用工厂方法模式，实际上需要9类怪物和9个工厂，现在的需要9个怪物但是只需3个工厂

城镇类的怪物定义在TownMonster.h中
沼泽类的怪物定义在SwampMonster.h中
山脉类的怪物定义在MountainMonster.h中
每个场景类都定义了3类怪物，亡灵、元素、机械

抽象工厂类的写法稍有变化，之前只有一个纯虚函数createMonster()
现在因为每个子工厂都可以创建全部的怪物类型，又因为怪物有3类，所以需要3个纯虚函数，定义在MonsterFactory.h中
virtual Monster* createUndeadMonster() = 0;
virtual Monster* createElementMonster() = 0;
virtual Monster* createMechanicMonster() = 0;
然后就可以定义不同的场景工厂子类，分别定义在TownFactory.h、SwampFactory.h、MountainFactory.h中

抽象工厂的好处在于，如果增加新的场景森林，怪物不变，只需要增加一个森林工厂子类即可，其他无需改动
坏处在于，如果增加一个龙类怪物，那么MonsterFactory需要增加1个对龙类怪物支持虚函数，然后所有场景工厂子类也要相应增加对该虚函数的实现
这种情况就不适合使用抽象工厂模式

另一个例子可见other文件夹下
有中国、日本和美国的厂商，都可以生成芭比娃娃，芭比娃娃由固定3个组件组成，身体、衣服和鞋子
所以other下的文件对应关系为:
- DollPart.h 定义了DollPart抽象部件类,3个子类Body、Clothes和Shoes继承DollPart作为抽象具体部件类
- ChinaDollPart.h 定义了ChinaBody,ChinaClothes,ChinaShoes
  JapanDollPart.h 定义了JapanBody,JapanClothes,JapanShoes
  UsaDollPart.h   定义了UsaBody,UsaClothes,UsaShoes
- DollFactory.h 定义了抽象厂商类DollFactory,内部有3个虚函数用于创建身体、衣服和鞋子
- ChinaFactory.h 定义ChinaFactory,对3个虚函数重实现
  JapanFactory.h 定义JapanFactory,对3个虚函数重实现
  UsaFactory.h 定义UsaFactory,对3个虚函数重实现
- BarbieDoll.h 芭比娃娃类,构造函数由身体、鞋子和衣服组成
- main.cpp 主程序
