class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
        };

        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r and !isVowel(s[l])) l++;
            while (l < r and !isVowel(s[r])) r--;
            if (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};
