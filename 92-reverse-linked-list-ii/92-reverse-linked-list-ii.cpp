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
    
    ListNode *reverse(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *temp=reverse(head->next);
        ListNode *tail=head->next;
        tail->next=head;
        head->next=NULL;
        
        return temp;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right)
        {
            return head;
        }
        ListNode *temp1=head,*tail1=head;
        ListNode *temp2=head,*tail2=head;
        if(left==1)
        {
            temp1=head;
            tail1=NULL;
        }
        else
        {
            int i=1;
            while(i<left-1 && tail1!=NULL)
            {
                tail1=tail1->next;
                i++;
            }
            temp1=tail1->next;
            
        }
        
            int i=1;
            while(i<right && tail2!=NULL)
            {
                tail2=tail2->next;
                i++;
            }
            temp2=tail2->next;
            tail2->next=NULL;
        if(tail1!=NULL)
        {
            tail1->next=NULL;
        }
        
        
        ListNode *temp=reverse(temp1);
        
        
         temp1->next=temp2; 
    
        if(tail1!=NULL)
        {
            tail1->next=temp;
        }
        if(left==1)
        {
            return temp;
        }
        return head;
        
        
    }
};