#include <cstdio>
#include <cmath>
using namespace std;
double f(double x);
double solve(double left,double right);

int main(){

    double ans = solve(1.5,2.4);
    printf("%.6f",ans);

}

double solve(double left,double right){
    
    double mid = (left+right)/2;
    if(fabs(f(mid))<0.0000001) return mid;

    if (f(left)*f(mid)<0) return solve(left,mid);
    else if (f(right)*f(mid)<0) return solve(mid,right);

}


double f(double x){
    return pow(x,5)-15*pow(x,4)+85*pow(x,3)-225*pow(x,2)+274*x-121;
}
