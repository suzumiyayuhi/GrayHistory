#include"标头.h"
using namespace std;

void Seek_and_Out(ifstream &InFile) {
	TextQuery TextQ(InFile);
	while (true)
	{
		cout << "Now put into a key:";
		string The_key;
		cin >> The_key;
		TextQ.query(The_key);		//主方法
		char on_off;
		cout << "put into '/' to finish this program." << endl;
		cin >> on_off;
		if (on_off == '/')
		{
			break;
		}
	}
}

int main() {
	//17_1
	tuple<int, int, int> a(10, 20, 30);
	//_______________________________________
	//17_2
	tuple<string, vector<string>, pair<string, int>> b;
	//________________________________________
	//17_3
	ifstream in("1.txt");
	TextQuery aaa(in);
	printResult(aaa.query("i"));
	//________________________________________
	getchar();
}