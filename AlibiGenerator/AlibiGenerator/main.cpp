#include <iostream>
#include <string>
//gotoxy문
#include <conio.h>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y) {
	COORD posXY = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}
void screen() {
	cout << "*****************************************" << endl;
	for (int i = 0; i < 15; i++) {
		cout << "*                                       *" << endl;
	}
	cout << "*****************************************" << endl;

	gotoxy(13, 3);
	cout << "알라비이 생성기" << endl;
	gotoxy(13, 7);
	cout << "▶한다" << endl;
	gotoxy(13,10);
	cout << "▶만다" << endl;
	
}
int main() {
	screen();
	gotoxy(1, 25);
	return 0;
}
