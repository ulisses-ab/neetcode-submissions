class Solution {
public:
    unordered_map<int, int> best_sequence;
    unordered_set<int> present;

    int find_best_sequence(int x) {
        if (present.count(x) == 0) {
            return 0;
        }

        if (best_sequence.find(x) != best_sequence.end()) {
            return best_sequence[x];
        } 

        return best_sequence[x] = find_best_sequence(x+1)+1;
    }

    int longestConsecutive(vector<int>& nums) {
        for (auto num : nums) {
            present.insert(num);
        }

        int best = 0;

        for (auto num : nums) {
            best = max(best, find_best_sequence(num));
        }

        return best;
    }
};


/*

    best_sequence[i] = longest current sequence that can be formed starting with i

    



    [2,20,4,10,3,4,5]

    best_sequence[5] = 1;

    best_sequence[4] = 2;

    best_sequence[i] = best_sequence[i+1] + 1;

*/