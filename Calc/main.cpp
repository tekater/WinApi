#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include<cstdio>

#include "resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LRESULT)hIcon);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{

		case IDC_BUTTON_PLUS:
		{
			SendMessage(GetDlgItem(hwnd, IDC_STATIC_Z), WM_SETTEXT, 1, (LPARAM)"+");
		}
		break;
		case IDC_BUTTON_MINUS:
		{
			SendMessage(GetDlgItem(hwnd, IDC_STATIC_Z), WM_SETTEXT, 1, (LPARAM)"-");
		}
		break;
		case IDC_BUTTON_MULT:
		{
			SendMessage(GetDlgItem(hwnd, IDC_STATIC_Z), WM_SETTEXT, 1, (LPARAM)"*");
		}
		break;
		case IDC_BUTTON_DEL:
		{
			SendMessage(GetDlgItem(hwnd, IDC_STATIC_Z), WM_SETTEXT, 1, (LPARAM)"/");
		}
		break;

		case IDC_BUTTON_ANS:
		{
			CONST INT SIZE = 256;

			CHAR sz_buffer_ANS[SIZE] = {};

			UINT A = GetDlgItemInt(hwnd, IDC_EDIT_NUM1, FALSE, FALSE);
			UINT B = GetDlgItemInt(hwnd, IDC_EDIT_NUM2, FALSE, FALSE);

			CHAR Z[SIZE] = {};

			SendMessage(GetDlgItem(hwnd, IDC_STATIC_Z), WM_GETTEXT, SIZE, (LPARAM)Z);

			if ((LPARAM)Z == (LPARAM)"+")
			{
				sprintf(sz_buffer_ANS, "%i", (A + B));
			}
			if ((LPARAM)Z == (LPARAM)"-")
			{
				sprintf(sz_buffer_ANS, "%d", (A - B));
			}
			if ((LPARAM)Z == (LPARAM)"*")
			{
				sprintf(sz_buffer_ANS, "%d", (A * B));
			}
			if ((LPARAM)Z == (LPARAM)"/")
			{
				sprintf(sz_buffer_ANS, "%d", (A / B));
			}
			sprintf(sz_buffer_ANS, "%i", (A + B));
			
			MessageBox(hwnd, Z, "ok", MB_OK);
			SendMessage(GetDlgItem(hwnd, IDC_STATIC_ANS), WM_SETTEXT, SIZE, (LPARAM)sz_buffer_ANS);

		}
		break;
		}
		break;
		case IDOK:
			break;

		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
	
	case WM_CLOSE: EndDialog(hwnd, 0); break;
	}


	return FALSE;
	
}
