
                   [   ]     v1 Byte = 8 Bit			

             [   ] [   ]    1 Word = 2 Bytes	  	  	   

 [   ] [   ] [   ] [   ]    1 Dword(Double Word) = 4 Bytes
 {  Loword } { HIWORD  }

 Focus - это часть окна которая принимает ?внимание? с клавиатуры.

 hwnd - Handler to Window (Обработчик окна)
 uMsg - unsignedMessage  - сообщение(беззнаковая переменная)
 wParam, lParam - параметры сообщения


 ~Главное окно

  INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
-----// Главное окно создаётся в 3 этапа:
-----//*1 этап - Регистрация класса окна :

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	//					//cb - Count Bytes (Кол-во Байт) 
	wc.cbWndExtra = 0;	// Дополнительные Байты окна
	wc.cbClsExtra = 0;	// Дополнительные Байты класса окна
	wc.style = 0;		// Стиль окна

	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CPU));
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_RAM)); // Sm - Small
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = HBRUSH(COLOR_WINDOW + 1);

	wc.hInstance = hInstance; // hInstance - это экземпляр исполняемого файла программы в памяти(оперативной)
	// Функция WinMain() принимает hInstance как параметр, и поэтому к нему есть прямой доступ,
	// В любой другой функции 'hInstance' всегда можно получить при помощи функции GetModuleHandle(NULL)
	wc.lpfnWndProc = WndProc; // Указатель на процедуру окна
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


-------*2 этап - Создание окна:
	HWND hwnd = CreateWindowEx
	(
		NULL,							// ExStyle
		g_sz_WINDOW_CLASS,				// Class Name
		g_sz_WINDOW_CLASS,				// Window name
		WS_OVERLAPPEDWINDOW,			// У главного окна всегда будет такой стиль
		CW_USEDEFAULT, CW_USEDEFAULT,	// Position - положение окна на экране
		CW_USEDEFAULT, CW_USEDEFAULT,	// Size - Размер окна
		NULL,							//Parent Window
		//---------------------------------------------
		NULL,		// hMenu - для главного окна этот параметр содержит ID-ресурса меню
					// для дочернего окна, которое является элементом другого окна, в hMenu передается ID_ресурса
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


-------3 этап - Запуск цикла сообщений:
	MSG msg;
	while(GetMessage(&msg, 0, 0, 0) > 0) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;

}






-------------------------------------------------------------------------------------
hInstance - это экземпляр исполняемого файла программы в оперативной памяти.
			Если нужно обратиться к exe файлу, то это можно сделать через hInstance.
			hInstance всегда можно получить при помощи функции GetModuleHandle(NULL).


hPrevInst - предыдущий экземпляр программы. Этот параметр давно не используется.

lp - Long Pointer.(указатель в начале)
lpCmdLine - это командная строка, из которой запустилась программа.
			Через эту командную строку в программу можно передать файл, или URL.

n - number.(значение типа int)
nCmdShow  - режим отображения окна, свёрнуто в окно, 
			свернутно в панель задач, развёрнуто на весь экран.
-------------------------------------------------------------------------------------