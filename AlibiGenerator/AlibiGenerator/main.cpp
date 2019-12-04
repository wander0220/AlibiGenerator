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
	cout << "비밀번호를 입력해주세요 >>";
	cin >> Upasswd;

	if (Upasswd != passwd) {
		gotoxy(5, 10);
		cout << "당신은 칩입자--!!!! 저희는 이용자를 우선시합니다.";
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
		cout << "알리바이를 추가하겠습니다.\n";
		cout << "*누가>>";
		cin >> who;
		cout << "*언제>>";
		cin >> when;
		cout << "*어디서>>";
		cin >> where;
		cout << "*무엇을>>";
		cin >> what;
		cout << "*어떻게>>";
		cin >> how;
		cout << "*왜>>";
		cin >> why;
	}

	ofstream fout("data.txt",ios::app);

	if (!fout) {
		return 1;
	}

	fout << who << setw(10) << when << setw(10) << where << setw(10)
		<< what << setw(10) << how << setw(10) << why << endl;
	cout << "저장되었습니다.";
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
	cout << "누가\t언제\t어디서\t무엇을\t어떻게\t왜\n";
	cout << "*======================================\n";
	
	string empNum;

	while (fin >> who>> when>> where>> what>> how>> why)
	{
		cout <<"*"<<who << setw(10) << when << setw(10) << where << setw(10)
			<< what << setw(10) << how << setw(10) << why << endl;
	}
	fin.close();
	
	
	gotoxy(2, 21);
	cout << " 상황을 추가하시겠습니까?? (y/n) >>";
	cin >> c;
	if (c == 'y') {
		int addResult = addAlibi();
		if (addResult == 1) {
			cout << "알리바이 상황 추가에 실패하셨습니다..." << endl;
			cout << "메뉴화면으로 돌아갑니다.";
			_getch();
		}
	}
	else if (c == 'n') {
		cout << "엔터키를 누르면 메뉴로 돌아갑니다.";
		_getch();
	}
	else {
		cout << "뭐노 다른거로 돌아간다 이넘아.";
	}
}
int makeAlibi() {
	ConfirmPassword();
	
	{
		screen();
		gotoxy(10, 10);
		printf("지직 알리바이를 생성중입니다..");
		Sleep(300);
		gotoxy(15, 12);
		cout << "●○○○○";
		Sleep(300);
		gotoxy(15, 12);
		cout << "●●○○○";
		Sleep(300);
		gotoxy(15, 12);
		cout << "●●●○○";
		Sleep(300);
		gotoxy(15, 12);
		cout << "●●●●○";
		Sleep(300);
		gotoxy(15, 12);
		cout << "●●●●●";
	}

	screen();

	while (1) {
		gotoxy(2, 2);
		cout << "누가\t언제\t어디서\t무엇을\t어떻게\t왜\n";
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
			printf("잘못 누르셨습니다. \n 엔터를 누르면 메뉴가 다시 나옵니다");
			_getch();
			system("cls");
		}
	}
	return 0;
}
