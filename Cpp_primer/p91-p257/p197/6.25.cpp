#include"iostream"
using namespace std;

int main(int argc, char *argv[]) {
	argv[1] = "fff";
	argv[2] = "xxx";
	cout << argc;
	for (; argc != 3; ++argc)
		cout << argv[argc]<<endl;
	getchar();
	return 0;
}