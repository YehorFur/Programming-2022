#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

#define ld long double

using namespace std;

struct Point{
    ld x,y;
};

struct line{
    ld a,b,c;
    friend istream & operator>>(istream & is, line & l){
        cout<<"Enter a"<<endl;
        is>>l.a;
        cout<<"Enter b"<<endl;
        is>>l.b;
        cout<<"Enter c"<<endl;
        is>>l.c;
        return is;
    }
    Point peret(line l2){
        Point per;
        per.x=((l2.c/(l2.b*(-1)))-(c/(b*(-1))))/((a/(b*(-1)))-(l2.a/(l2.b*(-1))));
        per.y=(a*per.x+c)/((-1)*b);
        return per;
    }

    ld kutper(line l2){
        ld kut;
        kut=atan((ld)abs(l2.a/(b*(-1))-a/(b*(-1)))/(1+(a/(b*(-1))*l2.a/(b*(-1)))));
        return kut;
    }
    bool chinal(Point p){
        if((a*p.x+b*p.y+c)==0){
            return true;
        } else {
            return false;
        }
    }
    bool chipar(line l2){
        if(a*l2.b-b*l2.a==0){
            return true;
        } else {
            return false;
        }
    }
};

line k[15],ox;
long long paral,perp;

int main()
{
    for(int i=1; i<=10; i++){
        cin>>k[i];
    }
    ox.a=1;
    ox.b=0;
    ox.c=0;
    paral=0;
    perp=0;
    for(int i=1; i<=10; i++){
        long long qwe=0;
        for(int j=1; j<=10; j++){
            if(i!=j){
                if(k[i].chipar(k[j])==false){
                    qwe++;
                    cout<<"LINE "<<qwe<<" "<<k[j].a<<"x+"<<k[j].b<<"y+"<<k[j].c<<"=0"<<" PERET "<<k[i].peret(k[j]).x<<" "<<k[i].peret(k[j]).y<<endl;;
                }
            }
        }
        if(ox.chipar(k[i])==true){
            paral++;
        }
        if(ox.kutper(k[i])==M_PI_2){
            perp++;
        }
    }
    cout<<"PARAL "<<paral<<" PERP "<<perp<<endl;
	return 0;
}
