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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*slow=head;
        ListNode*fast=head;
        for(int i=1;i<k;i++){
            fast= fast->next;
        }
        ListNode*first=fast;
         while(fast->next !=NULL){ 
            fast= fast->next;
            slow= slow->next;
         }
         ListNode*sec= slow;
         swap( first->val, sec ->val);
         return head;
    }
};