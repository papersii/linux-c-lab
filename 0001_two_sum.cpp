class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                result.push_back(map.find(target - nums[i]) -> second);
                result.push_back(i);
                break;
            }
            map[nums[i]] = i;
            
        }
        return result;
    }
