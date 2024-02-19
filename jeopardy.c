#include "qna.h"
#include <stdlib.h>
#include <stdio.h>

#define NUM_QUESTIONS 15


int main() {
    int nq = NUM_QUESTIONS;
    Question *questions = malloc(NUM_QUESTIONS * sizeof(Question));
    populateData(questions, &nq, "questions.json");

    return 0;
}