#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
//17_39
void My_seek() {
	fstream inout("1.txt", fstream::ate | fstream::in | fstream::out);
	if (!inout) {
		cout << "fail to read file" << endl;
		return ;
	}
	auto end_file = inout.tellg();
	inout.seekg(0, fstream::beg);
	string line;
	size_t line_sz = 0;
	while (inout.tellg() != end_file&&getline(inout, line)) {
		line_sz += line.size() + 1;
		auto tem_mark = inout.tellg();
		inout.seekg(0, fstream::end);
		inout << line_sz<<" ";
		inout.seekg(tem_mark);
	}
	return ;
}
//_______________

int main() {
	My_seek();
	getchar();
}