#include <Windows.h>

INT WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow) 
{
	MessageBox
	(
		NULL,
		"Hello Windows,\nHello world!!!",
		"Header",
		MB_YESNOCANCEL | MB_ICONINFORMATION | MB_HELP |
		MB_DEFBUTTON3 |
		MB_SYSTEMMODAL
	);

	MessageBox
	(
		NULL,
		
		"  ___.-''''-.\n/ ___  @ | \n',,,,.     |         _.'''''''._\n      '     |        /           \\\n      |     \\    _.-'             \\\n      |      '.-'                  '-.\n      |                               ',\n      |                                '',\n      ',,-,                           ':;\n           ',,| ;,,                 ,' ;;\n              ! ; !'',,,',',,,,'!  ;   ;:\n             : ;  ! !       ! ! ;  ;   :;\n             ; ;   ! !      ! !  ; ;   ;,\n            ; ;    ! !     ! !   ; ;\n            ; ;    ! !    ! !     ; ;\n           ;,,      !,!   !,!     ;,;\n           /_I      L_I   L_I     /_I\n",
		"Camel",
		MB_OK
	);


	MessageBox
	(
		NULL,
		"                                        _\n                                    ,-\"\" \"\".\n                                  ,'  ____  `.\n                                ,'  ,'    `.  `._\n       (`.         _..--.._   ,'  ,'        \\    \\\n      (`-.\\    .-\"\"        \"\"'   /          (  d _b\n     (`._  `-\"\" ,._             (            `-(   \\\n     <_  `     (  <`<            \\              `-._\\\n      <`-       (__< <           :\n       (__        (_<_<          ; \n       `------------------------------------------ \n",
		"Goose",
		MB_OK
	);

	MessageBox
	(
		NULL,
		"             ,\n            /|      __\n           / |   ,-~ /\n          Y :|  //  /\n          | jj /( .^\n          >-\"~\"-v\"\n         /       Y\n        jo  o    |\n       ( ~T~     j\n        >._-' _./\n       /   \"~\"  |\n      Y     _,  |\n     /| ;-\"~ _  l\n    / l/ ,-\"~    \\\n    \\//\\/      .- \\\n     Y        /    Y\n     l       I     !\n     ]\\      _\\    /\"\\\n    (\" ~----( ~   Y.  )\n",
		"Rabbit",
		MB_OK
	);

	MessageBox
	(
		NULL,
		"_________________               _________________\n     ~-.              \\  |\\___/|  /              .-~\n         ~-.           \\ / o o \\ /           .-~\n            >           \\  W  //           <\n           /             /~---~\\             \\\n          /_             |       |            _\\\n             ~-.        |       |        .-~\n                ;         \\      /         i\n               /___      /\\   /\\      ___\\\n                    ~-. /  \\_/  \\ .-~\n                       V           V\n",
		"Bat",
		MB_OK
	);

	return 0;
}