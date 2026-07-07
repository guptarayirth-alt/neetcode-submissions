class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char k = board[i][j];
                if(k == '.') continue;
                if(row[i].count(k)) {
                    return false;
                }
                row[i].insert(k);
                if(col[j].count(k)) {
                    return false;
                }
                col[j].insert(k);
                int Index = (i / 3) * 3 + (j / 3);
                if(box[Index].count(k)) {
                    return false;
                }
                box[Index].insert(k);
            }
        } 
        return true; 
    }
};