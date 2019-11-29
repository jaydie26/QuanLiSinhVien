#pragma once
#include"Header.h"
#include"struct.h"
using namespace std;
//thay doi mau sac
void changeTextColor(int k);
// an hien con tro
void showConsoleCursor(bool showFlag);        
// du chuyen toa do
void goToXY(int x, int y);    
// xoa man hinh 
void xoaManHinh(int x, int y, int a, int b);
// kich thuoc console
void resizeConsole(int width, int height);
// in chuoi voi mau sac
void veHinh(int x, int y, string s, int color);
// xoa dong nhap vao
void deleteEnter(int x, int y, int z);
// check password dang nhap
int passWord();
// nhan su kien ban phim
int move();
// ve box
void box(int x, int y, int z);
// giao dien dang nhap chuong trinh
void backGround();
// su kien nhap
char* nhap(int max,int x,int y);
char* nhapTK(list& l,int max, int x, int y);
// giao dien chinh ung dung
void backGround1();
static string mta[] = { " __  __   _____    ___","|  \\/  | |_   _|  /   \\","| |\\/| |   | |    | - |","|_|__|_|  _|_|_   |_|_|","_|*****|_|*****|_|*****|","*`-0-0-'*`-0-0-'*`-0-0-'" };
static string hvktqs1[] = { "_   _ _____ ___       _   _  _ ___    _   _     _   _  _     _     _____ _   _ _   _ _____ _____     _____ _   _ _____ _   _     ___   _   _ ","( ) ( |  _  |  _`\\    ( ) ( )(_|  _`\\ ( ) ( )   ( ) ( )( )   ( )   (_   _| ) ( | ) ( |  _  |_   _)   (  _  | ) ( |  _  | ) ( )   (  _`\\( ) ( )","| |_| | ( ) | ( (_)   | | | || | (_(_)| `\\| |   | |/'/'`\\`\\_/'/'     | | | |_| | | | | (_) | | |     | ( ) | | | | (_) | `\\| |   | (_(_) | | |","|  _  | | | | |  _    | | | || |  _)_ | , ` |   | , <    `\\ /'       | | |  _  | | | |  _  | | |     | | | | | | |  _  | , ` |   `\\__ \\| | | |","| | | | (_) | (_( )   | \\_/ || | (_( )| |`\\ |   | |\\`\\    | |        | | | | | | (_) | | | | | |     | (('\\| (_) | | | | |`\\ |   ( )_) | (_) |","(_) (_|_____|____/'   `\\___/'(_|____/'(_) (_)   (_) (_)   (_)        (_) (_) (_|_____|_) (_) (_)     (___\\_|_____|_) (_|_) (_)   `\\____|_____)" };
static string hvktqs[] = { "_   _ ____  ____    __  ___ ____ __  _     __  ____  __    _____ _   _ __ __ ____ _____     ____  __ __ ____  __  _      ____  __ __ ","| |_| / () \\/ (__`   \\ \\/ / | ===|  \\| |   |  |/  | \\/ /   |_   _| |_| |  |  / () \\_   _|   / () \\|  |  / () \\|  \\| |    (_ (_`|  |  |","|_| |_\\____/\\____)    \\__/|_|____|_|\\__|   |__|\\__\\|__|      |_| |_| |_|\\___/__/\\__\\|_|     \\____/=\\___/__/\\__\\_|\\__|   .__)__) \\___/ " };
static string co[] = { "@@@@@@@@@@@@@@.@@@@@@@@@@@@@@","@@@@@@@@@@@@@(.%@@@@@@@@@@@@@","@@@@@@@@@@@@@,..@@@@@@@@@@@@@","@@@@@@@@@@@@,,...@@@@@@@@@@@@","@@@,........,,...,,,,,,,,.@@@","@@@@@@,,,,...,..,,,....@@@@@@","@@@@@@@@@,,,,..,....@@@@@@@@@","@@@@@@@@@@...,..,,,@@@@@@@@@@","@@@@@@@@@..,,,....,,@@@@@@@@@","@@@@@@@@..,,@@@@@..,,@@@@@@@@","@@@@@@@@,@@@@@@@@@@@.@@@@@@@@" };