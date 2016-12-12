#include<iostream>
#include<string>
#include<memory>
using namespace std;
void x12_26(int n) {
	allocator<string> a;
	auto const b = a.allocate(n);
	auto d = b;
	string c;
	cin >> c;
	a.construct(d++,c);
	while (d != b)
	{
		cout << *--d << " ";
		a.destroy(d);
	}
	a.deallocate(d, n);
}
void input_reverse_output_string(int n)
{
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	auto q = p; 
	cin >> s;
	while ( q != p + n)
		alloc.construct(q++, s);

	while (q != p) {
		cout << *--q << " ";
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
}
int main() {
	x12_26(5);
//	input_reverse_output_string(5);
	string b;
	cin >> b;
	return 0;
}