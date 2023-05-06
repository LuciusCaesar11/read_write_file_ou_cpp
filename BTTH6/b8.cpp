#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	float tbc;
	fstream f;
	f.open("b8.txt", ios::out);
	f << a << "#" << b << "#" << c;
	f.close();
	f.open("b8.txt", ios::in);
	f >> a;
	f.ignore(1);
	f >> b;
	f.ignore(1);
	f >> c;
	f.close();
	cout << a << " " << b << " " << c;
	system("pause");
}