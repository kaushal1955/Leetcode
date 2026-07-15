class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        string ans = "";

        while (ss >> word) {

            string prefix = "";

            bool found = false;

            for (char ch : word) {

                prefix += ch;

                if (st.count(prefix)) {
                    found = true;
                    break;
                }
            }

            if (!ans.empty()) ans += " ";

            ans += (found ? prefix : word);
        }

        return ans;
    }
};