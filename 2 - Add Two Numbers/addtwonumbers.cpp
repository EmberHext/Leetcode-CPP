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
    ListNode* addTwoNumebrs(ListNode* l1, ListNode* l2) {
        ListNode *result =  l1, *prev;              // We store the head of l1 into the result to return it at the end
                                                    // We need to track the previous node in case we end up with a carry-over at the very end
        int sum;                                    
        int carry = 0;
        
        while (l1 && l2) {                          // while l1 and l2 are not null, we loop through summing them
            sum = l1->val + l2->val + carry;

            if (sum > 9) {                          // if the sum is two digits, we need to carry one over
                carry = 1;
                l1-> val = sum - 10;
            } else {                                // otherwise we can just store it
                carry = 0;
                l1 -> val = sum;
            }

            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (!carry) {                               // if there is no carry over, we can tack on any remaining digits
            prev -> next = l1 ? l1 : l2;
            return ans;                             // and finish
        }

        prev->next = l1 ? l1 : l2;                  // otherwise need to continue the process manually to add the
                                                    // carry over(s) manually
        while (l1) {
            int sum = l1->val + carry;

            if (sum > 9) {
                carry = 1;
                l1->val = sum-10;
            } else {
                carry = 0;
                l1->val = sum;
            }

            prev = l1;
            l1 = l1-> next;
        }
        
        while (l2) {
            int sum = l2->val + carry;

            if (sum > 9) {
                carry = 1;
                l2->val = sum-10;
            } else {
                carry = 0;
                l2->val = sum;
            }

            prev = l2;
            l2 = l2-> next;
        }

        if (carry) {
            ListNode *node = new ListNode(carry);
            prev->next = node;
        }

        return ans;                                 // and then return
    }
}