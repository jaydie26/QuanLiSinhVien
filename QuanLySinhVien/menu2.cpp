#include "Header.h"

void display1Sv(struct node* sv, int x, int y)
{
	goToXY(x + 5, y);
	changeTextColor(4);
	cout << "Thong tin sinh vien";
	changeTextColor(13);
	goToXY(x, y + 1);
	cout << "Ma lop: " << sv->sv.maLop;
	goToXY(x, y + 2);
	cout << "Ma sinh vien: " << sv->sv.maSv;
	goToXY(x, y + 3);
	cout << "Ho ten: " << sv->sv.hoTen;
	goToXY(x, y + 4);
	cout << "Ngay, thang, nam sinh: " << sv->sv.date.ngay << "/" << sv->sv.date.thang << "/" << sv->sv.date.nam;
	goToXY(x, y + 5);
	cout << "Diem trung binh: " << sv->sv.diemTB;
	changeTextColor(15);
}

void displayTable(int numberSv, int numberPage, int x, int y)
{
	changeTextColor(15);
	box(10 + x, 3 + y, 107);
	for (int i = 4; i < 5 + 2 * numberSv; i++) {
		goToXY(10 + x, i + y);
		printf("%c%108c\n", 179, 179);
	}
	goToXY(10 + x, 5 + 2 * numberSv + y);
	printf("%c", 192);
	for (int i = 0; i < 107; i++) cout << char(196);
	printf("%c\n", 217);
	goToXY(10 + x, 5 + y);
	printf("%c", 195);
	for (int i = 1; i < 108; i++) cout << char(196);
	printf("%c", 180);
	goToXY(17 + x, 3 + y); cout << char(194);
	goToXY(35 + x, 3 + y); cout << char(194);
	goToXY(53 + x, 3 + y); cout << char(194);
	goToXY(83 + x, 3 + y); cout << char(194);
	goToXY(103 + x, 3 + y); cout << char(194);
	goToXY(17 + x, 4 + y); printf("%c%18c%18c%30c%20c", 179, 179, 179, 179, 179);
	goToXY(17 + x, 5 + y); cout << char(197);
	goToXY(35 + x, 5 + y); cout << char(197);
	goToXY(53 + x, 5 + y); cout << char(197);
	goToXY(83 + x, 5 + y); cout << char(197);
	goToXY(103 + x, 5 + y); cout << char(197);
	changeTextColor(2);
	goToXY(12 + x, 4 + y); cout << "STT";
	goToXY(20 + x, 4 + y); cout << "Ma sinh vien";
	goToXY(41 + x, 4 + y); cout << "Ma lop";
	goToXY(65 + x, 4 + y); cout << "Ho ten";
	goToXY(91 + x, 4 + y); cout << "Ngay sinh";
	goToXY(109 + x, 4 + y); cout << "Diem";
	changeTextColor(15);
	int line = 7;
	for (int i = 0; i < numberSv; i++) {
		goToXY(10 + x, line + y);
		cout << char(195);
		for (int i = 1; i < 108; i++) cout << char(196);
		cout << char(180);
		line = line + 2;
	}
	line = 6;
	for (int i = 0; i < numberSv; i++) {
		goToXY(17 + x, line + y);
		printf("%c%18c%18c%30c%20c", 179, 179, 179, 179, 179);
		line = line + 1;
		goToXY(17 + x, line + y); cout << char(197);
		goToXY(35 + x, line + y); cout << char(197);
		goToXY(53 + x, line + y); cout << char(197);
		goToXY(83 + x, line + y); cout << char(197);
		goToXY(103 + x, line + y); cout << char(197);
		line = line + 1;
	}
	line = line - 1;
	goToXY(17 + x, line + y); cout << char(193);
	goToXY(35 + x, line + y); cout << char(193);
	goToXY(53 + x, line + y); cout << char(193);
	goToXY(83 + x, line + y); cout << char(193);
	goToXY(103 + x, line + y); cout << char(193);
	goToXY(10 + x, line + y); cout << char(192);
	goToXY(118 + x, line + y); cout << char(217);
	goToXY(60 + x, line + 1 + y);
	changeTextColor(9);
	cout << "Page " << numberPage;
	changeTextColor(15);
}
void displaySv(list& l, int numberPage, int numberSv, int svInDam, int x, int y)
{
	int line = 0;
	struct node* temp = l.pHead;
	for (int i = 0; i < (numberPage - 1) * 10; i++) {// mot trang co 10sv, trang 2 tu sinh vien 11
		temp = temp->pnext;
	}
	for (int i = 0; i < numberSv; i++)
	{
		if ((numberPage - 1) * 10 + i + 1 <= svInDam) changeTextColor(12);
		goToXY(11 + x, (i + 6) + line + y); cout << ((numberPage - 1) * 10 + i + 1);
		goToXY(22 + x, (i + 6) + line + y); cout << temp->sv.maSv;
		goToXY(41 + x, (i + 6) + line + y); cout << temp->sv.maLop;
		goToXY(69 + x - (int)(strlen(temp->sv.hoTen) / 2), (i + 6) + line + y); cout << temp->sv.hoTen;
		goToXY(87 + x, (i + 6) + line + y); cout << temp->sv.date.ngay;
		goToXY(90 + x, (i + 6) + line + y); cout << "/";
		goToXY(92 + x, (i + 6) + line + y); cout << temp->sv.date.thang;
		goToXY(95 + x, (i + 6) + line + y); cout << "/";
		goToXY(97 + x, (i + 6) + line + y); cout << temp->sv.date.nam;
		goToXY(110 + x, (i + 6) + line + y); cout << temp->sv.diemTB;
		changeTextColor(15);
		line += 1;
		temp = temp->pnext;
	}

}
void displaySvTK(list& l, int numberPage, int numberSv, char t[], int x, int y)
{
	int length = strlen(t);
	char* lop = new char[40];
	strcpy(lop, t);
	strupr(lop);
	int line = 0;
	struct node* temp = l.pHead;
	for (int i = 0; i < (numberPage - 1) * 10; i++) {// mot trang co 10sv, trang 2 tu sinh vien 11
		temp = temp->pnext;
	}
	for (int i = 0; i < numberSv; i++)
	{
		goToXY(11 + x, (i + 6) + line + y); cout << ((numberPage - 1) * 10 + i + 1);
		//
		goToXY(22 + x, (i + 6) + line + y); 
		for (int i = 0; i < strlen(temp->sv.maSv); i++) {
			if (temp->sv.maSv[i] == t[0] && kiemTraChuoi(temp->sv.maSv, t, i, length)) {
				changeTextColor(14);
				cout << t;
				i = i + length-1;
				changeTextColor(15);
			}
			else cout << temp->sv.maSv[i];
		}
		//
		goToXY(41 + x, (i + 6) + line + y);
		for (int i = 0; i < strlen(temp->sv.maLop); i++) {
			if (temp->sv.maLop[i] == lop[0] && kiemTraChuoi(temp->sv.maLop, lop, i, length)) {
				changeTextColor(14);
				cout << lop;
				i = i + length-1;
				changeTextColor(15);
			}
			else cout << temp->sv.maLop[i];
		}		
		//
		goToXY(69 + x - (int)(strlen(temp->sv.hoTen) / 2), (i + 6) + line + y); 
		for (int i = 0; i < strlen(temp->sv.hoTen); i++) {
			if (temp->sv.hoTen[i] == t[0] && kiemTraChuoi(temp->sv.hoTen, t, i, length)) {
				changeTextColor(14);
				cout << t;
				i = i + length-1;
				changeTextColor(15);
			}
			else cout << temp->sv.hoTen[i];
		}
		//
		goToXY(87 + x, (i + 6) + line + y); 
		char buf[20];
		itoa(temp->sv.date.ngay, buf, 10);
		for (int i = 0; i < strlen(buf); i++) {
			if (buf[i] == t[0] && kiemTraChuoi(buf, t, i, length)) {
				changeTextColor(14);
				cout << t;
				i = i + length-1;
				changeTextColor(15);
			}
			else cout << buf[i];
		}
		//
		goToXY(90 + x, (i + 6) + line + y); cout << "/";
		goToXY(92 + x, (i + 6) + line + y);
		char buf1[20];
		itoa(temp->sv.date.thang, buf1, 10);
		for (int i = 0; i < strlen(buf1); i++) {
			if (buf1[i] == t[0] && kiemTraChuoi(buf1, t, i, length)) {
				changeTextColor(14);
				cout << t;
				i = i + length-1;
				changeTextColor(15);
			}
			else cout << buf1[i];
		}
		//
		goToXY(95 + x, (i + 6) + line + y); cout << "/";
		goToXY(97 + x, (i + 6) + line + y);
		char buf2[20];
		itoa(temp->sv.date.nam, buf2, 10);
		for (int i = 0; i < strlen(buf2); i++) {
			if (buf2[i] == t[0] && kiemTraChuoi(buf2, t, i, length)) {
				changeTextColor(14);
				cout << t;
				i = i + length-1;
				changeTextColor(15);
			}
			else cout << buf2[i];
		}
		//
		goToXY(110 + x, (i + 6) + line + y);
		if (charToFloat(t) == temp->sv.diemTB) {
			changeTextColor(14);
			cout << temp->sv.diemTB;
			changeTextColor(15);
		}
		else cout << temp->sv.diemTB;
		changeTextColor(15);
		line += 1;
		temp = temp->pnext;
	}
}
void emptyTable(int numberSv, int x, int y)
{
	int line = 0;
	for (int i = 0; i < 10; i++) {
		goToXY(13 + x, i + 6 + line + y); cout << "   ";
		goToXY(22 + x, i + 6 + line + y); cout << "          ";
		goToXY(40 + x, i + 6 + line + y); cout << "          ";
		goToXY(55 + x, i + 6 + line + y); cout << "   ";
		goToXY(87 + x, i + 6 + line + y); cout << "   ";
		goToXY(92 + x, i + 6 + line + y); cout << "   ";
		goToXY(97 + x, i + 6 + line + y); cout << "   ";
		goToXY(111 + x, i + 6 + line + y); cout << "   ";
		line = line + 1;
	}
	goToXY(63, numberSv + 8); cout << "  ";
}

