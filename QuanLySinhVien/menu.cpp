#include "Header.h"

// menu chinh
void mainMenu(list& l)
{
	showConsoleCursor(false);
	int r = 0;
	selection s(6, 0);
	s.showSelection(r, 0, 12);
	int k = 0;
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
			if (r == 0) menu_ThemVaSua(l);
			if (r == 1) menu_HienThi(l);
			if (r == 2) menu_ThuatToanSapXep(l);
			if (r == 3) menu_TimKiem(l);
			if (r == 4) menu_ThongKe(l);
			if (r == 5) exit(0);
			break;
		}
		default:
		{
			break;
		}
		}
		if (k == 1) break;
		s.showSelection(r, 0, 12);
	}
}

void menu_ThemVaSua(list& l)
{
	selection s(3, 1);
	int r = 0;
	s.showSelection1(r, 41, 8);
	int k = 0;
	while (true) {
		int x = move();
		switch (x) {
		case 3:
		{
			if (r < s.numberSelection - 1) r++;
			else r = 0;
			break;

		}
		case 4:
		{
			if (r > 0) r--;
			else r = s.numberSelection - 1;
			break;
		}
		case 5:
		{
			xoaManHinh(41, 8, 159, 25);
			k = 1;
			break;
		}
		case 6:
		{
			switch (r) {
			case 0:
			{
				AddSv(l);
				break;
			}
			case 1:
			{
				suaSv(l);
				break;
			}
			case 2:
			{
				xoaSv(l);
				break;
			}
			}
			break;
		}
		default:
		{
			break;
		}
		}
		if (k == 1) break;
		s.showSelection1(r, 41, 8);
	}
}

void menu_HienThi(list& l)
{
	display(l, 0, 55, 12);
}

void menu_ThuatToanSapXep(list& l)
{
	selection s(5);
	int r = 0;
	s.showSelection1(r, 41, 8);
	int k = 0;
	while (true) {
		int x = move();
		switch (x) {
		case 3:
		{
			if (r < s.numberSelection - 1) r++;
			else r = 0;
			break;
		}
		case 4:
		{
			if (r > 0) r--;
			else r = s.numberSelection - 1;
			break;
		}
		case 5:
		{
			xoaManHinh(41, 8, 159, 25);
			k = 1;
			break;
		}
		case 6:
		{
			menu_SapXepc3(5,3, r, l);
			break;
		}
		default:
		{
			break;
		}
		}
		if (k == 1) break;
		s.showSelection1(r, 41, 8);
	}
}

void menu_TimKiem(list& l)
{
	selection s(6);
	int r = 0;
	s.showSelection1(r, 41,8 );
	int k = 0;
	while (true) {
		int x = move();
		switch (x) {
		case 3:
		{
			if (r < s.numberSelection - 1) r++;
			else r = 0;
			break;
		}
		case 4:
		{
			if (r > 0) r--;
			else r = s.numberSelection - 1;
			break;
		}
		case 5:
		{
			xoaManHinh(41, 8, 159, 25);
			k = 1;
			break;
		}
		case 6:
		{
			changeTextColor(4);
			menu_TimKiemc3(2,4, r, l);
			break;
		}
		default:
		{
			break;
		}
		}
		if (k == 1) break;
		s.showSelection1(r, 41, 8);
	}
}

void menu_ThongKe(list& l)
{
	selection s(2, 5);
	int r = 0;
	s.showSelection1(r, 41, 8);
	int k = 0;
	while (true) {
		int x = move();
		switch (x) {
		case 3:
		{
			if (r < s.numberSelection - 1) r++;
			else r = 0;
			break;
		}
		case 4:
		{
			if (r > 0) r--;
			else r = s.numberSelection - 1;
			break;
		}
		case 5:
		{
			xoaManHinh(41, 8, 159, 30);
			k = 1;
			break;
		}
		case 6:
		{
			switch (r)
			{
			case 0:
			{
				xoaManHinh(41, 9, 159, 30);
				thongKe1(l);
				break;
			}
			case 1:
			{
				xoaManHinh(41, 9, 159, 30);
				thongKe2(l);
				break;
			}
			}
		}
		default:
		{
			break;
		}
		}
		if (k == 1) break;
		s.showSelection1(r, 41, 8);
	}
}

