#pragma once
#include <fstream>
#include "print.h"
int firstScreen() {
	screen();
	int x = 15;
	int y = 10;
	gotoxy(x, y);
	cout << " �˸����̰� ó���̽ʴϱ�?";
	gotoxy(x, y + 1);
	cout << " ��";
	gotoxy(x, y + 2);
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
	string passwd;

	if (file == 11) {
		ofstream fout;
		fout.open("passwd.txt");

		screen();
		gotoxy(2, 10);
		cout << "��й�ȣ�� �������ּ���. (�ƹ��ų� 4�ڸ�) >>";
		cin >> passwd;
		gotoxy(5, 11);
		cout << "��й�ȣ�� �����Ǿ����ϴ�";
		fout << passwd;
		_getch();
	}
	else if (file != 12) {
		cout << "�� ��� ���� �����̳���?? �߸� �����̽��ϴ�.\n* �޴�ȭ������ �Ѿ�ڽ��ϴ�.";
	}
}