class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate=-1;
        int votes=0;
        for(int i=0;i<n;i++){
            if(votes!=0){
                if(nums[i]==candidate){
                    votes++;
                }
                else{
                    votes--;
                }
            }
            else{
                candidate=nums[i];
                votes++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate){
                cnt++;
            }
        }
        if(cnt > n/2){
            return candidate;
        }
        return -1;
    }
};