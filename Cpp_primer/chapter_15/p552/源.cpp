//15_24
//其派生类定义了一个动态分配的对象，一般基类都需要虚析构函数
//虚析构函数让编译器明白应该使用何种版本的析构函数，目的是释放本类中定义的数据成员,若没有指针类成员可以不执行任何操作