// i know this is already a thing in powershell
// but it isn't in normal windows cmd

#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
	char* dir = argc > 1 ? argv[1] : ".";

	struct dirent* de;
	DIR* dr = opendir(dir);

	if (dr == NULL)	{
		printf("something went wrong when opening directory %s\n", dir);
		return 0;
	}

	while ((de = readdir(dr)) != NULL)
		printf("%s\n", de->d_name);

	closedir(dr);
	return 0;
}
