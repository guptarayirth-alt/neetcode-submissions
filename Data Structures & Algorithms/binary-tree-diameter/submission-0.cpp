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
    int diameter = 0;

    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int lf = solve(root->left);
        int rg = solve(root->right);

        diameter = max(diameter, lf + rg);

        return 1 + max(lf, rg);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;  // ✅ Reset before each test case
        solve(root);
        return diameter;
    }
};
