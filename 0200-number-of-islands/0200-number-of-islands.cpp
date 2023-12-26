class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int cc = 0; // stores the number of connected components
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '0') {
                    // it is a water body
                    continue;
                }
                // new unvisited land piece found, i.e. new connected component
                cc++;
                grid[r][c] = '0'; // mark it visited
                queue<pair<int, int> > qu;
                qu.push({r, c}); // store the src node
                while(not qu.empty()) {
                    auto curr = qu.front(); // get one node from queue
                    qu.pop();
                    // go to all unvisited neighbours of the curr node
                    int currRow = curr.first;
                    int currCol = curr.second;
                    // check up
                    if(currRow - 1 >= 0 and grid[currRow - 1][currCol] == '1') {
                        qu.push({currRow-1, currCol});
                        grid[currRow - 1][currCol] = '0';
                    }
                    // check down
                    if(currRow + 1 < rows and grid[currRow + 1][currCol] == '1') {
                        qu.push({currRow+1, currCol});
                        grid[currRow + 1][currCol] = '0';
                    }
                    // check left
                    if(currCol - 1 >= 0 and grid[currRow][currCol-1] == '1') {
                        qu.push({currRow, currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    // check right
                    if(currCol + 1 < cols and grid[currRow][currCol+1] == '1') {
                        qu.push({currRow, currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }
                }
            }
        }
        
        return cc;
    }
    // int numIslands(vector<vector<char>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]=='0'){
    //                 continue;
    //             }
    //             cnt++;
    //             grid[i][j]='0';
    //             // cout<<i<<" "<<j<<endl;
    //             queue<pair<int,int>> qu;
    //             qu.push({i,j});
    //             while(not qu.empty()){
    //                 auto temp=qu.front();
    //                 qu.pop();
    //                 int cr = temp.first;
    //                 int cc = temp.second;
    //                 if(cr-1>=0 and grid[cr-1][cc]=='1'){
    //                     qu.push({cr-1,cc});
    //                     grid[cr-1][cc]=='0';
    //                 }
    //                 if(cr+1<n and grid[cr+1][cc]=='1'){
    //                     qu.push({cr+1,cc});
    //                     grid[cr+1][cc]=='0';
    //                 }
    //                 if(cc-1>=0 and grid[cr][cc-1]=='1'){
    //                     qu.push({cr,cc-1});
    //                     grid[cr][cc-1]=='0';
    //                 }
    //                 if(cc+1<m and grid[cr][cc+1]=='1'){
    //                     qu.push({cr,cc+1});
    //                     grid[cr][cc+1]=='0';
    //                 }
    //             }
    //         }
    //     }
    //     return cnt;
    // }
};