#include "Header.h"
using namespace std;

int charInvertInt(char* x)
{
	int xx = 0;
	int q = 10000000;
	for (int i = 0; i < 8; i++) {
		int cc = (int)x[i] - 48;
		xx = xx + cc * q;
		q = q / 10;
	}
	return xx;
}

int charToInt(char x[])
{
	int m = 1;
	for (int i = 0; i < strlen(x) - 1; i++) {
		m = m * 10;
	}
	int s = 0;
	if (strlen(x) > 4) return 0;
	else {
		for (int i = 0; i < strlen(x); i++) {
			if ((int)x[i] >= 48 && (int)x[i] <= 57) {
				s = s + ((int)x[i] - 48) * m;
				m = m / 10;
			}
			else return 0;
		}
		return s;
	}
}

float charToFloat(char x[])
{
	int m = 1;
	for (int i = 0; i < strlen(x) - 1; i++) {
		m = m * 10;
	}
	int s = 0;
	if (strlen(x) > 5) return -1;
	else {
		int mm = 0;
		for (int i = 0; i < strlen(x); i++) {
			if (x[i] == '.') mm = 1;
			else {
				if ((int)x[i] >= 48 && (int)x[i] <= 57) {
					mm = mm * 10;
					s = s + ((int)x[i] - 48) * m;
					m = m / 10;
				}
				else return -1;
			}
		}
		if (mm == 0) return (float)s;
		else return (float)(s / 10) / (float)mm;
	}
}

void box_AddSv()
{
	veHinh(73, 12, "Ma lop ", 188);      box(83, 11, 50);
	veHinh(73, 17, " Ma SV ", 188);      box(83, 16, 50);
	veHinh(73, 22, "Ho ten ", 188);      box(83, 21, 50);
	veHinh(73, 27, "  Ngay ", 188);      box(83, 26, 5);
	veHinh(99, 27, " Thang ", 188);      box(108, 26, 5);
	veHinh(119, 27,"  Nam  ", 188);      box(128, 26, 5);
	veHinh(73, 32, "Diem TB", 188);      box(83, 31, 5);
}

bool checkMaSvInList(char* masv, list& l)
{
	if (isEmpty(l)) return false;
	else {
		struct node* k = l.pHead;
		while (k != NULL) {
			if (strcmp(masv, k->sv.maSv) == 0) return true;
			k = k->pnext;
		}
		return false;
	}
}

void setMasv(char* maSv, list& l)
{
	char* ma = new char[30];
	strcpy(ma, nhap(25,84,17));
	while (true) {
		if (strlen(ma) != 8 || checkMaSvInList(ma, l) || (strlen(ma) == 8 && ((int)ma[0] < 48 || (int)ma[0]>57 || (int)ma[1] < 48 || (int)ma[1]>57 || (int)ma[2] < 48 || (int)ma[2]>57 || (int)ma[3] < 48 || (int)ma[3]>57 || (int)ma[4] < 48 || (int)ma[4]>57 || (int)ma[5] < 48 || (int)ma[5]>57 || (int)ma[6] < 48 || (int)ma[6]>57 || (int)ma[7] < 48 || (int)ma[7]>57))) {
			if (checkMaSvInList(ma, l)) {
				changeTextColor(4);
				goToXY(84, 19);
				cout << "                                  ";
				goToXY(84, 19);
				cout << "Ma sinh vien da ton tai";
				changeTextColor(15);
			}
			else {
				if (strlen(ma) != 8) {
					goToXY(84, 19);
					cout << "                                                       ";
					changeTextColor(4);
					goToXY(84, 19);
					cout << "Ma sinh vien phai co 8 ki tu";
					changeTextColor(15);
				}
				else {
					goToXY(84, 19);
					cout << "                                                       ";
					changeTextColor(4);
					goToXY(84, 19);
					cout << "Ma sinh vien khong hop le";
					changeTextColor(15);
				}
			}
			deleteEnter(84, 17, 48);
			strcpy(ma, nhap(25,84,17));
		}
		else {
			strcpy(maSv, ma);
			deleteEnter(84, 17, 48);
			changeTextColor(11);
			goToXY(105, 17); cout << maSv;
			goToXY(84, 19);
			cout << "                                                     ";
			changeTextColor(2);
			goToXY(84, 19);
			cout << "Ma sinh vien hop le!";
			changeTextColor(15);
			break;
		}
	}
	delete[] ma;
}

