//	file_rw.c -- opens a file for reading (change project config settings for testing vs running)
#include <stdio.h>
#include "file_utils.h"


int main(void) {
	int result = read_file("temp.txt");
	return 0;
}
