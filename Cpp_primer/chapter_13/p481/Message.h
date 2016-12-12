#pragma once
#include<iostream>
//以下拷贝自 https://github.com/pezy/CppPrimer/blob/master/ch13/ex13_49_Message.h#L13
//原版本需要定义东西，懒得弄了。。。。
#include <set>
#include <string>

class Folder;

class Message {
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Folder;

public:
	explicit Message(const std::string& str = "") : contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message&&);
	Message& operator=(Message&&);
	~Message();
	void save(Folder&);
	void remove(Folder&);

	void print_debug();

private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message*);

	void addFldr(Folder* f) { folders.insert(f); }
	void remFldr(Folder* f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder {
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Message;

public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	Folder(Folder&&);
	Folder& operator=(Folder&&);
	~Folder();

	void print_debug();

private:
	std::set<Message*> msgs;

	void add_to_Messages(const Folder&);
	void remove_from_Messages();
	void move_Messages(Folder*);

	void addMsg(Message* m) { msgs.insert(m); }
	void remMsg(Message* m) { msgs.erase(m); }
};

void swap(Folder&, Folder&);
void swap(Message& lhs, Message& rhs)
{
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

// Message Implementation

Message::Message(const Message& m) : contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message::Message(Message&& m) : contents(std::move(m.contents))
{
	move_Folders(&m);
}

Message& Message::operator=(Message&& rhs)
{
	if (this != &rhs) {
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder& f)
{
	addFldr(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	remFldr(&f);
	f.remMsg(this);
}

void Message::print_debug()
{
	std::cout << contents << std::endl;
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders) f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders) f->remMsg(this);
}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

// Folder Implementation

void swap(Folder& lhs, Folder& rhs)
{
	using std::swap;
	lhs.remove_from_Messages();
	rhs.remove_from_Messages();

	swap(lhs.msgs, rhs.msgs);

	lhs.add_to_Messages(lhs);
	rhs.add_to_Messages(rhs);
}

Folder::Folder(const Folder& f) : msgs(f.msgs)
{
	add_to_Messages(f);
}

Folder& Folder::operator=(const Folder& rhs)
{
	remove_from_Messages();
	msgs = rhs.msgs;
	add_to_Messages(rhs);
	return *this;
}

Folder::Folder(Folder&& f)
{
	move_Messages(&f);
}

Folder& Folder::operator=(Folder&& f)
{
	if (this != &f) {
		remove_from_Messages();
		move_Messages(&f);
	}
	return *this;
}

Folder::~Folder()
{
	remove_from_Messages();
}

void Folder::print_debug()
{
	for (auto m : msgs) std::cout << m->contents << " ";
	std::cout << std::endl;
}

void Folder::add_to_Messages(const Folder& f)
{
	for (auto m : f.msgs) m->addFldr(this);
}

void Folder::remove_from_Messages()
{
	for (auto m : msgs) m->remFldr(this);
}

void Folder::move_Messages(Folder* f)
{
	msgs = std::move(f->msgs);
	for (auto m : msgs) {
		m->remFldr(f);
		m->addFldr(this);
	}
	f->msgs.clear();
}