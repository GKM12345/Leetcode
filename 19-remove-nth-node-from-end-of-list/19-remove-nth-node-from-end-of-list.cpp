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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)
        {
            return head;
        }
        int count=0;
        ListNode *slow=head,*fast=head;
        while(count<=n && fast!=NULL)
        {
            count++;
            fast=fast->next;
        }
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        if(count==n && fast==NULL)
        {
            head=head->next;
            delete slow;
            return head;
        }
        ListNode *temp=slow->next;
        slow->next=temp->next;
        delete temp;
        
        return head;
        
    }
};