#include"the_header.h"
#include<iostream>

using namespace std;
//12_28
void Seek_and_Out(ifstream &InFile) {
	TextQuery TextQ(InFile) ;
	
	while (true)
	{
		cout << "Now put into a key:";
		string The_key;
		cin >> The_key;

		TextQ.query(The_key);		//������

		char on_off;
		cout << "put into '/' to finish this program." << endl;
		cin >> on_off;
		if (on_off == '/')
		{
			break;
		}
	}
}
//_________________________________________________________________
//12_29
//while���ã�while(true)�ض���ִ��һ�Σ����ұ�do while��Ϊ���
int main() {
	ifstream a("1.txt");
	Seek_and_Out(a);
	return 0;
}