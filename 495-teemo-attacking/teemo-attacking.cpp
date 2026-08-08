class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n= timeSeries.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            int interval=timeSeries[i+1]-timeSeries[i];
            cnt +=min(interval,duration);
        }
        return cnt+duration;
    }
};