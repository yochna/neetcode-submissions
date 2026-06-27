class Solution {
public:
vector<vector<int>>adj;
vector<int>state;
bool dfs(int node){
    state[node]=1;
    for(int n:adj[node]){
        if(state[n]==1)return true;
        if(state[n]==0 &&dfs(n))return true;
    }
    state[node]=2;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        state.assign(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(state[i]==0 &&dfs(i))return false;
        }
        return true;
    }
};
