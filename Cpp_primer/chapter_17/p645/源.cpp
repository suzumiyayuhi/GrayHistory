#include<iostream>
#include<bitset>
using namespace std;
//17_11
template<unsigned T> struct con {
public:
	//17_12
	void update(const size_t &a, const bit &b) {
		c[a] = b;
	}
	//_________________________________________________
	void check_generate() {
		for (int i = 0; i < T; ++i) {
			if (c[T]) {
				++val;
			}
		}
		cout << "the value is " << val;
	}
private:
	bitset<T> c;
	//17_13
	int val;
	//______________________
};
//_________________________________________
int main() {
	//17_10
	bitset<32> a(3);
	bitset<32> b;
	b.set(1); b.set(2); b.set(3); b.set(5); b.set(8); b.set(13);
	b.set(21);
	//________________________________
	

}