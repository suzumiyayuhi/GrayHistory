#include"Message.h"
#include"String.h"
#include"StrVec.h"
#include<algorithm>
#include"HasPtr.h"
//13_49
/*
这个故事告诉我们，每次写完一个类都要运行下看看有没有错= =
Message::Message(Message &&mes) {
	contents = std::move(mes.contents);
	Folders = std::move(mes.Folders);
	for (auto x : Folders) {
		x->RemMsg(&mes);
		x->addMsg(this);
	}
	mes.Folders.clear();
}
Message& Message::operator=(Message &&mes) {
	if (this != &mes) {
		remmove_from_Folders();
		contents = std::move(mes.contents);
		Folders = std::move(mes.Folders);
		for (auto x : Folders) {
			x->RemMsg(&mes);
			x->addMsg(this);
		}
		mes.Folders.clear();
	}
	return *this;
}
Folder::Folder(Folder &&fol) {
	Sname = std::move(fol.Sname);
	for (auto x : fol.Sname) {
		fol.Sname.erase(x);
		Sname.insert(x);
	}
	fol.Sname.clear();
}
Folder& Folder::operator=(Folder &&Fol){
	if (this != &Fol) {
		for (auto x : Sname)
			Sname.erase(x);
		Sname = std::move(Fol.Sname);
		for (auto x : Fol.Sname) {
			Sname.insert(x);
			Fol.Sname.erase(x);
		}
		Fol.Sname.clear();
	}
}
*/
String::String(String &&str) {
	elements = str.elements;
	end = str.end;
	str.elements = str.end = nullptr;
	cout << "String(String &&str)" << endl;
}
String& String::operator=(String &&str) {
	if (this != &str) {
		if (elements) {
			for_each(elements, end, [this](char &c) {alloc.destroy(&c); });
			alloc.deallocate(elements, end - elements);
		}
	}
	cout << "String& operator=(String &&str)" << endl;
	return *this;
}
StrVec::StrVec(StrVec &&Strv) {
	elements = Strv.elements;
	first_free = Strv.first_free;
	cap = Strv.cap;
	Strv.elements = Strv.first_free = Strv.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec &&strv) {
	free();
	first_free = strv.first_free;
	elements = strv.elements;
	cap = strv.cap;
	strv.first_free = strv.elements = strv.cap = nullptr;
	return *this;
}

int main() {
	//13_50
	vector<String> a;
	a.push_back("dd");
	a.push_back("ddf");
	a.push_back("xxx");
	//__________________________-
	cout << endl;
	String hp, hp2;
	hp2 = "ddd";
	cout << endl;
	hp = hp2;
	cout << endl;
	hp = std::move(hp2);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	//13_53
	//接下来的代码很好的回答了这个问题
	HasPtr b("xxx");
	HasPtr d("xxxx");
	HasPtr c();
	cout << endl;
	b = d;
	getchar();
}
//13_51
//clone所实行的其实不是拷贝操作，而是移动操作
//移动后，原对象被销毁

//13_52
//hp = hp2
//hp2为左值，使用拷贝赋值运算符，将hp2值赋给hp
//hp = std:move(hp2)
//调用std:move(hp2)，hp2数据被销毁，使用移动赋值运算符
