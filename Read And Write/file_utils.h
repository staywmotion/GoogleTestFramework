// file_utils.h -- contains metho ddeclarations for files
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#define LINE_SIZE 255

	int read_file(const char* source);
	int write_file(const char* destination, const char* data);
	int append_file(const char* destination, const char* data);

#ifdef __cplusplus
}
#endif

#endif
