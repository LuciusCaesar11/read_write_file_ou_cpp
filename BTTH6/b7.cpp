#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	float salary;
	fstream f;
	f.open("b7.txt", ios::out);
	while (true)
	{
		cin >> salary;
		if (salary == -1)
			break;
		f << salary <<endl;
	}
	f.close();
	system("pause");
}