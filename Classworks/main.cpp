#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Ïåðåâåñòè ç Öåëüñ³ÿ â ôàðèíãåéòè
    /*
    for(long double i=0; i<=100; i++){
        cout<<i<<" "<<(i*9)/5+32<<endl;
    }
    */
    // Çàäàíî ö³ëå ÷èñëî m>1þ Îòðèìàòè íàéá³ëüøå ö³ëå÷èñëî k, ïðè ÿêîìó 4^k<m
    /*
    long long m;
    cin>>m;
    int i=0;
    while(pow(4,i)<m){
        i++;
    }
    cout<<i-1<<endl;
    */
    // Îòðèìàòè ïîñë³äîâí³ñòü ô³áîíà÷³
    /*
    long long n,a[100005],i;
    a[1]=0;
    a[2]=1;
    i=3;
    cin>>n;
    int k=0;
    for(i=3; i<=n; i++){
        if(a[i-1]+a[i-2]>n){
            break;
        }
        a[i]=a[i-1]+a[i-2];
        k++;
    }
    for(int j=1; j<=k+2; j++){
        cout<<a[j]<<" ";
    }
    */
    //Âèâåñòè ÷èñëî à â çâîðîòíüîìó ïîðÿäêó
    /*
    string s;
    cin>>s;
    int n=s.size();
    for(int i=n-1; i>=0; i--){
        cout<<s[i];
    }
    */
    //Àëãîðèòì åâêë³äà
    long long a,b;
    cin>>a>>b;
    while(a!=0 and b!=0)
    {
        if(a>b){
            a=a%b;
        } else {
            b=b%a;
        }
    }
    cout<<a+b<<endl;
    return 0;
}
