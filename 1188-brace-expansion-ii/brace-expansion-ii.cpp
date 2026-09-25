class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;
        set<string> result = parseExpr();
        return vector<string>(result.begin(), result.end());
    }

private:
    string s;
    int i;

    set<string> parseExpr() {
        vector<set<string>> terms;
        terms.push_back(parseTerm());
        while (i < (int)s.size() && s[i] == ',') {
            i++;
            terms.push_back(parseTerm());
        }
        set<string> result;
        for (auto& t : terms) result.insert(t.begin(), t.end());
        return result;
    }

    set<string> parseTerm() {
        set<string> result;
        result.insert("");
        while (i < (int)s.size() && s[i] != ',' && s[i] != '}') {
            set<string> factor = parseFactor();
            set<string> next;
            for (const string& a : result)
                for (const string& b : factor)
                    next.insert(a + b);
            result = next;
        }
        return result;
    }

    set<string> parseFactor() {
        if (s[i] == '{') {
            i++;
            set<string> result = parseExpr();
            i++;
            return result;
        }
        int j = i;
        while (j < (int)s.size() && islower(s[j])) j++;
        string word = s.substr(i, j - i);
        i = j;
        return {word};
    }
};