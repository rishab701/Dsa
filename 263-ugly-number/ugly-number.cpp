class Solution {
public:
    bool f(int n){
       if(n==1){
            return true;
        }
        if(n==0 || n== INT_MIN || n == INT_MAX || n<0){
            return false;
        }
        if(n%2!=0 && n%3!=0 && n%5!=0){
            return false;
        }
        bool a=false;
        bool b=false;
        bool c=false;
        if(n%2==0){
            a=f(n/2);
        }
        else if(n%3==0){
            b=f(n/3);
        }
        else if(n%5==0){
            c=f(n/5);
        }
    return (a || b || c);
}
    bool isUgly(int n) {
        return f(n);
    }
};