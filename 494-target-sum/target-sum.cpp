class Solution {
public:
    int solve(int ind,int currTarget,int target,vector<int>& nums,unordered_map<string,int>& memo){
        if(ind == nums.size()-1){
            int plus=currTarget+nums[ind];
            int minus=currTarget-nums[ind];
            if(plus == target && minus == target ){
                return 2;
            }
            if(plus == target || minus == target ){
                return 1;
            }
            else{
                return 0;
            }
        }
        string key=to_string(ind) + " " + to_string(currTarget);
        if(memo.find(key) != memo.end())  return memo[key];
        int plus=solve(ind+1,currTarget+nums[ind],target,nums,memo);
        int minus=solve(ind+1,currTarget-nums[ind],target,nums,memo);

        return memo[key]=(plus+minus);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       unordered_map<string,int>umap;
       return solve(0,0,target,nums,umap); 
    }
};