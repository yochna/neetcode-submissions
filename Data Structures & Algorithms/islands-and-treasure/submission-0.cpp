class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int,int>> q;
        int INF = 2147483647;

        // Push all TREASURE chests (0s) into queue
        // and convert all islands (1s) to INF
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(rooms[r][c] == 0) {
                    q.push({r, c});  // treasure = distance 0
                } else if(rooms[r][c] == 1) {
                    rooms[r][c] = INF;  // island needs distance
                }
            }
        }
        
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // Multi-source BFS from all treasure chests
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            for(auto [dr, dc] : dirs){
                int nr = r + dr, nc = c + dc;
                
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || rooms[nr][nc] != INF)
                    continue;
                
                rooms[nr][nc] = rooms[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};