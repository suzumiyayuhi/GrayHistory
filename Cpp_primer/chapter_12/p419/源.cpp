#include<iostream>
#include<memory>
using namespace std;
//12_16
/*
void dd() {
	unique_ptr<int> d(new int(2));
	unique_ptr<int> c(new int(3));
	d = c;
}*/
//������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬
//����(�)		�޷����� ���� "std::unique_ptr<_Ty, _Dx>::operator=(const std::unique_ptr<_Ty, _Dx>::_Myt &) [���� _Ty=int, _Dx=std::default_delete<int>]"
//(������ �������� : 1436�������ļ� : "c:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\memory") --������ɾ���ĺ���	
//p419	d : \C++_primer\chapter_12\p419\p419\Դ.cpp	9
//______________________________________________________________________________________

int main() {
	int ix=1024,*pi=&ix,*pi2=new int(2048);
	typedef unique_ptr<int> Intp;
	//12_17
	//Intp po(ix); ixΪint���ͣ��޷����й���
	//Intp p1(pi);����ͨ�������г���p1����ʱͬʱ�ͷ�pi������Ϊ��δ�����
	//Intp p2(pi2);��ȷ
	//Intp p3(&ix);����ͨ�������г���p1����ʱͬʱ�ͷ�pi������Ϊ��δ�����
	//Intp p4(new int(2048));��ȷ
	//Intp p5(p2.get());����ͨ�������г���p2.get��������ָ�룬��p2������ʱp5��ɿ���ָ�룬
	//____________________________________________________________________________________________________
	getchar();
	return 0;
}
//12_18
//û�б�Ҫ�ṩrelease��Ա��shared_ptr���Խ��м򵥵ĸ��ƺͿ�������