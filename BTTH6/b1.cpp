#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{	
	string str;
	int a = 5;
	int b = 5;
	int tong = a + b;
	fstream f;
	f.open("b1.txt", ios::out);
	f <<tong;
	f.close();
	/*f.open("b1.txt", ios::in);
	while (!f.eof())
	{
		getline(f, str);
		cout << str<<endl;
	}
	*/
	system("pause");
}