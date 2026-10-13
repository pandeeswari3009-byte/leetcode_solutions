double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {

    // Always binary search on the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size,
                                      nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;

    int left = 0;
    int right = m;

    while (left <= right) {

        int partition1 = (left + right) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? -2147483648
                                         : nums1[partition1 - 1];

        int minRight1 = (partition1 == m) ? 2147483647
                                          : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? -2147483648
                                         : nums2[partition2 - 1];

        int minRight2 = (partition2 == n) ? 2147483647
                                          : nums2[partition2];

        // Correct partition
        if (maxLeft1 <= minRight2 &&
            maxLeft2 <= minRight1) {

            // Total number of elements is odd
            if ((m + n) % 2 == 1) {
                return (double)(
                    maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2
                );
            }

            // Total number of elements is even
            int leftMax = maxLeft1 > maxLeft2
                          ? maxLeft1 : maxLeft2;

            int rightMin = minRight1 < minRight2
                           ? minRight1 : minRight2;

            return (leftMax + rightMin) / 2.0;
        }

        // Move partition to the left
        else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        }

        // Move partition to the right
        else {
            left = partition1 + 1;
        }
    }

    return 0.0;
}