void deleteTable(int x, int y)
{
	goToXY(40 + x, 2 + y); cout << "                                                                                                                                         ";
	for (int i = 3; i <= 30; i++)
	{
		goToXY(10 + x, i + y); cout << "                                                                                                                                       ";
	}
}

void display(list& l, int svInDam, int x, int y)
{
	
	int numberPage = (int)l.countList / 10 + 1;
	changeTextColor(9);
	goToXY(44, 42);
	cout << "Tong so trang: " << numberPage;
	changeTextColor(15);
	int lastPage = l.countList % 10;
	int currentPage = 1;
	if (currentPage == numberPage) {
		displayTable(lastPage, currentPage, x, y);
		displaySv(l, currentPage, lastPage, svInDam, x, y);
	}
	else {
		displayTable(10, currentPage, x, y);
		displaySv(l, currentPage, 10, svInDam, x, y);
	}
	bool k = true;
	while (k) {
		int xx = move();
		switch (xx) {
		case 3:
		{
			if (currentPage == numberPage) currentPage = 1;
			else currentPage = currentPage + 1;
			break;
		}
		case 4:
		{
			if (currentPage == 1) currentPage = numberPage;
			else currentPage = currentPage - 1;
			break;
		}
		case 5:
		{
			k = false;
			xoaManHinh(43, 10, 159, 33);
			return;
		}
		default:
			continue;
		}
		if (currentPage == numberPage)
		{
			if (lastPage == 0) continue;
			xoaManHinh(43, 15, 159, 25);
			displayTable(lastPage, currentPage, x, y);
			displaySv(l, currentPage, lastPage, svInDam, x, y);
		}
		else
		{
			xoaManHinh(43, 15, 159, 25);
			displayTable(10, currentPage, x, y);
			displaySv(l, currentPage, 10, svInDam, x, y);
		}
	}
}

