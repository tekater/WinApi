#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include"resource.h"
#include <vector>
#include <string>

CONST CHAR g_sz_WINDOW_CLASS[] = "My Window Class"; // ��� ������ ����

#define IDC_COMBO			1001
#define IDC_BUTTON_APPLY	1002

CONST CHAR* g_CURSOR[] = { "busy.ani" ,"default.ani"};

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

std::vector<std::string> LoadCursorsFromDir(const std::string& directory);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	// ������� ���� �������� � 3 �����:
	//*1 ���� - ����������� ������ ���� :

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	//					//cb - Count Bytes (���-�� ����) 
	wc.cbWndExtra = 0;	// �������������� ����� ����
	wc.cbClsExtra = 0;	// �������������� ����� ������ ����
	wc.style = 0;		// ����� ����

	//wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CPU));
	//wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_RAM)); // Sm - Small
	wc.hIcon = (HICON)LoadImage(hInstance, "amogus.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hIconSm = (HICON)LoadImage(hInstance, "valorant_logo.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	//wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hCursor = LoadCursor(hInstance, (LPCSTR)(LoadCursorFromFile("ncurs.cur")));
	
	wc.hCursor = (HCURSOR)LoadImage(hInstance, "01_normal_select.cur", IMAGE_CURSOR, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	
	//wc.hCursor = LoadCursor(NULL, (LPCSTR)((HCURSOR)LoadCursorFromFile("ncurs.cur")));
	//wc.hCursor = LoadCursorFromFile("ncurs.png");
	//wc.hCursor = SetCursor((HCURSOR)LoadCursorFromFile("ncurs.ico"));
	//wc.hCursor = SetCursor(LoadCursorFromFile("ncurs.cur"));
	wc.hbrBackground = HBRUSH(COLOR_WINDOW + 1);

	wc.hInstance = hInstance; // hInstance - ��� ��������� ������������ ����� ��������� � ������(�����������)
	// ������� WinMain() ��������� hInstance ��� ��������, � ������� � ���� ���� ������ ������,
	// � ����� ������ ������� 'hInstance' ������ ����� �������� ��� ������ ������� GetModuleHandle(NULL)
	wc.lpfnWndProc = WndProc; // ��������� �� ��������� ����
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_sz_WINDOW_CLASS;

	if (!RegisterClassEx(&wc))
	{
		MessageBox
		(
			NULL,
			"Class registration failed",
			"Error",
			MB_OK | MB_ICONERROR
		);
	}


	//*2 ���� - �������� ����:
	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT screen_height = GetSystemMetrics(SM_CYSCREEN);

	//CHAR sz_msg[MAX_PATH]{};
	//sprintf(sz_msg, "Resolution: %ix%i", screen_width, screen_height);
	//MessageBox(NULL, sz_msg, "Screen resolution", MB_OK);

	INT window_width = screen_width * 3 / 4;
	INT window_height = screen_height * 3 / 4;

	INT start_x = screen_width / 8;
	INT start_y = screen_height / 8;

	HWND hwnd = CreateWindowEx
	(
		NULL,							// ExStyle
		g_sz_WINDOW_CLASS,				// Class Name
		g_sz_WINDOW_CLASS,				// Window name
		WS_OVERLAPPEDWINDOW,			// � �������� ���� ������ ����� ����� �����
		start_x, start_y,	// Position - ��������� ���� �� ������
		window_width, window_height,	// Size - ������ ����
		NULL,							//Parent Window
		//---------------------------------------------
		NULL,		// hMenu - ��� �������� ���� ���� �������� �������� ID-������� ����
					// ��� ��������� ����, ������� �������� ��������� ������� ����, � hMenu ���������� ID_�������
		//----------------------------------------------
		hInstance,
		NULL

	);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);


	//3 ���� - ������ ����� ���������:
	MSG msg;
	while(GetMessage(&msg, 0, 0, 0) > 0) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;

}


LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{

	case WM_CREATE:
	{
		HWND hCombo = CreateWindowEx
		(
			NULL,
			"ComboBox",
			"",
			WS_CHILD | WS_VISIBLE | CBN_DROPDOWN | WS_VSCROLL,
			10, 10,
			200, 200,
			hwnd,
			(HMENU)IDC_COMBO,
			GetModuleHandle(NULL),
			NULL
		);
		/*for (int i = 0; i < sizeof(g_CURSOR) / sizeof(g_CURSOR[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)g_CURSOR[i]);
		}*/

		CHAR sz_current_directory[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, sz_current_directory);

		std::vector<std::string> cursors = LoadCursorsFromDir("UniCursor\\*");
		for (int i = 0; i < cursors.size(); i++) 
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)cursors[i].c_str());
		}

		HWND hButton = CreateWindowEx
		(
			NULL,
			"Button",
			"Apply",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			220, 10,
			100, 24,
			hwnd,
			(HMENU)IDC_BUTTON_APPLY,
			GetModuleHandle(NULL),
			NULL
		);
	}
	break;

	case WM_SETCURSOR:
	{
		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO);
			int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);

			CHAR sz_filename[_MAX_PATH]{};
			CHAR sz_filepath[_MAX_PATH] = "UniCursor\\";

			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_filename);
			strcat(sz_filepath, sz_filename);

			//MessageBox(hwnd, sz_filepath, "Info", MB_OK);

			HCURSOR hCursor = (HCURSOR)LoadImage(GetModuleHandle(NULL),
				sz_filepath,
				IMAGE_CURSOR,
				LR_DEFAULTSIZE, LR_DEFAULTSIZE,
				LR_LOADFROMFILE);

			SetCursor(hCursor);
	}
	break;

	case WM_SIZE:
	case WM_MOVE:
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);

		CHAR sz_message[MAX_PATH]{};

		sprintf
		(
			sz_message, "%s - Position: %ix%i, Size: %ix%i", 
			g_sz_WINDOW_CLASS, 
			rect.left, rect.top,
			rect.right-rect.left,rect.bottom-rect.top
		);

		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_message);
	}
	break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		
		case IDC_BUTTON_APPLY:
		{
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO);
			int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);

			CHAR sz_filename[_MAX_PATH]{};
			CHAR sz_filepath[_MAX_PATH] = "UniCursor\\";

			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_filename);
			strcat(sz_filepath, sz_filename);

			//MessageBox(hwnd, sz_filepath, "Info", MB_OK);

			HCURSOR hCursor = (HCURSOR)LoadImage(GetModuleHandle(NULL),
				sz_filepath,
				IMAGE_CURSOR,
				LR_DEFAULTSIZE, LR_DEFAULTSIZE,
				LR_LOADFROMFILE);
			SetClassLong(hwnd, -12, (LONG)hCursor);
			SetClassLong(GetDlgItem(hwnd, IDC_BUTTON_APPLY), GCLP_HCURSOR, (LONG)hCursor);
			SetClassLong(GetDlgItem(hwnd, IDC_COMBO), GCLP_HCURSOR, (LONG)hCursor);
			//SetCursor(hCursor);
			/*SetCursor((HCURSOR)LoadImage(GetModuleHandle(NULL),
				sz_filename,
				IMAGE_CURSOR,
				LR_DEFAULTSIZE, LR_DEFAULTSIZE,
				LR_LOADFROMFILE));*/
			return FALSE;
		}
		}
		break;

	case WM_DESTROY: PostQuitMessage(0); break;
	case WM_CLOSE: DestroyWindow(hwnd); break;

	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return NULL;


}


std::vector<std::string> LoadCursorsFromDir(const std::string& directory)
{
	std::vector<std::string> files;
	WIN32_FIND_DATA data;

	for (
		HANDLE hFind = FindFirstFile(directory.c_str(), &data);
		FindNextFile(hFind, &data);
		)
		// const char* std::string::c_str() ���������� C-string, ���������� � ������� std::string
	{
		if  (
			strcmp(strrchr(data.cFileName, '.'), ".cur") == 0 ||
			strcmp(strrchr(data.cFileName, '.'), ".ani") == 0
			)
		{
		files.push_back(data.cFileName);
		}
	}

	return files;
}