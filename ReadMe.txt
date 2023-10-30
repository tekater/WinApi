
                   [   ]     v1 Byte = 8 Bit			

             [   ] [   ]    1 Word = 2 Bytes	  	  	   

 [   ] [   ] [   ] [   ]    1 Dword(Double Word) = 4 Bytes
 {  Loword } { HIWORD  }

 Focus - ��� ����� ���� ������� ��������� ?��������? � ����������.

 hwnd - Handler to Window (���������� ����)
 uMsg - unsignedMessage  - ���������(����������� ����������)
 wParam, lParam - ��������� ���������


 ~������� ����

  INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
-----// ������� ���� �������� � 3 �����:
-----//*1 ���� - ����������� ������ ���� :

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	//					//cb - Count Bytes (���-�� ����) 
	wc.cbWndExtra = 0;	// �������������� ����� ����
	wc.cbClsExtra = 0;	// �������������� ����� ������ ����
	wc.style = 0;		// ����� ����

	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CPU));
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_RAM)); // Sm - Small
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
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


-------*2 ���� - �������� ����:
	HWND hwnd = CreateWindowEx
	(
		NULL,							// ExStyle
		g_sz_WINDOW_CLASS,				// Class Name
		g_sz_WINDOW_CLASS,				// Window name
		WS_OVERLAPPEDWINDOW,			// � �������� ���� ������ ����� ����� �����
		CW_USEDEFAULT, CW_USEDEFAULT,	// Position - ��������� ���� �� ������
		CW_USEDEFAULT, CW_USEDEFAULT,	// Size - ������ ����
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


-------3 ���� - ������ ����� ���������:
	MSG msg;
	while(GetMessage(&msg, 0, 0, 0) > 0) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;

}






-------------------------------------------------------------------------------------
hInstance - ��� ��������� ������������ ����� ��������� � ����������� ������.
			���� ����� ���������� � exe �����, �� ��� ����� ������� ����� hInstance.
			hInstance ������ ����� �������� ��� ������ ������� GetModuleHandle(NULL).


hPrevInst - ���������� ��������� ���������. ���� �������� ����� �� ������������.

lp - Long Pointer.(��������� � ������)
lpCmdLine - ��� ��������� ������, �� ������� ����������� ���������.
			����� ��� ��������� ������ � ��������� ����� �������� ����, ��� URL.

n - number.(�������� ���� int)
nCmdShow  - ����� ����������� ����, ������� � ����, 
			��������� � ������ �����, ��������� �� ���� �����.
-------------------------------------------------------------------------------------