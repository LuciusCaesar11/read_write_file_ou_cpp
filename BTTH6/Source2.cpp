#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	char a[20];
	gets_s(a);
	char *p;
	fstream f;
	f.open("b4.txt", ios::out);
	p = a;
	while (*p != NULL)
	{
		f << (char)toupper(*p)<<endl;
		p++;
	}
	f.close();
	string str;
	f.open("b4.txt", ios::in);
	while (!f.eof())
	{
		getline(f, str);
		cout << str << endl;
	}
	system("pause");
	return 0;
}