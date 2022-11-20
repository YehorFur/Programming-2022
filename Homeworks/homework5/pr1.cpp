#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair <int,string>a[10000];
string t,words[10000];
long long n;

bool cmp (pair <int,string> p1, pair <int,string> p2){
    return p1.first>p2.first;
}

int main()
{
    //https://imgur.com/4zDB45P
    getline(cin, t);
    n=t.size();
    int flag=0;
    int wordsnum=1;
    for(int i=0; i<n; i++){
        if(t[i]==' ' || t[i]=='.'){
            wordsnum++;
            flag=0;
        } else {
            flag++;
            words[wordsnum].resize(flag);
            words[wordsnum][flag-1]=t[i];
        }
    }
    for(int i=1; i<=wordsnum; i++){
        a[i].first=words[i].size();
        a[i].second=words[i];
    }
    sort(a+1,a+1+wordsnum,cmp);
    for(int i=1; i<=wordsnum; i++){
        cout<<a[i].second<<endl;
    }
    return 0;
}
