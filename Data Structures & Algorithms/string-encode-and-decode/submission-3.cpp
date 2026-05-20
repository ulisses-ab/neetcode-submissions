class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";

        for (auto& s : strs) {
            output += to_string(s.size());
            output += "#";
            output += s;
        }

        return output;
    }

    vector<string> decode(string s) {
        int p = 0;
        vector<string> output;

        while (p < s.size()) {
            string number = "";

            while (s[p] != '#') {
                number += s[p];
                p++;
            }

            p++;

            int n = stoi(number);
            int end = p + n;
            string current = "";

            for (; p < end; p++) {
                current += s[p];
            }

            output.push_back(current);
        }

        return output;
    }
};

/*
    5#Hello5#World
*/