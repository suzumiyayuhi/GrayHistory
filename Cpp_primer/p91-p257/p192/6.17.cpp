#include"iostream"
#include"string"
using namespace std;
void isupper1(string a)
{
	auto q = a.size();
	for (decltype(q) o = 0; o != q; o++) 
	{
		if (isupper(a[o])) {
			cout << "There is an upper alpha"<<endl;
			break;
		}
	}
}
void tosmaller1(string &a)
{
	for (auto &c : a)
		c = tolower(c);
}
int main() {
	string i;
	cin >> i;
	isupper1(i);
	tosmaller1(i);
	cout << i<<endl;
	cin >>i ;
	return 0;
}