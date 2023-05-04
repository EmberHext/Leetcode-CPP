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
        // However, we 
        return { -1, -1 };
    }
};