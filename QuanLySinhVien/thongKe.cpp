#include "Header.h"

int xepLoai(float diemTb)
{
	if (diemTb >= 9.0) return 1;
	if (diemTb >= 8.0 && diemTb < 9.0) return 2;
	if (diemTb >= 6.5 && diemTb < 8.0) return 3;
	if (diemTb >= 5 && diemTb < 6.5) return 4;
	if (diemTb < 5) return 5;
}

float lamTron(int a, int b)
{
	if (b == 0) return 0;
	float c = (float)a / (float)b;
	c = (int)(c * 1000);
	if ((int)c % 10 >= 5) c = c + 1;
	c = c / 10;
	return c;
}

void tableThongKe2(int size, int col, int row)
{
	goToXY(col, row); cout << char(218); for (int i = 0; i < 90; i++) cout << char(196); cout << char(191);
	goToXY(col, row + 1); cout << char(179);
	goToXY(col + 91, row + 1); cout << char(179);
	goToXY(col, row + 2); cout << char(179);
	goToXY(col + 91, row + 2); cout << char(180);
	goToXY(col, row + 3); cout << char(179);
	goToXY(col + 91, row + 3); cout << char(179);
	goToXY(col, row + 4); cout << char(192); for (int i = 0; i < 90; i++) cout << char(196); cout << char(217);
	goToXY(col + 10, row); cout << char(194);
	goToXY(col + 10, row + 1); cout << char(179);
	goToXY(col + 10, row + 2); cout << char(195);
	goToXY(col + 10, row + 3); cout << char(179);
	goToXY(col + 10, row + 4); cout << char(193);
	goToXY(col + 11, row + 2); for (int i = 0; i < 80; i++) cout << char(196);
	goToXY(col + 27, row); cout << char(194);
	goToXY(col + 43, row); cout << char(194);
	goToXY(col + 59, row); cout << char(194);
	goToXY(col + 75, row); cout << char(194);
	goToXY(col + 27, row + 1); cout << char(179);
	goToXY(col + 43, row + 1); cout << char(179);
	goToXY(col + 59, row + 1); cout << char(179);
	goToXY(col + 75, row + 1); cout << char(179);
	for (int i = col + 27; i < 150; i = i + 16)
	{
		goToXY(i, row + 2); cout << char(197);
		goToXY(i, row + 3); cout << char(179);
		goToXY(i, row + 4); cout << char(193);
	}
	for (int i = 19; i < 85; i = i + 16)
	{
		goToXY(col + i, row + 2); cout << char(194);
		goToXY(col + i, row + 3); cout << char(179);
		goToXY(col + i, row + 4); cout << char(193);
	}
	goToXY(col, row + 4 + 2 * size); cout << char(192);
	for (int i = 0; i < 80; i++)
	{
		if (i == 9 || i == 17 || i == 24 || i == 31 || i == 38 || i == 45 || i == 52 || i == 59 || i == 66 || i == 73)
			cout << char(193);
		cout << char(196);
	}
	cout << char(217);
	goToXY(col, row + 4); cout << char(195);
	goToXY(col + 10, row + 4); cout << char(197);
	goToXY(col + 19, row + 4); cout << char(197);
	goToXY(col + 27, row + 4); cout << char(197);
	goToXY(col + 35, row + 4); cout << char(197);
	goToXY(col + 43, row + 4); cout << char(197);
	goToXY(col + 51, row + 4); cout << char(197);
	goToXY(col + 59, row + 4); cout << char(197);
	goToXY(col + 67, row + 4); cout << char(197);
	goToXY(col + 75, row + 4); cout << char(197);
	goToXY(col + 83, row + 4); cout << char(197);
	goToXY(col + 91, row + 4); cout << char(180);
	int _row = row + 6;
	for (int i = 1; i < size; i++)
	{
		goToXY(col, _row); cout << char(195);  for (int i = 0; i < 90; i++)	printf("%c", 196); cout << char(180);
		_row = _row + 2;
	}
	_row = row + 5;
	for (int i = 1; i <= size; i++)
	{
		goToXY(col, _row);
		printf("%c%10c%9c%8c%8c%8c%8c%8c%8c%8c%8c%8c", 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179);
		_row = _row + 1;
		goToXY(col + 10, _row); cout << char(197);
		goToXY(col + 19, _row); cout << char(197);
		goToXY(col + 27, _row); cout << char(197);
		goToXY(col + 35, _row); cout << char(197);
		goToXY(col + 43, _row); cout << char(197);
		goToXY(col + 51, _row); cout << char(197);
		goToXY(col + 59, _row); cout << char(197);
		goToXY(col + 67, _row); cout << char(197);
		goToXY(col + 75, _row); cout << char(197);
		goToXY(col + 83, _row); cout << char(197);
		_row = _row + 1;
	}
	changeTextColor(2);
	goToXY(col + 2, row + 2); cout << "MA LOP";
	changeTextColor(9);
	goToXY(col + 15, row + 1); cout << "XUAT SAC";
	goToXY(col + 33, row + 1); cout << "GIOI";
	goToXY(col + 50, row + 1); cout << "KHA";
	goToXY(col + 63, row + 1); cout << "TRUNG BINH";
	goToXY(col + 82, row + 1); cout << "YEU";
	changeTextColor(6);
	for (int i = 15; i < 83; i = i + 16)
	{
		goToXY(col + i, row + 3); cout << "SL";
	}
	for (int i = 23; i < 90; i = i + 16)
	{
		goToXY(col + i, row + 3); cout << "%";
	}
	changeTextColor(15);
	_row = _row - 1;
	goToXY(col + 10, _row); cout << char(193);
	goToXY(col + 19, _row); cout << char(193);
	goToXY(col + 27, _row); cout << char(193);
	goToXY(col + 35, _row); cout << char(193);
	goToXY(col + 43, _row); cout << char(193);
	goToXY(col + 51, _row); cout << char(193);
	goToXY(col + 59, _row); cout << char(193);
	goToXY(col + 67, _row); cout << char(193);
	goToXY(col + 75, _row); cout << char(193);
	goToXY(col + 83, _row); cout << char(193);
}

