//14_50
struct LonDouble {
	LonDouble(double = 0.0);
	operator double();
	operator float();
};
LonDouble ldObj;
//int ex1 = ldObj;//错误
//float ex2 = ldObj;正确
//——————————————————————

//14_51
void calc(int);
void calc(LonDouble);
double dval;
int main() {
	calc(dval);
	//double->int由标准库定义转换过程,优先级高于自定义转换
}
//___________________________________________________