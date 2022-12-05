#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* fp;
	char* line = NULL;
	size_t len = 0;

    int sum = 0;

    fp = fopen("input.txt", "r");

    char* bag1;
    char* bag2;
    char* bag3;
    int lineNumber = 0;

	while (getline(&line, &len, fp) != -1) {
        lineNumber++;

        if (lineNumber == 1) {
            bag1 = malloc(strlen(line));
            strcpy(bag1, line);
        }
        if (lineNumber == 2) {
            bag2 = malloc(strlen(line));
            strcpy(bag2, line);
        }
        if (lineNumber == 3) {
            bag3 = malloc(strlen(line));
            strcpy(bag3, line);
        }

        if (lineNumber == 3) {
            lineNumber = 0;

            int items1 = strlen(bag1);
            int items2 = strlen(bag2);
            int items3 = strlen(bag3);

            int found = 0;

            char badge;

            for (int i = 0; i < items1; i++) {
                for (int j = 0; j < items2; j++) {
                    if (bag1[i] == bag2[j]) {
                        for (int k = 0; k < items3; k++) {
                            if (bag1[i] == bag3[k]) {
                                badge = bag1[i];
                                found = 1;
                                break;
                            }
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }

            int itemValue;

            if (badge > 96) itemValue = badge - 96;
            else itemValue = badge - 38;

            sum = sum + itemValue;

            free(bag1);
            free(bag2);
            free(bag3);
        }
    }

    fclose(fp);

    free(line);
    printf("%d\n", sum);
    return 0;
}
