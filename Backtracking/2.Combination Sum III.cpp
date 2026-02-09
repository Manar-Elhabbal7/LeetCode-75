#define pb push_back

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(int k, int n, int start) {
        //base case
        if (path.size() == k and n == 0) {
            res.pb(path);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n)
                break;

            // update
            path.pb(i);
            // recurse
            backtrack(k, n - i, i + 1);
            // backtrack
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return res;
    }
};
