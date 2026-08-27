class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.size();
        unordered_set<char>vowels={'a','e','i','o','u'};
        int count=0;
        for(int i=0;i<n;i++){
            if (vowels.find(word[i]) == vowels.end()) continue;

            unordered_set<char>seen;
            for(int j=i;j<n;j++){
                if (vowels.find(word[j]) == vowels.end()) break; 
                seen.insert(word[j]);
                if (seen.size() == 5) count++;
            }
            
        }
        return count;
    }
};