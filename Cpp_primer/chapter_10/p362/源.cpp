#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<numeric>
using namespace std;
void X10_29(vector<string> &saving,string FName) {
	ifstream FileIn(FName);
	istream_iterator<string> FileIter(FileIn), eof;
	while (FileIter!=eof) {
		saving.push_back(*FileIter);
		++FileIter;
	}
	for (auto x : saving)
		cout << x << " ";
}
void X10_30(vector<int> a) {
	istream_iterator<int> Initer(cin), eof;
	while (Initer != eof)
	{
		a.push_back(*Initer);
		++Initer;
	}
	sort(a.begin(), a.end());
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
}
void X10_31(vector<int> a) {
	istream_iterator<int> InIter(cin), eof;
	while (InIter != eof)
	{
		a.push_back(*InIter);
		++InIter;
	}
	sort(a.begin(), a.end());
	unique_copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
}
struct Sale_data
{
	int price;
	string isbn;
};
bool compareIsbn(Sale_data a, Sale_data b) {
	return a.isbn > b.isbn;
}

void X10_32(vector<Sale_data> sales_data) {
	Sale_data temp;
	int switchoff;
	while (true)
	{
		cout << "put into the price:";
		cin >> temp.price;
		cout << endl;
		cout << "put into the isbn:";
		cin >> temp.isbn;
		sales_data.push_back(temp);
		cout << "put into 0 to finish:";
		cin >> switchoff;
		if (switchoff == 0) {
			break;
		}
	}
	sort(sales_data.begin(), sales_data.end(), compareIsbn);
	//没有sales_item.h，所以偷懒了。。。。
	int total_price = 0;
	for (auto x : sales_data)
		total_price += x.price;
}
void X10_33(string InFile,string OutFile1,string OutFile2) {
	ifstream In_file_stream(InFile);
	ofstream Out_file_stream(OutFile1),Out_file_stream1(OutFile2);
	istream_iterator<int> In_iter(In_file_stream), eof;
	ostream_iterator<int> Out_iter(Out_file_stream," "), Out_iter1(Out_file_stream1, "\n");
	istream_iterator<int> In_iterX = In_iter;
	while (In_iter != eof)
	{
		if ((*In_iter)%2==0)
		{
			Out_iter = *In_iter;
			++In_iter;
		}
		else
		{
			Out_iter1 = *In_iter;
			++In_iter;
		}
	}
}

int main() {
	vector<string> a;
//	X10_29(a, "xxx.txt");
	vector<int> b;
//	X10_31(b);
	vector<Sale_data> s;
	X10_33("s","ss","sss");
	getchar();
	return 0;
}