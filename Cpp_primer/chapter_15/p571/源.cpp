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
//��cout���ԵĽ�����ϣ����廹��Ҫ�Լ����һ�¡�����
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
//ִ��cout<<q�������,ע��ʵ��˳�򲢲���������Ŷ~
//(c)
//���ж��ж��У�����
//�����Լ�̽���ɡ�������û�Ǿ��񡣡���
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
	//ȫ���Ϸ�,Query����ת����BinaryQuery,AndQuery,OrQuery
	//���С�������BinaryQuery���eval�Ǵ��麯��,BinaryQueryû��ʵ������
	//_________________________________________
	getchar();
}

//15_37
//��Query���͵����ݳ�Ա�ĳ�Query_base��ָ��ͺ���