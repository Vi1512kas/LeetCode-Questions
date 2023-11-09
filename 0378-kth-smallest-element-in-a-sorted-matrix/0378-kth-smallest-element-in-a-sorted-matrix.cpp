#define pp pair<int,pair<int,int>>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        for(int i=0;i<matrix.size();i++){
            pq.push({matrix[i][0],{i,0}});
        }
        pp ans;
        while(k-- && !pq.empty()){
           ans = pq.top();
            pq.pop();
            int data=ans.first;
            int row=ans.second.first;
            int col=ans.second.second;
            if(col+1<matrix[row].size()){
                pq.push({matrix[row][col+1],{row,col+1}});
            }
        }
        return ans.first;
        
    }
};