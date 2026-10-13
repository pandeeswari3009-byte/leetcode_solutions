#include <stdbool.h>

bool isPalindrome(int x) {

    // Negative numbers are not palindromes
    if (x < 0) {
        return false;
    }

    // Numbers ending in 0 are not palindromes
    // except 0 itself
    if (x != 0 && x % 10 == 0) {
        return false;
    }

    int reversedHalf = 0;

    while (x > reversedHalf) {

        reversedHalf = reversedHalf * 10 + x % 10;
        x = x / 10;
    }

    // Even number of digits
    if (x == reversedHalf) {
        return true;
    }

    // Odd number of digits
    if (x == reversedHalf / 10) {
        return true;
    }

    return false;
}
