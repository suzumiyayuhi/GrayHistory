#include<iostream>
#include<string>
#include<vector>
#include"Screen.h"
using namespace std;


int main() {
	Screen myscreen(5, 5, 'X');
	myscreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myscreen.display(cout);
	cout << "\n";
	
	getchar();
}