void tableThongKe1(int size, int row, int col)
{
	goToXY(col, row); cout << char(218);
	for (int i = 1; i <= 70; i++)
	{
		if (i == 10 || i == 50) cout << char(194);
		else cout << char(196);
	}
	cout << char(191);
	goToXY(col, row + 1); cout << char(179);
	goToXY(col + 10, row + 1); cout << char(179);
	goToXY(col + 50, row + 1); cout << char(179);
	goToXY(col + 71, row + 1); cout << char(179);
	goToXY(col, row + 2); cout << char(192);
	for (int i = 1; i <= 70; i++)
	{
		if (i == 10 || i == 50) cout << char(193);
		else cout << char(196);
	}
	cout << char(217);
	goToXY(col, row + 2 + 2 * size); cout << char(192);
	for (int i = 1; i <= 70; i++)
	{
		if (i == 10 || i == 50) cout << char(193);
		else cout << char(196);
	}
	cout << char(217);
	int _row = row + 3;
	for (int i = 0; i < size; i++)
	{
		goToXY(col, _row); cout << char(179);
		goToXY(col + 10, _row); cout << char(179);
		goToXY(col + 50, _row); cout << char(179);
		goToXY(col + 71, _row); cout << char(179);
		_row = _row + 2;
	}
	_row = row + 2;
	changeTextColor(2);
	goToXY(col + 4, row + 1); cout << "STT";
	goToXY(col + 25, row + 1); cout << "TEN LOP";
	goToXY(col + 55, row + 1); cout << "SO SINH VIEN";
	goToXY(col + 16, row + 3 + 2 * size); cout << "TONG SO SINH VIEN";
	changeTextColor(15);
	for (int i = 0; i < size; i++)
	{
		goToXY(col + 1, _row);  for (int i = 1; i <= 70; i++) cout << char(196);
		goToXY(col, _row);  cout << char(195);
		goToXY(col + 10, _row);  cout << char(197);
		goToXY(col + 50, _row);  cout << char(197);
		goToXY(col + 71, _row);  cout << char(180);
		_row = _row + 2;
	}
	goToXY(col, row + 2 + 2 * size);  cout << char(195);
	goToXY(col + 50, row + 2 + 2 * size);  cout << char(197);
	goToXY(col + 71, row + 2 + 2 * size);  cout << char(180);
	goToXY(col, row + 3 + 2 * size);  cout << char(179);
	goToXY(col + 50, row + 3 + 2 * size);  cout << char(179);
	goToXY(col + 71, row + 3 + 2 * size);  cout << char(179);
	goToXY(col, row + 4 + 2 * size);  cout << char(192);
	goToXY(col + 1, row + 4 + 2 * size);  for (int i = 0; i < 70; i++) cout << char(196);
	goToXY(col + 50, row + 4 + 2 * size);  cout << char(193);
	goToXY(col + 71, row + 4 + 2 * size); cout << char(217);
}
void thongKe1(list& l) {
	int arr[10] = { 0 };
	string nameclass[10];
	nameclass[1] = maLop1; nameclass[2] = maLop2; nameclass[3] = maLop3;
	nameclass[4] = maLop4; nameclass[5] = maLop5;

	struct node* temp = l.pHead;
	while (temp != NULL)
	{
		for (int i = 1; i <= 5; i++)
			if (temp->sv.maLop == nameclass[i]) arr[i] = arr[i] + 1;
		temp = temp->pnext;
	}
	changeTextColor(4);
	goToXY(80, 12); cout << "THONG KE SINH VIEN THEO LOP";
	changeTextColor(15);
	tableThongKe1(5, 15, 59);
	for (int i = 1; i <= 5; i++)
	{
		changeTextColor(14);
		goToXY(65, 18 + 2 * (i - 1)); cout << i;
		changeTextColor(9);
		goToXY(85, 18 + 2 * (i - 1)); cout << nameclass[i];
		changeTextColor(15);
		goToXY(120, 18 + 2 * (i - 1)); cout << arr[i];
	}
	goToXY(120, 18 + 2 * 5); cout << l.countList;
	_getch();
	xoaManHinh(41, 9, 159, 33);
}
void thongKe2(list& l)
{

	int arr[36] = { 0 };
	string nameclass[10];
	nameclass[1] = maLop1; nameclass[2] = maLop2; nameclass[3] = maLop3;
	nameclass[4] = maLop4; nameclass[5] = maLop5;
	struct node* temp = l.pHead;
	while (temp != NULL)
	{
		for (int i = 1; i <= 5; i++)// gioi,kha,trung binh yeu tung lop
		{
			if (temp->sv.maLop == nameclass[i])
			{
				arr[(i - 1) * 6] += 1;
				arr[(i - 1) * 6 + xepLoai(temp->sv.diemTB)] += 1;
			}
		}
		temp = temp->pnext;
	}
	for (int i = 0; i < 30; i++)// tong gioi,kha, trung binh,yeu 
	{
		if (i % 6 == 0) arr[30] = arr[30] + arr[i];
		else if (i % 6 == 1) arr[31] = arr[31] + arr[i];
		else if (i % 6 == 2) arr[32] = arr[32] + arr[i];
		else if (i % 6 == 3) arr[33] = arr[33] + arr[i];
		else if (i % 6 == 4) arr[34] = arr[34] + arr[i];
		else arr[35] = arr[35] + arr[i];
	}
	tableThongKe2(6, 70, 15);
	changeTextColor(14);
	for (int i = 1; i <= 9; i++)
	{
		goToXY(72, 18 + 2 * i); cout << nameclass[i];
	}
	changeTextColor(15);
	goToXY(72, 30); cout << "Tong";
	for (int i = 15; i < 83; i = i + 16)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (j == 6) changeTextColor(4);
			goToXY(70 + i, 18 + j * 2); cout << arr[(j - 1) * 6 + int((i + 5) / 16)];
			goToXY(77 + i, 18 + j * 2); cout << lamTron(arr[(j - 1) * 6 + int((i + 5) / 16)], arr[(j - 1) * 6]);
			changeTextColor(15);
		}
	}
	bool k = true;
	int ii = -1;
	while (k) {
		int x = move();
		switch (x) {
		case 3:
		{
			if (ii == 5) ii = 0;
			else ii = ii + 1;
			break;
		}
		case 4:
		{
			if (ii == 0) ii = 5;
			else ii = ii - 1;
			break;
		}
		case 5:
		{
			k = false;
			xoaManHinh(41, 9, 159, 33);
			return;
		}
		default:
			continue;
		}
		if (ii < 5 && ii >= 0) {
			xoaManHinh(41, 9, 159, 33);
			string aa[] = { "xuat sac","gioi","kha","trung binh","yeu" };
			//bieu do so sanh ti le xuat sac, gioi, kha, trung binh,yeu giua cac lop
			// ve truc toa Oxy
			for (int i = 0; i < 20; i++) {
				goToXY(70, 35 - i);
				printf("%c", 179);
			}
			goToXY(70, 15); printf("^");
			changeTextColor(6);
			goToXY(71, 15); cout << "%";
			changeTextColor(15);
			for (int i = 0; i < 95; i++) {
				goToXY(70 + i + 1, 35);
				printf("_");
			}
			//
			// viet ten cac lop tren truc 0x
			changeTextColor(4);
			goToXY(70 + 13, 35 + 2); cout << maLop1;
			goToXY(70 + 28, 35 + 2); cout << maLop2;
			goToXY(70 + 45, 35 + 2); cout << maLop3;
			goToXY(70 + 58, 35 + 2); cout << maLop4;
			goToXY(70 + 73, 35 + 2); cout << maLop5;
			changeTextColor(2);
			goToXY(70 + 28, 35 + 4); cout << "*** Bieu do so sanh ti le hoc vien " << aa[ii] << "***" << endl;
			changeTextColor(15);
			for (int j = 1; j <= 5; j++)
			{
				float a = lamTron(arr[(j - 1) * 6 + ii + 1], arr[(j - 1) * 6]);
				int i = 0;
				for (i = 0; i < (int)(a / 4); i++) {
					changeTextColor(9);
					goToXY(70 + 15 + 15 * (j - 1), 35 - i); printf("%c%c", 219, 219);
				}
				goToXY(70 + 15 + 15 * (j - 1), 35 - i - 1);
				changeTextColor(6);
				cout << a;
				changeTextColor(15);
			}
		}
		if (ii == 5) {
			// bieu do ti le xuat sac, gioi, kha, trung binh, yeu
			// ve truc toa Oxy
			xoaManHinh(41, 9, 159, 30);
			for (int i = 0; i < 20; i++) {
				goToXY(70, 35 - i);
				printf("%c", 179);
			}
			goToXY(70, 15); printf("^");
			changeTextColor(6);
			goToXY(71, 15); cout << "%";
			changeTextColor(15);
			for (int i = 0; i < 95; i++) {
				goToXY(70 + i + 1, 35);
				printf("_");
			}
			//
			 // viet ten cac lop tren truc 0x
			changeTextColor(4);
			goToXY(70 + 12, 35 + 2); cout << "Xuat sac";
			goToXY(70 + 29, 35 + 2); cout << "Gioi";
			goToXY(70 + 45, 35 + 2); cout << "Kha";
			goToXY(70 + 55, 35 + 2); cout << "Trung binh";
			goToXY(70 + 75, 35 + 2); cout << "Yeu";
			changeTextColor(2);
			goToXY(75, 35 + 4); cout << "*** Bieu do so sanh ti le hoc vien xuat sac, gioi, kha, trung binh, yeu ***" << endl;
			changeTextColor(15);
			for (int j = 1; j <= 5; j++)
			{
				float a = lamTron(arr[30 + j], arr[30]);
				int i = 0;
				for (i = 0; i < (int)(a / 4); i++) {
					changeTextColor(9);
					goToXY(70 + 15 + 15 * (j - 1), 35 - i); printf("%c%c", 219, 219);
				}
				goToXY(70 + 15 + 15 * (j - 1), 35 - i - 1);
				changeTextColor(6);
				cout << a;
				changeTextColor(15);
			}

		}

	}
}


