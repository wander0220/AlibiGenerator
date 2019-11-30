#include <iostream>
#include <string>
#include "print.h"
#include "menu.h"
#include "infoAndEnd.h"

int makeAlibi() {
	printf("지직 알리바이를 생성중입니다..");
	Sleep(2000);
	screen();

	return 1;
}
int firstScreen() {
	screen();
	int x = 15;
	int y = 10;
	gotoxy(x, y);
	cout << " 알리바이가 처음이십니까?";
	gotoxy(x, y + 1);
	cout << " 예";
	gotoxy(x , y + 2);
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
	int passwd = 0;

	if (file == 11) {
		screen();
		gotoxy(15, 10);
		cout << "비밀번호를 설정해주세요. >>";
		cin >> passwd;
		cout << "비밀번호가 생성되었습니다";
	}
	else if (file != 12) {
		cout << "엥 어떻게 여길 들어오셨나요?? 잘못 들어오셨습니다.\n* 메뉴화면으로 넘어가겠습니다.";
	}
}
int main() {

	setPassWd();

	while (1) {
		int menu = menuDraw();
		if (menu == 15) {
			int mA=makeAlibi();
			if (mA == 1)break;
		}
		else if (menu == 16) {
			
		}
		else if (menu == 17) {
			infoGenerator();
			getchar();
			system("cls");
		}
		else if (menu == 18) {
			endAlibi();
			break;
		}
		else {
			printf("잘못 누르셨습니다. \n 엔터를 누르면 메뉴가 다시 나옵니다");
			getchar();
			system("cls");
		}
	}
	return 0;
}
