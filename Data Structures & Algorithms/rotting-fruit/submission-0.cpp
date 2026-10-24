class Solution {
public:
    int drow[4] = {-1 , 0 , 1 , 0};
    int dcol[4] = {0 , 1 , 0 , -1};

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int fcount = 0;

        queue<pair<int,pair<int,int>>>q;

        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0 , {i , j}});
                }
              else  if(grid[i][j] == 1){
                    fcount++;
                }
            }
        }

        int maxi = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

             int steps = it.first;          
             int row   = it.second.first;   
             int col   = it.second.second; 

             maxi = max(maxi , steps);          

            for(int i =0;i<4;i++){
                int nrow = drow[i] + row;
                 int ncol = dcol[i] + col;

                 if(nrow>=0 && ncol>=0 && nrow < n && ncol < m &&
                    grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        fcount--;
                        q.push({steps + 1 , {nrow, ncol}});
                    }
            }
        }
         if(fcount == 0) return maxi;
         else return -1;
    }
};