void menu_SapXepc3(int x,int y,int key, list& l)
{
	selection s(x,y);
	int r = 0;
	s.showSelection2(r, 46+key*25, 9);
	int k = 0;
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
			xoaManHinh(42, 9, 159, 25);
			k = 1;
			break;
		}
		case 6:
		{
			if (r == s.numberSelection - 1) {
				xoaManHinh(42, 9, 159, 25);
				compareSort(l, key);
			}
			else menu_SapXepc4(2, 2, r, key, l);
			/*if (r == s.numberSelection-1) {
				xoaManHinh(42, 9, 159, 25);
				compareSort(l, key);
			}
			else {
				xoaManHinh(42, 9, 159, 25);
				clock_t start = clock();
				sortBy(l, r, key);
				clock_t finish = clock();
				double delta = finish - start;
				double time = delta / (double)(CLOCKS_PER_SEC);
				goToXY(43, 10);
				changeTextColor(4);
				printf("Thoi gian sap xep la:%.20lf", time);
				changeTextColor(15);
				display(l, 0, 53, 10);
			}
			break;*/
		}
		default:
		{
			break;
		}
		}
		if (k == 1) break;
		s.showSelection2(r, 46+key*25, 9);
	}
}

void menu_SapXepc4(int x, int y, int rr, int kk, list& l)
{
	selection s(x, y);
	int r = 0;
	s.showSelection22(r, 46 + kk * 25+16, 9+rr);
	int k = 0;
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
			xoaManHinh(46 + kk * 25 + 16, 9, 7, 10);
			k = 1;
			break;
		}
		case 6:
		{
			
			if(r==0){
				xoaManHinh(42, 9, 159, 25);
				clock_t start = clock();
				sortBy(l, rr, kk);
				clock_t finish = clock();
				double delta = finish - start;
				double time = delta / (double)(CLOCKS_PER_SEC);
				goToXY(43, 10);
				changeTextColor(4);
				printf("Thoi gian sap xep la:%.20lf", time);
				changeTextColor(15);
				display(l, 0, 53, 10);
			}
			else {
				xoaManHinh(42, 9, 159, 25);
				list ll;
				khoiTaoList(ll);
				clock_t start = clock();
				sortBy(l, rr, kk);
				clock_t finish = clock();
				double delta = finish - start;
				double time = delta / (double)(CLOCKS_PER_SEC);
				goToXY(43, 10);
				changeTextColor(4);
				printf("Thoi gian sap xep la:%.20lf", time);
				changeTextColor(15);
				struct node* pp = l.pHead;
				while (pp != NULL) {
					insertHead(ll, pp->sv);
					pp = pp->pnext;
				}
				display(ll, 0, 53, 10);
				
			}
			k = 1;
			break;
		}
		default:
		{
			break;
		}
		}
		if (k == 1) break;
		s.showSelection22(r, 46 + kk * 25+16, 9+rr);
	}
}

void menu_TimKiemc3(int x,int y,int key, list& l)
{
	selection s(x,y);
	int r = 0;
	s.showSelection2(r, 46 + key * 25, 9);
	int k = 0;
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
			xoaManHinh(42, 9, 159, 30);
			k = 1;
			break;
		}
		case 6:
		{
			xoaManHinh(42, 9, 159, 30);
			goToXY(105, 10);
			changeTextColor(4);
			cout << "-----TIM KIEM SINH VIEN-----";
			goToXY(85, 13);
			changeTextColor(9);
			cout << "Nhap tu khoa:";
			changeTextColor(15);
			box(98, 12, 45);
			searchBy(l, r,key);
			break;
		}
		default:
		{
			break;
		}
		}
		if (k == 1) break;
		s.showSelection2(r, 46 + key * 25, 9);
	}
}