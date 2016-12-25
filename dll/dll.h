#include <stdio.h>
#include <wchar.h>
#include <iostream>
#include <cmath>

using namespace std;

extern "C++" __declspec(dllexport) wchar_t* Demo() {
	wchar_t* buf = new wchar_t[20];
	DWORD mask = GetLogicalDrives();
	wchar_t* buf2 = new wchar_t[2000];
	buf2[0] = '\0';
	wcscat_s(buf2,2000,L"Функция из dll: \n");
	int i = 0;
	while (mask != 0)
	{
		if (mask & 1 == 1) // проверка, что итый бит маски равен 1
		{
			buf[0] = 'a' + i;
			buf[1] = '\0';
			wcscat_s(buf, 20, L":\\");
			if (GetDiskFreeSpaceEx(buf, NULL, NULL, NULL))
			{
				wcscat_s(buf2, 2000, buf); //   диск 
				wcscat_s(buf2, 2000, L"\t"); //   диск 
			}
		}
		i++;
		mask = mask / 2;
	}
	// Выводим на экран переданную функции Demo строку
	return buf2;
}