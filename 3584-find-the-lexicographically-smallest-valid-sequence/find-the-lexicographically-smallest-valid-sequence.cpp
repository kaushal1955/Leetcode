class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        // suf[i] = max length of a suffix of word2 that can be matched
        // as a subsequence within word1[i..n-1]
        vector<int> suf(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = m - 1 - j;
        }
        
        vector<int> ans;
        j = 0;
        bool changed = false;
        
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!changed && suf[i + 1] >= m - j - 1) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }
        
        if (j != m) return {};
        return ans;
    }
};