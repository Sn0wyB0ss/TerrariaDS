#include "save.h"

void loadFile(char* test) {
	FILE* inf = fopen("/save.txt","rb");
	if (fgets(test, 7, inf) == NULL) {
		strcpy(test, "notwor");
	}
	else
	fclose(inf);
}

void writeToFile() {

	FILE* inf = fopen("/save.txt","w+b");

	fwrite("sonict", 1, 7, inf);

	fclose(inf);

}