#include <windows.h>
#include <iomanip>
#include "print.h"
#include "menu.h"
#include "infoAndEnd.h"
#include "SetPassWd.h"
#include "AlibiList.h"

void ConfirmPassword() {
	ifstream fin;
	fin.open("passwd.txt");
	string passwd;
	string Upasswd;
	fin >> passwd;

	screen();
	gotoxy(8, 10);
	cout << "��й�ȣ�� �Է����ּ��� >>";
	cin >> Upasswd;

	if (Upasswd != passwd) {
		gotoxy(5, 10);
		cout << "����� Ĩ����--!!!! ����� �̿��ڸ� �켱���մϴ�.";
		_getch();
		exit(0);
	}

	fin.close();
}
int addAlibi() {

	string who,when,where,what,how,why;

	{
		screen();
		gotoxy(2, 2);
		cout << "�˸����̸� �߰��ϰڽ��ϴ�.\n";
		cout << "*����>>";
		cin >> who;
		cout << "*����>>";
		cin >> when;
		cout << "*���>>";
		cin >> where;
		cout << "*������>>";
		cin >> what;
		cout << "*���>>";
		cin >> how;
		cout << "*��>>";
		cin >> why;
	}

	ofstream fout("data.txt",ios::app);

	if (!fout) {
		return 1;
	}

	fout << who << setw(10) << when << setw(10) << where << setw(10)
		<< what << setw(10) << how << setw(10) << why << endl;
	cout << "����Ǿ����ϴ�.";
	_getch();
	
	return 0;
}
void showAlibiList() {

	string who, when, where, what, how, why;

	ifstream fin;
	fin.open("data.txt");

	char c;
	ConfirmPassword();

	gotoxy(2, 2);
	cout << "����\t����\t���\t������\t���\t��\n";
	cout << "*======================================\n";
	
	string empNum;

	while (fin >> who>> when>> where>> what>> how>> why)
	{
		cout <<"*"<<who << setw(10) << when << setw(10) << where << setw(10)
			<< what << setw(10) << how << setw(10) << why << endl;
	}
	fin.close();
	
	
	gotoxy(2, 21);
	cout << " ��Ȳ�� �߰��Ͻðڽ��ϱ�?? (y/n) >>";
	cin >> c;
	if (c == 'y') {
		int addResult = addAlibi();
		if (addResult == 1) {
			cout << "�˸����� ��Ȳ �߰��� �����ϼ̽��ϴ�..." << endl;
			cout << "�޴�ȭ������ ���ư��ϴ�.";
			_getch();
		}
	}
	else if (c == 'n') {
		cout << "����Ű�� ������ �޴��� ���ư��ϴ�.";
		_getch();
	}
	else {
		cout << "���� �ٸ��ŷ� ���ư��� �̳Ѿ�.";
	}
}
int makeAlibi() {
	ConfirmPassword();
	
	{
		screen();
		gotoxy(10, 10);
		printf("���� �˸����̸� �������Դϴ�..");
		Sleep(300);
		gotoxy(15, 12);
		cout << "�ܡۡۡۡ�";
		Sleep(300);
		gotoxy(15, 12);
		cout << "�ܡܡۡۡ�";
		Sleep(300);
		gotoxy(15, 12);
		cout << "�ܡܡܡۡ�";
		Sleep(300);
		gotoxy(15, 12);
		cout << "�ܡܡܡܡ�";
		Sleep(300);
		gotoxy(15, 12);
		cout << "�ܡܡܡܡ�";
	}

	screen();

	while (1) {
		gotoxy(2, 2);
		cout << "����\t����\t���\t������\t���\t��\n";
		cout << "\n*======================================";
		
		_getch();
		break;
	}


	return 1;
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
			showAlibiList();
		}
		else if (menu == 17) {
			infoGenerator();
		}
		else if (menu == 18) {
			endAlibi();
			break;
		}
		else {
			printf("�߸� �����̽��ϴ�. \n ���͸� ������ �޴��� �ٽ� ���ɴϴ�");
			_getch();
			system("cls");
		}
	}
	return 0;
}
