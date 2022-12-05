#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* fp;
	char* line = NULL;
	size_t len = 0;

    int floor = 0;
    int entersBasement = 0;

    fp = fopen("input.txt", "r");
    getline(&line, &len, fp);

    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == '(') floor++;
        if (line[i] == ')') floor--;

        if (entersBasement == 0 && floor < 0) {
            entersBasement = i;
        }
    }

    fclose(fp);

    printf("%d\n", floor);
    printf("%d\n", entersBasement);
    return 0;
}