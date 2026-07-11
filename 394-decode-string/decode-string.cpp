class Solution {
public:
    string decodeString(string s) {

        stack<int> countStack;
        stack<string> stringStack;

        string currStr = "";
        int currNum = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            }

            else if (ch == '[') {
                countStack.push(currNum);
                stringStack.push(currStr);

                currNum = 0;
                currStr = "";
            }

            else if (ch == ']') {

                int repeat = countStack.top();
                countStack.pop();

                string previous = stringStack.top();
                stringStack.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += currStr;
                }

                currStr = previous + temp;
            }

            else {
                currStr += ch;
            }
        }

        return currStr;
    }
};