class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(q.size()!=0){
            int temp=q.front();
            q.pop();
            for(auto it:rooms[temp]){
                if(not visited.count(it)){
                    q.push(it);
                    visited.insert(it);
                }
            }
        }
        return visited.size()==rooms.size();
    }
};