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
    int maxDepth(TreeNode* root) {
        // Base case: An empty tree has a depth of 0
        if (root == NULL) {
            return 0;
        } 
        
        // Find the height of the left and right subtrees recursively
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // Take the larger height and add 1 for the current node
        return 1 + std::max(leftDepth, rightDepth);
    }
};
