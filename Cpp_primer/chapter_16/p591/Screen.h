#pragma once
#include<iostream>

using namespace std;
template<unsigned M,unsigned N>
struct Screen {
public:
	//16_15
	friend std::ostream & operator<< (std::ostream &os, const Screen<M, N> & sc)
	{
		os << sc.hight << " " << sc.width;
		return os;
	}
	friend istream& operator >> (istream &is, const Screen<M, N> &sc) {
		is >> sc.hight >> sc.width;
		return is;
	}
	//在类外面定义会出错,暂时不知道什么原因2017.1.14
	//___________________________________________________
private:
	//16_14
	int hight = M;
	int width = N;
	//____________________
};