#include <iostream>

using namespace std;

string ft(long long n){
    if(n==1)return "January";
    if(n==2)return "February";
    if(n==3)return "March";
    if(n==4)return "April";
    if(n==5)return "May";
    if(n==6)return "June";
    if(n==7)return "July";
    if(n==8)return "August";
    if(n==9)return "September";
    if(n==10)return "October";
    if(n==11)return "November";
    if(n==12)return "December";
}

string st(long long a, long long b, long long c){
    if(a<=24 && b<=60 && c<=60)return "YES";
    else return "NO";
}
string tt(long double a, long double b, long double c){
    if((a+c)/2==b)return "YES";
    else return "NO";
}

int main()
{
    long long n,a,b,c,k,t,h,m,a1,b1,c1;
    //15
    cin>>n;
    cout<<ft(n)<<endl;
    //19
    cin>>a>>b>>c;
    cout<<st(a,b,c)<<endl;
    //20
    cin>>a1>>b1>>c1;
    cout<<tt(a1,b1,c1)<<endl;
    //18
    cin>>t;
    int a2=t/100;
    int b2=t/10%10;
    int c2=t%10;
    cout<<a2+b2+c2<<endl;
    //1
    cin>>k;
    h=k/3600;
    m=k%3600/60;
    cout<<h<<" "<<m<<endl;

    return 0;
}
