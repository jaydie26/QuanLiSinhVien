#include "header.h"
using namespace std;
selection::selection(int number, int x)
{
	strSelection = new string[number + 1];
	numberSelection = number;
	switch (x) {
	// selection cap 1
	case 0:
	{
		strSelection[0] = "THEM MOI, SUA VA XOA";
		strSelection[1] = " HIEN THI DANH SACH ";
		strSelection[2] = "  SAP XEP SINH VIEN ";
		strSelection[3] = " TIM KIEM SINH VIEN ";
		strSelection[4] = " THONG KE SINH VIEN ";
		strSelection[5] = " EXIT CHUONG TRINH  ";
		break;
	}
	//selection cap 2
	case 4:
	{
		strSelection[0] = "";
		strSelection[1] = "TIM KIEM TUAN TU ";
		strSelection[2] = "TIM KIEM NHI PHAN";
		break;
	}
	case 3:
	{
		strSelection[0] = "";
		strSelection[1] = "SELECTION SORT  ";
		strSelection[2] = "INSERT SORT     ";
		strSelection[3] = "BUBBLE SORT     ";
		strSelection[4] = "QUICK SORT      ";
		strSelection[5] = "SO SANH TIME    ";
		break;

	}
	case 1:
	{
		strSelection[0] = "";
		strSelection[1] = "THEM SINH VIEN";
		strSelection[2] = "SUA SINH VIEN ";
		strSelection[3] = "XOA SINH VIEN ";
		break;
	}
	case 5:
	{
		strSelection[0] = "THONG KE";
		strSelection[1] = "  QUAN SO SINH VIEN   ";
		strSelection[2] = "TI LE KET QUA HOC TAP ";
		break;
	}
	//
	case 2:
	{
		strSelection[0] = "";
		strSelection[1] = " TANG ";
		strSelection[2] = " GIAM ";
		break;
	}
	//
	}

}

selection::selection(int number)
{
	strSelection = new string[number + 1];
	numberSelection = number;
	switch (number) {
	case 4:
	{
		strSelection[0] = "";
		strSelection[1] = "       MA LOP SINH VIEN        ";
		strSelection[2] = "       HO TEN SINH VIEN        ";
		strSelection[3] = "        NGAY THANG NAM         ";
		strSelection[4] = "        DIEM TICH LUY          ";
		break;
	}
	case 6:
	{
		strSelection[0] = "";
		strSelection[1] = "MA LOP SINH VIEN ";
		strSelection[2] = "  MA SINH VIEN   ";
		strSelection[3] = "HO TEN SINH VIEN ";
		strSelection[4] = " NGAY THANG NAM  ";
		strSelection[5] = "  DIEM TICH LUY  ";
		strSelection[6] = "     TAT CA      ";
		break;
	}
	case 5:
	{
		strSelection[0] = "";
		strSelection[1] = "MA LOP SINH VIEN";
		strSelection[2] = " MA SINH VIEN   ";
		strSelection[3] = "HO TEN SINH VIEN";
		strSelection[4] = " NGAY THANG NAM ";
		strSelection[5] = "  DIEM TICH LUY ";
		break;
	}
	}
}

void selection::showSelection(int y)
{
	goToXY(45, 1);
	changeTextColor(4);
	cout << strSelection[0];
	changeTextColor(13);
	for (int i = 0; i < numberSelection; i++)
	{
		if (i == y)
		{
			changeTextColor(9);
		}
		goToXY(45, 3 + i * 5);
		for (int i = 0; i <= 33; i++) printf("%c", 178);
		goToXY(45, 6 + i * 5);
		for (int i = 0; i <= 33; i++) printf("%c", 178);
		goToXY(45, 4 + i * 5); printf("%c", 178);
		goToXY(45, 5 + i * 5); printf("%c", 178);
		goToXY(45 + 33, 4 + i * 5); printf("%c", 178);
		goToXY(45 + 33, 5 + i * 5); printf("%c", 178);
		goToXY((33 - strSelection[i + 1].length()) / 2 + 45, i * 5 + 5);
		cout << strSelection[i + 1] << endl;
		changeTextColor(13);
	}
}

void selection::showSelection(int row, int x, int y)
{
	changeTextColor(14);
	for (int i = 0; i < numberSelection; i++)
	{
		if (i == row)
		{
			changeTextColor(1);
		}
		goToXY(x+3, y  + i * 4);
		for (int i = 0; i <= 33; i++) printf("%c", 219);
		goToXY(x+3, y + 1 + i * 4);
		for (int i = 0; i <= 33; i++) printf("%c", 219);
		goToXY(x+3, y + 2 + i * 4);
		for (int i = 0; i <= 33; i++) printf("%c", 219);
		if(i==row) veHinh((39 - strSelection[i].length()) / 2 + x, y + i * 4 + 1, strSelection[i], 28);
		else veHinh((39 - strSelection[i].length()) / 2 + x, y + i * 4 + 1, strSelection[i], 236);
		changeTextColor(14);
	}
	showConsoleCursor(false);

}

void selection::showSelection1(int row, int x, int y)
{
	goToXY(x, y);
	changeTextColor(9);
	for (int i = 0; i < 159;i ++) printf("%c", 219);
	for (int i = 0; i < numberSelection; i++)
	{
		if (i == row)
		{
			veHinh(x + 5 + 25 * i, y, strSelection[i + 1], 236);

		}
		else veHinh(x + 5 + 25 * i , y, strSelection[i + 1], 172);
	}
	
	showConsoleCursor(false);
}

void selection::showSelection2(int row, int x, int y)
{
	for (int i = 0; i < numberSelection; i++)
	{
		if (i == row)
		{
			veHinh(x , y+i, strSelection[i + 1], 206);

		}
		else veHinh(x , y+i, strSelection[i + 1], 250);
	}

	showConsoleCursor(false);
}

void selection::showSelection22(int row, int x, int y)
{
	for (int i = 0; i < numberSelection; i++)
	{
		if (i == row)
		{
			veHinh(x, y + i, strSelection[i + 1], 220);

		}
		else veHinh(x, y + i, strSelection[i + 1], 217);
	}
	showConsoleCursor(false);
}
