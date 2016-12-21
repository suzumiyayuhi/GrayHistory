//15_8
//静态类型在编译时总是已知的,类型是声明时或者表达式生成的类型
//动态类型在编译后才明确，他的类型是变量或表达式在内存中所表达对象的类型

//15_9
//当使用一个派生类对象来初始化或对基类赋值时
struct base{
	int x;
};
struct foo:public base{
	int v;
};
foo a;
base *b = &a;

//15_10
//ifstream input(argv[1]);
//Sales_data total;
//read(input,total);
//read函数第一个形参要求为fstream为ifstream的基类
//用派生类ifstream初始化了fstream基类