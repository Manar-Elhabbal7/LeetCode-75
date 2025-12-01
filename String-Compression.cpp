1class Solution {
2public:
3    int compress(vector<char>& chars) {
4        string s = "";
5        for (auto c : chars)
6            s += c;
7        chars.clear();
8
9        for (int j = 0; j < s.size(); j++) {
10            int count = 1;
11
12            while (j + 1 < s.size() and s[j] == s[j + 1]) {
13                count++;
14                j++;
15            }
16
17            chars.push_back(s[j]);
18            if (count > 1) {
19                string cnt = to_string(count);
20                for (auto ch : cnt)
21                    chars.push_back(ch);
22            }
23        }
24        return (int)chars.size();
25    }
26};