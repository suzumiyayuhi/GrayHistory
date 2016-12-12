//14_52
struct SmallInt;
struct LongDouble
{
	LongDouble operator+(const SmallInt&);
};
LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;
int main(){
	//ld = si + ld;一般的重载运算符
	//ld = ld + si;类的成员运算符
}
//__________________________________________

//14_53
//double d = s1 + Smallint(3.14);