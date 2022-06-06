/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    int length(ListNode *head1)
    {
        int len=0;
        ListNode *head=head1;
        while(head!=NULL)
        {
            head=head->next;
            len++;
        }
        
        return len;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA=length(headA);
        int lenB=length(headB);
        
        if(lenA>lenB)
        {
            int val=lenA-lenB;
            int i=0;
            while(i<val && headA!=NULL)
            {
                ListNode *temp=headA;
                headA=headA->next;
                // delete temp;
                i++;
            }
        }
        else
        {
             int val=lenB-lenA;
            int i=0;
            while(i<val && headB!=NULL)
            {
                ListNode *temp=headB;
                headB=headB->next;
                // delete temp;
                i++;
            }
        }
        
        ListNode *ans=NULL;
        while(headA!=NULL && headB!=NULL)
        {
            if(headA==headB)
            {
                ans=headA;
                break;
            }
            headA=headA->next;
            headB=headB->next;
        }
        
        return ans;
        
    }
};