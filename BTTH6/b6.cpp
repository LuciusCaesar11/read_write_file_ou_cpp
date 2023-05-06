#include<iostream>
#include<fstream>
using namespace std;

bool nguyenAm(char a)
{
	char b[] = { 'u','e','o','a','i' };
	for (int i = 0; i < 5; i++)
		if (a == b[i])
			return true;
	return false;
}

int main()
{
	char c[20];
	gets_s(c);
	fstream f;
	f.open("b6.txt", ios::out);
	for (int i = 0; i < strlen(c); i++)
		if (nguyenAm(c[i]))
			f << c[i] << endl;
	f.close();
	system("pause");
}