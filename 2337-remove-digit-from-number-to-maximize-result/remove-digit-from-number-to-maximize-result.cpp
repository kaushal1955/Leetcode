class Solution {
public:
    string removeDigit(string number, char digit) {

        int idx = -1;

        for (int i = 0; i < number.size(); i++) {

            if (number[i] == digit) {

                idx = i;

                if (i + 1 < number.size() && number[i] < number[i + 1]) {

                    number.erase(i, 1);
                    return number;
                }
            }
        }

        number.erase(idx, 1);

        return number;
    }
};