#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addToStack(char value, int stackNumber);
void addToStack2(char value, int stackNumber);
void moveToStack(int from, int to);
void printStacks();

struct stack {
    char value;
    struct stack *next;
};

typedef struct stack STACK;

struct stack* stacks[10];
struct stack* stackHeads[10];


int main(void) {
    FILE *fp;
    char line[40];

    int readingStacks = 1;

    for (int i = 0; i < 10; i++) {
        stacks[i] = (struct stack*) malloc(sizeof(struct stack));
        stackHeads[i] = stacks[i];
        stacks[i]->value = ' ';
        stacks[i]->next = NULL;
    }

    fp = fopen("input.txt", "r");

    while (fgets(line, 40, fp) != NULL) {
        if (line[1] == '1') {
            readingStacks = 0;
            // printf("%c\n", line[strlen(line) - 3]);
            continue;
        }

        if (readingStacks == 1) {
            addToStack(line[1], 1);
            addToStack(line[5], 2);
            addToStack(line[9], 3);
            addToStack(line[13], 4);
            addToStack(line[17], 5);
            addToStack(line[21], 6);
            addToStack(line[25], 7);
            addToStack(line[29], 8);
            addToStack(line[33], 9);
            // printf("1: %c 2: %c 3: %c\n", line[1], line[5], line[9]);
        }

        if (strlen(line) == 1) {
            printStacks();
            continue;
        }

        if (readingStacks == 0) {
            int count = 0;
            int where;
            int to;

            sscanf(line, "move %d from %d to %d", &count, &where, &to);
            // printf("Process line: %d %d %d\n", count, where, to);

            for (int i = 0; i < count; i++) {
                moveToStack(where, to);
            }
            // printStacks();
        }
    }
    
    fclose(fp);

    printStacks();

    return 0;
}

void addToStack(char value, int stackNumber) {
    if (value != ' ') {
        if (stacks[stackNumber]->value == ' ') {
            stacks[stackNumber]->value = value;
            return;
        }

        STACK *stack = (STACK*) malloc(sizeof(STACK));

        stack->value = value;
        stacks[stackNumber]->next = stack;
        stacks[stackNumber] = stack;
    }
}

void addToStack2(char value, int stackNumber) {
    if (value != ' ') {
        if (stackHeads[stackNumber]->value == ' ') {
            stackHeads[stackNumber]->value = value;
            return;
        }

        STACK *stack = (STACK*) malloc(sizeof(STACK));

        stack->value = value;
        stack->next = stackHeads[stackNumber];
        // stackHeads[stackNumber]->next = stack;
        stackHeads[stackNumber] = stack;
    }
}

void moveToStack(int from, int to) {
    // printf("%d %d\n", from, to);
    STACK *fromHead = stackHeads[from];
    char value = fromHead->value;

    if (fromHead->next == NULL) {
        stackHeads[from] = (STACK*) malloc(sizeof(STACK));
        stackHeads[from]->next = NULL;
    } else {
        stackHeads[from] = fromHead->next;
    }

    // printStacks();
    addToStack2(value, to);
    free(fromHead);
}

void printStacks() {
    for (int j = 1; j < 10; j++) {
        printf("%d: ", j);
        STACK *sp = stackHeads[j];

        do {
            printf("%c ", sp->value);
            sp = sp->next;
        } while (sp != NULL);
        printf("\n");
    }
    printf("\n");
}
