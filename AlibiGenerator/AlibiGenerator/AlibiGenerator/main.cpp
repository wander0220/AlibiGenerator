#include <iostream>
#include <string>
#include "print.h"
#include "menu.h"
#include "infoAndEnd.h"

int makeAlibi() {
	printf("���� �˸����̸� �������Դϴ�..");
	Sleep(2000);
	screen();

	return 1;
}
int firstScreen() {
	screen();
	int x = 15;
	int y = 10;
	gotoxy(x, y);
	cout << " �˸����̰� ó���̽ʴϱ�?";
	gotoxy(x, y + 1);
	cout << " ��";
	gotoxy(x , y + 2);
	cout << " �ƴϿ�";

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
		cout << "��й�ȣ�� �������ּ���. >>";
		cin >> passwd;
		cout << "��й�ȣ�� �����Ǿ����ϴ�";
	}
	else if (file != 12) {
		cout << "�� ��� ���� �����̳���?? �߸� �����̽��ϴ�.\n* �޴�ȭ������ �Ѿ�ڽ��ϴ�.";
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
			printf("�߸� �����̽��ϴ�. \n ���͸� ������ �޴��� �ٽ� ���ɴϴ�");
			getchar();
			system("cls");
		}
	}
	return 0;
}
