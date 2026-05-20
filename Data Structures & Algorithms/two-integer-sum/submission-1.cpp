class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            if (auto it = m.find(num); it != m.end()) {
                return {(*it).second, i};
            }

            m[target-num] = i; 
        }      

        return {-1, -1};
    }
};