#include <stdlib.h>
#include <string.h>

char* letters[] = {
    "",     "",     "abc",  "def",
    "ghi",  "jkl",  "mno",  "pqrs",
    "tuv",  "wxyz"
};

void backtrack(
    char* digits,
    int index,
    char* current,
    char** result,
    int* returnSize
) {
    // All digits processed
    if (digits[index] == '\0') {

        result[*returnSize] = malloc(
            (strlen(current) + 1) * sizeof(char)
        );

        strcpy(result[*returnSize], current);
        (*returnSize)++;

        return;
    }

    int digit = digits[index] - '0';
    char* possibleLetters = letters[digit];

    for (int i = 0; possibleLetters[i] != '\0'; i++) {

        current[index] = possibleLetters[i];

        backtrack(
            digits,
            index + 1,
            current,
            result,
            returnSize
        );
    }

    current[index] = '\0';
}

char** letterCombinations(
    char* digits,
    int* returnSize
) {
    *returnSize = 0;

    int n = strlen(digits);

    if (n == 0) {
        return NULL;
    }

    // Maximum possible combinations = 4^n
    int capacity = 1;

    for (int i = 0; i < n; i++) {
        capacity *= 4;
    }

    char** result = malloc(capacity * sizeof(char*));
    char* current = malloc((n + 1) * sizeof(char));

    current[n] = '\0';

    backtrack(
        digits,
        0,
        current,
        result,
        returnSize
    );

    free(current);

    return result;
}
