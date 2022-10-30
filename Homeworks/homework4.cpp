#include <iostream>

using namespace std;

long long a,b,c;
int gcd(int a, int b){
    while(a!=0 and b!=0)
    {
        if(a>b){
            a=a%b;
        } else {
            b=b%a;
        }
    }
    return a+b;
}

int main()
{
    cin>>a>>b>>c;
    cout << gcd(gcd(a,b),c) << endl;
    return 0;
}
