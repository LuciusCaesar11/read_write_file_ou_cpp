#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct SinhVien {
	string masv;
	string hoten;
	int namsinh;
};

void Nhap(SinhVien *sv)
{
	cout << "Nhap ma sinh vien: ";
	getline(cin, sv->masv);
	cout << "Nhap ho ten sinh vien: ";
	getline(cin, sv->hoten);
	cout << "Nhap nam sinh: ";
	cin >> sv->namsinh;
	getchar();
}

void Xuat(SinhVien sv)
{
	cout << "ma sinh vien: " << sv.masv << endl;
	cout << "ho ten sinh vien: " << sv.hoten << endl;
	cout << "nam sinh: " << sv.namsinh << endl;
}

void NhapDs(SinhVien *sv, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap sinh vien thu " << i << ": " << endl;
		Nhap(&sv[i]);
	}
}
void XuatDs(SinhVien *sv, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "thong tin sinh vien thu " << i << ": " << endl;
		Xuat(sv[i]);
	}
}

void Luuds(SinhVien *sv, int n)
{
	fstream f;
	f.open("b10.txt", ios::out);
	for (int i = 0; i < n; i++)
		f << sv[i].masv << " " << sv[i].hoten << " " << sv[i].namsinh << endl;
	f.close();
}

void XuatdsFromFile(SinhVien *sv, int n)
{
	fstream f;
	string token;
	f.open("b10.txt", ios::in);
	while (!f.eof())
	{
		getline(f, token);
		cout << token << endl;
	}
}

void timSvFromFile()
{
	bool found = false;
	string line;
	fstream f;
	string Masv;
	cout << "Nhap ma sinh vien can tim: ";
	getline(cin, Masv);
	f.open("b10.txt", ios::in);
	while (getline(f, line)&&!f.eof())
	{
		int pos = line.find(" ");
		if (Masv == line.substr(0, pos))
		{
			SinhVien *sv=new SinhVien;
			sv->masv = line.substr(0, pos);
			line.erase(0, pos+1);
			int pos1 = line.find(" ");
			sv->hoten = line.substr(0, pos1);
			line.erase(0, pos1+1);
			sv->namsinh = stoi(line);
			Xuat(*sv);
			found = true;
			system("pause");
			break;
		}
	}
	f.close();
	if (found == false)
	{
		cout << "khong tim thay";
	}
}
int main()
{
	int n;
	cout << "nhap so luong sv: ";
	cin >> n;
	SinhVien *sv=new SinhVien[n];
	int luachon;
	while (true)
	{
		cout << "1.nhap ds sv" << endl;
		cout << "2.xuat ds sv" << endl;
		cout << "3.luu ds sv" << endl;
		cout << "4.tim sv qua ma sv" << endl;
		cout << "0.thoat" << endl;
		cout << "nhap lua chon: ";
		cin >> luachon;
		getchar();
		if (luachon == 1)
			NhapDs(sv, n);
		else if (luachon == 2)
			XuatDs(sv, n);
		else if (luachon == 3)
		{
			Luuds(sv, n);
			cout << "luu thanh cong" << endl;
		}
		else if (luachon == 4)
			timSvFromFile();
		else
			break;
	}
	system("pause");
	return 0;
}
