#include<iostream>
#include<cmath>
using namespace std;
//17_34
void show_manipulator() {
	cout << true << " " << false << boolalpha << true << " " << false << noboolalpha
		<< "\n" << showbase << 20 << " " << hex << 20 << " " << endl;
}
//____________________________________
//17_35
void print_upper() {
	cout << hexfloat << uppercase << sqrt(2) << endl;
}
//____________________________________
//17_36
void print_row_upper() {
	cout << hexfloat << uppercase << 2.442314 << ends << 3.55442 << endl;
}
//____________________________________
int main() {
	show_manipulator();
	print_upper();
	print_row_upper();
	getchar();
}