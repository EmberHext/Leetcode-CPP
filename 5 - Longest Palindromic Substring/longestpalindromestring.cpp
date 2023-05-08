/*
 * Author: Ember Hext
 * Problem: Longest Palindromic Substring
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 *
 * This solution uses an expand-around-center approach to find the longest 
 * palindromic substring. It iterates through each character of the input 
 * string, considering it as a potential center for odd and even length 
 * palindromes. For each center, it expands outwards while the characters at 
 * both ends match, keeping track of the maximum length palindrome found so far.
 *
 * The algorithm has two separate loops: one for odd length palindromes, where 
 * the center is a character, and another for even length palindromes, where the 
 * center is between two characters. For each iteration, it updates the longest 
 * palindrome found accordingly.
 * 
 * This solution works in O(n^2) time, where n is the length of the input string,
 * since for each character, it may expand outwards up to n/2 times.
 *
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int oddLength = 0, evenLength = 0, n = s.size();
        string oddPalindrome, evenPalindrome;
        
        // Check for odd length palindrome
        for (int i = 0; i < n; i++) {
            int currentLength = 1;
            int start = i - 1, end = i + 1;
            
            // Expand around the center while characters match
            while (start >= 0 && end < n && s[start] == s[end]) {
                currentLength += 2;
                start--, end++;
            }
            
            // Update the longest odd palindrome found
            if (currentLength > oddLength) {
                oddLength = currentLength;
                oddPalindrome = s.substr(i - currentLength / 2, currentLength);
            }
        }
        
        // Check for even length palindrome
        for (int i = 1; i < n; i++) {
            int currentLength = 0;
            int start = i - 1, end = i;
            
            // Expand around the center while characters match
            while (start >= 0 && end < n && s[start] == s[end]) {
                currentLength += 2;
                start--, end++;
            }
            
            // Update the longest even palindrome found
            if (currentLength > evenLength) {
                evenLength = currentLength;
                evenPalindrome = s.substr(i - currentLength / 2, currentLength);
            }
        }
        
        // Return the longer palindrome between the two
        if (evenLength > oddLength) {
            return evenPalindrome;
        }
        return oddPalindrome;
    }
};
