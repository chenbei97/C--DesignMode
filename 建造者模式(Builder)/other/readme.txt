另一个建造者模式的案例

员工周报，由3个部分组成，分别是标题、内容（可以多条）和结尾，由于这3个部分没有共性，所以不需要共同基类
这3个组成部分的类定义于header.h,content.h,footer.h
标题需要提供部门名称和周报时间，内容是工作描述和花费的时间，结尾是员工名字

现在需要把这个周报合并导出成各种格式，比如txt格式，xml格式，json格式等等
导出文件固定的3个步骤是拼接标题、拼接内容、拼接结尾

所以如果不使用建造者模式，比如导出txt和xml格式，就需要2个类，定义了exportFile()函数
定义在ExportTxtFileV1.h和ExportXmlFileV1.h中，导出简略为打印到屏幕中
可以看出如果以后还要导出各种各样的格式，就会导致大量的重复代码，这也是为何需要建造者模式
主程序见mainV1.cpp中的调用

现在使用建造者模式，可以提出固定导出的3个步骤，这3个步骤函数是建造者类的虚函数，定义在FileBuilder.h
然后不同的格式构建子类需要重写这3个虚函数，现在给出txt和xml的，定义在ExportTxtFileV2.h和ExportXmlFileV2.h中

构建步骤可以调整次序，定义一个指挥者类，在FileDirector.h中
构造函数以FileBuilder*为参数，同时提供setBuilder()函数用于设置mBuilder
提供build()方法去执行构建，主程序见mainV2.cpp中的调用


