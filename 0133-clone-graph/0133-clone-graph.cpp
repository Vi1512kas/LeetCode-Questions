/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> cR;
    Node* cloneGraph(Node* n) {
        if(n==NULL) return NULL;
        Node* new_node = new Node(n->val);
        cR.resize(105,NULL);
        cR[new_node->val]=new_node;
        dfs(n,new_node);
        return new_node;
    }
    void dfs(Node* actual,Node* clone){
        for(auto it:actual->neighbors){
            if(not cR[it->val]){
                Node* new_node = new Node(it->val);
                cR[new_node->val]=new_node;
                clone->neighbors.push_back(new_node);
                dfs(it,new_node);
            }else{
               clone->neighbors.push_back(cR[it->val]); 
            }
        }
        
    }
};