class Solution {
public:
    string minWindow(string str, string t) {
        unordered_map<char, int> cnt1, cnt2;
        int satisfied = 0, goal = 0;

        for (auto c : t) {
            if (cnt2[c] == 0) goal++;
            cnt2[c]++;
        }

        int e = 0;
        int smallest = 1e9;
        int best;

        cout << goal << endl;

        for (int s = 0; s < str.size(); s++) {
            while (satisfied < goal) {
                if (e == str.size()) break;

                cnt1[str[e]]++;
                if (cnt1[str[e]] == cnt2[str[e]] && cnt2[str[e]] > 0) satisfied++;
                e++;
            }

            if (satisfied < goal && e == str.size()) break;

            cout << e << endl;

            int sz = e - s;

            if (sz < smallest) {
                best = s;
                smallest = sz;
            }

            if (cnt1[str[s]] == cnt2[str[s]] && cnt2[str[s]] > 0)  {
                satisfied--;
                cout << "T" << endl;
            }
            cnt1[str[s]]--;
        }

        return smallest == 1e9 ? "" : str.substr(best, smallest);
    }
};
