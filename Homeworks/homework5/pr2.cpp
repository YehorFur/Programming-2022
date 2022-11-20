#include <iostream>

using namespace std;

long double n,m,a[10000][10000],b[10000];

int main()
{
    //https://imgur.com/a/5p9PDeb
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            b[i]+=a[i][j];
        }
        b[i]/=m;
    }
    for(int i=1; i<=n; i++){
        cout<<b[i]<<endl;
    }
    return 0;
}
