/*
 * Author: Ember Hext
 * Problem: Zigzag Conversion
 * Link: https://leetcode.com/problems/zigzag-conversion/
 *
 * This solution uses a simple pattern traversal approach to convert the given string
 * based on the specified number of rows. It calculates the zigzag cycle length and 
 * iterates through each row of the zigzag pattern while maintaining the current 
 * index and current row. The while loop inside the row iteration adds both diagonal
 * and vertical elements to the result string, ensuring that they are within the input
 * string's boundaries.
 *
 * This is a fairly naive solution but it seems to solve the problem at an adequate speed
 * so no further optimization was necessary.
 * 
 * This solution works in O(n) time, where n is the length of the input string, as it 
 * iterates through the entire string once, performing constant-time operations at each step.
 *
 */

class Solution {
public:
    string convert(string inputStr, int numRows) {
        if (numRows == 1 || inputStr.size() <= numRows) return inputStr;
        int zigzagCycleLength((numRows - 1) * 2); // Length of one zigzag cycle
        int diagonalStep(zigzagCycleLength), currentIndex(0), currentRow(0);
        string result;

        // Iterate through each row of the zigzag pattern
        while (diagonalStep >= 0) {
            result += inputStr[currentIndex];

            // Iterate through the elements in the current row
            while (currentIndex < inputStr.size()) {
                // Add the diagonal element if it exists and is not the start or end of the cycle
                if (diagonalStep != zigzagCycleLength && diagonalStep != 0 && currentIndex + diagonalStep < inputStr.size()) {
                    result += inputStr[currentIndex + diagonalStep];
                }
                // Add the vertical element if it exists
                if (currentIndex + zigzagCycleLength < inputStr.size()) {
                    result += inputStr[currentIndex + zigzagCycleLength];
                }
                // Move to the next position in the same row
                currentIndex += zigzagCycleLength;
            }

            diagonalStep -= 2; // Update the diagonal step for the next row
            currentRow++; // Move to the next row
            currentIndex = currentRow; // Reset the index to start at the new row
        }

        return result;
    }
};
