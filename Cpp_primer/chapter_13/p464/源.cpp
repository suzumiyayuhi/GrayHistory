//13_33
//����const folder& ��Ϊ��Ҫ�ı�ֵ
//����foloder��Ϊ��Ҫ�ı�ʵ�ε�ֵ��ʹ�����ø��ӷ���
#include<iostream>
#include<set>
using namespace std;
//13_34
//ע��ע�⣡ ���캯�������������ȵȣ�û����ȫ�����꣬�ᱨ�������﷨û��
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
//�������ƾ�մ��ڣ������������κ�folder֮��

//13_36
//��ֵ��ԭmessage��Ӧ�ò�������
//ʹ��message::swap������Ч��

int main() {

}