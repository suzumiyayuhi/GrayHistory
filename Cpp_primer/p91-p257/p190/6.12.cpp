#include"iostream"
using namespace std;
void reset2(int &i,int &j){
	int a;
	a = i;
	i = j;
	j = a;
}
int main2() {
	int i = 40,j=20;
	reset2(i,j);
	cout << i<<" "<<j;
	getchar();
	return 0;
}