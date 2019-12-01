#include <windows.h>
#include <stdio.h> 

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
	
	char exe[MAX_PATH + 1];
    GetCurrentDirectory(MAX_PATH, exe);
	

	char paramsConf[MAX_PATH + 1];
	GetCurrentDirectory(MAX_PATH, paramsConf);      
	strcat(paramsConf,"\\bin\\params.txt");
 
	char * trimPointer = NULL;
	FILE *fp = fopen(paramsConf,"r");
	char bin[MAX_PATH];	
	fgets(bin,MAX_PATH,fp);
	
	trimPointer = strchr(bin, '\r'); 
	if(trimPointer){
		*trimPointer = '\0';  
	}
	trimPointer = strchr(bin, '\n'); 
	if(trimPointer){
		*trimPointer = '\0';  
	}
	
	strcat(exe,bin);

	char params[MAX_PATH];	
	fgets(params,MAX_PATH,fp);
	
	trimPointer = strchr(params, '\r'); 
	if(trimPointer){
		*trimPointer = '\0';  
	}
	trimPointer = strchr(params, '\n'); 
	if(trimPointer){
		*trimPointer = '\0';  
	}
	
	fclose(fp);

	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);
	si.wShowWindow=SW_SHOW;
	si.dwFlags=STARTF_USESHOWWINDOW;
	CreateProcess(exe, params,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
}
