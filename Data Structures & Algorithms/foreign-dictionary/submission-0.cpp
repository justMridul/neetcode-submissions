class Solution {
public:
    
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark characters present in words
        for (string& word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < (int)words.size() - 1; i++) {
            string& s1 = words[i];
            string& s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            int j = 0;

            while (j < len && s1[j] == s2[j]) {
                j++;
            }

            // Invalid prefix case
            if (j == len) {
                if (s1.size() > s2.size()) {
                    return "";
                }
                continue;
            }

            int u = s1[j] - 'a';
            int v = s2[j] - 'a';

            // Avoid duplicate edges
            bool exists = false;

            for (int neighbor : adj[u]) {
                if (neighbor == v) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        // Initialize BFS
        queue<int> q;
        int uniqueCount = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                uniqueCount++;

                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        // Topological sort
        string ans = "";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Detect cycle
        if (ans.size() != uniqueCount) {
            return "";
        }

        return ans;
    }
};
