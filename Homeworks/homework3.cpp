#include <bits/stdc++.h>

using namespace std;

long double x[15],a,h,b,up,down,upf,downf,flag,flag2,sum,s[15],y[15],po[15],prevv;

int main()
{
    // https://imgur.com/a/NvGonjF
    cin>>a>>h>>b;
    x[1]=a;
    x[10]=b;
    for(int i=1; i<=8; i++){
        x[i+1]=a+(h*i);
    }
    for(int i=1; i<=10; i++){
        up=1;
        upf=1;
        down=1;
        downf=4;
        sum=1;
        flag2=1;
        flag=100;
        prevv=1;
        while(flag>=0.00001){
            for(int j=1; j<=flag2; j++){
                up*=upf;
                down*=downf;
                upf+=4;
                downf+=4;
            }
            sum+=((up/down)*pow(x[i],flag2));
            flag=abs(((up/down)*pow(x[i],flag2))-prevv);
            prevv=((up/down)*pow(x[i],flag2));
            flag2++;
        }
        s[i]=sum;
        y[i]=1.0/(long double)pow(1-x[i], 0.25);
        po[i]=abs((s[i]-y[i])/y[i])*100;
    }
    for(int i=1; i<=10; i++){
        cout<<x[i]<<"   "<<s[i]<<"   "<<y[i]<<"   "<<po[i]<<endl;
    }


    return 0;
}
