#pragma once
#include"Header.h"
void display1Sv(struct node* sv, int x, int y);// hien thi 1 sinh vien o toa do (x,y)
void displayTable(int numberSv, int numberPage, int x, int y);// hien thi bang o toa do (x,y)
void displaySv(list& l, int numberPage, int numberSv, int svInDam, int x, int y);// hien thi danh sach sinh vien
void displaySvTK(list& l, int numberPage, int numberSv, char t[], int x, int y);
void emptyTable(int numberSv, int x, int y);// lam rong bang hien thi
void deleteTable(int x, int y);// xoa bang 
void display(list& l, int svInDam, int x, int y);// hien thi danh sach sinh vien kem voi bang va so sinh vien in dam
void display1(list& l, char t[], int x, int y);
void display2(list& l, char t[], int x, int y);
bool kiemTraChuoi(char x[], char y[], int xx, int length);