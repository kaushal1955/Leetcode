class Solution {
public:
    bool sumGame(string num) {
       int n = num.size();
        long long s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') c1++;
            else s1 += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') c2++;
            else s2 += num[i] - '0';
        }

        int total = c1 + c2;
        if (total % 2 != 0) return true;   

        long long diff = s1 - s2;
        long long target = 9LL * (c2 - c1) / 2;
        return diff != target;  
    }
};