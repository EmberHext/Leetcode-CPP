/* 
 *
 * Author: Ember Hext
 * Problem: Median of Two Sorted Arrays
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 *
 * This solution employs a binary search approach to find the median of two sorted arrays. 
 * It ensures that the first input array is smaller than the second one and performs a binary 
 * search on the smaller array to find the correct partition points. The algorithm maintains 
 * pointers to elements on both sides of the partition in each array and checks whether the 
 * correct partition has been found.
 * 
 * If the total length of both arrays is even, the median is calculated as the average of the 
 * maximum element on the left side and the minimum element on the right side. If the total 
 * length is odd, the median is simply the maximum element on the left side. The binary search 
 * continues until the correct partition is found, adjusting the partition points based on the 
 * comparisons.
 * 
 * This solution leverages the properties of sorted arrays and the efficiency of binary search 
 * to achieve far better solution than the naive solutions. The overall time complexity of this 
 * solution is O(log(n)), where n is the length of the shorter array
 *
 */

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is smaller than nums2
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Initialize variables
        int x = nums1.size();
        int y = nums2.size();
        int low = 0;
        int high = x;

        // Binary search on the smaller array
        while (low <= high) {
            // Calculate partitions for both arrays
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            // Find elements on both sides of the partition
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            // Check if correct partition is found
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If the total length of both arrays is even
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else { // If the total length of both arrays is odd
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) { // Move the partition towards the left
                high = partitionX - 1;
            } else { // Move the partition towards the right
                low = partitionX + 1;
            }
        }

        // Throw an exception if input arrays are not sorted
        throw invalid_argument("Input arrays are not sorted.");
    }
};
