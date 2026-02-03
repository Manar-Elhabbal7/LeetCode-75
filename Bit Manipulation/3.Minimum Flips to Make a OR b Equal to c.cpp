class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> A(a), B(b), C(c);
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            if (C[i]) {
                if (!(A[i] or B[i])) {
                    ans++;
                }
            } else {
                if (A[i] and B[i]) {
                    ans += 2;
                } else if (A[i] or B[i]) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
