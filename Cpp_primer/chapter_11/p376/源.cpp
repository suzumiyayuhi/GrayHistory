//11_1
//map�����������ǹؼ��ֶ�ֵ�������������ؼ��ִ�����ݡ�
//vector��˳�������������ռ�˳�������ݡ�

//11_2
//list���ʺϿ���ɾ�����������ݣ�ѧ����Ϣ����Ӧ�á�
//vector���ʺϿ��ٽ���������ʣ�������Ӧ�á�
//deque���ʺϿ��ٶ���β����Ԫ�صķ��ʣ�����Ӧ�á�
//map���ֵ�Ӧ�á�
//set������Ӧ�á�
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
void X11_3() {
	map<string, int> dic;
	string word;
	while (cin >> word)
	{
		++dic[word];
	}
	for (const auto &w : dic)
		cout << w.first << " " << w.second << endl ;
}
void X11_4() {
	map<string, int> dic;
	string word;
	while (cin >> word)
	{
		
		if (word.find_first_of(",.QWERTYUIOPASDFGHJKLZXCVBNM")!=string::npos)
		{
			++dic[word];
		}
	}
	for (const auto &w : dic)
		cout << w.first << " " << w.second << endl;
}

int main() {
	X11_4();
	getchar();
	return 0;
}