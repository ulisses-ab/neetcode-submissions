class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;

        while (lo <= hi) {
            int m = (lo + hi) / 2;

            if (nums[m] == target) return m;

            if (nums[m] > target) {
                hi = m - 1;
            }
            else {
                lo = m + 1;
            }
        }

        return -1;
    }
};
