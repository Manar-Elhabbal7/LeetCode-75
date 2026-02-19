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
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root)
            return;
        if (!root->right and !root->left) {
            leaves.push_back(root->val);
            return;
        }
        getLeaves(root->right, leaves);
        getLeaves(root->left, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2;
        getLeaves(root1, tree1);
        getLeaves(root2, tree2);
        return tree1 == tree2;
    }
};
