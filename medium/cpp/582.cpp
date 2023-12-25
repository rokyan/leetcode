// https://leetcode.com/problems/kill-process/description/

class Solution {

public:

    std::unordered_map<int, std::vector<int>> tree;

    std::vector<int> answer;

    

    void dfs(int node, int parent, int kill, bool need_to_add) {

        need_to_add = need_to_add || kill == node;

        

        if (need_to_add) {

            answer.push_back(node);

        }

        

        for (auto to : tree[node]) {

            if (to != parent) {

                dfs(to, node, kill, need_to_add);

            }

        }

    }

    

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {

        auto root = -1;

        

        for (auto i = 0; i < pid.size(); ++i) {

            if (ppid[i] != 0) {

                tree[ppid[i]].push_back(pid[i]);

            } else {

                root = pid[i];

            }

        }

        

        assert(root != -1);

        

        dfs(root, -1, kill, false);

        

        return answer;

    }

};