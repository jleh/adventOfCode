#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* fp;
	char* line = NULL;
	size_t len = 0;

    int sum = 0;

    fp = fopen("input.txt", "r");

	while (getline(&line, &len, fp) != -1) {
        int items = (strlen(line) - 1) / 2;
        int found = 0;
        char common;
        
        for (int i = 0; i < items; i++) {
            for (int j = 0; j < items; j++) {
                if (line[i] == line[items + j]) {
                    found = 1;
                    common = line[i];
                    break;
                }
            }
            if (found == 1) break;
        }
        
        int itemValue;

        if (common > 96) itemValue = common - 96;
        else itemValue = common - 38;

        printf("%c %d %d\n", common, common, itemValue);
        sum = sum + itemValue;
    }

    fclose(fp);

    printf("%d\n", sum);
    return 0;
}
