/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // we found the target delete it
            // there are 4 cases

            // is leaf ?
            if (!root->left and !root->right) {
                delete root;
                return nullptr;
            } 
            else if (!root->left) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
             else if (!root->right) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            } else {
                // has two childeren
                TreeNode* suc = root->right;
                while (suc->left)
                    suc = suc->left;

                // we replace it with the left node in the leaf
                root->val = suc->val;

                // delete it here to avoid repetion
                root->right = deleteNode(root->right, suc->val);
            }
        }
        return root;
    }
};
