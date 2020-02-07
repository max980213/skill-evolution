//最大公约数与最小公倍数
//方法：辗转相除法，基于如下定理：gcd(a,b)=gcd(b,a%b) （最大公约数）

#include <stdio.h>

int gcd(int a,int b) //最大公约数
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int lcm(int a,int b) //最小公倍数
{
    int p=gcd(a,b);
    return a*b/p;
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int p=gcd(a,b);
    printf("%d %d",p,a*b/p);
    return 0;
}
