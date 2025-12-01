1class Solution {
2public:
3    string gcdOfStrings(string str1, string str2) {
4        if (str1 + str2 != str2 + str1) return "";
5        int g = gcd(str1.size(), str2.size());
6        return str1.substr(0, g);
7    }
8};
9