#include"Header.h"
using namespace std;

void changeTextColor(int k)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void goToXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void xoaManHinh(int x,int y,int a,int b)// tu vi tri (x,y) xoa theo truc Ox=a, Oy=b;
{
	
	for (int i = 0; i < b; i++) {
		goToXY(x, y + i);
		for (int j = 0; j < a; j++) {
			cout << " ";
		}
	}
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, true);
}

void veHinh(int x, int y, string s, int color)
{
		goToXY(x, y);
		changeTextColor(color);
		cout << s;
		changeTextColor(15);
}

void deleteEnter(int x, int y, int z)
{
	goToXY(x, y);
	for (int i = 0; i < z; i++) cout << " ";
}

int passWord()// ma hoa password ROT10
{
	int i = 0;
	char c = 0;
	char x[20];
	char xx[20];
	int kk = 0;
	while (true) {
		c = _getch();
		if (c == 27) {
			kk = 1;
			break;
		}
		if (c == 13||i>15) break;
		else {
			x[i++] = c;
			cout << "*";
		}
	}
	x[i] = '\0';
	for (int i = 0; i < strlen(x); i++) {
		int y = (int)x[i];
		xx[i] = (char)(y + 10);
	}
	xx[strlen(x)] = '\0';
	if (kk == 1) return 2;
	if (strcmp(xx, "CCCCCCCCC") == 0) return 1;// password=999999999
	else return 0;
}

int move()
{
	char c = _getch();
	if ((int)c == -32) c = _getch();
	switch ((int)c)
	{
	case 80:	//	phim xuong
		return 1;
	case 72:	//	phim len
		return 2;
	case 77:	//	phim sang phai
		return 3;
	case 75:	//	phim sang trai
		return 4;
	case 27:	//	phim esc 
		return 5;
	case 13:	//   phim Enter
		return 6;
	default:	//	cac phim con lai
		return 0;
	}
}

void box(int x, int y, int z)
{
	goToXY(x, y);
	printf("%c", 218);
	for (int i = 0; i < z; i++) printf("%c", 196);
	printf("%c", 191);
	goToXY(x, y + 1);
	printf("%c", 179);
	goToXY(x + z + 1, y + 1);
	printf("%c", 179);
	goToXY(x, y + 2);
	printf("%c", 192);
	for (int i = 0; i < z; i++) printf("%c", 196);
	printf("%c", 217);
}

void backGround()
{
	changeTextColor(2);
    ifstream FileIn;
	changeTextColor(2);
	FileIn.open("mta.txt", ios::in);
	while (!FileIn.eof()) {// hien thi chua MTA 
		char c;
		FileIn.get(c);
		cout << c;
	}
	// ve khung vien man hinh
	goToXY(1, 1);
	for (int i = 0; i < 197; i++) printf("%c", 176);
	goToXY(1, 43);
	for (int i = 0; i < 197; i++) printf("%c", 176);
	for (int i = 0; i < 42; i++) {
		goToXY(1, 2 + i);
		printf("%c%c", 176,176);
	}
	for (int i = 0; i < 42; i++) {
		goToXY(196, 2 + i);
		printf("%c%c", 176,176);
	}
	//
	// ve co To quoc o goc man hinh
	for (int i = 0; i < 11; i++) {
		goToXY(4, 2+i);
		for (int j = 0; j < co[i].length(); j++) {
			if (co[i][j]=='@') {
				changeTextColor(4);
				cout << co[i][j];
				changeTextColor(15);
			}
			else {
				changeTextColor(6);
				cout << co[i][j];
				changeTextColor(15);
			}
		}
	}
	//
	// hien thi chu hoc vien ki thuat quan su
	changeTextColor(4);
	goToXY(31, 20);
	cout << hvktqs[0];
	goToXY(30, 21);
	cout << hvktqs[1];
	goToXY(30, 22);
	cout << hvktqs[2];
	//
	showConsoleCursor(false);
	changeTextColor(15);
	goToXY(50, 24);
	changeTextColor(4);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=====@@@@@@@@@@@@@@@@@=====~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// khung dang nhap
	goToXY(85, 29);
	changeTextColor(9);
	cout << "VUI LONG DANG NHAP!";
	goToXY(60, 32);
	cout << "Ten dang nhap";
	changeTextColor(15);
	box(75, 31, 40);
	changeTextColor(9);
	goToXY(60, 35);
	cout << "Mat khau";
	changeTextColor(15);
	box(75, 34, 40);
	int k = 0;
	int kk = 0;
	while (true) {
		char tenDangNhap[20];
		char tenDn[20];
		char matKhau[20];
		showConsoleCursor(true);
		goToXY(76, 32);
		cin.getline(tenDangNhap, 20);
		for (int i = 0; i < strlen(tenDangNhap); i++) {
			int xx = (int)tenDangNhap[i];
			tenDn[i] = (char)(xx + 2);
		}
		tenDn[strlen(tenDangNhap)] = '\0';
		changeTextColor(15);
		goToXY(76, 35);
		int key = passWord();
		if (strcmp(tenDn, "cfokp") == 0 && key == 1) {// ten dang nhap: admin - ROT2
			k = 1;
		}
		if (k == 1) {
			break;
		}
		else {
			deleteEnter(76, 32, 40);
			deleteEnter(76, 35, 40);
			goToXY(76, 37);
			cout << "                                            ";
			goToXY(76, 37);
			changeTextColor(4);
			cout << "Dang nhap that bai! Vui long nhap lai";
			changeTextColor(15);
		}
	}
	goToXY(76, 37);
	cout << "                                                    ";
	string ten = "CHUONG TRINH QUAN LI SINH VIEN";
	goToXY(80, 38);
	for (int i = 0; i < ten.length(); i++) {
		cout << ten[i];
		Sleep(100);
	}
	system("cls");
	backGround1();
}

