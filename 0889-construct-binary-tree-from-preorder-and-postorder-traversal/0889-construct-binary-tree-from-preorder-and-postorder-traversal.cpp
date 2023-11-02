
class Solution {
public:
TreeNode* solve(vector<int>& pre,int prelo,int prehigh,vector<int>& po,int plo,int phi){
      if(prelo>prehigh) return NULL;
      TreeNode* root=new TreeNode(pre[prelo]);
      if(prelo==prehigh) return root;
      int i=plo;
      while(i<=phi){
          if(pre[prelo+1]==po[i]) break;
          i++;
      }
      int lc=i-plo+1;
      int rc=phi-1-i;
      root->left=solve(pre,prelo+1,prelo+lc,po,plo,i);
      root->right=solve(pre,prelo+lc+1,prehigh,po,i+1,phi-1);
      return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        if(n==-1) return NULL;
        return solve(preorder,0,n-1,postorder,0,n-1);
    }
};