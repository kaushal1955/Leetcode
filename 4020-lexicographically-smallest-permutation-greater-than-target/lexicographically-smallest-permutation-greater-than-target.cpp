class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        int bestIdx = -1, bestChar = -1;
        vector<int> bestFreqSnapshot;
        
        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';
            
            int greaterLetter = -1;
            for (int c = t + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    greaterLetter = c;
                    break;
                }
            }
            
            if (greaterLetter != -1) {

                freq[greaterLetter]--;
                bestIdx = i;
                bestChar = greaterLetter;
                bestFreqSnapshot = freq;
                freq[greaterLetter]++;
            }
            
            
            if (freq[t] > 0) {
                freq[t]--;
            } else {
                break;
            }
        }
        
        if (bestIdx == -1) return "";
        string result = target.substr(0, bestIdx) + (char)('a' + bestChar);
        for (int c = 0; c < 26; c++) {
            result += string(bestFreqSnapshot[c], (char)('a' + c));
        }
        
        return result;
    }
};