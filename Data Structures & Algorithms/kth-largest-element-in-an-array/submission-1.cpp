class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end());

        auto end = nums.end();

        while (--k) {
            std::pop_heap(nums.begin(), end);
            --end;
        }

        return nums.front();
    }
};