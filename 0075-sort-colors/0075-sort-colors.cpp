class Solution {
public:
    void sortColors(vector<int>& array) {
       int l = 0, m = 0, h = array.size() - 1;
       while (l <= h) {
            if (array[l] == 2) {
            swap(array[l], array[h]);
            h--;
            }
            else if (array[l] == 0) {
              swap(array[m], array[l]);
              m++;
              l++;
            }
            else {
              l++;
            }
        }
    }
};