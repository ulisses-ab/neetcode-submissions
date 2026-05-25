class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool present[256];

        for (auto& x : present) x = false;

        int start = 0;
        int best = 0;

        for (int end = 0; end < s.size(); end++) {
            best = max(best, end - start);

            char c = s[end];

            while (present[c]) {
                present[s[start]] = false;
                start++;
            }

            present[c] = true;
        }

        return max(best, int(s.size())-start);
    }
};
