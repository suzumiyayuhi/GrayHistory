#pragma once
struct FunctionObject
{
public:
	//14_34
	FunctionObject(int x1, int x2, int x3) :a1(x1), a2(x2), a3(x3) {}
	int operator()(int a, int b, int c) {
		if (a > 10)
			return b;
		else
			return c;
	}
private:
	int a1;
	int a2;
	int a3;
};