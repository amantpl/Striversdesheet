class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=0;

        for(auto it:st){
            int cnt=0;
            if(st.find(it-1)==st.end()){
                while(st.find(it)!=st.end()){
                    cnt++;
                    it++;
                }
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};