void setMalop(char* malop)
{
	char* lop = new char[30];
	while (true) {
		strcpy(lop, nhap(20,84,12));
		strupr(lop);
		if (!(strcmp(lop, maLop1) == 0 || strcmp(lop, maLop2) == 0 || strcmp(lop, maLop3) == 0 || strcmp(lop, maLop4) == 0 || strcmp(lop, maLop5) == 0)) {
			goToXY(84, 14);
			changeTextColor(4);
			cout << "Ma lop khong ton tai (CNTT1, CNTT2, ANHTTT, BDATTT, DTH)";
			changeTextColor(15);
			deleteEnter(84, 12, 48);
		}
		else {
			strcpy(malop, lop);
			deleteEnter(84, 12, 48);
			changeTextColor(11);
			goToXY(107, 12); cout << malop;
			goToXY(84, 14);
			changeTextColor(2);
			cout << "                                                                             ";
			goToXY(84, 14);
			cout << "Ma lop hop le!";
			changeTextColor(15);
			break;
		}
	}
	delete[] lop;
}

char* deleteAtPosition(char* name, int sizeOfArray, int index)// xoa ki tu o vi tri index
{
	int i;
	for (i = index; i < sizeOfArray - 1; i++)// dich cac ki tu tu vi tri index sang trai 1 ki tu
	{
		*(name + i) = *(name + (i + 1));
	}
	*(name + i) = NULL;
	return name;
}
char* fixHoten(char name[])
{
	int preIndex = 0;
	int leng = strlen(name);
	int counter = 0;
	for (counter = 0; counter < leng; counter++)
	{
		if ((counter == 0) && name[counter] == ' ')// xoa khoang trang o dau chuoi
		{
			name = deleteAtPosition(name, leng, 0);
			counter = counter - 1;

		}
		else
		{
			int n = (int)(name[counter]);
			if (n >= 48 && n <= 57)//xoa so trong chuoi
			{
				name = deleteAtPosition(name, leng, counter);
				counter = counter - 1;
			}
			if ((n == 32) && ((int)(name[preIndex]) == 32))// xoa 2 khoang trang canh nhau
			{
				name = deleteAtPosition(name, leng, preIndex);
				counter = counter - 1;
			}
			if (((int)(name[preIndex]) == 32) || counter == 0)// vi tri dau tien hoac sau khoang trang
			{
				if (n >= 97 && n <= 122)// in thuong thanh in hoa
				{
					name[counter] = char(n - 32);
				}
			}
			if (counter == leng && (int)(name[counter]) == 32)// xoa phan tu cuoi la khoang trang
			{
				name = deleteAtPosition(name, leng, counter);
			}
		}
		if (counter > 0) preIndex = counter;
		leng = strlen(name);
	}
	return name;
}

void setTen(char* ten)
{
	char* t = new char[50];
	int k = 0;
	while (true) {
		strcpy(t, nhap(40,84,22));
		bool kt = true;
		for (int i = 0; i < strlen(t); i++) {
			if ((int)t[i] == 32 || ((int)t[i] > 64 && (int)t[i] < 91) || ((int)t[i] > 96 && (int)t[i] < 123)) continue;
			else {
				kt = false;
				break;
			}
		}
		if (strlen(t) < 50 && strlen(t) > 0 && kt) {
			deleteEnter(84, 22, 48);
			k = 1;
		}
		else {
			deleteEnter(84, 22, 48);
			goToXY(84, 24);
			changeTextColor(4);
			cout << "Ho ten khong hop le";
			changeTextColor(15);
		}
		if (k == 1) break;
	}
	goToXY(84, 24);
	cout << "                                    ";
	strcpy(ten, t);
	ten = fixHoten(ten);
	deleteEnter(84, 22, 48);
	changeTextColor(11);
	goToXY(108 - (int)(strlen(ten) / 2), 22); cout << ten;
	changeTextColor(15);
	delete[] t;
}

