#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
//17_37
void get_file() {
	char content[20];
	ifstream is("1.txt");
	is.get(content, 20, '.');
	for (int i = 0; content[i]; ++i) {
		cout << content[i];
	}
}
//___________________________________________
//17_38
void get_file_updated() {
	char content[20];
	ifstream is("1.txt");
	is.get(content, 20, '.');
	for (int i = 0; content[i]; ++i) {
		if (content[i] == ' ')
			cout << endl;
		else
			cout << content[i];
	}
}
//___________________________________________

int main() {
	get_file();
	cout << endl << endl;
	get_file_updated();
	getchar();
}