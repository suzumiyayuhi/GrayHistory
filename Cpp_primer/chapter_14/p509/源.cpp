#include"isequal.h"
#include"biggies.h"
#include<vector>
#include<algorithm>
//14_40
void biggies(vector<string> &vec,size_t sz) {
	sort(vec.begin(), vec.end());
	auto end_unique = unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());
	stable_sort(vec.begin(), vec.end(), biggies1());
	
	auto wc = find_if(vec.begin(), vec.end(), biggies2(sz));
	auto count = vec.end() - wc;
	cout << count << endl;
	for_each(wc, vec.end(), biggies3());
}


int main() {
	vector<string> vec = { "ddd", "ss", "zz", "ffff" };
	//14_38
	cout<<count_if(vec.begin(), vec.end(), isequal(2));
	//_____________________________________________________________
	cout << endl << endl << endl;
	//14_39
	int n = 0;
	for (size_t i = 1; i <= 9; ++i) {
		for (auto beg = vec.begin(); beg != vec.end(); ++beg) {
			isequal ise(i);
			if (ise(*beg)) {
				++n;
			}
		}
	}
	cout << n << endl << endl;
	int n1 = 0;
	for (auto beg = vec.begin(); beg != vec.end(); ++beg) {
		isequal ise(10);
		if (!ise(*beg)) {
			++n1;
		}
	}
	cout << n1-n<<endl<<endl;
	//___________________________________________________________
	//14_40
	biggies(vec, 4);
	//__________________________________________________________
	getchar();
}
//14_41
//需要反复运用lambda，我会选择类来代替
