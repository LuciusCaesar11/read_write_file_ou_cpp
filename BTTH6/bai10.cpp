#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct SinhVien{
	string masv;
	string hoten;
	int namsinh;
};

void Nhap1sv(SinhVien *sv)
{
	cout << "nhap ma sinh vien: ";
	getline(cin, sv->masv);
	cout << "nhap ho ten sinh vien: ";
	getline(cin, sv->hoten);
	cout << "nhap nam sinh: ";
	cin >> sv->namsinh;
	getchar();
}

void Nhapdssv(SinhVien *sv,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap thong tin sinh vien thu " << i << ": " << endl;
		Nhap1sv(&sv[i]);
	}
}

void Xuat1sv(SinhVien sv)
{
	cout << "ma sinh vien: " << sv.masv << endl;
	cout << "ten sinh vien: " << sv.hoten << endl;
	cout << "nam sinh: " << sv.namsinh << endl;
}

void Xuatdssv(SinhVien *sv,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "thong tin sinh vien thu " << i << ": " << endl;
		Xuat1sv(sv[i]);
	}
}

void LuuFile(SinhVien *sv,int n)
{
	fstream f;
	f.open("source7.txt", ios::out);
	for (int i = 0; i < n; i++)
		f << sv[i].masv << " " << sv[i].hoten << " " << sv[i].namsinh << endl;
	f.close();
	cout << "luu thanh cong !";
	system("pause");
}

void DocFile()
{
	string line;
	fstream f;
	f.open("source7.txt", ios::in);
	while (!f.eof())
	{
		getline(f, line);
		cout << line << endl;
	}
	f.close();
	system("pause");
}

void KiemtraMasv(string masv)
{
	fstream f;
	string s;
	f.open("source7.txt", ios::in);
	{
		bool found = false;
		while (!f.eof())
		{
			SinhVien *sv = new SinhVien;
			getline(f, s);
			int pos = s.find(" ");
			sv->masv = s.substr(0, pos);
			if (masv == sv->masv)
			{
				s.erase(0, pos + 1);
				int pos1 = s.find(" ");
				sv->hoten = s.substr(0, pos1);
				s.erase(0, pos1 + 1);
				sv->namsinh = stoi(s);
				Xuat1sv(*sv);
				found = true;
				break;
			}
		}
		if (found == false)
			cout << "khong tim thay sinh vien co ma " << masv;
		f.close();
	}
}

void menu()
{
	cout << "1.nhap dssv \n";
	cout << "2.xuat dssv \n";
	cout << "3.luu dssv vao file\n";
	cout << "4.mo file luu dssv \n";
	cout << "5.kiem tra thong tin sinh vien bang ma sv \n";
	cout << "6.thoat\n";
}
int main()
{
	bool in = false;
	int luachon;
	int n;
	do {
		cout << "nhap so luong sinh vien: ";
		cin >> n;
		getchar();
		if (n <= 0 && n > 10)
			cout << "vui long nhap lai so luong sinh vien,max=10";
	} while (n <= 0 && n > 10);
	SinhVien *sv = new SinhVien[n];
	do {
		menu();
		cout << "Nhap lua chon: ";
		cin >> luachon;
		getchar();
		if (luachon == 1)
		{
			Nhapdssv(sv, n);
			in = true;
		}
		else if (luachon == 2)
		{
			if (in == true)
				Xuatdssv(sv, n);
			else
				cout << "vui long nhap dssv\n";
		}
		else if (luachon == 3)
		{
			if (in == true)
				LuuFile(sv, n);
			else
				cout << "vui long nhap dssv\n";
		}
		else if (luachon == 4)
			DocFile();
		else if (luachon == 5)
		{
				string ma;
				cout << "Nhap ma sinh vien can kiem tra: " << endl;
				getline(cin, ma);
				KiemtraMasv(ma);
		}
		else if (luachon == 6)
			break;
		else
			cout << "lua chon khong hop le\n";
	} while (luachon >= 1 && luachon <= 6);
	system("pause");
	return 0;
}