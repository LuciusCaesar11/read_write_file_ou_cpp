#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void write(int a,int b, int c,char name[])
{
	ofstream f;
	f.open(name, ios::out);
	f << a << " " << b << " " << c;
	f.close();
}

string read(char name[])
{
	ifstream f;
	f.open(name, ios::in);
	string a;
	while (!f.eof())
	{
		getline(f, a);
	}
	f.close();
	return a;
}

int main()
{
	char name[10];
	int a, b, c;
	cin >> a >> b >> c;
	cin.ignore();
	gets_s(name);
	write(a, b, c, name);
	cout << "chuoi trong file la: " << read(name);
	system("pause");
	return 0;
}