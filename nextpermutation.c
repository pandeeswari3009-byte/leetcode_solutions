#include <stdio.h>

// Helper function to swap two integer values
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to reverse an array section in-place
void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    // If the array is empty or has only one element, no permutation change is needed
    if (numsSize <= 1) {
        return;
    }

    int i = numsSize - 2;

    // Step 1: Find the first element from the right that breaks descending order
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // Step 2 & 3: If a valid pivot index is found, find its successor and swap
    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }

    // Step 4: Reverse the sub-array to the right of the pivot
    reverse(nums, i + 1, numsSize - 1);
}

