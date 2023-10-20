#include <Windows.h>
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
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2));
		SendMessage(hwnd, WM_SETICON, 0, (LRESULT)hIcon);
		SetFocus(GetDlgItem(hwnd, IDC_EDIT_PASSWORD));
		//SetFocus(GetDlgItem(hwnd, IDC_EDIT_LOGIN));
		//SetFocus(GetDlgItem(hwnd, IDOK));

		if (GetFocus() == GetDlgItem(hwnd, IDC_EDIT_LOGIN)) {
			SendMessage(GetDlgItem(hwnd, IDC_EDIT_LOGIN), WM_SETTEXT, 0, (LPARAM)"");
		}
		else {
			SendMessage(GetDlgItem(hwnd, IDC_EDIT_LOGIN), WM_SETTEXT, 0, (LPARAM)"Введите логин");
		}

	}
		break;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{

		case IDC_BUTTON_COPY:
		{
			// (1) - Создаём буфер чтения:
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};

			// (2) - Получаем обработчик текстовых полей:
			HWND hLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			
			      // Функция GetDlgItem()
			      // по ID-ресурса дочернего окна возвращает HWND соответствующего дочернего окна

		    // (3) - Читаем текст из текствого поля 'Login':
			SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);

			// (4) - Загружаем содержимое текстового буфера в поле 'Password':
			SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);

			// (Мини проверка)
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
				"Была нажата кнопка ОК",
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
