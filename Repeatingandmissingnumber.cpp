vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    long long sum=((long long)n*(n+1))/2;
    long long sq=((long long)n*(n+1)*(2*n+1))/6;
    
    long long actualsum=0;
    long long actualsq=0;
    
    for(int i=0;i<n;i++){
        actualsum+=A[i];
        actualsq+=(long long)A[i]*(long long)A[i];
    }
    // let x be the repeating number and y be the missing number
    long long val1=actualsum-sum; // x-y
    long long val2=actualsq-sq;  // x^2 - y^2
    long long val3=val2/val1;  // x+y
    long long val4=val3+val1; // 2*x
    long long repeating=val4/2; // x
    long long missing=val3-repeating; // y;
    
    return {(int)repeating,(int)missing};
    
    
}
