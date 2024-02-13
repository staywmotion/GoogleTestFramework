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
		return -2;
	}

	fclose(infile);
	return 0;
}

int append_file(const char* destination, const char* data) {
	FILE* o_file = fopen(destination, "a");
	if(!o_file) {
		perror("Error opening file!\n");
		return -1;
	}
	if(fputs(data, o_file) == EOF) {
		perror("Error writing to file");
		fclose(o_file);
		return -2;
	}
	fclose(o_file);
	return 0;
}

int write_file(const char* destination, const char* data) {
	FILE* o_file = fopen(destination, "w");
	if (!o_file) {
		perror("Error opening file!\n");
		return -1;
	}
	if (fputs(data, o_file) == EOF) {
		perror("Error writing to file");
		fclose(o_file);
		return -2;
	}
	fclose(o_file);
	return 0;
}