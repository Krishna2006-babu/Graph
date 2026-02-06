class Solution {
public:
    vector<int> result;
    vector<vector<int>> adj;
    string labels;

    vector<int> dfs(int curr, int parent) {
        vector<int> freq(26, 0);

        for(int child : adj[curr]) {
            if(child == parent) continue;

            vector<int> childFreq = dfs(child, curr);

            for(int i = 0; i < 26; i++) {
                freq[i] += childFreq[i];
            }
        }

        // include current node's label
        freq[labels[curr] - 'a']++;

        // store result
        result[curr] = freq[labels[curr] - 'a'];

        return freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->labels = labels;

        adj.resize(n);
        result.resize(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return result;
    }
};
