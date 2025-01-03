class Solution {
public:

void merge(vector<int>& nums,int low,int mid,int high,int& count){
    vector<int> temp;

    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){
        if((long long)nums[right]*2<nums[left]){
            count+=mid-left+1;
            right++;
        }else{
            left++;
        }
    }

    
    int i=low;
    int j=mid+1;

    while(i<=mid && j<=high){
        if(nums[j]>nums[i]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }

    while(j<=high){
        temp.push_back(nums[j]);
        j++;
    }

    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }


}

void mergesort(vector<int>& nums,int low,int high,int& count){
    if(low>=high){
        return ;
    }

    int mid=(low+high)/2;
    mergesort(nums,low,mid,count);
    mergesort(nums,mid+1,high,count);
    merge(nums,low,mid,high,count);
}
    int reversePairs(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int count=0;
        mergesort(nums,low,high,count);
        return count;
    }
};