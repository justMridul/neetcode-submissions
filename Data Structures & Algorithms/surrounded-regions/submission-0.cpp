class Solution {
public:
     int drow[4] = {-1 , 0 , 1 , 0};
     int dcol[4] = {0 , 1 , 0 , -1};

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>>q;

        //row check
         for(int i = 0;i<m;i++){
            if(board[0][i] == 'O'){
                 board[0][i] = '#';
              q.push({0 , i});
            }
         }

         // row2 check
         for(int i =0; i<m; i++){
            if(board[n-1][i] == 'O'){
                 board[n-1][i] = '#';
                q.push({n-1 , i});
            }
         }

         // col check
          for(int i =0;i<n;i++){
            if(board[i][0] == 'O'){
                board[i][0] = '#';
                q.push({i , 0});
            }
          }

          //col2 check
          for(int i = 0;i<n;i++){
            if(board[i][m-1] == 'O'){
                board[i][m-1] = '#';
                q.push({i , m-1});
            }
          }

          while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

          q.pop();

          for(int i = 0;i<4;i++){

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
            board[nrow][ncol] == 'O'){
                board[nrow][ncol] = '#';
                q.push({nrow , ncol});
               }
          }
          }
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded 'O' -> Flip to 'X'
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O'; // Safe boundary-connected '#' -> Revert to 'O'
                }
            }
        }

    }
};
