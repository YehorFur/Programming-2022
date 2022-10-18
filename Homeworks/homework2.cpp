#include <bits/stdc++.h>

using namespace std;

long long fib[10005],f[10005],n;

long double x[105];
long double a[105];

int main()
{
    // https://imgur.com/a/ornwo3f

    cin>>n;
    fib[0]=0;
    fib[1]=1;
    for(int i=2; i<=n; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    f[0]=0;
    f[1]=1;
    for(int i=2; i<=n; i++){
        f[i]=f[i-2]+f[i-1]+fib[i-2];
    }
    for(int i=0; i<n; i++){
        cout<<f[i]<<endl;
    }

    // https://imgur.com/a/lirtINq

    x[1]=0.3;
    x[2]=-0.3;
    for(int i=3; i<=100; i++){
        x[i]=(long double)i+sin(x[i-2]);
    }
    for(int i=1; i<=100; i++){
        a[i]=abs(abs(x[i])-round(x[i]));
    }
    long double minn=100000;
    long double res2;
    for(int i=1; i<=100; i++){
        if(minn>a[i]){
            minn=a[i];
            res2=x[i];
        }
    }
    cout<<fixed<<setprecision(10)<<res2<<endl;


    return 0;
}
