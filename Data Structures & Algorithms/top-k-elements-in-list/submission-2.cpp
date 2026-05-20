class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int frequency[2100];

        for (int i = 0; i < 2100; i++) {
            frequency[i] = 0;
        }

        for (int num : nums) {
            frequency[num+1000]++;
        }

        vector<vector<int>> elements(nums.size()+1);

        for (int i = -1000; i <= 1000; i++) {
            elements[frequency[i+1000]].push_back(i);
        }

        vector<int> output;

        for (int i = nums.size(); i>=0; i--) {
            for (auto el : elements[i]) {
                output.push_back(el);
            }
            if (output.size() >= k) {
                break;
            }
        }
        
        return output;
    }
};


/*
    map1: element -> frequency

    map2: frequency -> vector of elements


*/