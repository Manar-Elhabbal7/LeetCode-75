1#define pb push_back
2
3class Solution {
4public:
5    string reverseWords(string s) {
6        string temp = "";
7
8        vector<string> res;
9
10        for (int i = 0; i < s.size(); i++) {
11            if (s[i] != ' ') {
12                temp += s[i];
13            } else {
14                if (temp != "") {
15                    res.pb(temp);
16                    temp = "";
17                }
18            }
19        }
20        if (!temp.empty()) {
21            res.pb(temp);
22        }
23        reverse(res.begin(), res.end());
24        string ans = "";
25        for (int i = 0; i < res.size() - 1; i++) {
26            ans += res[i] + ' ';
27        }
28        ans += res[res.size() - 1];
29        return ans;
30    }
31};