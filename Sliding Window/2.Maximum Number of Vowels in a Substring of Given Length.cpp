class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        string vowels = "aeiou";
        int l = 0, cnt = 0, mx = 0;
        for (int r = 0; r < n; r++) {
            if (vowels.find(s[r]) != string::npos)
                cnt++;
            
            if (r - l + 1 == k) {
                mx = max(mx, cnt);
                if (vowels.find(s[l]) != string::npos) {
                    cnt--;
                }
                l++;
            }
        }
        return mx;
    }
};
