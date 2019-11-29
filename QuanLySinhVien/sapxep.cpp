#include "Header.h"
using namespace std;

// hoan vi 2 node trong danh sach
void swapNode(node* x, node* y)
{
	sinhVien s;
	s = x->sv;
	x->sv = y->sv;
	y->sv = s;
}
// selection Sort
void selectionSort(list& l, int keyType)
{
	struct node* p = l.pHead;
	struct node* q = l.pHead;
	while (p->pnext != NULL) {
		while (q != NULL) {
			if (compare(p->sv, q->sv, keyType)) {
				swapNode(p, q);
			}
			q = q->pnext;
		}
		if (p) {
			p = p->pnext;
			q = p->pnext;
		}
	}
}
//
// insert Sort
void insert(list& ll, node* newNode, int keyType)// insert node vao list < list tang dan >
{
	if (ll.pHead == NULL || compare(ll.pHead->sv, newNode->sv, keyType)) {
		newNode->pnext = ll.pHead;
		ll.pHead = newNode;
		if (ll.pTail == NULL) ll.pTail = newNode;
		ll.countList = ll.countList + 1;
	}
	else {
		struct node* temp = ll.pHead;
		while (temp->pnext != NULL && !compare(temp->pnext->sv, newNode->sv, keyType)) temp = temp->pnext;// newNode > phan tu trong list thi dung roi chen vao
		newNode->pnext = temp->pnext;
		temp->pnext = newNode;
		ll.countList = ll.countList + 1;
	}
}
void insertSort(list& l, int keyType)
{
	list ll;
	khoiTaoList(ll);
	struct node* p = l.pHead;
	while (p != NULL) {
		struct node* next = p->pnext;
		insert(ll, p, keyType);
		p = next;
	}
	l.pHead = ll.pHead;
	l.pTail = ll.pTail;
	l.countList = ll.countList;
}
//quickSort

void swapSV(sinhVien& sv1, sinhVien& sv2)// hoan vi 2 sinh vien
{ 
	sinhVien temp;
	temp = sv1;
	sv1 = sv2;
	sv2 = temp;
}
node* getTail(node* cur)
{
	while (cur != NULL && cur->pnext != NULL) cur = cur->pnext;
	return cur;
}

node* partition(node* head, node* end, node** newHead, node** newEnd, int keyType)
{
	struct node* pivot = end;// phan tu chot
	struct node* prev = NULL, * cur = head, * tail = pivot;
	while (cur != pivot) {
		if (!compare(cur->sv, pivot->sv, keyType)) {// < chot (neu list rong thi la ptu dau neu khong o ben trai chot
			if ((*newHead) == NULL) (*newHead) = cur;
			prev = cur;
			cur = cur->pnext;
		}
		else {
			if (prev) prev->pnext = cur->pnext;// xoa cur
			struct node* tmp = cur->pnext;
			cur->pnext = NULL;// chen xuong cuoi list
			tail->pnext = cur;
			tail = cur;
			cur = tmp;
		}
	}
	if ((*newHead) == NULL) (*newHead) = pivot; // neu pivot nho nhat -> pivot la phan tu dau
	(*newEnd) = tail;
	return pivot;
}
node* quickSortRecur(node* head, node* end, int keyType)// phan tu nho nhat cho len dau danh sach
{
	if (!head || head == end) return head;
	node* newHead = NULL, * newEnd = NULL;
	struct node* pivot = partition(head, end, &newHead, &newEnd, keyType);
	// khi pivot kp la phan tu nho nhat
	// ben trai pivot
	if (newHead != pivot) {
		struct node* tmp = newHead;
		while (tmp->pnext != pivot) tmp = tmp->pnext;// dich den truoc pivot
		tmp->pnext = NULL;
		newHead = quickSortRecur(newHead, tmp, keyType);// duyet danh sach truoc pivot
		tmp = getTail(newHead);
		tmp->pnext = pivot;
	}
	// ben phai pivot
	pivot->pnext = quickSortRecur(pivot->pnext, newEnd, keyType);
	return newHead;
}

void quickSort1(node** headRef, int keyType)
{
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef), keyType);
	return;
}

