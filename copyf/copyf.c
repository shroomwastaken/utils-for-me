#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc < 3) {
		printf("usage: copyf <file to copy> <file to copy to>\n");
		return 1;
	}

	FILE* file = fopen(argv[1], "rb");
	if (file == NULL) {
		printf("something went wrong when opening file.\n");
		return 1;
	}

	FILE* copy = fopen(argv[2], "wb");
	if (copy == NULL) {
		printf("something went wrong when creating file.\n");
		fclose(file);
		return 1;
	}

	printf("copying...\n");

	char buffer[1024];
	int bytesRead;
	while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
		fwrite(buffer, 1, bytesRead, copy);
	}
	
	printf("finished!\n");

	fclose(file);
	fclose(copy);

	return 0;
}