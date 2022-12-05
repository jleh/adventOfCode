#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shapeScore(char shape);
int outcomeScore(char my, char opponent);
char getMyShape(char opponent, char needed);

const char ROCK = 'A';
const char PAPER = 'B';
const char SCISSORS = 'C';

int main(void) {
    FILE* fp;
	char* line = NULL;
	size_t len = 0;

    int totalScore = 0;

    fp = fopen("input.txt", "r");
	
	while (getline(&line, &len, fp) != -1) {
        char opponent = line[0];
        char needed = line[2];
        int score = 0;

        char my = getMyShape(opponent, needed);
        score = shapeScore(my) + outcomeScore(my, opponent);

        totalScore = totalScore + score;
    }

    printf("%d\n", totalScore);
    fclose(fp);
}

int shapeScore(char shape) {
    if (shape == ROCK) return 1;
    if (shape == PAPER) return 2;
    return 3;
}

int outcomeScore(char my, char opponent) {
    if (my == ROCK) {
        if (opponent == ROCK) return 3;
        if (opponent == PAPER) return 0;
        if (opponent == SCISSORS) return 6;
    }
    if (my == PAPER) {
        if (opponent == ROCK) return 6;
        if (opponent == PAPER) return 3;
        if (opponent == SCISSORS) return 0;
    }
    if (my == SCISSORS) {
        if (opponent == ROCK) return 0;
        if (opponent == PAPER) return 6;
        if (opponent == SCISSORS) return 3;
    }
    return 0;
}

char getMyShape(char opponent, char needed) {
    if (opponent == ROCK) {
        if (needed == 'X') return SCISSORS;
        if (needed == 'Y') return ROCK;
        if (needed == 'Z') return PAPER;
    }
    if (opponent == PAPER) {
        if (needed == 'X') return ROCK;
        if (needed == 'Y') return PAPER;
        if (needed == 'Z') return SCISSORS;
    }
    if (opponent == SCISSORS) {
        if (needed == 'X') return PAPER;
        if (needed == 'Y') return SCISSORS;
        if (needed == 'Z') return ROCK;
    }
}
