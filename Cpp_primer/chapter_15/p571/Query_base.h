#pragma once
#include<iostream>
#include<memory>
#include<string>
using namespace std;
//15_35
class Query_base {
	friend class Query;
public:
	//virtual ~Query_base() {}//����protected�������ʱ��֪��ʲôԭ�򡣡���2016.12.22
	virtual ~Query_base() = default;
protected:
	
	
private:
	
	virtual string rep() const = 0;//c2259 ����ʵ����Query_base,��������ʵ����Query_base������,���Իᱨ��
	//Query_base() { cout << "Query()" << endl; }
};