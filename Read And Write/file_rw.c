//	file_rw.c -- opens a file for reading (change project config settings for testing vs running)
#include <stdio.h>
#include "file_utils.h"


int main(void) {
	const char* data = "First line of test data.\nSecond line of test data.\nThird line of test data.";
	write_file("temp.txt", data);
	return 0;
}
