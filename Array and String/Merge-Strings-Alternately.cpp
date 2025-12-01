class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int mx = max(word1.size(), word2.size());
        string ans = "";
        while (mx--) {
            if (!word1.empty()) {
                ans += word1.front();
                word1.erase(word1.begin());
            }
            if (!word2.empty()) {
                ans += word2.front();
                word2.erase(word2.begin());
            }
        }
        return ans;
    }
};
