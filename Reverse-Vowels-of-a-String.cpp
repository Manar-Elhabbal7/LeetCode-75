1class Solution {
2public:
3    string reverseVowels(string s) {
4        auto isVowel = [](char c) {
5            c = tolower(c);
6            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
7        };
8
9        int l = 0, r = s.size() - 1;
10        while (l < r) {
11            while (l < r && !isVowel(s[l])) l++;
12            while (l < r && !isVowel(s[r])) r--;
13            if (l < r) swap(s[l++], s[r--]);
14        }
15        return s;
16    }
17};
18