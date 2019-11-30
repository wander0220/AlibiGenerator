#pragma once
#include <conio.h>
#include <windows.h>
using namespace std;

#define UP  72
#define DOWN 80
#define SUBMIT 32

void gotoxy(int x, int y) {
	COORD pos = { x - 1 ,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int keyControl() {
	char temp = _getch();
	if (temp == '72') return UP;
	else if (temp == '80') return DOWN;
	else if (temp == '32') return SUBMIT;
}
void screen() {
	system("cls");
	gotoxy(0, 0);
	cout << "********************************************************" << endl;
	for (int i = 0; i < 20; i++) {
		cout << "*                                                      *" << endl;
	}
	cout << "********************************************************" << endl;
}
