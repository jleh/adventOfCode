#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int calories;
	struct node *next;
};

int main(void) {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	
	int total = 0;
	struct node *head = NULL;

	fp = fopen("input.txt", "r");
	
	while (getline(&line, &len, fp) != -1) {
		if (strlen(line) == 1) {
			if (head == NULL || head->calories < total) {
				struct node *link = (struct node*) malloc(sizeof(struct node));
				link->calories = total;
				link->next = head;
				head = link;
			}

			total = 0;
		} else {
			total = total + strtol(line, NULL, 10);
		}
	}

	int first = head->calories;
	int second = head->next->calories;
	int third = head->next->next->calories;

	printf("1. %d\n", first);
	printf("2. %d\n", second);
	printf("3. %d\n", third);
	printf("TOTAL: %d\n", first + second + third);

	fclose(fp);
	free(line);
	return 0;
}
