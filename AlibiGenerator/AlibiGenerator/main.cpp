#include <iostream>
#include <string>
//gotoxy��
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
	cout << "�˶���� ������" << endl;
	gotoxy(13, 7);
	cout << "���Ѵ�" << endl;
	gotoxy(13,10);
	cout << "������" << endl;
	
}
int main() {
	screen();
	gotoxy(1, 25);
	return 0;
}
