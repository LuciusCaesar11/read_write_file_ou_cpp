#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int a, b, c, a1, b1, c1;
	cin >> a >> b >> c;
	float tbc;
	fstream f;
	f.open("b3.txt", ios::out);
	f << a <<"#"<< b <<"#"<< c;
	f.close();
	f.open("b3.txt", ios::in);
	f >> a1;
	f.ignore(1);
	f >> b1;
	f.ignore(1);
	f >> c1;
	f.close();
	cout << a1 << " " << b1 <<" "<< c1;
	//tbc = (a1 + b1 + c1 )/ 3.0;
	//cout << tbc;
	system("pause");
}