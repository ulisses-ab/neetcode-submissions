class Solution {
public:
    int jump(vector<int>& nums) {
        int furthest = 0;
        int jumps = 0;
        int limit = 0;

        if (nums.size() == 1) return 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > limit) {
                limit = furthest;
                jumps++;
            }

            furthest = max(furthest, i+nums[i]);

            if (furthest >= nums.size()-1) break;
        }

        return jumps+1;
    }
};
