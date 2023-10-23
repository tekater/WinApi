#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<Windows.h>
#include"resource.h"


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


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
		//HWND hList = GetDlgItem(hwnd, IDC_LIST1);
		/*for (int i = 0; i < sizeof(g_sz_VALUES) / sizeof(g_sz_VALUES[0]); i++) {
			SendMessage(hList, CB_ADDSTRING, 0, (LPARAM)g_sz_VALUES[i]);
		}*/
	}
	break;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{

		case IDOK:
			break;

		case IDCANCEL: EndDialog(hwnd, 0); break;
		}

	case WM_CLOSE: EndDialog(hwnd, 0); break;
	}

	return FALSE;
}