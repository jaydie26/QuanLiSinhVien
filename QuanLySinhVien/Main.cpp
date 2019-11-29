#include"header.h"

using namespace std;

int main() {
	list l;
	khoiTaoList(l);
	resizeConsole(1850, 950);
	backGround();
	readFile(l);
	mainMenu(l);
	//printfFile(l);
}