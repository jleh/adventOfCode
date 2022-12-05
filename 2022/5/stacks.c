#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addToStack(char value, int stackNumber);
void moveToStack(int from, int to, int count);
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
        stacks[i] = NULL;
        stackHeads[i] = NULL;
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
            moveToStack(where, to, count);
        }
    }
    
    fclose(fp);

    printStacks();

    // Free used memory for stacks
    for (int i = 0; i < 10; i++) {
        STACK *head = stackHeads[i];
        STACK *ptr = head;
        while (ptr != NULL) {
            head = ptr->next;
            free(ptr);
            ptr = head;
        }
    }

    return 0;
}

void addToStack(char value, int stackNumber) {
    if (value != ' ') {
        STACK *stack = (STACK*) malloc(sizeof(STACK));

        stack->value = value;
        
        if (stacks[stackNumber] != NULL) {
            stacks[stackNumber]->next = stack;
        }

        stacks[stackNumber] = stack;

        if (stackHeads[stackNumber] == NULL) {
            stackHeads[stackNumber] = stack;
        }
    }
}

void moveToStack(int from, int to, int count) {
    STACK *fromHead = stackHeads[from];
    STACK *lastToMove = stackHeads[from];
    STACK *toHead = stackHeads[to];

    for (int i = 0; i < count - 1; i++) {
        lastToMove = lastToMove->next;
    }

    stackHeads[from] = lastToMove->next;
    lastToMove->next = toHead;
    stackHeads[to] = fromHead;
}

void printStacks() {
    for (int j = 1; j < 10; j++) {
        printf("%d: ", j);
        STACK *sp = stackHeads[j];

        while (sp != NULL) {
            printf("%c ", sp->value);
            sp = sp->next;
        }
        printf("\n");
    }
    printf("\n");
}
