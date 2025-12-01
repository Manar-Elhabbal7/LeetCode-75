1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4        int mx = max(word1.size(),word2.size());
5        string ans = "";
6        while(mx--){
7            if(!word1.empty()){
8                ans+=word1.front();
9                word1.erase(word1.begin());
10            }
11            if(!word2.empty()){
12                ans +=word2.front();
13                word2.erase(word2.begin());
14            }
15        }
16        return ans;
17    }
18};