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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx = -1, prevCriticalIdx = -1;
        int minGap = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        
        while (curr->next != nullptr) {
            bool isMax = curr->val > prev->val && curr->val > curr->next->val;
            bool isMin = curr->val < prev->val && curr->val < curr->next->val;
            
            if (isMax || isMin) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minGap = min(minGap, idx - prevCriticalIdx);
                }
                prevCriticalIdx = idx;
            }
            
            prev = curr;
            curr = curr->next;
            idx++;
        }
        
        if (firstIdx == -1 || firstIdx == prevCriticalIdx) {
            return {-1, -1};
        }
        
        int maxGap = prevCriticalIdx - firstIdx;
        return {minGap, maxGap};
    }
};