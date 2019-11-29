#pragma once
#include"Header.h"

// addSv
void AddSv(list& l);
void box_AddSv();// khung them moi sinh vien
bool checkMaSvInList(char* masv, list& l);// kiem tra ma sinh vien co ton tai trong danh dach khong?
void setMasv(char* maSv, list& l);//nhap ma sinh vien va kiem tra tinh hop le
void setMalop(char* malop);// nhap ma lop va kiem tra tinh hop le
void setTen(char* ten);// nhap ten va chuan hoa ten
void setSv(list& l);// set cac thuoc tinh cua sinh vien
char* deleteAtPosition(char* name, int sizeOfArray, int index);// xoa 1 ki tu trong 1 chuoi
char* fixHoten(char name[]);// chuan hoa ho ten
bool checkNgaySinh(int ngay, int thang, int nam);//kiem tra tinh hop le cua ngay, thang, nam sinh
int charInvertInt(char* x);// doi ma sinh vien char sang int
int charToInt(char x[]);
float charToFloat(char x[]);
//sua sinh vien
void suaSv(list& l);
// xoa sinh vien
void xoaSv(list& l);

