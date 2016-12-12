#pragma once
#include<string>
#include"Screen.h"
#include<vector>
using namespace std;
struct Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	vector<Screen> screens = { Screen(24, 80, ' ') };
};
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}