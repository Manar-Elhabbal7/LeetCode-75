/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //Just conditions hmmmmm
    /* Useful Link : 
        https://www.geeksforgeeks.org/dsa/lowest-common-ancestor-binary-tree-set-1/
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        if (root->val == p->val or root->val == q->val)
            return root;
            
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        if (right and left)
            return root;

        return right ? right : left;
    }
};
