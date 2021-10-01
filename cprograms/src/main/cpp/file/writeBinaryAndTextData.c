#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[] = { 2, 3, 4 };

	//--------------------------------------------writing binary data start
	//  FILE *__cdecl fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
	char *filename_bin = "myfile.bin";
	FILE *pFile = fopen(filename_bin, "wb");
	if (pFile == NULL) {
		printf("Open %s failed!", filename_bin);
		exit(1);
	}
	//  size_t  fwrite(const void *  _Str,size_t _Size,size_t _Count,FILE * _File);
	fwrite(arr, sizeof(int), sizeof(arr) / sizeof(int), pFile);
	fclose(pFile);
	//--------------------------------------------writing binary data end

	//--------------------------------------------writing text data start
	char *filename_text = "myfile.txt";
	pFile = fopen(filename_text, "w");
	if (pFile == NULL) {
		printf("Open %s failed!", filename_bin);
		exit(1);
	}
	fwrite(arr, sizeof(int), sizeof(arr) / sizeof(int), pFile);
	fclose(pFile);
	//--------------------------------------------writing text data end

	//--------------------------------------------writing format data start
	char *filename_format = "../test/myfile.format";
	pFile = fopen(filename_format, "w");
	if (pFile == NULL) {
		printf("Open %s failed!", filename_bin);
		exit(1);
	}
	char ch = 0x7D, *pChar = &ch;
	fwrite(pChar, sizeof(char), 1, pFile);
	fprintf(pFile, "%d", *pChar);
	fclose(pFile);
	//--------------------------------------------writing format data end
	return 0;
}
