#pragma once
#include <iostream>
#include <string>
//gotoxy¹®
#include <conio.h>
#include <windows.h>
using namespace std;
void screen();
void gotoxy(int x, int y) {
	COORD posXY = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}