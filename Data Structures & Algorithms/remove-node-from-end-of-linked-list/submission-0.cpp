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
        ListNode* curr=head;
        int index=0;
        while(curr!=NULL)
        {
          index++;
          curr=curr->next;
        }
        int x= index-n;
        if (x == 0)
         {
            return head->next;
        }
        ListNode* curry=head;
        ListNode* temp=NULL;
        int t=0;
        while(curry!=NULL)
        {
         
          if(t== x)
          {
            temp->next=curry->next;
            break;
          }  
          temp=curry;
          curry=curry->next;
           t++;
        }
        return head;
    }
};
