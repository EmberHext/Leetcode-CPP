/* 
 * Author: Ember Hext
 * Problem: Two Sum
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * This solution uses a hash map, storing the number as the key
 * and the index as the value. This order is used because it allows
 * us to check if the number needed to sum to the target has already
 * been inserted into the hash map.
 * 
 * This solution works in O(n) time.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a hash map to store previously seen numbers
        unordered_map<int, int> prevNums;

        // Iterate through the input array
        for (int i = 0; i < nums.size(); i++) {
            // If the complement (target - current number) is found in the hash map
            if (prevNums.find(target - nums[i]) != prevNums.end()) {
                // Return the indices of the current number and its complement
                return { i, prevNums[target - nums[i]] };
            }

            // If no match, add the current number and its index to the hash map
            prevNums[nums[i]] = i;
        }

        // The problem specification indicates that there will always be a working pair
        // But typically this would be our failure state
        return { -1, -1 };
    }
};