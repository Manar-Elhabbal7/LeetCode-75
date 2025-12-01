class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        for (auto c : chars)
            s += c;
        chars.clear();

        for (int j = 0; j < s.size(); j++) {
            int count = 1;

            while (j + 1 < s.size() and s[j] == s[j + 1]) {
                count++;
                j++;
            }

            chars.push_back(s[j]);
            if (count > 1) {
                string cnt = to_string(count);
                for (auto ch : cnt)
                    chars.push_back(ch);
            }
        }
        return (int)chars.size();
    }
};
