class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

       int index = 0;
       int extra = 0;
       int balance = 0;


       for(int i =0;i<n;i++){

        int curr = gas[i] - cost[i];
          extra += curr;
          balance += curr;

         if(balance < 0){
            balance = 0;
            index = i + 1;
         }
       }
       if(extra < 0) return -1;
       return index;
    }
};
