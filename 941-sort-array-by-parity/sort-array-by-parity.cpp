class Solution{
public:
vector<int>sortArrayByParity(vector<int>& nums){
    int cnt=0;
    int n= nums.size();
    for(int i=0;i<n;i++){ 
       if(!(nums[i] & 1)){    
            swap(nums[i],nums[cnt]);  
            cnt++; 
       }
    }
    return nums;
   }
};