//15_32
//Query:
//拷贝时:调用默认合成的拷贝构造函数或者拷贝赋值运算符
//因为成员类型是shared_ptr,所以该元素引用计数会增加
//销毁时:调用默认合成的析构函数
//移动时:调用默认合成的移动运算符

//15_33
//Query_base:
//因为Query_base是一个抽象基类,没有任何的数据成员,所以执行这些操作并没有什么意义
