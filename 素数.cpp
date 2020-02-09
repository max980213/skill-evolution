//求素数的两种方法（以100以内素数为例）

//1.直接法：若存在n%a==0，则n不是素数
//          但考虑到，若n%a==0，则n/a=m（能除尽），则n%m==0，且a和n/a一定在根号n的左右两侧
//          所以在枚举时，只需要判断从2到根号n，有没有能除尽的数即可

#include <cstdio>
#include <math.h>
#define MAX 101

bool isPrime(int n)  //复杂度：判断该数为O(sqrt(n))
{
    if(n<=1)
        return false;
    int sqr=(int)sqrt(n);
    for(int i=2;i<=sqr;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

//2.埃氏筛法
//思想：对每一个素数，筛掉它所有的倍数
//如：2是素数，筛掉4,6,8,......
//    3没有被之前的步骤筛去，所以3是素数，筛掉6,9,12.....
//    重复以上过程，从小到大到达某数a，如果a没有被筛掉，则它一定是素数

int prime[MAX],pNum=0;
bool p[MAX]={0};

void find_prime()    //复杂度为O(loglogn)
{
    for(int i=2;i<MAX;i++)  //1不是素数
    {
        if(p[i]==0)
            {
                prime[pNum++]=i;
                for(int j=i+i;j<MAX;j+=i)
                {
                    p[j]=1;
                }
            }
    }
}

int main()
{
    find_prime();
    for(int i=0;i<pNum;i++)
    {
        printf("%d ",prime[i]);
    }
    return 0;
}
