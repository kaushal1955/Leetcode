class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int totalOnes=count(s.begin(),s.end() ,'1');
        if(totalOnes<k)return "";
        string best="";
        int left=0,ones=0;

        for(int right=0;right<n;right++){
            if(s[right]=='1')ones++;

            while(ones==k){
                if (s[left] == '0') {  
                    left++;
                    continue;
                }
                string candidate = s.substr(left, right - left + 1);
                if (best.empty() || candidate.size() < best.size() ||(candidate.size() == best.size() && candidate < best)) {
                    best = candidate;
                }
                left++;
                ones--;
            }
        }
        return best;
    }
};