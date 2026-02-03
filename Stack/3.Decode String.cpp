class Solution {
public:
    string decodeString(string s) {
        //the idea is that to use two stacks
        stack<int> cnts;
        stack<string> resStack;

        string res;
        int idx = 0;

        while (idx < s.length()) {
            if (isdigit(s[idx])) {
                int count = 0;

                while (isdigit(s[idx])) {
                    count = count * 10 + (s[idx] - '0');
                    idx++;
                }
                
                cnts.push(count);
            } 
            else if (s[idx] == '[') {
                resStack.push(res);
                res = "";
                idx++;
            } 
            else if (s[idx] == ']') {
                string temp = resStack.top();
                resStack.pop();

                int freq = cnts.top();
                cnts.pop();

                for (int i = 0; i < freq; i++) {
                    temp += res;
                }
                res = temp;
                idx++;
            } 
            else {
                res += s[idx];
                idx++;
            }
        }

        return res;
    }
};
