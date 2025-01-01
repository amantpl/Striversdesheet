class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // moore's voting algorithm

        int n=nums.size();
        int element1=INT_MIN;
        int element2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && element2!=nums[i]){
                cnt1++;
                element1=nums[i];
            }else if(cnt2==0 && element1!=nums[i]){
                cnt2++;
                element2=nums[i];
            }else{
                if(element1==nums[i]){
                    cnt1++;
                }else if(element2==nums[i]){
                    cnt2++;
                }else{
                    cnt1--;
                    cnt2--;
                }
            }
        }

        cnt1=0;
        cnt2=0;
        vector<int> vec;

        for(int i=0;i<n;i++){
            if(element1==nums[i]){
                cnt1++;
            }else if(element2==nums[i]){
                cnt2++;
            }
        }

        if(cnt1>(n/3)){
            vec.push_back(element1);
        }

        if(cnt2>n/3){
            vec.push_back(element2);
        }

        return vec;
    }
};