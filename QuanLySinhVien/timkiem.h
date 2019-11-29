#pragma once
#include"Header.h"

void searchBy(list&, int searchType, int keyType);// lua chon thuat toan sap xep va tu khoa sap xep
void tuanTu(list& l, int keyType);
//

bool checkSv1(sinhVien sv, char key[]);// kiem tra sinh vien co ton tai key hay khong
void binary(list& l, int keyType);
//
//binary linkList;
struct node1* middle1(node1* start, node1* last);
struct node1* binarySearch1(node1* head, int keyType, char key[], Date key1, float key2);
bool compareHoten(char key1[], char key2[]);

