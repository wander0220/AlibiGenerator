#pragma once
#include "print.h"
static int MenuCount = 0;

void printchar() {
	int x = 10, y = 6;
	/*cout << "      **      **  **  *******    **" << endl;
	cout << "     ****     **      **   ***     " << endl;
	cout << "    **  **    **  **  *******    **" << endl;
	cout << "   ********   **  **  *******    **" << endl;
	cout << "  **      **  **  **  **   ***   **" << endl;
	cout << " **        ** **  **  *******    **" << endl;*/

	gotoxy(x, y);
	cout << "      ** " << endl;
	gotoxy(x, ++y);
	cout << "     ****" << endl;
	gotoxy(x, ++y);
	cout << "    **  ** " << endl;
	gotoxy(x, ++y);
	cout << "   ******** " << endl;
	gotoxy(x, ++y);
	cout << "  **      ** " << endl;
	gotoxy(x, ++y);
	cout << " **        **" << endl;

	Sleep(500);
	x = 23, y = 5;
	gotoxy(x, ++y);
	cout << "** " << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;

	Sleep(500);
	x = 26, y = 5;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "  " << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;

	Sleep(500);
	x = 29, y = 5;
	gotoxy(x, ++y);
	cout << "*******" << endl;
	gotoxy(x, ++y);
	cout << "**    ***" << endl;
	gotoxy(x, ++y);
	cout << "*******" << endl;
	gotoxy(x, ++y);
	cout << "*******" << endl;
	gotoxy(x, ++y);
	cout << "**   ***" << endl;
	gotoxy(x, ++y);
	cout << "*******" << endl;

	Sleep(500);
	x = 40, y = 5;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "  " << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;
	gotoxy(x, ++y);
	cout << "**" << endl;

}
void printchar2() {
	int x = 10, y = 6;
	gotoxy(x, y);
	cout << "      **      **  **  *******    **" << endl;
	gotoxy(x, ++y);
	cout << "     ****     **      **   ***     " << endl;
	gotoxy(x, ++y);
	cout << "    **  **    **  **  *******    **" << endl;
	gotoxy(x, ++y);
	cout << "   ********   **  **  *******    **" << endl;
	gotoxy(x, ++y);
	cout << "  **      **  **  **  **   ***   **" << endl;
	gotoxy(x, ++y);
	cout << " **        ** **  **  *******    **" << endl;
}
int menuDraw() {
	screen();

	int x = 20;
	int y = 15;
	gotoxy(x, y);
	cout << " �˸����� �����ϱ�";
	gotoxy(x, y + 1);
	cout << " ������ ��Ȳ��";
	gotoxy(x, y + 2);
	cout << " ������ ����";
	gotoxy(x, y + 3);
	cout << " ������ ����";

	MenuCount++;
	if (MenuCount == 1) {
		printchar();
	}
	else if (MenuCount != 0) {
		printchar2();
	}

	gotoxy(x - 2, y - 1);
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP:
			if (y > 15) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 18) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		case SUBMIT:
			return y;
		} //switch
	} //while

	return 0;
}