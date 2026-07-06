class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> pairs;

        for(int i = 0;i<nums.size();i++){
            pairs.push_back({nums[i],i});
        } 

        sort(pairs.begin(),pairs.end());
        int i = 0;
        int j = pairs.size()-1;

        while(i<j){
            int sum = pairs[i].first + pairs[j].first;
            if(sum == target) {
                return {pairs[i].second,pairs[j].second};
            }
            else if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};