void backGround1()
{
	changeTextColor(14);
	goToXY(0, 7);
	for (int i = 0; i < 200; i++) printf("%c", 205);
	for (int i = 0; i < 44; i++) {
		goToXY(40, i);
		printf("%c", 186);
	}
	goToXY(0, 43);
	for (int i = 0; i < 200; i++) printf("%c", 205);
	changeTextColor(14);
	goToXY(0, 0);
	for (int i = 0; i < 39; i++) printf("%c", 176);
	goToXY(0, 6);
	for (int i = 0; i < 39; i++) printf("%c", 176);
	for (int i = 0; i < 7; i++) {
		goToXY(38, i);
		printf("%c%c",176, 176);
		goToXY(0, i);
		printf("%c%c", 176,176);
	}
	for (int i = 0; i < 5; i++) {
		goToXY(2, 1 + i);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,219);
	}
	veHinh(10, 1, "QUAN LI SINH VIEN", 228);
	veHinh(4, 3, "User : Nguyen Dinh Dai", 233);
	veHinh(4, 4, "Class: Bao dam an toan thong tin", 233);
	changeTextColor(14);
	goToXY(41, 0);
	for (int i = 0; i < 158; i++) printf("%c", 176);
	goToXY(41, 6);
	for (int i = 0; i < 158; i++) printf("%c", 176);
	for (int i = 0; i < 7; i++) {
		goToXY(41, i);
		printf("%c%c", 176, 176);
		goToXY(198, i);
		printf("%c%c", 176, 176);
	}
	changeTextColor(4);
	for (int i = 0; i < 5; i++) {
		goToXY(43, 1 + i);
		for (int i = 0; i < 155; i++) printf("%c", 219);
	}
	veHinh(50, 1, hvktqs1[1], 78);
	veHinh(50, 2, hvktqs1[2], 78);
	veHinh(50, 3, hvktqs1[3], 78);
	veHinh(50, 4, hvktqs1[4], 78);
	veHinh(50, 5, hvktqs1[5], 78);
	changeTextColor(12);
	for (int i = 0; i < 3; i++) {
		goToXY(0, 8 + i);
		for (int j = 0; j < 40; j++) {
			printf("%c", 219);
		}
	}
	veHinh(14, 9, "----MENU----", 207);
	changeTextColor(2);
	goToXY(8, 36); cout << mta[0];
	goToXY(8, 37); cout << mta[1];
	goToXY(8, 38); cout << mta[2];
	goToXY(8, 39); cout << mta[3];
	goToXY(8, 40); cout << mta[4];
	goToXY(8, 41); cout << mta[5];
	goToXY(0, 42);
	for (int i = 0; i <= 39; i++) printf("%c", 219);
	changeTextColor(15);
}
char* nhap(int max,int x,int y) {
	goToXY(x, y);
	int i = 0;
	char c = 0;
	char* xx = new char[max + 5];
	int kk = 0;
	bool k = true;
	int index = -1;
	while (k) {
		c = _getch();
		if ((int)c == -32) c = _getch();
		switch ((int)c) {
		case 13:
		{
			k = false;
			break;
		}
		case 77:
		{
			if (index == i) {
				index = 0;
				goToXY(x, y);
			}
			else {
				index = index + 1;
				goToXY(x + index, y);
			}
			break;
		}
		case 75:
		{
			if (index < 0) {
				index = i;
				goToXY(x + index, y);
			}
			else {
				goToXY(x + index, y);
				index = index - 1;
			}
			break;
		}
		case 80: break;
		case 72: break;
		case 8:
		{
			if (index == i - 1) {
				i = i - 1;
				index = index - 1;
				if (i >= 0) {
					goToXY(x + i, y);
					cout << " ";
					goToXY(x + i, y);
				}
			}
			else {
				if (index >= 0) {
					i = i - 1;
					for (int j = index; j < i; j++) {
						xx[j] = xx[j + 1];
					}
					goToXY(x + index, y);
					for (int j = index; j < i; j++) {
						cout << xx[j];
					}
					cout << " ";
					goToXY(x + i, y);
					index = i - 1;
				}
				else {
					goToXY(x + i, y);
					index = i - 1;
				}
			}
			break;
		}
		default:
		{
			if (index == i - 1) {
				xx[i++] = c;
				cout << c;
				index = index + 1;
			}
			else {
				i = i + 1;
				for (int j = i - 1; j > index + 1; j--) xx[j] = xx[j - 1];
				xx[index + 1] = c;
				goToXY(x + index, y);
				for (int j = index; j < i; j++) cout << xx[j];
				goToXY(x - 1, y); printf("%c", 179);
				goToXY(x + i, y);
				index = i - 1;
			}
		}
		}
		if (i > max || i < 0) k = false;
	}
	if (i < 0) xx[0] = '\0';
	else xx[i] = '\0';
	return xx;
}

