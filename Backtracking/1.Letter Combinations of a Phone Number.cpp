class Solution {
public:
    map<int, string> mp;
    string current = "";

    void backtrack(string& digits, int idx, vector<string>& ans) {
        //base case
        if (idx == digits.size()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[idx] - '0';
        string letters = mp[digit];

        for (char ch : letters) {
            //update
            current.push_back(ch);
            //recurse
            backtrack(digits, idx + 1, ans);
            //backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        vector<string> ans;
        int n = digits.size();

        if (n == 0)
            return ans;

        backtrack(digits, 0, ans);
        return ans;
    }
};
