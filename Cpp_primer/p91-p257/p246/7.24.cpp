#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos a, pos b) :height(a), width(b) { contents=(a*b, ""); }
	Screen(pos a,pos b,char c):height(a),width(b),contents(a*b,c){}
private:
	string::size_type curspr = 0;
	string::size_type height = 0, width = 0;
	string contents;
};
int main() {

}