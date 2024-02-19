#include "qna.h"
#include <string.h>

void populateData(Question* questions, int* num_questions, const char* json_file) {
    json_object *json_data = json_object_from_file(json_file);

    json_object *questions_array = json_object_object_get(json_data, "questions");


    size_t i;


    for (i = 0; i < json_object_array_length(questions_array); i++) {
    json_object *question_obj = json_object_array_get_idx(questions_array, i);


    if (i >= *num_questions) {
        break;
    }


    const char* category = json_object_get_string(json_object_object_get(question_obj, "category"));
    const char* question_text = json_object_get_string(json_object_object_get(question_obj, "question"));
    int value = json_object_get_int(json_object_object_get(question_obj, "value"));


    strcpy(questions[i].category, category);
    strcpy(questions[i].question, question_text);
    questions[i].value = value;


    json_object *answers_array = json_object_object_get(question_obj, "answers");
    for (size_t j = 0; j < json_object_array_length(answers_array); j++) {
        json_object *answer_obj = json_object_array_get_idx(answers_array, j);

        const char* answer_text = json_object_get_string(answer_obj);
        bool correct = json_object_get_boolean(answer_obj);

        strcpy(questions[i].answers[j].answer_text, answer_text);
        questions[i].answers[j].correct = correct;
    }
    }

    *num_questions = i;

    json_object_put(json_data);
}
