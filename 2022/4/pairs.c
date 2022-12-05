#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* fp;
	char* line = NULL;
	size_t len = 0;

    int sumPart1 = 0;
    int sumPart2 = 0;

    fp = fopen("input.txt", "r");

    while (getline(&line, &len, fp) != -1) {
        char* first;
        char* second;

        first = strtok(line, ",");
        second = strtok(NULL, ",");

        int firstStart = strtol(strtok(first, "-"), NULL, 10); 
        int firstEnd = strtol(strtok(NULL, "-"), NULL, 10);
        int secondStart = strtol(strtok(second, "-"), NULL, 10); 
        int secondEnd = strtol(strtok(NULL, "-"), NULL, 10);

        /* first part */
        if (firstStart >= secondStart && firstEnd <= secondEnd) {
            sumPart1 = sumPart1 + 1;
        } else if (secondStart >= firstStart && secondEnd <= firstEnd) {
            sumPart1 = sumPart1 + 1;
        }

        /* second part */
        if (firstStart <= secondEnd && firstEnd >= secondStart) {
            sumPart2 = sumPart2 + 1;
        }
    }

    printf("Part1: %d\n", sumPart1);
    printf("Part2: %d\n", sumPart2);

    fclose(fp);
    free(line);

    return 0;
}
