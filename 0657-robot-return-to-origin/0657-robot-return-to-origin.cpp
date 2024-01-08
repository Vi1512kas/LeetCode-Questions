class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.size()%2!=0) return false;
        int v=0,u=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                v++;
            }
            else if(moves[i]=='D') v--;
            else if(moves[i]=='L') u++;
            else if(moves[i]=='R') u--;
        }
        return u==0 and v==0;
    }
};