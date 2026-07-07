/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        return helper(root, k, v);
        
    }
    private:
    int helper ( TreeNode* root, int k, vector<int> v){
    if(root==NULL)
    {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
            int n = q.size(); 
            
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                
                if (curr->left != nullptr)  q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
        }
    sort (v.begin(),v.end());
    int z = v[k-1];
    return z;
    }
};
