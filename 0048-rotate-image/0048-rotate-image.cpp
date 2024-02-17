class Solution {
public:
    void transpose(vector<vector<int>> &m){
        int r = m.size();
        int c = m[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<r;j++){
                if(i<j){
                    swap(m[i][j],m[j][i]);
                }
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int x=0;
        int y=matrix[0].size()-1;
        int s=matrix.size();
        while(x<y){
            for(int i=0;i<s;i++){
                swap(matrix[i][x],matrix[i][y]);
            }
            x++;
            y--;
        }
        
    }
};