#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	fstream f;
	f.open("b1.txt", ios::out);
	f << sum;
	f.close();
	f.open("b1.txt", ios::in);
	string str;
	while (!f.eof())
	{
		getline(f, str);
		cout << str;
	}
	f.close();
	system("pause");
	return 0;
}