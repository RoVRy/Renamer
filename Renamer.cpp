// Renamer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "time.h"
#include "stdlib.h"

#define WIN32_LEAN_AND_MEAN

int _tmain(int argc, TCHAR* argv[])
{
	if (argc == 1)
	{
		printf("Specify filename as single argument\n");
		return -1;
	}
	char srcname[257] = "";
	char dstname[257] = "";
	CharToOem(argv[1], srcname);
	strcpy(dstname, srcname);
	char *dot = strchr(srcname, (int)'.');
	int dotpos = (dot == NULL) ? strlen(srcname) : (int)(dot - srcname);
	srand((unsigned)time(NULL));
	char j;
	for (int i = 0; i < dotpos; i++)
	{
         j = 48 + 36 * ((double)rand() / (RAND_MAX + 1));
		 if (j > 57) j += 39;
		 dstname[i] = j;
	}
	int result = rename(srcname, dstname);
	if (result == 0) printf("File successfully renamed!\n");
		else printf("Renaming failed\n");
}

