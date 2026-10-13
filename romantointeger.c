#include <string.h>

int getValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }

    return 0;
}

int romanToInt(char* s) {

    int total = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {

        int current = getValue(s[i]);

        if (i + 1 < length) {

            int next = getValue(s[i + 1]);

            if (current < next) {
                total -= current;
            }
            else {
                total += current;
            }
        }
        else {
            total += current;
        }
    }

    return total;
}
