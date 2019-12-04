#pragma once
#include <fstream>
#include "print.h"
int firstScreen() {
	screen();
	int x = 15;
	int y = 10;
	gotoxy(x, y);
	cout << " 알리바이가 처음이십니까?";
	gotoxy(x, y + 1);
	cout << " 예";
	gotoxy(x, y + 2);
	cout << " 아니요";

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP:
			if (y > 11) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 12) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		case SUBMIT:
			return y;
			break;
		} //switch
	} //while
}
void setPassWd() {
	int file = firstScreen();
	string passwd;

	if (file == 11) {
		ofstream fout;
		fout.open("passwd.txt");

		screen();
		gotoxy(2, 10);
		cout << "비밀번호를 설정해주세요. (아무거나 4자리) >>";
		cin >> passwd;
		gotoxy(5, 11);
		cout << "비밀번호가 생성되었습니다";
		fout << passwd;
		_getch();
	}
	else if (file != 12) {
		cout << "엥 어떻게 여길 들어오셨나요?? 잘못 들어오셨습니다.\n* 메뉴화면으로 넘어가겠습니다.";
	}
}