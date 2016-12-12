//12_27
#include<vector>
#include<memory>
#include<map>
#include<set>
#include<fstream>
#include<string>
using namespace std;
struct TextQuery
{
public:
	QueryResult query(string&);
	TextQuery() {};
	TextQuery(ifstream&a);
private:
	shared_ptr<vector<string>> TextContents;
	size_t times;
};

struct QueryResult
{
public:

private:
	shared_ptr <set<vector<string>::size_type>> LineNo;
	shared_ptr <map<vector<string>::size_type, string>> KeyInfo;

};