#include <Windows.h>

INT WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow) 
{

	MessageBox
	(
		NULL,
		
		"  ___.-''''-.\n/ ___  @ | \n',,,,.     |         _.'''''''._\n      '     |        /           \\\n      |     \\    _.-'             \\\n      |      '.-'                  '-.\n      |                               ',\n      |                                '',\n      ',,-,                           ':;\n           ',,| ;,,                 ,' ;;\n              ! ; !'',,,',',,,,'!  ;   ;:\n             : ;  ! !       ! ! ;  ;   :;\n             ; ;   ! !      ! !  ; ;   ;,\n            ; ;    ! !     ! !   ; ;\n            ; ;    ! !    ! !     ; ;\n           ;,,      !,!   !,!     ;,;\n           /_I      L_I   L_I     /_I\n",
		"Header",
		MB_YESNOCANCEL | MB_ICONINFORMATION | MB_HELP |
		MB_DEFBUTTON3  |
		MB_SYSTEMMODAL
	);


	return 0;
}