void display1(list& l, char t[], int x, int y)
{

	int numberPage = (int)l.countList / 10 + 1;
	changeTextColor(9);
	goToXY(44, 42);
	cout << "Tong so trang: " << numberPage;
	changeTextColor(15);
	int lastPage = l.countList % 10;
	int currentPage = 1;
	if (currentPage == numberPage) {
		displayTable(lastPage, currentPage, x, y);
		displaySvTK(l, currentPage, lastPage, t, x, y);
	}
	else {
		displayTable(10, currentPage, x, y);
		displaySvTK(l, currentPage, 10, t, x, y);
	}
	bool k = true;
	while (k) {
		int xx = move();
		switch (xx) {
		case 3:
		{
			if (currentPage == numberPage) currentPage = 1;
			else currentPage = currentPage + 1;
			break;
		}
		case 4:
		{
			if (currentPage == 1) currentPage = numberPage;
			else currentPage = currentPage - 1;
			break;
		}
		case 5:
		{
			k = false;
			xoaManHinh(43, 10, 159, 33);
			return;
		}
		default:
			continue;
		}
		if (currentPage == numberPage)
		{
			if (lastPage == 0) continue;
			xoaManHinh(43, 15, 159, 25);
			displayTable(lastPage, currentPage, x, y);
			displaySvTK(l, currentPage, lastPage, t, x, y);
		}
		else
		{
			xoaManHinh(43, 15, 159, 25);
			displayTable(10, currentPage, x, y);
			displaySvTK(l, currentPage, 10, t, x, y);
		}
	}
}

