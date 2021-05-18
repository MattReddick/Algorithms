/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        ListNode* current = head;
        while(current != NULL){
            values.push_back(current->val);
            current = current->next;
        }
        
        if(values.size() == 2){
            return head->val == head->next->val;
        }
        
        
        for(int i = 0; i < values.size()/2;i++){
            if(head->val != values[values.size()-1-i]){
                return false;
            }else{
                head = head->next;
            }
        }
        return true;
    }
};
