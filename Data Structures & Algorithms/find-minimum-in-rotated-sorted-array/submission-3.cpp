class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) return nums.back();
        int lo = 1, hi = nums.size()-1;

        while (lo < hi) {
            int m = (lo+hi) / 2;

            if (nums[m] > nums[0]) {
                lo = m + 1;
            }
            else {
                hi = m;
            }
        } 

        return min(nums[0], nums[lo]);
    }
};
