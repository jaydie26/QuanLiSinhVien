#pragma once
#include"Header.h"
struct Date {
	int ngay, thang, nam;
	bool operator==(Date x)// nap chong toan tu == cua lop Date
	{
		if (ngay == x.ngay && thang == x.thang && nam == x.nam) return true;
		else return false;
	};
	bool operator>(Date x)// nap chong toan tu > cua lop Date
	{
		if (nam > x.nam) return true;
		else if (nam < x.nam) return false;
		else
		{
			if (thang > x.thang) return true;
			else if (thang < x.thang) return false;
			else
			{
				if (ngay > x.ngay) return true;
				else return false;
			}
		}
	};
	bool operator<(Date x)// nap chong toan tu < cua lop Date
	{
		if (nam < x.nam) return true;
		else if (nam > x.nam) return false;
		else
		{
			if (thang < x.thang) return true;
			else if (thang > x.thang) return false;
			else
			{
				if (ngay < x.ngay) return true;
				else return false;
			}
		}
	};
};
// cau truc cua 1 sinh vien
struct sinhVien {
	char maLop[40];
	char maSv[40];
	char hoTen[40];
	Date date;
	float diemTB;
};
// 5 lop
static char maLop4[40] = "CNTT1";
static char maLop5[40] = "CNTT2";
static char maLop1[40] = "ANHTTT";
static char maLop2[40] = "BDATTT";
static char maLop3[40] = "DTH";
//cau truc 1 node trong danh sach lien ket don
struct node {
	sinhVien sv;
	struct node* pnext;
};
// cau truc danh sach lien ket don
struct list {
	struct node* pHead;
	struct node* pTail;
	int countList;
};
//
void makeEmptyList(list& l);// lam rong danh sach
bool isEmpty(list& l);//kiem tra danh sach co rong hay khong?
void khoiTaoList(list& l);//khoi tao cac thuoc tinh cua danh sach lien ket
void insertHead(list& l, sinhVien sv);// chen node vao dau danh sach
void insertTail(list& l, sinhVien sv);// chen node vao cuoi danh sach
void insertAtPosition(list& l, sinhVien sv, int pos);// chen node o vi tri bat ki trong danh sach
void deleteSv(list& l, sinhVien sv);// xoa 1 sinh vien trong danh sach
void deleteSv_masv(list& l, char* masv);// coa sinh vien theo ma sinh vien
void readFile(list& l);// doc danh sach tu file
void deleteHead(list& l);// xoa phan tu dau danh sach
void deleteTail(list& l);// xoa phan tu cuoi danh sach
void printfFile(list& l);// ghi danh sach ra file
int countMaSv(list& l, char* maLop);// dem so sinh vien trong cung 1 lop
std::ifstream::pos_type filesize(const char* filename);// dung trong doc file
// danh sach lien ket kep
struct node1 {
	sinhVien sv;
	struct node1* pnext;
	struct node1* prev;
};
struct list1 {
	struct node1* pHead;
	struct node1* pTail;
};
void khoiTaoList1(list1& l);
void insertTail1(list1& l,struct node1* p);


