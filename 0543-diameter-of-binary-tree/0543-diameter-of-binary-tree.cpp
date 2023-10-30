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
int height(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
void solve(TreeNode* root,int &d){
       if(root==NULL) return;
       int h=height(root->left);
       int hr=height(root->right);
       solve(root->left,d);
       solve(root->right,d);
       d=max(d,h+hr);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        solve(root,d);
        return d;
    }
};