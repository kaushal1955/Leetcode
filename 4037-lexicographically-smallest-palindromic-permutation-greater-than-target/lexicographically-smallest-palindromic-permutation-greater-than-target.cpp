class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
       
        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++) {
            if (freq[c] % 2 == 1) { oddCount++; oddChar = c; }
        }
        int mid = -1;
        char midVal = 0;
        if (n % 2 == 0) {
            if (oddCount != 0) return "";
        } else {
            if (oddCount != 1) return "";
            mid = n / 2;
            midVal = (char)('a' + oddChar);
        }
        
        int h = n / 2;
        vector<int> halfBase(26);
        for (int c = 0; c < 26; c++) halfBase[c] = freq[c] / 2;
        
        for (int p = n - 1; p >= 0; p--) {
            vector<int> half(h, -1); 
            vector<int> usage = halfBase;
            bool valid = true;
            
            
            for (int i = 0; i < p && valid; i++) {
                if (i == mid) {
                    if (midVal != target[i]) valid = false;
                    continue;
                }
                int r = min(i, n - 1 - i);
                int c = target[i] - 'a';
                if (half[r] == -1) {
                    if (usage[c] <= 0) { valid = false; break; }
                    usage[c]--;
                    half[r] = c;
                } else if (half[r] != c) {
                    valid = false;
                }
            }
            if (!valid) continue;
            
            
            if (p == mid) {
                if (!(midVal > target[p])) continue;
            } else {
                int r = min(p, n - 1 - p);
                int tc = target[p] - 'a';
                if (half[r] != -1) {
                    if (half[r] <= tc) continue; 
                } else {
                    int chosen = -1;
                    for (int c = tc + 1; c < 26; c++) {
                        if (usage[c] > 0) { chosen = c; break; }
                    }
                    if (chosen == -1) continue;
                    usage[chosen]--;
                    half[r] = chosen;
                }
            }
            
            vector<int> remain;
            for (int c = 0; c < 26; c++)
                for (int k = 0; k < usage[c]; k++)
                    remain.push_back(c);
            int ptr = 0;
            for (int r = 0; r < h; r++) {
                if (half[r] == -1) half[r] = remain[ptr++];
            }
            
        
            string result(n, '?');
            for (int i = 0; i < n; i++) {
                if (i == mid) result[i] = midVal;
                else result[i] = (char)('a' + half[min(i, n - 1 - i)]);
            }
            return result;
        }
        
        return "";
    }
};