class Solution {
public:
double power(double x,int n){
    if(n==0){
        return 1;
    }
    

    double half=power(x,n/2);
    
    if(n%2==0){
        half=half*half;
    }else{
        half=half*half*x;
    }

    return half;
}
    double myPow(double x, int n) {
        if(n<0){
            x=1/x;
        }
        double ans=power(x,n);
        return ans;
    }
};