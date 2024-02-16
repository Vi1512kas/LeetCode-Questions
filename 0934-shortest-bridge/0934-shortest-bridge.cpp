class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    
    bool check(int i,int j,int r,int c){
        if(i<0||j<0||i>=r||j>=c) return false;
        return true;
    }
    void markisland(vector<vector<int>>& grid,int i,int j){
        grid[i][j]=-1;
        for(int k=0;k<4;k++){
            int nr = i+dir[k][0];
            int nc = j+dir[k][1];
            if(check(nr,nc,grid.size(),grid[0].size()) && grid[nr][nc]==1){
                markisland(grid,nr,nc);
            }
        }
         
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        
        bool flag=true;
        // mark one group of island as -1.
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    flag = false;
                    markisland(grid,i,j);
                    break;
                }
            }
            if(flag==false) break;
        }
        
        // queue that represent flips on a particular path
        queue<pair<int, int>> q;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == -1) {
                    q.push({i * r + j, 0});
                }
            }
        }
        while(not q.empty()){
            auto [index,flips]=q.front();
            int i = index / r;
            int j = index % r;
            q.pop();
        for (int k = 0; k < 4; ++k)
            {
               int nr = i+dir[k][0];
               int nc = j+dir[k][1];
                int next_index = nr * r + nc;

                if (check(nr, nc, r, c)) {
                    if (grid[nr][nc] == 1) return flips;

                    if (grid[nr][nc] == -1) continue;

                    q.push({next_index, flips + 1});

                    grid[nr][nc] = -1;
                }
            }

        }
        return -1;   
    }
};