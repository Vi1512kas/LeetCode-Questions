class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
    void dfs(vector<vector<int>> &image,int cR,int cC,int ic,int c){
        int n=image.size();
        int m=image[0].size();
        if(cR<0||cC<0||cR>=n||cC>=m) return;
        if(image[cR][cC]!=ic){
            return;
        }
        image[cR][cC]=c;
        dfs(image,cR+1,cC,ic,c);
        dfs(image,cR,cC+1,ic,c);
        dfs(image,cR-1,cC,ic,c);
        dfs(image,cR,cC-1,ic,c);
    }
};