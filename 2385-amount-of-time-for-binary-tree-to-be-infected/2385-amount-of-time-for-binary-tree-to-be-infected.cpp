
class Solution {
public:
 TreeNode* first=NULL;
    void find(TreeNode* root,int st){
    // 1. find the given node in tree.
        if(root==NULL) return;
        if(root->val==st) first=root;
        find(root->left,st);
        find(root->right,st);
}
void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
    if(root==NULL) return;
    if(root->left!=NULL) mp[root->left]=root;
    if(root->right!=NULL) mp[root->right]=root;
    mark_parent(root->left,mp);
    mark_parent(root->right,mp);
}
int amountOfTime(TreeNode* root, int start) {
       if(root==NULL) return 0;
        find(root,start);
        // 2. Make Hashmap of parent and child using any traversal.
        unordered_map<TreeNode*,TreeNode*> mp;
        mark_parent(root,mp);
        unordered_set<TreeNode*> s;  // to check is infected or not.
        s.insert(first);
        int maxlevel=0;
        queue<pair<TreeNode*,int>> q; // q for bfs
        q.push({first,0});
        // bfs
        while(q.size()>0){
            pair<TreeNode*,int> p=q.front();
            q.pop();
            int level = p.second;
            TreeNode* temp = p.first;
            maxlevel=max(level,maxlevel);
            if(temp->left!=NULL){
                if(s.find(temp->left)==s.end()){
                    q.push({temp->left,level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right!=NULL){
                if(s.find(temp->right)==s.end()){
                    q.push({temp->right,level+1});
                    s.insert(temp->right);
                }
            }
            if(mp.find(temp)!=mp.end()){
                if(s.find(mp[temp])==s.end()){
                    q.push({mp[temp],level+1});
                    s.insert(mp[temp]);
                }
            }
        }
        return maxlevel;     
}
};