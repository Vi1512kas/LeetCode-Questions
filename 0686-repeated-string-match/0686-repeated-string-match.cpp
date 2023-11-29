class Solution {
public:
     bool f(string a, string b) {
        int n=a.length();
        int m=b.length();
        for(int i=0;i<=n-m;i++){
             int first = i,second = 0;
                while(second<m){
                    if(a[first]==b[second]){
                        first++;
                        second++;
                    }
                    else{
                        break;
                    }
                }
                if(second == m) return true;
        }
    return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        string c=a;
        int count = 1;
        int n = c.size();
        int m = b.size();
        while(n<m){
            c+=a;
            count++;
            n=c.size();
        }
        if(a==b) return count;
        if(f(c,b)) return count;
        if(f(a+c,b)) return count+1;
        else return -1;
        
        
    }
};