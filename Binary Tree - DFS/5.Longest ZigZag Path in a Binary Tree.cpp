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
    int mx = 0;
    int dfs(TreeNode* node, char dir, int len) {
        if (!node)
            return 0;

        mx = max(mx, len);

        if (dir == 'L') {
            dfs(node->left, 'R', ++len);
            /*
            in this case if there isn't left and i will walk 
            to right again so restart the length
            */
            dfs(node->right, 'L', 1);
        } 
        else {
            dfs(node->right, 'L', ++len);
            /*
            in this case if there isn't right and i will walk 
            to left again so restart the length
            */
            dfs(node->left, 'R', 1);
        }
        return mx;
    }

    int longestZigZag(TreeNode* root) {
        return max(dfs(root, 'L', 0), dfs(root, 'R', 0));
    }
};
