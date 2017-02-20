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
	//�������涨������,��ʱ��֪��ʲôԭ��2017.1.14
	//___________________________________________________
private:
	//16_14
	int hight = M;
	int width = N;
	//____________________
};