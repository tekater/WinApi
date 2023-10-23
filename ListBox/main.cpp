#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<Windows.h>
#include"resource.h"


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


CONST CHAR* g_sz_FIGHTERS[] = 
{
	"Jin kazama","Katarina","Hwoarang",
	"Akuma","Alisa","Devil Jin" ,
	"Heihachi Mishima","Lars","Paul",
	"Yoshimitsu","Jack","Gigas",
	"Bryan","Lucky Chloe","Raven",
	"Eliza","Nina","Feng Wei"
};


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);

	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam) 
{
	switch (uMsg)
	{

	case WM_INITDIALOG:
	{
		HWND hList = GetDlgItem(hwnd, IDC_LIST1);
		for (int i = 0; i < sizeof(g_sz_FIGHTERS) / sizeof(g_sz_FIGHTERS[0]); i++) {
			SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)g_sz_FIGHTERS[i]);
		}
	}
	break;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{

		case IDOK:
		{
			CONST INT SIZE = 256;

			CHAR sz_buffer[SIZE] = {};
			HWND hList = GetDlgItem(hwnd, IDC_LIST1);

			int i = SendMessage(hList, LB_GETCURSEL, 0, 0);
			SendMessage(hList, LB_GETTEXT, i, (LPARAM)sz_buffer);

			CHAR sz_message[SIZE]{};
			sprintf(sz_message, "Вы выбрали бойца %s, под номером %i", sz_buffer, i);

			MessageBox
			(
				hwnd,
				sz_message,
				"Info",
				MB_OK | MB_ICONINFORMATION
			);
		}
			break;

		case IDCANCEL: EndDialog(hwnd, 0); break;
		}

	case WM_CLOSE: EndDialog(hwnd, 0); break;
	}

	return FALSE;
}