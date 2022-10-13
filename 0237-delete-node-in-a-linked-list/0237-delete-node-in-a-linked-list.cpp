/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode *node2=node->next;
        int temp=node->val;
        node->val=node2->val;
        node2->val=temp;
        
        node->next=node2->next;
        
        delete node2;
        
    }
};