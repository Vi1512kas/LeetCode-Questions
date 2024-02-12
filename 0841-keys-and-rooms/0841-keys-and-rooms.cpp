class Solution {
public:
    vector<bool> vis;
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vis.resize(n, false);
        vis[0] = true; // Mark the first room as visited
        
        dfs(rooms, 0); // Start DFS from the first room
        
        // Check if all rooms are visited
        for (bool visited : vis) {
            if (!visited) {
                return false;
            }
        }
        
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, int currentRoom) {
        for (int nextRoom : rooms[currentRoom]) {
            if (!vis[nextRoom]) {
                vis[nextRoom] = true;
                dfs(rooms, nextRoom);
            }
        }
    }
};
