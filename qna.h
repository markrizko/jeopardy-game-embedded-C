#include <stdbool.h>
#include <json-c/json.h>

#define MAX_C 100
#define MAX_Q 100
#define MAX_A 100

typedef struct Answer {
    char answer_text[MAX_A];
    bool correct;
} Answer;

typedef struct Question {
    char category[MAX_C];
    char question[MAX_Q];
    Answer answers[4];
    int value;
} Question;

void populateData(Question* questions, int* num_questions, const char* json_file);
