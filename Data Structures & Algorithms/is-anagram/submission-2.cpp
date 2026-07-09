class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        unordered_map<char,int>mp;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        for(int j=0;j<m;j++){
            if (--mp[t[j]] < 0) return false;
        }

        return true;
    }
};
