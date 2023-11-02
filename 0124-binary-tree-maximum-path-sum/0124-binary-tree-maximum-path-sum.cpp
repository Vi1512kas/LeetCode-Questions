/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max(int a,int b){
        if(a>b) return a;
        else return b;
    }
    int solve(TreeNode *root,int &maxi){
        if(root==NULL) return 0;
        int lf = max(0,solve(root->left,maxi));
        int rf = max(0,solve(root->right,maxi));
        maxi =  max(maxi,root->val+lf+rf);
        return root->val + max(lf,rf);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root,maxi);
        return maxi; 
    }
};