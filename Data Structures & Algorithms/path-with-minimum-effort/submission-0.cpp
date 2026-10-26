class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, -1, 0, 1};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

         priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>>dist(n , vector<int>(m , 1e9));

        pq.push({0, {0 , 0}});

        dist[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return dis;

            for(int i =0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m
                ){
                    int newMax = max(abs(heights[nrow][ncol] - heights[row][col]),
                                        dis);

                           if(newMax < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newMax;
                        pq.push({newMax, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};