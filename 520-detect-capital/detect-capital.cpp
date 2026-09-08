class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount=0;
        for(char c:word){
            if(isupper(c)) upperCount++;
        }
        if(upperCount==0 || upperCount==word.size()){
            return true;
        }
        if(upperCount==1 && isupper(word[0])){
            return true;
        }
        return false;
    }
};