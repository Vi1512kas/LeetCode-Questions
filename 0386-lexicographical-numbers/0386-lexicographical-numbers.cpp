class Solution {
public:
    void f(int i,int n,vector<int> &ans){
        if(i>n) return;
        if(i<=n and i!=0){
            ans.push_back(i);
        }
        if(i!=0){
            for(int j=0;j<=9;j++){
                f(10*i+j,n,ans);
            }
        } else{
            for(int j=1;j<=9;j++){
                f(10*i+j,n,ans);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        f(0,n,ans);
        return ans;
    }
};