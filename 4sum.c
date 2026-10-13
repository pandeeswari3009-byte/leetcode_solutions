#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** fourSum(
    int* nums,
    int numsSize,
    int target,
    int* returnSize,
    int** returnColumnSizes
) {
    *returnSize = 0;

    if (numsSize < 4) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Allocate result space
    int capacity = 1000;

    int** result = malloc(capacity * sizeof(int*));

    *returnColumnSizes =
        malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {

        // Skip duplicate first number
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < numsSize - 2; j++) {

            // Skip duplicate second number
            if (j > i + 1 &&
                nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {

                long long sum =
                    (long long)nums[i] +
                    nums[j] +
                    nums[left] +
                    nums[right];

                if (sum == target) {

                    // Increase capacity if needed
                    if (*returnSize >= capacity) {
                        capacity *= 2;

                        result = realloc(
                            result,
                            capacity * sizeof(int*)
                        );

                        *returnColumnSizes = realloc(
                            *returnColumnSizes,
                            capacity * sizeof(int)
                        );
                    }

                    result[*returnSize] =
                        malloc(4 * sizeof(int));

                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }

                else if (sum < target) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }
    }

    return result;
}