void display2(list& l, char t[], int x, int y)
{

	int numberPage = (int)l.countList / 10 + 1;
	changeTextColor(9);
	goToXY(44, 42);
	cout << "Tong so trang: " << numberPage;
	changeTextColor(15);
	int lastPage = l.countList % 10;
	int currentPage = 1;
	if (currentPage == numberPage) {
		displayTable(lastPage, currentPage, x, y);
		displaySvTK(l, currentPage, lastPage, t, x, y);
	}
	else {
		displayTable(10, currentPage, x, y);
		displaySvTK(l, currentPage, 10, t, x, y);
	}
	bool k = true;
	while (k) {
		int xx = move();
		switch (xx) {
		case 3:
		{
			if (currentPage == numberPage) currentPage = 1;
			else currentPage = currentPage + 1;
			break;
		}
		case 4:
		{
			if (currentPage == 1) currentPage = numberPage;
			else currentPage = currentPage - 1;
			break;
		}
		case 5:
		{
			k = false;
			xoaManHinh(43, 16, 159, 25);
			break;

		}
		default:
			break;
		}
		if (currentPage == numberPage)
		{
			if (lastPage == 0) continue;
			xoaManHinh(43, 15, 159, 25);
			displayTable(lastPage, currentPage, x, y);
			displaySvTK(l, currentPage, lastPage, t, x, y);
		}
		else
		{
			xoaManHinh(43, 15, 159, 25);
			displayTable(10, currentPage, x, y);
			displaySvTK(l, currentPage, 10, t, x, y);
		}
	}
}

bool kiemTraChuoi(char x[], char y[], int xx, int length)
{
	int dem = 0;
	for (int i = 0; i < length; i++) {
		if (x[xx + i] == y[i]) dem++;
	}
	if (dem == length) return true;
	else return false;
}

