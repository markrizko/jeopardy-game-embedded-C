#include <stdio.h>
#include <stdbool.h>

#define MAX_C 100
#define MAX_Q 100
#define MAX_A 100

typedef struct Answer {
    char answer_test[MAX_A];
    bool correct;
} Answer;

typedef struct Question {
    char category[MAX_C];
    char question[MAX_Q];
    Answer answers[4];
    int value;
} Question;



int main() {
    return 0;
}