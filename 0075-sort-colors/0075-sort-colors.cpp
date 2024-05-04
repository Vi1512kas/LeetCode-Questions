class Solution {
public:
    void sortColors(vector<int>& array) {
        int n=array.size();
      int zero_count = 0, one_count = 0,two_count=0;
      for (int i = 0; i < n; i++) {
        if (array[i] == 0) zero_count++;
        else if(array[i]==1) one_count++;
        else two_count++;
      }
      for (int i = 0; i < n; i++) {
            if (zero_count) {
              array[i] = 0;
              zero_count--;
            }
            else if(one_count) {
              array[i] = 1;
              one_count--;
            }
            else{
              array[i]=2;
              two_count--;
            }
        }
    }
};