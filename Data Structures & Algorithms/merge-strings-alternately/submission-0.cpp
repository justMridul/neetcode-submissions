class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        string ans = "";

        int low = 0;
       int high = 0;

        int mini = min(n , m);

        while(low < mini){
         ans += word1[low++];
         ans += word2[high++];
        }

        while(low < n){
            ans += word1[low];
            low++;
        }

        while(high < m){
          ans += word2[high];
          high++;
        }
        return ans;
    }
};