class Solution {
public:
    vector<pair<int,int>> internal;
    void dfs(vector<vector<int>> &grid,int r,int c,int newColor,int oc){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]!=oc) return;
        grid[r][c]=-newColor;
        dfs(grid,r+1,c,newColor,oc);
        dfs(grid,r,c+1,newColor,oc);
        dfs(grid,r-1,c,newColor,oc);
        dfs(grid,r,c-1,newColor,oc);
        
        //below executed when coming out.
        if(not (r==0||c==0||r==grid.size()-1||c==grid[0].size()-1||grid[r+1][c]!=-newColor||grid[r-1][c]!=-newColor||grid[r][c-1]!=-newColor||grid[r][c+1]!=-newColor)){
            internal.push_back({r,c});
            
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r, int c, int color){
        int oc = grid[r][c];
        if(oc==color) return grid;
        dfs(grid,r,c,color,oc);
        for(auto p:internal){
            grid[p.first][p.second]=oc;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0) grid[i][j]*=-1;
            }
        }
        return grid; 
    }
};
      