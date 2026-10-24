class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
     vector<int>totaltrust(n+1 , 0);

       for(auto it : trust){
        int a = it[0];
        int b = it[1];

        totaltrust[a]--;
        totaltrust[b]++;
       }

       for(int i =1;i<=n;i++){
         if(totaltrust[i] == n-1) return i;
       }
       return -1;
    }
};