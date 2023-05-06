#include<iostream>
#include<fstream>
#include<string>
using namespace std;


bool isVowel(char a)
{
	char vowel[] = { 'u','e','o','a','i','U','E','O','A','I' };
	for (int i = 0; i < 10; i++)
		if (a == vowel[i])
			return true;
	return false;
}
int main()
{
	fstream f;
	fstream f1;
	f.open("b4.txt", ios::in);
	char ch;
	string s = "";
	while (f >> ch)
	{
		if (isVowel(ch))
		{
			s += ch;
			s += '\n';
		}
	}
	f.close();
	f1.open("b6.txt", ios::out);
	f1 << s;
	f1.close();
	string str;
	f1.open("b6.txt", ios::in);
	while (!f1.eof())
	{
		getline(f1, str);
		cout << str << " ";
	}
	system("pause");
	return 0;
}