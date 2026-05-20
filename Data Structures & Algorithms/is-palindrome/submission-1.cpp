class Solution {
public:
    string normalize(string s) {
        string out = "";

        for (auto c : s) {
            if (isalpha(c) || isdigit(c)) {
                out.push_back(tolower(c));
            }
        } 

        return out;
    } 

    bool isPalindrome(string s) {
        s = normalize(s);

        for (int l = 0, r = s.size()-1; l < r; l++, r--) {
            if (s[l] != s[r]) return false;
        }      

        return true;
    }
};