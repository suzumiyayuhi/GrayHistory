#include"iostream"
using namespace std;

int main() 
{
	int a, b;

	while (true)
	{
		cin >> a >> b;
		try
		{
			if (b == 0)
				throw runtime_error("b is 0");
		}
		catch (runtime_error err)
		{
			cout << err.what() << "\n Try again?\n";
			char c;
			cin >> c;
			if (c != 'n')
				continue;
		}
		cout << a / b;
	}
	return 0;
}