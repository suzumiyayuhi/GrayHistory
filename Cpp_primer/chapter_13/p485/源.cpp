#include"StrVec.h"
#include"Foo.h"
using namespace std;
//13_56
//sorted造成递归死循环

//13_57
//不会发生什么
int main() {
	Foo("ss").sorted();
}