class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int num =left;num<=right;num++){
            int x= num;
            bool ok= true;

            while(x>0){
                int digit=x%10;

                if(digit==0 ||num % digit !=0){
                    ok=false;
                    break;
                }
                x/=10;
            }
            if(ok)
            ans.push_back(num);

        }
        return ans;
    }
};