char* nhapTK(list& l, int max, int x, int y)
{
	goToXY(x, y);
	int i = 0;
	char c = 0;
	char* xx = new char[max + 5];
	int kk = 0;
	bool k = true;
	int index = -1;
	while (k) {
		showConsoleCursor(true);
		goToXY(x + i, y);
		c = _getch();
		if ((int)c == -32) c = _getch();
		switch ((int)c) {
		case 13:
		{
			k = false;
			break;
		}
		case 77:
		{
			if (index == i) {
				index = 0;
				goToXY(x, y);
			}
			else {
				index = index + 1;
				goToXY(x + index, y);
			}
			break;
		}
		case 75:
		{
			if (index < 0) {
				index = i;
				goToXY(x + index, y);
			}
			else {
				goToXY(x + index, y);
				index = index - 1;
			}
			break;
		}
		case 80: break;
		case 72: break;
		case 8:
		{
			if (index == i - 1) {
				i = i - 1;
				index = index - 1;
				if (i >= 0) {
					goToXY(x + i, y);
					cout << " ";
					goToXY(x + i, y);
				}
				xx[i] = '\0';
			}
			break;
		}
		default:
		{
			if (index == i - 1) {
				xx[i++] = c;
				xx[i] = '\0';
				cout << c;
				index = index + 1;
			}
			else {
				i = i + 1;
				for (int j = i - 1; j > index + 1; j--) xx[j] = xx[j - 1];
				xx[index + 1] = c;
				goToXY(x + index, y);
				for (int j = index; j < i; j++) cout << xx[j];
				goToXY(x - 1, y); printf("%c", 179);
				goToXY(x + i, y);
				index = i - 1;
			}
		}
		}
		if (i > max || i < 0) k = false;
		showConsoleCursor(false);
		list l1;
		khoiTaoList(l1);
		struct node* temp1 = l.pHead;
		struct node* temp2 = temp1;
		while (temp2 != NULL) {
			if (checkSv1(temp2->sv, xx)) {
				insertHead(l1, temp2->sv);
			}
			temp2 = temp2->pnext;
		}
		if (l1.countList == 0) {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Khong co sinh vien ton tai";
			xoaManHinh(43, 16, 159, 27);
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		else {
			display2(l1, xx, 53, 13);
			goToXY(100, 15);
			cout << "                                         ";
		}
	}
	return xx;
}




