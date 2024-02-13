class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<int> ans;
    vector<int> arr2(26, 0);

    // creating count mapping for p string characters
    for (char ch : p) {
        int index = ch - 'a';
        arr2[index]++;
    }

    int k = m;
    int i = 0, j = 0;

    while (j < n) {
        // calculation
        int index = s[j] - 'a';
        arr2[index]--;

        // move j until it reaches the window size k
        if (j - i + 1 < k) {
            j++;
        } else if (j - i + 1 == k) {
            // calculate the answer
          bool allZero = true;
          for (int count : arr2) {
              if (count != 0) {
                  allZero = false;
                  break;  // exit the loop as soon as a non-zero count is found
              }
          }

          if (allZero) {
              ans.push_back(i);
          }

            // Undo the change for the character leaving the window
            arr2[s[i] - 'a']++;

            // slide the window
            i++;
            j++;
        }
    }

    return ans;
    }
};