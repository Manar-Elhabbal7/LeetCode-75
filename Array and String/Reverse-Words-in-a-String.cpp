#define pb push_back

class Solution {
public:
    string reverseWords(string s) {
        string temp = "";

        vector<string> res;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                if (temp != "") {
                    res.pb(temp);
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            res.pb(temp);
        }
        reverse(res.begin(), res.end());
        string ans = "";
        for (int i = 0; i < res.size(); i++) {
            ans += res[i];
            if (i != res.size() - 1) ans += ' ';
        }
        return ans;
    }
};
