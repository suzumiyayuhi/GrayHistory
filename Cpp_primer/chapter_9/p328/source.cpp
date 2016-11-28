#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
void X9_50_vol1(vector<string> a) {
	int sum = 0;
	for (auto ele : a) {
		int temp = stod(ele);
		sum += temp;
	}
	cout << sum;
}
void X9_50_vol2(vector<string> a) {
	double sum = 0;
	for (auto ele : a) {
		double temp = stod(ele);
		sum += temp;
	}
	cout << sum;
}
struct date
{
	unsigned year;
	unsigned month;
	unsigned day;
	date(string str);
};
date::date(string str){
	char temp1;
	string temp2;
	string first = "/";
	string second = " ";
	if (str.find_first_of(first)!=string::npos)
	{
		if (true)				//这里只考虑1/1/1990的情况。考虑1990/1/1，改一下条件，再写个else就好了。
		{
			istringstream in(str);
			int key = 0;
			while (in>>temp1)
			{
				if (temp1!='/'  )
				{
					temp2.push_back(temp1);
				}
				else
				{
					switch (key)
					{
					case 0:day = stod(temp2); temp2.clear(); ++key; break;
					case 1:month = stod(temp2); temp2.clear(); break;
					default: cout << "error!!!!";
						break;
					}
				}
			}
			year = stod(temp2);
			temp2.clear();
		}
	}
	else if (str.find_first_of(second) != string::npos) 
	{
		if (str.find("Jan")) { month = 1; }
		if (str.find("January")) { month = 1; }
		if (str.find("Feb")) { month = 2; }
		if (str.find("February ")) { month = 2; }
		if (str.find("March ")) { month = 3; }
		if (str.find("Mar")) { month = 3; }
/*		if (str.find("Jan")) { month = 1; }			理解就好-_-||
		if (str.find("Jan")) { month = 1; }
		if (str.find("Jan")) { month = 1; }
		if (str.find("Jan")) { month = 1; }
		if (str.find("Jan")) { month = 1; }
		if (str.find("Jan")) { month = 1; }
		*/
		string numbers = { "0123456789" };
		istringstream in(str);
		int key = 0;
		while (in>>temp1)
		{
			if ((temp1!=','))
			{
				temp2.push_back(temp1);
				if (temp2.find_first_of(numbers) == string::npos) {
					temp2.clear();
				}
			}
			else
			{
				switch (key)
				{
				case 0: day = stod(temp2); temp2.clear(); break;
				default:cout << "error!!!!"; 
					break;
				}
			}
		}
		year = stod(temp2);
		temp2.clear();
	}
}
int main() {
//	vector<string> a = { "1.2","2","3" };
//	X9_50_vol2(a);
	string x = "1/1/1990";
	string y = "January 1,1900";
	string z = "Jan 1 1900";
	date a(y);
	cout <<a.day<<a.month<<a.year;
	getchar();
	return 0;
}