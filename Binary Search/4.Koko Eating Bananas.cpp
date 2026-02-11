#define ll long long

class Solution {
public:
    // check if can finish all bananas using this speed
    bool check(int mid, int h, vector<int>& piles) {
        ll hours{0};
        for (auto pile : piles) {
            hours += (pile + mid - 1) / mid;
        }
        return (hours <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        // Binary search on answer
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, h, piles)) {
            /*
                Note :if it's ok at speed x 
                so it will also ok with any speed greater than x 
            */
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
