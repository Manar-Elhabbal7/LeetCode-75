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

#define ll long long
class Solution {
public:

    //sufficient than using map ( in time complexity)
    unordered_map<ll, int> mp;

   //dfs and backtracking 
    int dfs(TreeNode* root, ll curSum, ll targetSum) {
        if (!root)
            return 0;

        curSum += root->val;
        int pathsCnt = mp[curSum - targetSum];

      //update
        mp[curSum]++;

      //recurse
        int ans = pathsCnt + dfs(root->left, curSum, targetSum) +
                  dfs(root->right, curSum, targetSum);

      //backtrack
        mp[curSum]--;

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
