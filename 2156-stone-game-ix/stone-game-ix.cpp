class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};
        for(int s:stones){
            count[s%3]++;
        }
        if(count[0]%2==0){
            return min(count[1],count[2])>0;
        }else{
            return abs(count[1]-count[2])>2;
        }
    }
};