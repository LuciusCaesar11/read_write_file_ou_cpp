#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int m;
	fstream f;
	f.open("b1.txt", ios::in);
	f >> m;
	cout << m;
	system("pause");
}