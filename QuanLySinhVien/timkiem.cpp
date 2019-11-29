#include "Header.h"

// lua chon thuat toan tim kiem
void searchBy(list& l, int searchType, int keyType)
{
	switch (searchType) {
	case 0: {
		tuanTu(l, keyType);
		break;
	}
	case 1:
	{
		binary(l, keyType);
		break;
	}
	}
}
// tim kiem tuan tu
void tuanTu(list& l, int keyType)
{
	switch (keyType)
	{
	case 0://ma lop
	{
		showConsoleCursor(true);
		char* temp2 = new char[40];
		strcpy(temp2, nhap(30,100,13));
		strupr(temp2);
		showConsoleCursor(false);
		if (strcmp(maLop1, temp2) != 0 && strcmp(maLop2, temp2) != 0 && strcmp(maLop3, temp2) != 0 && strcmp(maLop4, temp2) != 0 && strcmp(maLop5, temp2) != 0) {
			goToXY(100, 15);
			cout << "                           ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Lop khong ton tai";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		else {
			int inDam = 0;
			struct node* temp = l.pHead;
			struct node* temp1 = temp;
			while (temp1 != NULL) {
				if (strcmp(temp1->sv.maLop, temp2) == 0) {
					swapNode(temp1, temp);
					temp = temp->pnext;
					inDam++;
				}
				temp1 = temp1->pnext;
			}
			display(l, inDam, 53, 13);
		}
		break;
	}
	case 1://ma sinh vien
	{
		showConsoleCursor(true);
		char* masv = new char[40];
		strcpy(masv, nhap(30,100,13));
		showConsoleCursor(false);
		if (strlen(masv) != 8 || !checkMaSvInList(masv, l) || (strlen(masv) == 8 && ((int)masv[0] < 48 || (int)masv[0]>57 || (int)masv[1] < 48 || (int)masv[1]>57 || (int)masv[2] < 48 || (int)masv[2]>57 || (int)masv[3] < 48 || (int)masv[3]>57 || (int)masv[4] < 48 || (int)masv[4]>57 || (int)masv[5] < 48 || (int)masv[5]>57 || (int)masv[6] < 48 || (int)masv[6]>57 || (int)masv[7] < 48 || (int)masv[7]>57))) {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Ma sinh vien khong ton tai";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		else {
			struct node* temp = l.pHead;
			while (temp != NULL) {
				if (strcmp(temp->sv.maSv, masv) == 0) {
					swapNode(temp, l.pHead);
					break;
				}
				else temp = temp->pnext;
			}
			display(l, 1, 53, 13);
			goToXY(100, 15);
			cout << "                                             ";
		}
		break;
	}
	case 2://ho ten
	{
		showConsoleCursor(true);
		char* ten = new char[40];
		strcpy(ten, nhap(30,100,13));
		char* t = fixHoten(ten);
		int inDam = 0;
		struct node* temp = l.pHead;
		showConsoleCursor(false);
		while (temp != NULL) {
			if (strstr(temp->sv.hoTen, ten) != NULL) {
				inDam++;
			}
			temp = temp->pnext;
		}
		if (inDam == 0) {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Ho ten khong ton tai";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		else {
			struct node* temp1 = l.pHead;
			struct node* temp2 = temp1;
			while (temp2 != NULL) {
				if (strstr(temp2->sv.hoTen, ten) != NULL) {
					swapNode(temp1, temp2);
					temp1 = temp1->pnext;
				}
				temp2 = temp2->pnext;
			}
			display(l, inDam, 53, 13);
			goToXY(100, 15);
			cout << "                                         ";
		}
		break;
	}
	case 3:// ngay sinh
	{
		showConsoleCursor(true);
		xoaManHinh(43, 12, 110, 5);
		goToXY(98, 13); cout << "Ngay: "; box(103, 12, 5);
		goToXY(110, 13); cout << "Thang: "; box(116, 12, 5);
		goToXY(123, 13); cout << "Nam:"; box(127, 12, 5);
		int ngay, thang, nam;
		char ng[6], th[6], na[6];
		strcpy(ng, nhap(4,104,13));
		strcpy(th, nhap(4,117,13));
		strcpy(na, nhap(4,128,13));
		ngay = charToInt(ng);
		thang = charToInt(th);
		nam = charToInt(na);
		showConsoleCursor(false);
		if (checkNgaySinh(ngay, thang, nam)) {
			int inDam = 0;
			struct node* temp = l.pHead;
			struct node* temp1 = temp;
			while (temp1 != NULL) {
				if (temp1->sv.date.ngay == ngay && temp1->sv.date.thang == thang && temp1->sv.date.nam == nam) {
					inDam++;
					swapNode(temp, temp1);
					temp = temp->pnext;
				}
				temp1 = temp1->pnext;
			}
			if (inDam == 0) {
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(4);
				goToXY(100, 15);
				cout << "Khong co ngay,thang,nam phu hop";
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(15);
			}
			else {
				display(l, inDam, 53, 13);
				goToXY(100, 15);
				cout << "                                         ";
			}
		}
		else {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Ngay,thang,nam sinh khong phu hop";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		break;
	}
	case 4:// diem trung binh
	{
		showConsoleCursor(true);
		float diem;
		char temp[6];
		strcpy(temp, nhap(4,100,13));
		diem = charToFloat(temp);
		showConsoleCursor(false);
		if ( diem >= 0 && diem <= 10) {
			int inDam = 0;
			struct node* temp = l.pHead;
			struct node* temp1 = temp;
			while (temp1 != NULL) {
				if (temp1->sv.diemTB == diem) {
					swapNode(temp, temp1);
					temp = temp->pnext;
					inDam++;
				}
				temp1 = temp1->pnext;
			}
			if (inDam == 0) {
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(4);
				goToXY(100, 15);
				cout << "Khong co diem phu hop";
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(15);
			}
			else {
				display(l, inDam, 53, 13);
				goToXY(100, 15);
				cout << "                                         ";
			}
		}
		else {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Diem khong phu hop";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		break;
	}
	case 5:// tat ca cac truong
	{
		showConsoleCursor(true);
		char* temp = new char[40];
		strcpy(temp,nhapTK(l,35,100,13));
		showConsoleCursor(false);
		list l1;
		khoiTaoList(l1);
		struct node* temp1 = l.pHead;
		struct node* temp2 = temp1;
		while (temp2 != NULL) {
			if (checkSv1(temp2->sv, temp)) {
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
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		else {
			display1(l1,temp , 53, 13);
			goToXY(100, 15);
			cout << "                                         ";
		}
		break;
	}
	}
}


bool checkSv1(sinhVien sv, char key[])
{
	strupr(sv.maLop);// chuyen in hoa
	if (strstr(sv.maLop,key) != NULL) return true;
	if (strstr(sv.maSv,key) != NULL) return true;
	if (strstr(sv.hoTen,key) != NULL) return true;
	char buf[20];
	itoa(sv.date.ngay, buf, 10);// chuyen int sang text
	if (strstr(buf,key) != NULL) return true;
	itoa(sv.date.thang, buf, 10);// chuyen int sang text
	if (strstr(buf,key) != NULL) return true;
	itoa(sv.date.nam, buf, 10);// chuyen int sang text
	if (strstr(buf,key) != NULL) return true;
	if (sv.diemTB == charToFloat(key)) return true;
	return false;
}
/////
node1* middle1(node1* start, node1* last)
{
	if (start == NULL) return NULL;
	struct node1* mid = start;
	struct node1* fast = start->pnext;
	while (fast != last) {
		fast = fast->pnext;
		if (fast != last) {
			mid = mid->pnext;
			fast = fast->pnext;
		}
	}
	return mid;
}

node1* binarySearch1(node1* head, int keyType, char key[], Date key1, float key2)
{
	switch (keyType) {
	case 0:
	{
		struct node1* start = head;
		struct node1* last = NULL;
		do {
			node1* mid = middle1(start, last);
			if (mid == NULL) {
				return NULL;
			}
			if (strcmp(mid->sv.maLop, key) == 0) {
				return mid;
			}
			else if (strcmp(mid->sv.maLop, key) < 0) start = mid->pnext;
			else last = mid;
		} while (last == NULL || last != start);
		return NULL;
		break;
	}
	case 2:
	{
		struct node1* start = head;
		struct node1* last = NULL;
		do {
			node1* mid = middle1(start, last);
			if (mid == NULL) {
				return NULL;
			}
			if (strcmp(mid->sv.hoTen, key) == 0) {
				return mid;
			}
			else if (compareHoten(mid->sv.hoTen,key)==false) start = mid->pnext;
			else last = mid;
		} while (last == NULL || last != start);
		return NULL;
		break;
	}
	case 1:// ma sinh vien
	{
		struct node1* start = head;
		struct node1* last = NULL;
		do {
			node1* mid = middle1(start, last);
			if (mid == NULL) {
				return NULL;
			}
			if (strcmp(mid->sv.maSv, key) == 0) {
				return mid;
			}
			else if (strcmp(mid->sv.maSv, key) < 0) start = mid->pnext;
			else last = mid;
		} while (last == NULL || last != start);
		return NULL;
		break;
	}
	case 3:// ngay thang nam sinh
	{
		struct node1* start = head;
		struct node1* last = NULL;
		do {
			node1* mid = middle1(start, last);
			if (mid == NULL) {
				return NULL;
			}
			if (mid->sv.date == key1) {
				return mid;
			}
			else if (mid->sv.date < key1) start = mid->pnext;
			else last = mid;
		} while (last == NULL || last != start);
		return NULL;
		break;
	}
	case 4:// diem trung binh
	{
		struct node1* start = head;
		struct node1* last = NULL;
		do {
			node1* mid = middle1(start, last);
			if (mid == NULL) {
				return NULL;
			}
			if (mid->sv.diemTB == key2) {
				return mid;
			}
			else if (mid->sv.diemTB < key2) start = mid->pnext;
			else last = mid;
		} while (last == NULL || last != start);
		return NULL;
		break;
	}
	}
}

bool compareHoten(char key1[], char key2[])
{
	fixname(key1, nameFix1, nameFix2);
	fixname(key2, nameFix3, nameFix4);
	if (strcmp(nameFix1, nameFix3) < 0) return false;
	else if (strcmp(nameFix1, nameFix3) > 0) return true;
	else
	{
		if (strcmp(nameFix2, nameFix4) < 0) return false;
		else return true;
	}
}



void binary(list& l, int keyType)
{
	sortBy(l, 1, keyType);
	switch (keyType)
	{
	case 0://ma lop
	{
		showConsoleCursor(true);
		char* temp2 = new char[40];
		strcpy(temp2, nhap(30, 100, 13));
		strupr(temp2);
		showConsoleCursor(false);
		if (strcmp(maLop1, temp2) != 0 && strcmp(maLop2, temp2) != 0 && strcmp(maLop3, temp2) != 0 && strcmp(maLop4, temp2) != 0 && strcmp(maLop5, temp2) != 0) {
			goToXY(100, 15);
			cout << "                           ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Lop khong ton tai";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		else {
			Date key1 = { 0,0,0 };
			float key2 = 0;
			list1 ll;
			khoiTaoList1(ll);
			struct node* p = l.pHead;
			while (p != NULL) {
				struct node1* pp = (struct node1*)malloc(sizeof(struct node1));
				pp->sv = p->sv;
				insertTail1(ll, pp);
				p = p->pnext;
			}
			struct node1* m = binarySearch1(ll.pHead, 0, temp2, key1, key2);
			if (m == NULL) {
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(4);
				goToXY(100, 15);
				cout << "Ma lop khong duoc tim thay";
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(15);
			}

			else {
				int inDam = 0;
				struct node1* p = m;
				while (p != NULL && strcmp(p->sv.maLop,m->sv.maLop)==0) {
					insertHead(l, p->sv);
					inDam++;
					p = p->pnext;
				}
				struct node1* pp = m->prev;
				while (pp != NULL && strcmp(pp->sv.maLop, m->sv.maLop) == 0) {
					insertHead(l, pp->sv);
					inDam++;
					pp = pp->prev;
				}
				display(l, inDam, 53, 13);
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
			}
		}
		break;
	}
	case 1://ma sinh vien
	{
		showConsoleCursor(true);
		char* masv = new char[50];
		fflush(stdin);
		strcpy(masv, nhap(30,100,13));
		showConsoleCursor(false);
		if (strlen(masv) != 8 || !checkMaSvInList(masv, l) || (strlen(masv) == 8 && ((int)masv[0] < 48 || (int)masv[0]>57 || (int)masv[1] < 48 || (int)masv[1]>57 || (int)masv[2] < 48 || (int)masv[2]>57 || (int)masv[3] < 48 || (int)masv[3]>57 || (int)masv[4] < 48 || (int)masv[4]>57 || (int)masv[5] < 48 || (int)masv[5]>57 || (int)masv[6] < 48 || (int)masv[6]>57 || (int)masv[7] < 48 || (int)masv[7]>57))) {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Ma sinh vien khong ton tai";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		else {
			Date key1 = { 0,0,0 };
			float key2 = 0;
			list1 ll;
			khoiTaoList1(ll);
			struct node* p = l.pHead;
			while (p != NULL) {
				struct node1* pp = (struct node1*)malloc(sizeof(struct node1));
				pp->sv = p->sv;
				insertTail1(ll, pp);
				p = p->pnext;
			}
			struct node1* m=binarySearch1(ll.pHead, 1, masv, key1, key2);
			if (m==NULL) {
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(4);
				goToXY(100, 15);
				cout << "Ma sinh vien khong ton tai";
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(15);
			}
			else {
				insertHead(l, m->sv);
				display(l, 1, 53, 13);
			}
		}
		break;
	}
	case 2://ho ten
	{
		showConsoleCursor(true);
		char* ten = new char[40];
		strcpy(ten, nhap(30, 100, 13));
		char* t = fixHoten(ten);
		showConsoleCursor(false);
		Date key1 = { 0,0,0 };
		float key2 = 0;
		list1 ll;
		khoiTaoList1(ll);
		struct node* p = l.pHead;
		while (p != NULL) {
			struct node1* pp = (struct node1*)malloc(sizeof(struct node1));
			pp->sv = p->sv;
			insertTail1(ll, pp);
			p = p->pnext;
		}
		struct node1* m = binarySearch1(ll.pHead, 2, t, key1, key2);
		if (m == NULL) {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Ho ten khong duoc tim thay";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		else {
			int inDam = 0;
			struct node1* p = m;
			while (p != NULL && strcmp(p->sv.hoTen, m->sv.hoTen) == 0) {
				insertHead(l, p->sv);
				inDam++;
				p = p->pnext;
			}
			struct node1* pp = m->prev;
			while (pp != NULL && strcmp(pp->sv.hoTen, m->sv.hoTen) == 0) {
				insertHead(l, pp->sv);
				inDam++;
				pp = pp->prev;
			}
			display(l, inDam, 53, 13);
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
		}
		break;
	}
	case 3:// ngay sinh
	{
		showConsoleCursor(true);
		Date d;
		xoaManHinh(43, 12, 110, 6);
		goToXY(98, 13); cout << "Ngay: "; box(103, 12, 5);
		goToXY(110, 13); cout << "Thang: "; box(116, 12, 5);
		goToXY(123, 13); cout << "Nam:"; box(127, 12, 5);
		char ng[6], th[6], na[6];
		strcpy(ng, nhap(4,104,13));
		strcpy(th, nhap(4,117,13));
		strcpy(na, nhap(4,128,13));
		d.ngay = charToInt(ng);
		d.thang = charToInt(th);
		d.nam = charToInt(na);
		showConsoleCursor(false);
		if (checkNgaySinh(d.ngay, d.thang, d.nam)) {
			char key[1];
			float key2 = 0;
			list1 ll;
			khoiTaoList1(ll);
			struct node* p = l.pHead;
			while (p != NULL) {
				struct node1* pp = (struct node1*)malloc(sizeof(struct node1));
				pp->sv = p->sv;
				insertTail1(ll, pp);
				p = p->pnext;
			}
			struct node1* m = binarySearch1(ll.pHead, 3, key, d, key2);
			if (m==NULL) {
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(4);
				goToXY(100, 15);
				cout << "Ngay,thang,nam sinh khong duoc tim thay";
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(15);
			}

			else {
				int inDam = 0;
				struct node1* p = m;
				while (p != NULL && p->sv.date == m->sv.date) {
					insertHead(l, p->sv);
					inDam++;
					p = p->pnext;
				}
				struct node1* pp = m->prev;
				while (pp != NULL && pp->sv.date == m->sv.date) {
					insertHead(l, pp->sv);
					inDam++;
					pp = pp->prev;
				}
				display(l, inDam, 53, 13);
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
			}
		}
		else {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Ngay,thang,nam sinh khong phu hop";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		break;
	}
	case 4:// diem trung binh
	{
		showConsoleCursor(true);
		float diem;
		char d[6];
		strcpy(d, nhap(4,100,13));
		diem = charToFloat(d);
		showConsoleCursor(false);
		if (diem >= 0 && diem <= 10) {
			char key[1];
			Date key1 = { 0,0,0 };
			list1 ll;
			khoiTaoList1(ll);
			struct node* p = l.pHead;
			while (p != NULL) {
				struct node1* pp = (struct node1*)malloc(sizeof(struct node1));
				pp->sv = p->sv;
				insertTail1(ll, pp);
				p = p->pnext;
			}
			struct node1* m = binarySearch1(ll.pHead, 4, key, key1, diem);
			if (m==NULL) {
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(4);
				goToXY(100, 15);
				cout << "Khong co diem phu hop";
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
				changeTextColor(15);
			}
			else {
				int inDam = 0;
				struct node1* p = m;
				while (p != NULL && p->sv.diemTB == m->sv.diemTB) {
					insertHead(l, p->sv);
					inDam++;
					p = p->pnext;
				}
				struct node1* pp = m->prev;
				while (pp != NULL && pp->sv.diemTB == m->sv.diemTB) {
					insertHead(l, pp->sv);
					inDam++;
					pp = pp->prev;
				}
				display(l, inDam, 53, 13);
				_getch();
				goToXY(100, 15);
				cout << "                                         ";
			}
		}
		else {
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(4);
			goToXY(100, 15);
			cout << "Diem khong phu hop";
			_getch();
			goToXY(100, 15);
			cout << "                                         ";
			changeTextColor(15);
		}
		break;
	}
	case 5:// tat ca cac truong
	{
		goToXY(100, 15);
		cout << "                                         ";
		changeTextColor(4);
		goToXY(100, 15);
		cout << "Truong tim kiem khong phu hop";
		_getch();
		goToXY(100, 15);
		cout << "                                         ";
		changeTextColor(15);
		break;
	}
	}
}