bool checkNgaySinh(int ngay, int thang, int nam)
{
	bool check = true;
	if (nam < 1960 || nam>2020) check = false;// gioi han nam 1980-2020
	if (thang > 12 || thang < 1) check = false;// kiem tra tinh hop le cua thang
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {//kiem tra thang co 31 ngay
		if (ngay > 31 || ngay < 1) check = false;
	}
	if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {//kiem tra thang co 30 ngay
		if (ngay > 30 || ngay < 1) check = false;
	}
	if (thang == 2) {// kiem tra ngay cua thang 2 nam nhuan va nam khong nhuan
		int x;
		if (((nam % 4 == 0) && (nam % 100 != 0)) || (nam % 400 == 0)) x = 0;
		else x = 1;
		if (x == 0) {
			if (ngay > 29 || ngay < 1) check = false;
		}
		else {
			if (ngay > 28 || ngay < 1) check = false;
		}
	}
	return check;
}

void setSv(list& l)
{
	char malop[50], masv[50], ten[50];
	int ngay = 0, thang = 0, nam = 0;
	float diemTB;
	goToXY(84, 12);
	sinhVien sv;
	showConsoleCursor(true);
	fflush(stdin);
	setMalop(malop);
	fflush(stdin);
	setMasv(masv, l);
	fflush(stdin);
	setTen(ten);
	fflush(stdin);
	while (true) {
		while (true) {
			char n[6];
			strcpy(n, nhap(4,84,27));
			ngay = charToInt(n);
			if ( ngay > 0 && ngay < 32) break;
			else {
				goToXY(94, 29);
				cout << "                                                                                                         ";
				goToXY(83, 29);
				changeTextColor(4);
				cout << "Ngay khong hop le";
				changeTextColor(15);
				goToXY(84, 27); cout << "     ";
			}

		}
		goToXY(83, 29); cout << "                                                                                                          ";
		while (true) {
			char t[6];
			strcpy(t, nhap(4,109,27));
			thang = charToInt(t);
			if (thang > 0 && thang < 13) break;
			else {
				goToXY(108, 29);
				changeTextColor(4);
				cout << "Thang khong hop le";
				changeTextColor(15);
				goToXY(109, 27); cout << "     ";
			}

		}
		goToXY(108, 29); cout << "                            ";
		while (true) {
			char na[6];
			strcpy(na, nhap(4,129,27));
			nam = charToInt(na);
			if (nam > 1980 && nam < 2020) break;
			else {
				goToXY(128, 29);
				changeTextColor(4);
				cout << "Nam khong hop le";
				changeTextColor(15);
				goToXY(129, 27); cout << "     ";
			}

		}
		goToXY(128, 29); cout << "                               ";
		if (checkNgaySinh(ngay, thang, nam)) {
			goToXY(100, 29);
			changeTextColor(2);
			cout << "Ngay thang nam hop le";
			goToXY(84, 27); cout << "   ";
			goToXY(109, 27); cout << "   ";
			goToXY(129, 27); cout << "    ";
			changeTextColor(11);
			goToXY(86, 27); cout << ngay;
			goToXY(111, 27); cout << thang;
			goToXY(129, 27); cout << nam;
			changeTextColor(15);
			break;
		}
		goToXY(95, 29);
		changeTextColor(4);
		cout << "Ngay thang nam sinh khong hop le";
		changeTextColor(15);
		goToXY(129, 17); cout << "     ";
		goToXY(109, 17); cout << "     ";
		goToXY(84, 17); cout << "     ";
	}
	while (true) {
		char d[6];
		strcpy(d, nhap(4,84,32));
		diemTB = charToFloat(d);
		if (diemTB >= 0 && diemTB <= 10) {
			goToXY(83, 34);
			cout << "                                             ";
			goToXY(83, 34);
			changeTextColor(2);
			cout << "Diem TB hop le!";
			goToXY(84, 32); cout << "     ";
			changeTextColor(11);
			goToXY(85, 32); cout << diemTB;
			changeTextColor(15);
			break;
		}
		else {
			goToXY(83, 34);
			changeTextColor(4);
			cout << "Diem TB khong hop le!";
			changeTextColor(15);
			goToXY(84, 32); cout << "     ";
		}

	}
	strcpy(sv.hoTen, ten);
	strcpy(sv.maLop, malop);
	strcpy(sv.maSv, masv);
	sv.date.ngay = ngay;
	sv.date.thang = thang;
	sv.date.nam = nam;
	sv.diemTB = diemTB;
	showConsoleCursor(false);
	insertHead(l, sv);
}

