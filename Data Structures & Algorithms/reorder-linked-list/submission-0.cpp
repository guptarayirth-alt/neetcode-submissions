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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        vector<pair<int, ListNode*>> lis; 
        int index = 0;

        while (curr != NULL) {
            lis.push_back({index, curr});  
            curr = curr->next;
            index++;
        }

        int n = lis.size();
        vector<pair<int, ListNode*>> order;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (left == right) {
                order.push_back(lis[left]); 
            } else {
                order.push_back(lis[left]);   
                order.push_back(lis[right]);  
            }
            left++;
            right--;
        }

        for (int i = 0; i < order.size() - 1; i++) {
            order[i].second->next = order[i + 1].second;
        }
        order.back().second->next = NULL; 
    }
};