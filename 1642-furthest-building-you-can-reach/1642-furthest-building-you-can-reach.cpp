class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int bu=0;
        int i=0;
        for(;i<heights.size()-1;i++){
            if(heights[i]>heights[i+1]) continue;
            int hd = heights[i+1]-heights[i];
            if(hd+bu<=bricks){
                bu+=hd;
                pq.push(hd);
            } else if(ladders>0){
                if(!pq.empty() and hd<pq.top()){
                    bu = bu - pq.top()+hd;
                    pq.pop();
                    pq.push(hd);
                    
                }
                ladders--; 
            }
            else{
                    break;
                }
        }
        return i;
        
    }
};