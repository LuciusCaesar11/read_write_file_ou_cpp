#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	fstream f;
	char c;
	int count = 0;
	f.open("b4.txt", ios::in);
	while (f>>c)
	{
		count++;
	}
	f.close();
	cout << count;
	system("pause");
	return 0;
}