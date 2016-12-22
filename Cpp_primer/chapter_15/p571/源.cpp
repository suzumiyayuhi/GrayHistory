//15_34
//(a)
/*
WordQuery(const string &str)
Query(const string &)
WordQuery(const string &str)
Query(const string &)
WordQuery(const string &str)
Query(const string &)
BinaryQuery(const Query&, const Query&, const string)
AndQuery(const Query&, const Query &, const string &)
Query(shared_ptr<Query_base>)
BinaryQuery(const Query&, const Query&, const string)
OrQuery(const Query&, const Query&)
Query(shared_ptr<Query_base>)
*/
//用cout测试的结果如上，具体还需要自己体会一下。。。
//(b)
/*
Query::rep()
BinaryQuery::rep()
Query::rep()
WordQuery::rep()
Query::rep()
BinaryQuery::rep()
Query::rep()
WordQuery::rep()
Query::rep()
WordQuery::rep()
fiery & bird | wind
*/
//执行cout<<q结果如上,注意实际顺序并不是这样的哦~
//(c)
//都有都有都有！！！
//具体自己探究吧。。。我没那精神。。。
//____________________________________________________________
#include"AndQuery.h"
#include"OrQuery.h"
#include"NotQuery.h"
#include"WordQuery.h"
int main() {
	//15_36
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << endl << endl << endl << endl;
	cout << q;
	//____________________________________________________________
	//15_38
	//全不合法,Query不能转换成BinaryQuery,AndQuery,OrQuery
	//还有。。。。BinaryQuery里的eval是纯虚函数,BinaryQuery没法实例化的
	//_________________________________________
	getchar();
}

//15_37
//吧Query类型的数据成员改成Query_base的指针就好了