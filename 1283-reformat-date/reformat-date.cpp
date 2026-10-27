
class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> months = {
            {"Jan", "01"}, {"Feb", "02"},
            {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"},
            {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"},
            {"Nov", "11"}, {"Dec", "12"}
        };

        string day, month, year;
        stringstream ss(date);

        ss >> day >> month >> year;

        // Remove the last two characters: st, nd, rd, or th
        day = day.substr(0, day.size() - 2);

        // Add a leading zero if the day has one digit
        if (day.size() == 1) {
            day = "0" + day;
        }

        return year + "-" + months[month] + "-" + day;
    }
};
