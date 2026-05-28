class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = 0;
        int best = -1e9;

        for (auto num : nums) {
            current = max(current, 0);
            current += num;
            best = max(best, current);
        }

        return best;
    }
};