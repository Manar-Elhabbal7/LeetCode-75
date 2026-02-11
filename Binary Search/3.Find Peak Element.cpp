class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid > 0 and nums[mid - 1] > nums[mid]) {
                r = mid - 1;
            } 
            else if (mid < nums.size() - 1 and nums[mid + 1] > nums[mid]) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return l;
    }
};
