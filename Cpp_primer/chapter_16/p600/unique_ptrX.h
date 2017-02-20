#pragma once
//16_28
using namespace std;
template<typename T>
struct unique_ptrX {
public:
	unique_ptrX(const unique_ptrX &a) = delete;
	unique_ptrX& operator=(const unique_ptrX &a) = delete;
	unique_ptrX() = default;
	unique_ptrX(T *tem) :data(tem) {}
	~unique_ptrX()
	{
		delete(data);
		data = nullptr;
	}
private:
	T *data;
};
