/* 
 * Author: Ember Hext
 * Problem: Add Two Numbers
 * Link: https://leetcode.com/problems/add-two-numbers/
 * 
 * This solution works in-place to limit the memory allocation,
 * iterating through both lists and adding them while tracking
 * carry-overs. This solution is destructive and a different solution
 * would be necessary if the original numbers needed to be preserved.
 *
 * This solution works in O(n) time.
 */

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode *result = list1, *previousNode;    // We store the head of list1 into the result to return it at the end
                                                    // We need to track the previous node in case we end up with a carry-over at the very end
        int currentSum;
        int carryOver = 0;
        
            while (list1 && list2) {                    // while list1 and list2 are not null, we loop through summing them
            currentSum = list1->val + list2->val + carryOver;

            if (currentSum > 9) {                   // if the sum is two digits, we need to carry one over
                carryOver = 1;
                list1->val = currentSum - 10;
            } else {                                // otherwise we can just store it
                carryOver = 0;
                list1->val = currentSum;
            }

            previousNode = list1;
            list1 = list1->next;
            list2 = list2->next;
        }

        if (!carryOver) {                           // if there is no carry over, we can tack on any remaining digits
            previousNode->next = list1 ? list1 : list2;
            return result;                          // and finish
        }

        previousNode->next = list1 ? list1 : list2; // otherwise need to continue the process manually to add the
                                                    // carry over(s) manually
        while (list1) {
            currentSum = list1->val + carryOver;

            if (currentSum > 9) {
                carryOver = 1;
                list1->val = currentSum - 10;
            } else {
                carryOver = 0;
                list1->val = currentSum;
            }

            previousNode = list1;
            list1 = list1->next;
        }
        
        while (list2) {
            currentSum = list2->val + carryOver;

            if (currentSum > 9) {
                carryOver = 1;
                list2->val = currentSum - 10;
            } else {
                carryOver = 0;
                list2->val = currentSum;
            }

            previousNode = list2;
            list2 = list2->next;
        }

        if (carryOver) {
            ListNode *carryNode = new ListNode(carryOver);
            previousNode->next = carryNode;
        }

        return result;                              // and then return
    }
};