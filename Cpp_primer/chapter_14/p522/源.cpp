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
	//ld = si + ld;һ������������
	//ld = ld + si;��ĳ�Ա�����
}
//__________________________________________

//14_53
//double d = s1 + Smallint(3.14);