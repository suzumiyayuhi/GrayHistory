/*#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos a, pos b) :height(a), width(b) { contents = (a*b, ""); }
	Screen(pos a, pos b, char c) :height(a), width(b), contents(a*b, c) {}
	Screen &move(pos a, pos b);
	Screen &set(char);
	Screen &set(pos , pos , char);
	const Screen &display(ostream &os) { 
	do_display(os);
	return *this;
	}
private:
	void do_display(ostream & os) const { os << contents; }
	string::size_type cursor = 0;
	string::size_type height = 0, width = 0;
	string contents;
};
Screen & Screen::move(pos  a, pos  b)
{
	pos row = a*width;
	cursor = row + b;
	return *this;
}

Screen & Screen::set(char a)
{
	contents[cursor] = a;
	return *this;
}

Screen & Screen::set(pos a, pos b, char c)
{
	contents[a*width + b] = c;
	return *this;
}
int main() {
	Screen myscreen(5, 5, 'X');
	myscreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myscreen.display(cout);
	cout << "\n";
	getchar();
}*/