void AddSv(list& l)
{
	int i = 6;
	while (i == 6) {
		xoaManHinh(43, 10, 159, 33);
		box_AddSv();
		setSv(l);
		struct node* p = l.pHead;
		// kiem tra ma sinh vien co dund voi ma lop hay khong?
		int kiemTra = 0;
		if (strcmp(p->sv.maLop, maLop1) == 0) {
			if (charInvertInt(p->sv.maSv) != countMaSv(l, maLop1) + 10000000 - 1) {
				kiemTra = 1;
				deleteHead(l);
			}
		}
		if (strcmp(p->sv.maLop, maLop2) == 0) {
			if (charInvertInt(p->sv.maSv) != countMaSv(l, maLop2) + 20000000 - 1) {
				kiemTra = 1;
				deleteHead(l);
			}
		}
		if (strcmp(p->sv.maLop, maLop3) == 0) {
			if (charInvertInt(p->sv.maSv) != countMaSv(l, maLop3) + 30000000 - 1) {
				kiemTra = 1;
				deleteHead(l);
			}
		}
		if (strcmp(p->sv.maLop, maLop4) == 0) {
			if (charInvertInt(p->sv.maSv) != countMaSv(l, maLop4) + 40000000 - 1) {
				kiemTra = 1;
				deleteHead(l);
			}
		}
		if (strcmp(p->sv.maLop, maLop5) == 0) {
			if (charInvertInt(p->sv.maSv) != countMaSv(l, maLop5) + 50000000 - 1) {
				kiemTra = 1;
				deleteHead(l);
			}
		}
		if (kiemTra == 0) {
			goToXY(100, 36);
			changeTextColor(9);
			cout << "<<Them moi thanh cong>>" << endl;
			changeTextColor(15);
		}
		else {
			goToXY(90, 36);
			changeTextColor(4);
			cout << "<<Them moi that bai>> (Kiem tra lai maSV)" << endl;
			changeTextColor(15);
		}
		changeTextColor(9);
		for (int i = 0; i < 4; i++) {
			goToXY(96, 38+i);
			for (int j = 0; j < 30; j++) {
				printf("%c", 219);
			}
		}
		veHinh(100, 39, "Ban co muon tiep tuc?", 159);
		int r = 0;
		while (true) {
			if (r == 0) {
				veHinh(102, 40, "Yes", 156);
				veHinh(115, 40, "No", 159);
			}
			else {
				veHinh(102, 40, "Yes", 159);
				veHinh(115, 40, "No", 156);
			}
			int k = move();
			if (k == 3 && r == 0) r = 1;
			else if (k == 3 && r == 1) r = 0;
			else if (k == 4 && r == 1) r = 0;
			else if (k == 4 && r == 0) r = 1;
			else if(k==6) break;
		}
		changeTextColor(15);
		if (r == 0) i = 6;
		else i = 5;
	}
	if (i == 5) xoaManHinh(41, 8, 159, 34);
}
void suaSv(list& l)
{
	changeTextColor(8);
	goToXY(80, 20);
	for (int i = 0; i < 62; i++) printf("%c", 219);
	for (int i = 0; i < 10; i++) {
		goToXY(80, 21 + i);
		printf("%c%c", 219, 219);
		goToXY(140, 21 + i);
		printf("%c%c", 219, 219);
	}
	goToXY(80, 31);
	for (int i = 0; i < 62; i++) printf("%c", 219);
	changeTextColor(9);
	goToXY(92, 22);
	cout << "Nhap mat khau sua thong tin sinh vien";
	veHinh(85, 25, "Nhap password: ", 124);
	changeTextColor(15);
	box(100, 24, 33);
	showConsoleCursor(true);
	int kt = 0;
	while (true) {
		int test = 0;
		goToXY(101, 25);
		int key = passWord();
		if (key == 2) {
			kt = 2;
			break;
		}
		if (key == 1) {
			kt = 1;
			goToXY(100, 28);
			cout << "                     ";
			goToXY(100, 28);
			changeTextColor(2);
			cout << "PassWord chinh xac";
			changeTextColor(15);
			break;
		}
		else {
			deleteEnter(101, 25, 30);
			goToXY(100, 28);
			cout << "                          ";
			goToXY(100, 28);
			changeTextColor(4);
			cout << "PassWord khong chinh xac";
			changeTextColor(15);
		}
	}
	if (kt == 2)  xoaManHinh(41, 8, 159, 34);
	if (kt == 1) {// xu li ham sua
		while (true) {
			showConsoleCursor(true);
			xoaManHinh(41, 10, 159, 32);
			changeTextColor(4);
			goToXY(101, 11);
			cout << "----SUA THONG TIN SINH VIEN----";
			goToXY(45, 15);
			changeTextColor(9);
			cout << "Nhap ma sinh vien: ";
			changeTextColor(15);
			box(64, 14, 30);
			char ma1[20];
			strcpy(ma1, nhap(20,65,15));
			int kiemTra = 0;
			if (strlen(ma1) != 8 || !checkMaSvInList(ma1, l) || (strlen(ma1) == 8 && ((int)ma1[0] < 48 || (int)ma1[0]>57 || (int)ma1[1] < 48 || (int)ma1[1]>57 || (int)ma1[2] < 48 || (int)ma1[2]>57 || (int)ma1[3] < 48 || (int)ma1[3]>57 || (int)ma1[4] < 48 || (int)ma1[4]>57 || (int)ma1[5] < 48 || (int)ma1[5]>57 || (int)ma1[6] < 48 || (int)ma1[6]>57 || (int)ma1[7] < 48 || (int)ma1[7]>57))) {
				if (!checkMaSvInList(ma1, l)) {
					changeTextColor(4);
					goToXY(65, 17);
					cout << "                                        ";
					veHinh(65, 17, "Ma sinh vien khong ton tai", 124);
					changeTextColor(15);
				}
				if (strlen(ma1) != 8) {
					goToXY(65, 17);
					cout << "                                          ";
					changeTextColor(4);
					veHinh(65, 17, "Ma sinh vien phai co 8 ki tu", 124);
					changeTextColor(15);
				}
				kiemTra = 1;
			}
			else {
				struct node* temp = l.pHead;
				while (strcmp(temp->sv.maSv, ma1) != 0) temp = temp->pnext;
				display1Sv(temp, 50, 18);
				changeTextColor(9);
				goToXY(135, 15);
				cout << "Moi ban chon thong tin can sua: ";
				changeTextColor(15);
				selection s(4);
				int k = 0;
				int r = 0;
				s.showSelection2(r, 135, 17);
				showConsoleCursor(false);
				while (true) {
					int x = move();
					switch (x) {
					case 1:
					{
						if (r < s.numberSelection - 1) r++;
						else r = 0;
						break;

					}
					case 2:
					{
						if (r > 0) r--;
						else r = s.numberSelection - 1;
						break;
					}
					case 5:
					{
						k = 1;
						break;
					}
					case 6:
					{
						switch (r) {
						case 0://sua ma lop
						{
							goToXY(80, 26);
							changeTextColor(9);
							cout << "Nhap ma lop moi: ";
							changeTextColor(15);
							box(97, 25, 30);
							char maLopMoi[30];
							showConsoleCursor(true);
							while (true) {
								strcpy(maLopMoi, nhap(20,98,26));
								strupr(maLopMoi);
								if (!(strcmp(maLopMoi, maLop1) == 0 || strcmp(maLopMoi, maLop2) == 0 || strcmp(maLopMoi, maLop3) == 0 || strcmp(maLopMoi, maLop4) == 0 || strcmp(maLopMoi, maLop5) == 0)) {
									goToXY(98, 28);
									changeTextColor(4);
									cout << "Ma lop khong ton tai (CNTT1, CNTT2, ANHTTT, BDATTT, DTH)";
									changeTextColor(15);
									deleteEnter(98, 26, 25);
								}
								else {
									strcpy(temp->sv.maLop, maLopMoi);
									deleteEnter(98, 26, 20);
									goToXY(110, 26); cout << temp->sv.maLop;
									goToXY(98, 28);
									changeTextColor(2);
									cout << "                                                             ";
									goToXY(100, 28);
									cout << "Thay doi thanh cong!";
									changeTextColor(15);
									k = 1;
									break;
								}
							}
							showConsoleCursor(false);
							break;
						}
						case 1://sua ho ten
						{
							goToXY(80, 26);
							changeTextColor(9);
							cout << "Nhap ten moi: ";
							changeTextColor(15);
							box(97, 25, 45);
							char* name = new char[40];
							showConsoleCursor(true);
							int kk = 0;
							while (true) {
								strcpy(name, nhap(33,98,26));
								bool kt = true;
								for (int i = 0; i < strlen(name); i++) {
									if ((int)name[i] == 32 || ((int)name[i] > 64 && (int)name[i] < 91) || ((int)name[i] > 96 && (int)name[i] < 123)) continue;
									else {
										kt = false;
										break;
									}
								}
								if (strlen(name) < 50 && strlen(name) > 0 && kt) {
									deleteEnter(98, 26, 35);
									kk = 1;
								}
								else {
									deleteEnter(98, 26, 35);
									goToXY(100, 28);
									changeTextColor(4);
									cout << "Ho ten khong hop le";
									changeTextColor(15);
								}
								if (kk == 1) break;
							}
							showConsoleCursor(false);
							goToXY(98, 28);
							cout << "                                    ";
							goToXY(100, 28);
							changeTextColor(2);
							cout << "Thay doi thanh cong!";
							changeTextColor(15);
							name = fixHoten(name);
							strcpy(temp->sv.hoTen, name);
							deleteEnter(98, 26, 35);
							goToXY(120 - (int)(strlen(name) / 2), 26); cout << name;
							k = 1;
							break;
						}
						case 2://sua ngay thang nam sinh
						{
							int ngay, thang, nam;
							changeTextColor(15);
							goToXY(80, 27);      cout << "Ngay sinh:";       box(90, 26, 5);
							goToXY(98, 27);      cout << "Thang sinh:";      box(109, 26, 5);
							goToXY(117, 27);      cout << "Nam sinh:";        box(126, 26, 7);
							showConsoleCursor(true);
							while (true) {
								while (true) {
									char ng[6];
									strcpy(ng, nhap(4,91,27));
									ngay = charToInt(ng);
									if ( ngay > 0 && ngay < 32) break;
									else {
										goToXY(85, 29);
										cout << "                   ";
										goToXY(85, 29);
										changeTextColor(4);
										cout << "Ngay khong hop le";
										changeTextColor(15);
										goToXY(91, 27); cout << "     ";
									}

								}
								goToXY(85, 29); cout << "                                                                ";
								while (true) {
									char th[6];
									strcpy(th, nhap(4,110,27));
									thang = charToInt(th);
									if (thang > 0 && thang < 13) break;
									else {
										goToXY(85, 29);
										cout<<"                              ";
										goToXY(85, 29);
										changeTextColor(4);
										cout << "Thang khong hop le";
										changeTextColor(15);
										goToXY(110, 27); cout << "     ";
									}

								}
								goToXY(85, 29); cout << "                                                                   ";
								while (true) {
									char na[6];
									strcpy(na, nhap(4,127,27));
									nam = charToInt(na);
									if ( nam > 1960 && nam < 2020) break;
									else {
										goToXY(85, 29);
										cout << "                                                              ";
										goToXY(85, 29);
										changeTextColor(4);
										cout << "Nam khong hop le";
										changeTextColor(15);
										goToXY(127, 27); cout << "     ";
									}

								}
								goToXY(85, 29); cout << "                                       ";
								if (checkNgaySinh(ngay, thang, nam)) {
									goToXY(85, 29);
									changeTextColor(2);
									cout << "Ngay thang nam hop le. Thay doi thanh cong!";
									changeTextColor(15);
									k = 1;
									break;
								}
								goToXY(85, 29);
								changeTextColor(4);
								cout << "Ngay thang nam sinh khong hop le";
								changeTextColor(15);
								goToXY(91, 27); cout << "   ";
								goToXY(110, 27); cout << "   ";
								goToXY(127, 27); cout << "     ";
							}
							showConsoleCursor(false);
							temp->sv.date.ngay = ngay;
							temp->sv.date.thang = thang;
							temp->sv.date.nam = nam;
							break;
						}
						case 3://sua diem TB
						{
							goToXY(97, 27);
							changeTextColor(9);
							cout << "Nhap diem TB moi:";
							changeTextColor(15);
							box(115, 26, 5);
							float diemTB;
							
							showConsoleCursor(true);
							while (true) {
								char d[6];
								strcpy(d, nhap(4,116,27));
								diemTB = charToFloat(d);
								if (diemTB >= 0 && diemTB <= 10) {
									goToXY(100, 29);
									cout << "                                                ";
									goToXY(100, 29);
									changeTextColor(2);
									cout << "Thay doi thanh cong!";
									changeTextColor(15);
									k = 1;
									break;
								}
								else {
									goToXY(100, 29);
									changeTextColor(4);
									cout << "Diem TB khong hop le!";
									changeTextColor(15);
									goToXY(117, 27); cout << "    ";
								}
							}
							temp->sv.diemTB = diemTB;
							showConsoleCursor(false);
							break;
						}
						}
						break;
					}
					}
					if (k == 1) break;
					s.showSelection2(r, 135, 17);
				}
			}
			if (kiemTra == 0) {
				struct node* temp = l.pHead;
				while (strcmp(temp->sv.maSv, ma1) != 0) temp = temp->pnext;
				display1Sv(temp, 96, 31);
			}
			changeTextColor(9);
			for (int i = 0; i < 4; i++) {
				goToXY(96, 38 + i);
				for (int j = 0; j < 30; j++) {
					printf("%c", 219);
				}
			}
			veHinh(100, 39, "Ban co muon tiep tuc?", 159);
			int r = 0;
			while (true) {
				if (r == 0) {
					veHinh(102, 40, "Yes", 156);
					veHinh(115, 40, "No", 159);
				}
				else {
					veHinh(102, 40, "Yes", 159);
					veHinh(115, 40, "No", 156);
				}
				int k = move();
				if (k == 3 && r == 0) r = 1;
				else if (k == 3 && r == 1) r = 0;
				else if (k == 4 && r == 1) r = 0;
				else if (k == 4 && r == 0) r = 1;
				else if (k == 6) break;
			}
			if (r != 0) {
				xoaManHinh(41, 9, 159, 33);
				break;
			}
			showConsoleCursor(false);
		}
	}
	fflush(stdin);
}
void xoaSv(list& l)
{
	showConsoleCursor(true);
	changeTextColor(8);
	goToXY(80, 20);
	for (int i = 0; i < 62; i++) printf("%c", 219);
	for (int i = 0; i < 10; i++) {
		goToXY(80, 21 + i);
		printf("%c%c", 219, 219);
		goToXY(140, 21 + i);
		printf("%c%c", 219, 219);
	}
	goToXY(80, 31);
	for (int i = 0; i < 62; i++) printf("%c", 219);
	changeTextColor(9);
	goToXY(92, 22);
	cout << "Nhap mat khau xoa sinh vien";
	veHinh(85, 25, "Nhap password: ", 124);
	changeTextColor(15);
	box(100, 24, 33);
	int kt = 0;
	while (true) {
		int test = 0;
		goToXY(101, 25);
		int key = passWord();
		if (key == 2) {
			kt = 2;
			break;
		}
		if (key == 1) {
			kt = 1;
			goToXY(100, 28);
			cout << "                     ";
			goToXY(100, 28);
			changeTextColor(2);
			cout << "PassWord chinh xac";
			changeTextColor(15);
			break;
		}
		else {
			deleteEnter(101, 25, 30);
			goToXY(100, 28);
			cout << "                          ";
			goToXY(100, 28);
			changeTextColor(4);
			cout << "PassWord khong chinh xac";
			changeTextColor(15);
		}
	}
    if (kt == 2)  xoaManHinh(41, 8, 159, 34);
	if (kt == 1) {
		while (true) {
			showConsoleCursor(true);
			xoaManHinh(41, 10, 159, 32);
			changeTextColor(4);
			goToXY(105, 11);
			cout << "----XOA SINH VIEN----";
			goToXY(45, 15);
			changeTextColor(9);
			cout << "Nhap ma sinh vien: ";
			changeTextColor(15);
			box(64, 14, 30);
			char ma1[30];
			fflush(stdin);
			strcpy(ma1, nhap(20,65,15));
			if (strlen(ma1) != 8 || !checkMaSvInList(ma1, l) || (strlen(ma1) == 8 && ((int)ma1[0] < 48 || (int)ma1[0]>57 || (int)ma1[1] < 48 || (int)ma1[1]>57 || (int)ma1[2] < 48 || (int)ma1[2]>57 || (int)ma1[3] < 48 || (int)ma1[3]>57 || (int)ma1[4] < 48 || (int)ma1[4]>57 || (int)ma1[5] < 48 || (int)ma1[5]>57 || (int)ma1[6] < 48 || (int)ma1[6]>57 || (int)ma1[7] < 48 || (int)ma1[7]>57))) {
				if (!checkMaSvInList(ma1, l)) {
					changeTextColor(4);
					goToXY(65, 17);
					cout << "                                  ";
					goToXY(65, 17);
					cout << "Ma sinh vien khong ton tai";
					changeTextColor(15);
				}
				if (strlen(ma1) != 8) {
					goToXY(65, 17);
					cout << "                                                       ";
					changeTextColor(4);
					goToXY(65, 17);
					cout << "Ma sinh vien phai co 8 ki tu";
					changeTextColor(15);

				}
			}
			else {
				struct node* temp = l.pHead;
				while (strcmp(temp->sv.maSv, ma1) != 0) temp = temp->pnext;
				display1Sv(temp, 50, 18);
				goToXY(45, 25);
				changeTextColor(9);
				cout << "Delete? [Yes/No]";
				changeTextColor(15);
				box(62, 24, 6);
				char luachon[10];
				strcpy(luachon, nhap(3,63,25));
				strupr(luachon);
				if (strcmp(luachon, "YES") == 0) {
					deleteSv_masv(l, ma1);
					goToXY(45, 28);
					changeTextColor(4);
					cout << "Da xoa thanh cong";
					changeTextColor(15);
				}
				else {
					goToXY(50, 28);
					changeTextColor(4);
					cout << "Cancel";
					changeTextColor(15);
				}

			}
			showConsoleCursor(false);
			changeTextColor(9);
			for (int i = 0; i < 4; i++) {
				goToXY(96, 38 + i);
				for (int j = 0; j < 30; j++) {
					printf("%c", 219);
				}
			}
			veHinh(100, 39, "Ban co muon tiep tuc?", 159);
			int r = 0;
			while (true) {
				if (r == 0) {
					veHinh(102, 40, "Yes", 156);
					veHinh(115, 40, "No", 159);
				}
				else {
					veHinh(102, 40, "Yes", 159);
					veHinh(115, 40, "No", 156);
				}
				int k = move();
				if (k == 3 && r == 0) r = 1;
				else if (k == 3 && r == 1) r = 0;
				else if (k == 4 && r == 1) r = 0;
				else if (k == 4 && r == 0) r = 1;
				else if (k == 6) break;
			}
			changeTextColor(15);
			if (r != 0) {
				xoaManHinh(41, 9, 159, 33);
				break;
			}
		}
	}
}


