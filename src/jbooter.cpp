#include <windows.h>

void startupJava();
void createJavaProcess();

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow){
	startupJava();
	return 0;
}



void startupJava(){ 
	createJavaProcess();
}


void createJavaProcess(){
	BOOL IsFileCommond = false;
	int ShowType = SW_SHOWMAXIMIZED;
	
	char exe[MAX_PATH + 1];
    GetCurrentDirectory(MAX_PATH, exe);      
	strcat(exe,"\\jre\\bin\\javaw.exe");


	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);
	si.wShowWindow=ShowType;
	si.dwFlags=STARTF_USESHOWWINDOW;
	CreateProcess(exe, " -jar .\\startup.jar ",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
}