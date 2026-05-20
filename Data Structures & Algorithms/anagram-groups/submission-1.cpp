class Solution {
public:
    vector<int> get_char_count(string& s) {
        vector<int> out(26, 0);

        for (auto c : s) {
            out[c-'a']++;
        }

        return std::move(out);
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;

        for (auto str : strs) {
            m[get_char_count(str)].push_back(str);
        }

        vector<vector<string>> out;

        for (auto p : m) {
            out.push_back({});

            for (auto s : p.second) {
                out.back().push_back(s);
            }
        }

        return out;
    }
};
