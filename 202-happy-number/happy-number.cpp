class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> visit;

        while (n != 1) {
            if (visit.count(n))
                return false;

            visit.insert(n);
            n = getNext(n);
        }

        return true;
    }
};