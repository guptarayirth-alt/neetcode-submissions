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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: If the tree is empty or we didn't find the key
        if (root == nullptr) {
            return nullptr;
        }

        // STEP 1: Search for the node
        if (key < root->val) {
            // Key is smaller, go left. Re-attach the updated subtree.
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            // Key is larger, go right. Re-attach the updated subtree.
            root->right = deleteNode(root->right, key);
        } 
        
        // STEP 2: We found the node! Now, delete it.
        else {
            // Case 1 & Case 2: Node has 0 or 1 child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root; // Free the memory to prevent leaks
                return temp;
            } 
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has 2 children
            // Find the minimum value in the right subtree (In-Order Successor)
            TreeNode* successor = findMin(root->right);
            
            // Replace current node's value with the successor's value
            root->val = successor->val;
            
            // Recursively delete that successor from the right subtree
            root->right = deleteNode(root->right, successor->val);
        }
        
        return root; // Return the completely updated root
    }

private:
    // Helper function to find the smallest node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};