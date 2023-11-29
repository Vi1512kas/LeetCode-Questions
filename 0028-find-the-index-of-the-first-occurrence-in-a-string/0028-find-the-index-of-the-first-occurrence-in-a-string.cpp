class Solution {
public:
    int strStr(string a, string b) {
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
    if(second == m) return first-second;
  }
  return -1;
    }
};