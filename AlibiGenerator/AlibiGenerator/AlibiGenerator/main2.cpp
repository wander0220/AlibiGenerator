#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#define UP  72
#define DOWN 80
#define SUBMIT 32
using namespace std;

void gotoxy(int x, int y) {
	COORD pos = { x - 1 ,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int menuDraw();
void screen();

int main() {
	screen();
	gotoxy(1, 25);

	

	return 0;
}


void screen() {
	cout << "***************************************" << endl;
	for (int i = 0; i < 15; i++) {
		cout << "*                                       *" << endl;
	}
	cout << "***************************************" << endl;

	menuDraw();
}

int menuDraw() {
	int x = 14;
	int y = 6;
	gotoxy(x - 2, y);
	cout << " 알리바이 생성하기";
	gotoxy(x, y + 1);
	cout << " 생성기 정보";
	gotoxy(x, y + 2);
	cout << " 생성기 종료";
	
	return 0;
}