class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // vector<vector<int>> ans;
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
    void dfs(vector<vector<int>> &image,int sr,int sc,int intial_color,int color){
        
        
        if(sr>=image.size() || sr<0 || sc<0 || sc>=image[0].size()) return;
        if(image[sr][sc]!=intial_color) return;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,intial_color,color);
        dfs(image,sr,sc+1,intial_color,color);
        dfs(image,sr-1,sc,intial_color,color);
        dfs(image,sr,sc-1,intial_color,color);
        
    }
};