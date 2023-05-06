#include<iostream>
using namespace std;
#include<string>

int main()
{
	//123 eee 2000
	string s;
	getline(cin, s);
	int pos = s.find(" ");
	string a = s.substr(0, pos);
	s.erase(0, pos + 1)
	system("pause");
	return 0;
}