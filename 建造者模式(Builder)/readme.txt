建造者模式就是指某些事需要固定的步骤，可以用到模板方法
现在假设怪物都是躯干、头部和四肢组成的，组成一个怪物需要3个步骤
组装躯干、组装头部、组装四肢，这些局部模型都有一些方向和位置的信息，可以告知如何组装成整个模型

试想，一个亡灵类如果有3个头部、3个躯干、3个四肢，它们就可以组成27种亡灵怪物模型
这样做可以节省内存成本

所以现在MonsterV1.h定义了一个怪物基类，有1个固定模板方法assemble()，3个装载虚函数的方法
然后在UndeadMonsterV1.h、ElementMonsterV1.h、MechanicMonsterV1.h分别定义怪物子类
不过这个版本的实现还不能称之为建造者模式，顶多是个模板方法模式的应用

实际情况是与组装关联的有4个函数，即assemble(),loadTrunk(),loadHead(),loadLimbs()
这4个函数内部的实现肯定是非常复杂的,起始可以把这4个函数的内容单门作为2个类实现，体现构建过程的独立性
一个类是构建者类，封装了loadTrunk(),loadHead(),loadLimbs()这3个函数，组合了MonsterV2*，提供了一个返回函数getMonster()
一个类是指挥者类，封装了assemble()函数内部的内容取名为build()函数，组合了MonsterBuilder属性，返回MonsterV2*，实际类型取决于MonsterBuilder类型
定义在MonsterBuilder.h、MonsterConstructor.h和UndeadBuilder.h、ElementBuilder.h、MechanicBuilder.h中

指挥者内通过构造函数或者setBuilder()函数设置构建者，然后调用build函数，内部让构建者对其内部的Monster进行构建，之后返回
设置不同的构建者MonsterBuilder*就可以返回不同的MonsterV2*

需要说明的是，指挥者可以是不必要的，也就是assemble函数可以在构建者内直接实现，
如果Builder本身比较庞大，或者子类繁多，或者有调整构建次序的需求可以拆分出来

--- 快速理解 ---
① 指挥者构造函数以建造者基类为构造参数，s提供setBuilder和build方法，build内调用建造者基类提供的方法
② 建造者无需以待构建者为参数，内部有个待构建者基类指针即可，建造者类型和待构建者类型一致
建造者子类在构造函数内直接new对应的待构建者即可
③ 待构建者也是多态，被不同建造者构建
