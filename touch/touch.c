#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("usage: touch <file name>");
		return 1;
	}

	FILE* file = fopen(argv[1], "w");
	fclose(file);

	return 0;
}