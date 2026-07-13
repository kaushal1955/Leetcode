class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>result;
        for(int i =1;i<=nums.size();i++){
            if(st.find(i)==st.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};