#include "Header.h"

void makeEmptyList(list& l)
{
	while (!isEmpty(l)) {
		struct node* p = l.pHead;
		l.pHead = l.pHead->pnext;
		free(p);
	}
	l.pTail = NULL;
	l.countList = 0;
}

bool isEmpty(list& l)
{
	if (l.pHead == NULL) return true;
	else return false;
}

void khoiTaoList(list& l)
{
	l.pHead = l.pTail = NULL;
	l.countList = 0;
}

void insertHead(list& l, sinhVien sv)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->pnext = l.pHead;
	p->sv = sv;
	l.pHead = p;
	if (l.pTail == NULL) l.pTail = p;
	l.countList++;
}

void insertTail(list& l, sinhVien sv)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->sv = sv;
	p->pnext = NULL;
	if (isEmpty(l)) {
		l.pHead = l.pTail = p;
		l.countList = l.countList + 1;
	}
	else {
		l.pTail->pnext = p;
		l.pTail = p;
		l.countList = l.countList + 1;
	}
}

void insertAtPosition(list& l, sinhVien sv, int pos)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	if (isEmpty(l)) insertHead(l, sv);
	else {
		if (pos == l.countList) insertTail(l, sv);
		else {
			if (pos == 1) insertHead(l, sv);
			else {
				struct node* k = l.pHead;
				int dem = 0;
				while (k != NULL) {
					dem++;
					if (dem == pos - 1) {
						p->sv = sv;
						p->pnext = k->pnext;
						k->pnext = p;
						l.countList++;
					}
					k = k->pnext;
				}
			}
		}
	}
}

void deleteSv(list& l, sinhVien sv)
{
	if (isEmpty(l)) return;
	else {
		struct node* temp = l.pHead;
		while ((temp->sv).maSv != sv.maSv) temp = temp->pnext;
		if (temp == l.pHead) {
			l.pHead = temp->pnext;
			free(temp);
			l.countList = l.countList - 1;
		}
		else {
			struct node* temp1 = l.pHead;
			while (temp1->pnext != temp) temp1 = temp1->pnext;
			temp1->pnext = temp->pnext;
			free(temp);
			l.countList = l.countList - 1;
			if (temp1 == NULL) l.pTail = temp1;
		}
	}
}

void deleteSv_masv(list& l, char* masv)
{
	if (isEmpty(l)) return;
	struct node* temp = l.pHead;
	while (strcmp(temp->sv.maSv, masv) != 0) temp = temp->pnext;
	if (temp == l.pHead)
	{
		l.pHead = temp->pnext;
		l.countList = l.countList - 1;
		if (l.pHead == NULL) l.pTail = NULL;
	}
	else
	{
		struct node* temp1 = l.pHead;
		while (temp1->pnext != temp) temp1 = temp1->pnext;
		temp1->pnext = temp->pnext;
		l.countList = l.countList - 1;
		if (temp1->pnext == NULL) l.pTail = temp1;
	}
	free(temp);
}

void readFile(list& l)
{
	fstream fin("dai.dat", ios::binary | ios::in);
	sinhVien sv;
	int n = filesize("dai.dat") / sizeof(sv);
	for (int i = 0; i < n; i++) {
		fin.read(reinterpret_cast<char*>(&sv), sizeof(sv));
		insertTail(l, sv);
	}
	fin.close();
}

void deleteHead(list& l)
{
	if (l.pHead == NULL) return;
	else {
		struct node* p = l.pHead;
		l.pHead = l.pHead->pnext;
		free(p);
	}
}

void deleteTail(list& l)
{
	if (l.pHead == NULL) return;
	else {
		if (l.pHead->pnext == NULL) deleteHead(l);
		else {
			for (struct node* k = l.pHead; k != NULL; k = k->pnext) {
				if (k->pnext == l.pTail) {
					free(l.pTail);
					k->pnext = NULL;
					l.pTail = k;
				}
			}
		}
	}
}

void printfFile(list& l)
{
	fstream fout("dai.dat", ios::binary | ios::out | ios::trunc);
	struct node* p = l.pHead;
	while (p != NULL) {
		fout.write(reinterpret_cast<char*>(&p->sv), sizeof(p->sv));
		p = p->pnext;
	}
	fout.close();
}

int countMaSv(list& l, char* maLop)
{
	int dem = 0;
	struct node* p = l.pHead;
	while (p != NULL) {
		if (strcmp(p->sv.maLop, maLop) == 0) dem++;
		p = p->pnext;
	}
	return dem;
}

std::ifstream::pos_type filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

void khoiTaoList1(list1& l)
{
	l.pHead = l.pTail = NULL;
}

void insertTail1(list1& l, node1* p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else {
		p->pnext = NULL;
		l.pTail->pnext = p;
		p->prev = l.pTail;
		l.pTail = p;
	}
}












