#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

string nhap()
{
	string s;
	cout << "Nhap s: ";
	getline(cin, s);
	return s;
}

void ghi(string s)
{
	fstream f;
	f.open("b9.txt", ios::out);
	f << s;
	f.close();
}

void doc()
{
	string s;
	fstream f;
	f.open("b9.txt", ios::in);
	while (!f.eof())
	{
		getline(f, s);
		cout << s;
	}
	f.close();
}

void cmp(string a, string b)
{
	if (a > b)
		cout << "chuoi" << a << ">" << "chuoi" << b;
	else if (a == b)
		cout << "hai chuoi bang nhau";
	else
		cout << "chuoi" << a << "<" << "chuoi" << b;
}

string noichuoi(string a, string b)
{
	return a + b;
}

bool nguyenAm(char a)
{
	char b[] = { 'u','e','o','a','i' };
	for (int i = 0; i < 5; i++)
		if (a == b[i])
			return true;
	return false;
}

int count(string a)
{
	int count = 0;
	int len = a.length();
	for (int i = 0; i < len; i++)
		if (nguyenAm(a[i]))
			count++;
	return count;
}

int demtu(string a)
{
	int cnt = 0;
	stringstream ss(a);
	string token;
	while (ss >>token)
	{
		cnt++;
	}
	return cnt;
}

int main()
{
	string s;
	getline(cin, s);
	cout << demtu(s);
	system("pause");
}
