#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {

    *returnSize = 0;

    if (numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Maximum possible number of triplets
    int capacity = numsSize * numsSize;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {

        // Skip duplicate first values
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        // If the smallest number is > 0,
        // sum can never be 0
        if (nums[i] > 0) {
            break;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            long sum = (long)nums[i] +
                       nums[left] +
                       nums[right];

            if (sum == 0) {

                result[*returnSize] = malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Skip duplicate values
                while (left < right &&
                       nums[left] == nums[left + 1]) {
                    left++;
                }

                while (left < right &&
                       nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            }

            else if (sum < 0) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    return result;
}
