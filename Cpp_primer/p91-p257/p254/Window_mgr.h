#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Screen.h"
class Screen;
class Window_mgr {
public:
	friend Screen;
	typedef std::vector<Screen>::size_type ScreenIndex;
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens{};
};
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.width*s.height, ' ');
}