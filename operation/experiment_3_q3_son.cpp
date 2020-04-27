#include <Windows.h>
#include <iostream>


using namespace std;
int main()
{
	HANDLE hPipeRead = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hPipeWrite = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwRead;
	char strbuf[10];
	while (ReadFile(hPipeRead, strbuf, 10, &dwRead, NULL))
	{
		printf_s("%s   ", strbuf);
	}
}