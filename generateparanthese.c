#include <stdlib.h>
#include <string.h>

void generate(
    int open,
    int close,
    int n,
    char* current,
    int pos,
    char** result,
    int* returnSize
) {
    // All parentheses are used
    if (pos == 2 * n) {
        current[pos] = '\0';

        result[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);

        (*returnSize)++;
        return;
    }

    // Add '(' if we still have opening brackets
    if (open < n) {
        current[pos] = '(';

        generate(
            open + 1,
            close,
            n,
            current,
            pos + 1,
            result,
            returnSize
        );
    }

    // Add ')' only when it won't become invalid
    if (close < open) {
        current[pos] = ')';

        generate(
            open,
            close + 1,
            n,
            current,
            pos + 1,
            result,
            returnSize
        );
    }
}

char** generateParenthesis(
    int n,
    int* returnSize
) {
    *returnSize = 0;

    // Maximum number of combinations
    int capacity = 1;

    for (int i = 0; i < 2 * n; i++) {
        capacity *= 2;
    }

    char** result = malloc(capacity * sizeof(char*));

    char* current = malloc((2 * n + 1) * sizeof(char));

    generate(
        0,
        0,
        n,
        current,
        0,
        result,
        returnSize
    );

    free(current);

    return result;
}
