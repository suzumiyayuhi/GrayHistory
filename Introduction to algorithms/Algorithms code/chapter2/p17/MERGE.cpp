#include<iostream>
#include<vector>
using namespace std;
void MERGE(vector<int> &A, size_t q, size_t p, size_t r) {
	size_t n1 = q - p + 1;
	size_t n2 = r - q;
	vector<int> R;
	vector<int> L;
	for (size_t i = 1; i <= n1; ++i) {
		L.push_back(A[p + i - 1]);
	}
	for (size_t j = 1; j <= n2; ++j) {
		R.push_back(A[q + j]);
	}
	L.push_back(99999999);
	R.push_back(99999999);//L[n1+1]=???
	size_t i = 0, j = 0;
	for (size_t k = p; k <= r; ++k) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
	}
}
int main() {
}