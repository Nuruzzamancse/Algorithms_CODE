#include<bits/stdc++.h>

using namespace std;

long long int bm(int base, int pow, int mod)
{

    if(pow==0)
        return 1%mod;

    long long int x = bm(base,pow/2,mod);

    x = (x*x)%mod;

    if(pow%2)
        x =(x*base)%mod;


    return x;


}

int main()
{


    long long int base, pow, mod;

    while(scanf("%d %d %d",&base,&pow,&mod)==3)
    {

    printf("%lld\n",bm(base,pow,mod));

    }


}
