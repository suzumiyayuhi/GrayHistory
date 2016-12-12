#include<memory>
#include<string>
#include<iostream>
using namespace std;
//12_14
struct connection {
	string ip;
	int port;
	connection(string _ip, int _port) :ip(_ip), port(_port) {};
	connection() {};
};
struct destination {
	string ip;
	int port;
	destination() {};
	destination(string _ip, int _port) :ip(_ip), port(_port) {};
};
connection connect(destination *a) {
	auto b = connection(a->ip, a->port);
	return b;
}
void disconnect(connection a) {
	
}
void end_connect(connection *a) {
	disconnect(*a);
}

void f(destination &b) {
	auto a = connect(&b);
	shared_ptr<connection> x(&a, end_connect);
}
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//12_15
void f1(destination &b) {
	auto a = connect(&b);
	shared_ptr<connection> x(&a, [](connection *a) {disconnect(*a); });
}
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
int main() {
	destination dest("123.245.233.54", 23);
	f1(dest);
}