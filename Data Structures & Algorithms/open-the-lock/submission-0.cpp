class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";

        unordered_set<string>dead(deadends.begin() , deadends.end());

        unordered_set<string> visited;
        queue<pair<string, int>> q;

        if (dead.count("0000"))
            return -1;

        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [current, moves] = q.front();
            q.pop();

            if (current == target)
                return moves;

            for (int i = 0; i < 4; i++) {
                string up = current;
                up[i] = (current[i] - '0' + 1) % 10 + '0';

                string down = current;
                down[i] = (current[i] - '0' + 9) % 10 + '0';

                if (!dead.count(up) && !visited.count(up)) {
                    visited.insert(up);
                    q.push({up, moves + 1});
                }

                if (!dead.count(down) && !visited.count(down)) {
                    visited.insert(down);
                    q.push({down, moves + 1});
                }
            }
        }

        return -1;
    }
};