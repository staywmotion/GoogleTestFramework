// file_utils.c -- implemtation of function prototypes
#include "file_utils.h"
#include <stdio.h>

/* Read from a file line by line and output to stdo */
int read_file(const char* source) {
	FILE* infile = fopen(source, "r");
	if (!infile) {
		perror("Error opening file!\n");
		return -1;
	}

	char line[LINE_SIZE];
	while (fgets(line, LINE_SIZE, infile)) {
		printf("%s", line);
	}

	if (ferror(infile)) {
		perror("Error reading file");
		fclose(infile);
		return -1;
	}

	fclose(infile);
	return 0;
}