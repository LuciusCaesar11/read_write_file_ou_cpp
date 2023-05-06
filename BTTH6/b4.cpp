#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char c[20];
	gets_s(c);
	char *p;
	fstream f;
	f.open("b4.txt", ios::out);
	p = c;
	while (*p != '\0')
	{
		f << (char)toupper(*p) << endl;
		p++;
	}
	f.close();
	system("pause");
}