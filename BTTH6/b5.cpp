#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int count=0;
	char c;
	fstream f;
	f.open("b4.txt", ios::in);
	while (f >> c)
	{
		count++;
	}
	f.close();
	cout << count;
	system("pause");
}