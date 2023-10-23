#include <Windows.h>
#include "resource.h"


CONST CHAR g_sz_LOGIN_INVITATION[] = "������� ��� ������������";
CONST CHAR g_sz_PASSWORD_INVITATION[] = "������� ������";


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
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2));
		SendMessage(hwnd, WM_SETICON, 0, (LRESULT)hIcon);
		SetFocus(GetDlgItem(hwnd, IDC_EDIT_PASSWORD));

		HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_LOGIN_INVITATION);
	}
		break;


	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			if (HIWORD(wParam) == EN_SETFOCUS && strcmp(sz_buffer, g_sz_LOGIN_INVITATION) == 0) {
				SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
			}
			if (HIWORD(wParam) == EN_KILLFOCUS && strcmp(sz_buffer, "") == 0) {
				SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_LOGIN_INVITATION);
			}
		}
		break;

		case IDC_EDIT_PASSWORD:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			SendMessage(hEditPassword, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			if (HIWORD(wParam) == EN_SETFOCUS && strcmp(sz_buffer, g_sz_PASSWORD_INVITATION) == 0) {
				SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)"");
			}
			if (HIWORD(wParam) == EN_KILLFOCUS && strcmp(sz_buffer, "") == 0) {
				SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)g_sz_PASSWORD_INVITATION);
			}
		}
			break;

		case IDC_BUTTON_COPY:
		{
			// (1) - ������ ����� ������:
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};

			// (2) - �������� ���������� ��������� �����:
			HWND hLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);

			// ������� GetDlgItem()
			// �� ID-������� ��������� ���� ���������� HWND ���������������� ��������� ����

	  // (3) - ������ ����� �� ��������� ���� 'Login':
			SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);

			// (4) - ��������� ���������� ���������� ������ � ���� 'Password':
			SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);

			// (���� ��������)
			// {
			//  HWND hPassword_Name = GetDlgItem(hwnd, IDC_STATIC_PASSWORD);
			//  SendMessage(hPassword_Name, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			// }

		}
		break;

		case IDOK:
			MessageBox
			(
				hwnd,
				"���� ������ ������ ��",
				"Info",
				MB_OK | MB_ICONINFORMATION
			);
			break;

		case IDCANCEL:
			EndDialog(hwnd, 0);
			break;
		}
		break;

	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	}

	return FALSE;
}