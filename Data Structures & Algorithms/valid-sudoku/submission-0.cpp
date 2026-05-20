class Solution {
public:
    bool check_col(int j, vector<vector<char>>& board) {
        bool seen[10];
        for (int i = 0; i < 10; i++) seen[i] = false;

        for (int i = 0; i < 9; i++) {
            char c = board[i][j];
            
            if (c == '.') continue;

            if (seen[c-'0']) return false;

            seen[c-'0'] = true;
        }

        return true;
    }

    bool check_row(int i, vector<vector<char>>& board) {
        bool seen[10];
        for (int i = 0; i < 10; i++) seen[i] = false;

        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            
            if (c == '.') continue;

            if (seen[c-'0']) return false;

            seen[c-'0'] = true;
        }

        return true;
    }

    bool check_square(int si, int sj, vector<vector<char>>& board) {
        bool seen[10];
        for (int i = 0; i < 10; i++) seen[i] = false;

        for (int i = si; i < si+3; i++) {
            for (int j = sj; j < sj+3; j++) {
                char c = board[i][j];
                
                if (c == '.') continue;

                if (seen[c-'0']) return false;

                seen[c-'0'] = true;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!check_row(i, board)) return false;
        }

        for (int i = 0; i < 9; i++) {
            if (!check_col(i, board)) return false;
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!check_square(i, j, board)) return false;
            }
        }    

        return true;
    }
};
