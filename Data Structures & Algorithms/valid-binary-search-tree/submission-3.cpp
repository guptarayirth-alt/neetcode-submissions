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
    // By assigning default values, this can be called as isValidBST(root) OR isValidBST(root, min, max)
    bool isValidBST(TreeNode* root, long long minVal = LONG_MIN, long long maxVal = LONG_MAX) {
        // Base case
        if (root == nullptr) {
            return true;
        }

        // Boundary check
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        // Recursive calls passing the updated limits down
        return isValidBST(root->left, minVal, root->val) && 
               isValidBST(root->right, root->val, maxVal);
    }
};
