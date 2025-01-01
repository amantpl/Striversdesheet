class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algo
        int n=nums.size();
        int cnt=0;
        int element=nums[0];
        for(int i=0;i<n;i++){
            if(element==nums[i]){
                cnt++;
            }else{
                cnt--;
                if(cnt==0){
                    element=nums[i];
                    cnt++;
                }
            }
        }
        return element;
    }
};