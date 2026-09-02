class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state){
        if (state[node] == 1) {
            return true;
        }
        if (state[node] == 2) {
            return false;
        }
        state[node] = 1;
        for (int neighbor : adj[node]) {
            if (dfs(neighbor, adj, state)) {
                return true;
            }
        }
        state[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &pre:prerequisites){
            int course=pre[0];
            int prerequisite=pre[1];
            adj[prerequisite].push_back(course);
        }
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state)) {
                    return false;
                }
            }
        }
        return true;
    }
};