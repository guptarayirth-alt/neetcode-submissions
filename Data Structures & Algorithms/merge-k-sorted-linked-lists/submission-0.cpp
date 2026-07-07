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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<ListNode *> head= lists;
        vector<int> v;
        for(int i =0; i<n; i++)
        {
            ListNode * curr= head[i];
            while(curr!= nullptr)
            {
             v.push_back(curr->val);
             curr = curr->next;
            }
        }
           sort(v.begin(), v.end());
        int x= v.size();
        ListNode * dummy= new ListNode(0);
        ListNode *head1= dummy;
        ListNode* curr= head1;
        for(int i =0 ; i< x; i++)
        {
         curr->next = new ListNode(v[i]);
         curr = curr->next;
        }
            curr->next= nullptr;
        return head1->next;
        
    }
};
