#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>


using namespace::std;
int main()
{
	fstream in(".//CommandList.txt");
	if (!in)
	{
		cout << "无法打开输入文件！" << endl;
		return -1;
	}
	string line;
	getline(in, line);
	//run exe
	while (getline(in, line))
	{
		PROCESS_INFORMATION pi;
		STARTUPINFO si = { sizeof(si) };
		wstring widstr;
		widstr = std::wstring(line.begin(), line.end());
		LPWSTR commandLine = (LPWSTR)widstr.c_str();
		CreateProcess(commandLine, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
	}
	//set date
	SYSTEMTIME time;
	GetLocalTime(&time);
	string date = to_string(time.wYear) + "\\" + to_string(time.wMonth) + "\\" + to_string(time.wDay);
	ofstream out;
	out.open(".//CommandList.txt", ios::in);
	out.seekp(32, ios::beg);
	out.write(date.c_str(), 10);
	out.close();
	return 0;
}