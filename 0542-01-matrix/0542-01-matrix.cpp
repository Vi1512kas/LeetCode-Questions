class Solution {
public:
    // we are doing multisource dfs from all zeroes.
    vector<vector<int>> newMatrix;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        newMatrix.resize(r,vector<int>(c,-1));
        queue<pair<int,int>> qu;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    newMatrix[i][j]=0;
                    qu.push({i,j});
                }
            }
        }
        
        while(! qu.empty()){
            auto temp = qu.front();
            qu.pop();
            int i = temp.first;
            int j = temp.second;
            for(int k=0;k<4;k++){
                int nr = i+dir[k][0];
                int nc = j+dir[k][1];
                if (nr < 0 || nr == r || nc < 0 || nc == c || newMatrix[nr][nc] != -1) continue;
                newMatrix[nr][nc] = newMatrix[i][j]+1;
                qu.push({nr,nc});
            }
            
            
        }
        return newMatrix;
        
    }
};