//13_33
//不用const folder& 因为需要改变值
//不用foloder因为需要改变实参的值，使用引用更加方便
#include<iostream>
#include<set>
using namespace std;
//13_34
//注意注意！ 构造函数，析构函数等等，没有完全定义完，会报错，但是语法没错
struct Folder {
public:
	void addMsg( Message *Mes) {
		Sname.insert(Mes);//13_36_____________________________________________-
	}
	void RemMsg( Message *Mes) {
		Sname.erase(Mes);
	}
private:
	set<Message*> Sname;
};

struct Message
{
public:
	friend struct Folder;
	Message(const string &s = "") :contents(s) {}
	Message(const Message &Mes) { 
		contents = Mes.contents;
		Folders = Mes.Folders;
		add_to_Folders(Mes);
	}
	Message& operator=(const Message &Mes) {
		remmove_from_Folders();
		contents =  Mes.contents;
		Folders = Mes.Folders;
		add_to_Folders(Mes);
		return *this;
	}
	void EraFolder(Folder *a) {
		Folders.erase(a);
	}//13_7______________________________________________________
	void save(Folder&);
	void remove(Folder&);
	void swap(Message &a, Message &b);
private:
	string contents;
	set<Folder*> Folders;
	void add_to_Folders(const Message&);
	void remmove_from_Folders();
};
void Message::save(Folder &f) {
	Folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder &f) {
	Folders.erase(&f);
	f.RemMsg(this);
}
void Message::add_to_Folders(const Message &Mes) {
	for (auto x : Mes.Folders)
		x->addMsg(this);
}
void Message::remmove_from_Folders() {
	for (auto x : Folders)
		x->RemMsg(this);
}
void Message::swap(Message &a, Message&b) {
	using std::swap;
	for (auto x : a.Folders)
		x->RemMsg(&a);
	for (auto x : b.Folders)
		x->RemMsg(&a);
	swap(a.contents, b.contents);
	swap(a.Folders, b.Folders);
	for (auto x : a.Folders)
		x->addMsg(&a);
	for (auto x : b.Folders)
		x->addMsg(&b);
}
//13_35
//对象仅仅凭空存在，并不存在于任何folder之中

//13_36
//赋值后原message就应该不存在了
//使用message::swap降低了效率

int main() {

}