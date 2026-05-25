class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> cnt1, cnt2;

        for (auto c : s1) {
            cnt1[c]++;
        }

        int s = 0;

        for (int e = 0; e < s2.size(); e++) {
            char c = s2[e];

            while (cnt2[c] == cnt1[c]) {
                cnt2[s2[s]]--;
                s++;
            }

            cnt2[c]++;

            if (e-s+1 == s1.size()) return true;
        }

        return false;
    }
};
