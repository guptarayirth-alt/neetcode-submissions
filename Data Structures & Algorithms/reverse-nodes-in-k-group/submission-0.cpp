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
    ListNode* reverseKGroup(ListNode* head, int k) {
       vector<vector<ListNode*>> v;
        ListNode* curr = head;
        int x = 0;
        int count = 0;

        v.push_back(vector<ListNode*>());

        while (curr != nullptr) {
            v[x].push_back(curr);
            curr = curr->next;
            count++;
            if (count == k) {
                x++;
                v.push_back(vector<ListNode*>());
                count = 0;
            }
        }

        int z = v.size();
        for (int i = 0; i < z; i++) {
            if ((int)v[i].size() == k) {
                reverse(v[i].begin(), v[i].end());
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (int i = 0; i < z; i++) {
            for (int j = 0; j < (int)v[i].size(); j++) {
                tail->next = v[i][j];
                tail = tail->next;
            }
        }
        tail->next = nullptr;

        return dummy->next;
    }
};