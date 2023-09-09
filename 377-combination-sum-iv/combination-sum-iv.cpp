class Solution {
public:
    int f(vector<int>& nums,int target,vector<int>& dp){
        dp[0]=1;
        if(dp[target]>-1) return dp[target];
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= target){
                count+=f(nums,target-nums[i],dp);
            }
        }
      return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
       vector<int>dp(target+1,-1);
       f(nums,target,dp);
       return dp[target];
    }
};