class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set<char> row[9] , col[9] , boxes[9];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char val = board[i][j];

                if(val == '.')continue;

                if(row[i].count(val)) return false;
                if(col[j].count(val)) return false;

                int boxInd = (i/3)*3 + (j/3);

                if(boxes[boxInd].count(val)) return false;

                row[i].insert(val);
                col[j].insert(val);
                boxes[boxInd].insert(val);
            }
        }
        return true;
    }
};
