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
    ListNode* partition(ListNode* head, int x) {
        
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *head1=NULL,*tail1=NULL;
        ListNode *head2=NULL,*tail2=NULL;
        
        ListNode *temp=head;
        
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                if(head1==NULL)
                {
                    head1=temp;
                    tail1=temp;
                }
                else
                {
                    tail1->next=temp;
                    tail1=tail1->next;
                    
                }
            }
            else
            {
                if(head2==NULL)
                {
                    head2=temp;
                    tail2=temp;
                }
                else
                {
                    tail2->next=temp;
                    tail2=tail2->next;
                    
                }
            }
            temp=temp->next;
        }
        
        if(head1==NULL)
        {
            return head2;
        }
        if(head2==NULL)
        {
            return head1;
        }
        tail2->next=NULL;
        tail1->next=head2;
        
        return head1;
        
    }
};