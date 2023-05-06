#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	int a, b, c,e,h,g;
	cin >> a >> b >> c;
	fstream f;
	f.open("b2.txt", ios::out);
	f << a << "#" << b << "#" << c;
	f.close();
	f.open("b2.txt", ios::in);
	f >> e;
	f.ignore(1);
	f >> h;
	f.ignore(1);
	f >> g;
	f.close();
	cout << (e+h+g)/(3.0);
	system("pause");
	return 0;
}