class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();

        string ans = "";

        for(int i =0;i<n;i++){
            string s = strs[i];
            int m = s.size();

            ans += to_string(m); 
           ans += '_';

            ans += s; 
        }
        return ans;
    }

    vector<string> decode(string s) {
       vector<string> ans;
    int n = s.size();
    int i = 0; // Use an explicit pointer variable

    // FIXED: Use a while loop instead of a for loop to prevent automatic 'i++' conflicts
    while (i < n) {
        int pos = s.find('_', i);
        
        string found = s.substr(i, pos - i);

        // FIXED: Convert the string length ("5") to an actual integer (5)
        int len = stoi(found); 

        i = pos + 1;
        
        string originalStr = s.substr(i, len);
        ans.push_back(originalStr);

        // FIXED: Move the pointer past the word you just extracted 
        // to set up the next iteration
        i += len; 
    }
    
    return ans;
    }
};
