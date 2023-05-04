/* 
 * Author: Ember Hext
 * Problem: Longest Substring without Repeating Characters
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 * This solution uses a sliding window approach to find the
 * longest substring without repeating characters. It stores the
 * count of each character in a vector, and a pointer to both the
 * left and right index of the current substring. The while loop
 * removes characters from the left of the substring until there
 * are no repeating characters left, and the length of each valid
 * 
 * The vector method over a HashMap works similarly but with
 * slightly better performance.
 * 
 * This solution works in O(n) time.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Variables to store the length of the longest substring, the left and right indexes 
        // of the sliding window, and the count of each character in the current window
        int result = 0;
        int left_index = 0;
        int right_index = 0;
        int count[256] = {0};

        // Iterate through each character in the input string
        for (unsigned char c : s) {
            // Increment the count of the current character
            count[c]++;

            // While the current character appears more than once in the window
            while (count[c] > 1) {
                // Decrement the count of the character at the left index
                count[s[left_index]]--;
                // Move the left index of the window one position to the right
                left_index++;
            }

            // Update the result with the maximum length found
            result = std::max(result, right_index - left_index + 1);
            // Move the right index of the window one position to the right
            right_index++;
        }

        // Return the length of the longest substring
        return result;
    }
};