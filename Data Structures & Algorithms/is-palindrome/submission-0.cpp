class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        int low = 0;
        int high = n-1;

        while(low < high){
          char c1 = tolower(s[low]);
          char c2 = tolower(s[high]);

          if (isalnum(c1) && isalnum(c2)) { 
            if (c1 != c2) return false;
            low++;
            high--;
        } 
          else{

            if(!isalnum(c1)){
                low++;
            }
            
         if(!isalnum(c2)){
                high--;
            }
          }
        }
        return true; 
    }
};
