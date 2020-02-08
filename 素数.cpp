//100内的素数

#include <cstdio>

#define MAX 101

int prime[MAX],pNum=0;
bool p[MAX]={0};

void find_prime()
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
