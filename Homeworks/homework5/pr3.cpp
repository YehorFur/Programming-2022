#include <iostream>

using namespace std;

void csort(int a[], int n)
{
    int maxx=INT_MIN, minn=INT_MAX;
    for (int i=0; i<n; i++){
        if (a[i]>maxx)
            maxx=a[i];
        if (a[i]<minn)
            minn=a[i];
    }
    int *c = new int[maxx+1-minn];
    for (int i=0; i<maxx+1-minn; i++){
        c[i]=0;
    }
    for (int i=0; i<n; i++){
        c[a[i]-minn]=c[a[i]-minn]+1;
    }
    int i=0;
    for (int j=minn; j<maxx+1; j++){
        while (c[j-minn] != 0){
            a[i] = j;
            c[j-minn]--;
            i++;
        }
    }
}

int main()
{
    //https://imgur.com/a/hL7GBAc
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    csort(a, n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
