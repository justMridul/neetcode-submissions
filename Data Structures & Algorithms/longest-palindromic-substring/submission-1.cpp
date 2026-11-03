class Solution {
public:
    string longestPalindrome(string s) {
           int n = s.size();
    if (n == 0) return "";

   
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int maxi = 1; 
    int sp = 0;  

  
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            sp = i;
            maxi = 2;
        }
    }

    
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // Ending index of current substring

            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                
                if (len > maxi) {
                    maxi = len;
                    sp = i;
                }
            }
        }
    }

    return s.substr(sp, maxi);

    }
};
