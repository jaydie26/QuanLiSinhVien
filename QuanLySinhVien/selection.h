#pragma once
#include"Header.h"
struct selection {
public:
	selection(int number, int x);//selection cap 1,2
	selection(int number);//selection cap 3
	void showSelection(int y);//hien thi tu vi tri(0,0)
	void showSelection(int row, int x, int y);//hien thi tu vi tri(x,y)<menu chinh>
	void showSelection1(int row, int x, int y);//<menu cap 2>
	void showSelection2(int row, int x, int y);//<menu cap 3>
	void showSelection22(int row, int x, int y);
	std::string* strSelection;
	int numberSelection;
};
