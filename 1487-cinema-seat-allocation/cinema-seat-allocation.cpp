class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;

        for(auto & x:reservedSeats){
            mp[x[0]].insert(x[1]);

        }
        int ans= 2*n;
        for(auto &[row,seats]:mp){
            bool left=true;
            bool right=true;
            bool middle= true;
            for(int i=2;i<=5;i++){
                if(seats.count(i)){
                    left= false;
                    break;
                }
                
            }
            for(int i=6;i<=9;i++){
                if(seats.count(i)){
                    right= false;
                    break;
                }

            }
            for(int i=4;i<=7;i++){
                if(seats.count(i)){
                    middle=false;
                    break;
                }
            }
            ans -=2;
            if(left && right){
                ans +=2;

            }else if(left|| right|| middle){
                ans +=1;
            }

            
        }
        return  ans;
        
    }

};