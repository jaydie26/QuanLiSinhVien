#pragma once
#include"Header.h"

//sap xep chon
void swapSV(sinhVien& sv1, sinhVien& sv2);
void swapNode(struct node*, struct node*);
void selectionSort(list&, int);
//sap xep chen
void insert(list&, struct node*, int);
void insertSort(list&, int);
// sap xep nhanh
struct node* getTail(struct node* cur);
struct node* partition(struct node* head, struct node* end, struct node** newHead, struct node** newEnd, int keyType);
struct node* quickSortRecur(struct node* head, struct node* end, int keyType);
void quickSort1(struct node** headRef, int keyType);
//sap xep noi bot
void bubbleSort(list& l, int keyType);
//sap xep
static char nameFix1[40]; // ten1
static char nameFix2[40]; // ho1
static char nameFix3[40]; // ten2
static char nameFix4[40]; // ho2
void fixname(char*, char*, char*);
bool compare(sinhVien&, sinhVien&, int);
void sortBy(list& l, int, int);
// compare
void compareSort(list& l, int keyType);

