class Solution {
public:
    
//     int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//     void solve(vector<vector<char>>& board) {
//     int arr[200][200]={0};
//        int r=board.size();
//         int c=board[0].size();
//         queue<pair<int,int>> qu;
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                if(board[i][j]=='O'){
//                    if(i==0||j==0||i==(r-1)||j==(c-1)){
//                        qu.push({i,j});
//                        board[i][j]=1;
//                    }
//                } 
//             }
//         }
        
//         while(not qu.empty()){
//             auto [r,c] = qu.front();
//             qu.pop();
//             board[r][c] = 'A';
//             for(int k=0;k<4;k++){
//                 int nr = r+dir[k][0];
//                 int nc = c+dir[k][1];
//                 if(nr>r||nr<0||nc>c||nc<0||board[nr][nc]=='X'||board[nr][nc]==1) continue;
//                 qu.push({nr,nc});
//             }
//         }
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                 if(board[i][j]=='O') board[i][j]='X';
//                 if(board[i][j]=='A') board[i][j]='O'; 
//             }
//         }
//     }
    void bfs(queue<pair<int,int>> q, vector<vector<char>> &arr){

        vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
        int n = arr.size();
        int m = arr[0].size();

        while(q.size()!=0){
            auto [i,j] = q.front();
            q.pop();
            arr[i][j]='Y';

            for(int k=0; k<4; k++){
                int nr = i+dir[k][0];
                int nc = j+dir[k][1];

                if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc]=='O'){
                    arr[nr][nc]='Y';
                    q.push({nr,nc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            if(arr[i][0]=='O'){
                q.push({i,0});
            }
            if(arr[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }

        for(int j=1; j<m-1; j++){
            if(arr[0][j]=='O') q.push({0,j});
            if(arr[n-1][j]=='O') q.push({n-1,j});
        }


        bfs(q,arr);


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]=='Y') arr[i][j]='O';
                else if(arr[i][j]=='O') arr[i][j] = 'X';
            }
        }
    }
};