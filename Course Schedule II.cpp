class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        // Build graph
        for (auto &it : prerequisites) {
            int u = it[1]; // prerequisite
            int v = it[0]; // course
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (auto next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // Cycle check
        if (result.size() != n)
            return {};

        return result;
    }
};
