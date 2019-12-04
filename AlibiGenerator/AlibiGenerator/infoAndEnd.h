#pragma once
#include "print.h"
void infoGenerator() {
	screen();
	gotoxy(2, 2);
	cout << "생성기 사용방법!";
	gotoxy(2, 3);
	cout << " 메뉴에서 알리바이 생성하기로 들어가세요 ->\n* 생성한 후 마음에 들지 않는 부분을 고치세요"
		<< "\n* 더 다양한 알리바이 상황을 만들고 싶다면 \n* 정보에서 추가후 저장해 주세요"
		<< "\n* 처음 뜨는 상황들은 기본 상황 입니다.";

	gotoxy(2, 9);
	cout << "기획 의도..." << "\n* 변명이란 최악의 상황을 피하기위해 쓰는\n* 차선의 얘기라 생각합니다. "
		<< "\n* 그 차선을 위해 저희가 만들어 드리고 싶었습니다..." << endl;

	gotoxy(2, 13);
	cout << "비밀번호는 마지막으로 설정한 것으로 로그인해주세요." << endl;

	gotoxy(2, 21);
	cout << "이 메뉴를 마치려면 enter키를 누르시오...";
	_getch();
}
void endAlibi() {
	screen();
	gotoxy(2, 3);
	cout<<"알리바이 생성기 종료쓰... 잘가랏 뻥잘치구... ";
	gotoxy(8, 10);
	cout << ">> push enter to exit <<";
	_getch();
	system("cls");
}