#pragma once
#include<iostream>
#include<string>

class Screen {
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos a, pos b) :height(a), width(b) { contents = (a*b, " "); }
	Screen(pos a, pos b, char c) :height(a), width(b), contents(a*b, c) {}
	char get() const {
		return contents[cursor];
	}
	char get(pos a, pos b) const;
	Screen &set(char c);
	Screen &set(pos a, pos b, char c);
	Screen &display(std::ostream &os) {
		do_display(os);
		return *this;
	}
	Screen &move(pos a, pos b);
private:
	void do_display(std::ostream &os) const { os << contents; }
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};
char Screen::get(pos a, pos b)const {
	pos row = a*width;
	return contents[row + b];
}
Screen &Screen::move(pos a, pos b) {
	pos row = a*width;
	cursor = row + b;
	return *this;
}
Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
Screen &Screen::set(pos a, pos b, char c) {
	contents[a*width + b] = c;
	return *this;
}