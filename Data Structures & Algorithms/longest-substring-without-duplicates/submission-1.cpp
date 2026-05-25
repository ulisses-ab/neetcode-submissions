class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> present;

        int start = 0;
        int best = 0;

        for (int end = 0; end < s.size(); end++) {
            best = max(best, end - start);

            char c = s[end];

            while (present.count(c)) {
                present.erase(s[start]);
                start++;
            }

            present.insert(c);
        }

        return max(best, int(s.size())-start);
    }
};
