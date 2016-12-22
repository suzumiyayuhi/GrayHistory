#pragma once
#include<iostream>
#include<memory>
#include<string>
using namespace std;
//15_35
class Query_base {
	friend class Query;
public:
	//virtual ~Query_base() {}//放在protected会出错，暂时不知道什么原因。。。2016.12.22
	virtual ~Query_base() = default;
protected:
	
	
private:
	
	virtual string rep() const = 0;//c2259 不能实例化Query_base,其他类有实例化Query_base的现象,所以会报错
	//Query_base() { cout << "Query()" << endl; }
};