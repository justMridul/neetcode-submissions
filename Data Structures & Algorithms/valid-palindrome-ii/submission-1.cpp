class Solution {
public:
    bool ispalindrome(int low , int high , string &s){
        while(low < high){
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int cnt = 0;

        int low = 0;
        int high = n-1;

        while(low < high){

           if(s[low] != s[high]){

            return ispalindrome(low+1 , high , s) ||
             ispalindrome(low , high - 1, s);
           }
           low++;
           high--;
        }
        return true;
    }
};