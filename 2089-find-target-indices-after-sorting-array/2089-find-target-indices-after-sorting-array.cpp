class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
    //   int n = nums.size();
    //   sort(nums.begin(), nums.end());
    //   vector <int>ans;
    //   for(int i = 0; i<n ; i++){
    //     if(nums[i] == target){
    //         ans.push_back(i);
    //     }
    //   }
    //   return ans;

    sort(nums.begin(), nums.end());
    auto first = lower_bound(nums.begin(), nums.end(), target);
    auto last = upper_bound(nums.begin(), nums.end(), target);
    vector<int> ans;

    for (auto it = first; it != last; ++it) {
       ans.push_back(it - nums.begin());
    }

    return ans;
      
    }
};