//11_5
//map�ǹؼ��ֶ�ֵ��������setΪ�洢�ؼ��ֵ�������
//�ֵ�Ӧ��Ӧʹ��map����set��洢�ؼ�����������

//11_6
//map�ǹ����������洢�����֣��Ҳ������ظ�Ԫ�ء�
//list������˳���������ɴ����ظ�����
#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void X11_7() {
	map<string, vector<string>> names;
	string name; 
	while (cin >> name)
	{
		names["Kirisame"].push_back(name);
	}
	for (auto x : names) {
		cout << x.first << " ";
		for (auto y : x.second)
			cout << y << endl;
	}
}
void X11_8() {
	//vector�ʺϾ���������޸����ݡ�
	//set���ۺ�ʱ��һֱ���������ظ������ݴ��ڡ�
	vector<string> exclude;
	string word;
	while (cin>>word)
	{
		for (auto X : exclude) {
			if (X.find(word))
				break;
			else
			{
				exclude.push_back(word);
			}
		}
	}
}
int main()
{
	X11_7();
	getchar();
	return 0;
}