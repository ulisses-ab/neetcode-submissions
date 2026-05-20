class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;

            for (int x : v) {
                h ^= hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }

            return h;
        }
    };

    vector<int> get_char_count(string& s) {
        vector<int> out(26, 0);

        for (char c : s) {
            out[c - 'a']++;
        }

        return out;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHash> m;

        for (auto& str : strs) {
            m[get_char_count(str)].push_back(str);
        }

        vector<vector<string>> out;

        for (auto& p : m) {
            out.push_back(p.second);
        }

        return out;
    }
};