// bubble sort
void bubbleSort(list& l, int keyType)
{
	if (isEmpty(l)) return;
	struct node* temp1 = l.pHead;
	while (temp1 && temp1->pnext) {
		struct node* temp2 = temp1->pnext;
		while (temp2) {
			if (compare(temp1->sv, temp2->sv, keyType)) swapNode(temp1, temp2);
			temp2 = temp2->pnext;
		}
		temp1 = temp1->pnext;
	}
}
void fixname(char* arr, char* a, char* b)// cat ho ten
{
	strcpy(a, arr);
	int k = 0;
	for (int i = strlen(arr); i >= 0; i--)
	{
		if (arr[i] == ' ') {
			int j = i + 1;
			while (arr[j] != '\0')
			{
				a[k] = arr[j];
				k++;
				j++;
			}
			a[k] = '\0';
			break;
		}
	}
	for (int i = 0; i < strlen(arr) - k - 1; i++)
	{
		b[i] = arr[i];
	}
}
//
// so sanh 2 doi tuong sinh vien
bool compare(sinhVien& sv1, sinhVien& sv2, int keyType)
{
	switch (keyType)
	{
	case 0://so sanh ma lop
	{
		if (strcmp(sv1.maLop, sv2.maLop) < 0) return false;
		else return true;
	}
	case 1://so sanh hai ma sv voi nhau
	{
		if (strcmp(sv1.maSv, sv2.maSv) < 0) return false;
		else return true;
	}
	case 2://so sanh hai ten voi nhau
	{
		fixname(sv1.hoTen, nameFix1, nameFix2);
		fixname(sv2.hoTen, nameFix3, nameFix4);
		if (strcmp(nameFix1, nameFix3) < 0) return false;
		else if (strcmp(nameFix1, nameFix3) > 0) return true;
		else
		{
			if (strcmp(nameFix2, nameFix4) < 0) return false;
			else return true;
		}
	}
	case 3://so sanh theo ngay thang nam sinh
	{
		return (sv1.date > sv2.date);
	}
	case 4://so sanh theo diem trung binh
	{
		return (sv1.diemTB > sv2.diemTB);
	}
	}
}
// lua chon thuat toan sap xep
void sortBy(list& l, int sortType, int keyType)
{
	switch (sortType)
	{
	case 0://selection sort
	{
		selectionSort(l, keyType);
		break;
	}
	case 1://insertion sort
	{
		insertSort(l, keyType);
		break;
	}
	case 3://quick sort
	{
		if (keyType == 1) quickSort1(&l.pHead, 4);
		quickSort1(&l.pHead, keyType);
		break;
	}
	case 2://bubble sort
	{
		bubbleSort(l, keyType);
		break;
	}
	}
}

void compareSort(list& l, int keyType)
{
	list l1, l2, l3, l4;
	khoiTaoList(l1);
	khoiTaoList(l2);
	khoiTaoList(l3);
	khoiTaoList(l4);
	struct node* p1 = l.pHead;
	while (p1 != NULL) {
		insertHead(l1, p1->sv);
		p1 = p1->pnext;
	}
	//
	struct node* p2 = l.pHead;
	while (p2 != NULL) {
		insertHead(l2, p2->sv);
		p2 = p2->pnext;
	}
	//
	struct node* p3 = l.pHead;
	while (p3 != NULL) {
		insertHead(l3, p3->sv);
		p3 = p3->pnext;
	}
	//
	struct node* p4 = l.pHead;
	while (p4 != NULL) {
		insertTail(l4, p4->sv);
		p4 = p4->pnext;
	}
	if (keyType == 1) quickSort1(&l4.pHead, 2);
	//
	clock_t start1 = clock();
	selectionSort(l1, keyType);
	clock_t finish1 = clock();
	double delta1 = finish1 - start1;
	double time1 = delta1 / (double)(CLOCKS_PER_SEC);
	//
	clock_t start2 = clock();
	insertSort(l2, keyType);
	clock_t finish2 = clock();
	double delta2 = finish2 - start2;
	double time2 = delta2 / (double)(CLOCKS_PER_SEC);
	//
	clock_t start3 = clock();
	bubbleSort(l3, keyType);
	clock_t finish3 = clock();
	double delta3 = finish3 - start3;
	double time3 = delta3 / (double)(CLOCKS_PER_SEC);
	//
	clock_t start4 = clock();
	quickSort1(&l4.pHead, keyType);
	clock_t finish4 = clock();
	double delta4 = finish4 - start4;
	double time4 = delta4 / (double)(CLOCKS_PER_SEC);
	//
	goToXY(45, 12);
	changeTextColor(9);
	printf("Time Selection Sort:%.20lf   ", time1);
	changeTextColor(4);
	for (int i = 0; i < (int)(time1 * 10); i++) printf("%c", 219);
	changeTextColor(15);
	goToXY(45, 14);
	changeTextColor(9);
	printf("Time Insert Sort   :%.20lf   ", time2);
	changeTextColor(4);
	for (int i = 0; i < (int)(time2 * 10); i++) printf("%c", 219);
	changeTextColor(15);
	goToXY(45, 16);
	changeTextColor(9);
	printf("Time Bubble Sort   :%.20lf   ", time3);
	changeTextColor(4);
	for (int i = 0; i < (int)(time3 * 10); i++) printf("%c", 219);
	changeTextColor(15);
	goToXY(45, 18);
	changeTextColor(9);
	printf("Time Quick Sort    :%.20lf   ", time4);
	changeTextColor(4);
	for (int i = 0; i < (int)(time4 * 10); i++) printf("%c", 219);
	changeTextColor(15);
	//
	_getch();
	xoaManHinh(42, 9, 159, 25);
}








