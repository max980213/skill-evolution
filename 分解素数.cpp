//素数因子分解
//每个质因子都可以不止出现一次，因此定义结构体factor，存放质因子及其个数
//上一次作业中有结论，质因子是在根号n左右成对出现，则利用递归思想，很容易想到：
//对于整数n，若其可分解为若干质数的和，则最多只有一个存在于根号n右侧的质因子
//思路：枚举1~根号n的所有质数p，判断其是否为质因
//      如果是，则结构体数组中添加该因子，个数置为0，并用n除p
//      只要p还是n的因子，就不断整除p，同时个数加1，知道p不再是n的因子
//      如果p不是质因子，则直接跳过
//      如果枚举到根号n，n（被p除后）仍大于1，说明有且只有一个大于根号n的质因子（有可能就是此时的n本身）
//      把它加入到结构体数组，令其个数为1


#include <stdio.h>
#include <math.h>

#define MAX 100010

int prime[MAX];
int pNum=0;

struct factor
{
    int x;      //值
    int cnt;    //个数
}fac[10];

bool is_prime(int n)
{
    if(n==1)
        return false; //1不是素数
    int sqr=(int)sqrt(n);
    for(int i=2;i<=sqr;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

void list_prime()
{
    for(int i=1;i<MAX;i++)
    {
        if(is_prime(i)==1)
        {
            prime[pNum++]=i;  //枚举法列出了素数表，也可用埃氏筛法
        }
    }
}

void list_prime2()   //埃氏筛法
{
    bool p[MAX]={0};
    for(int i=2;i<MAX;i++)   //筛出MAX以内的素数
    {
        if(p[i]==0)
        {
            prime[pNum++]=i;
            for(int j=i+i;j<MAX;j=j+i) //依次加i，筛掉，循环条件不可为j<=MAX，防止正好到MAX，会溢出
            {
                p[j]=1;
            }
        }
    }
}

int main()
{
    list_prime2();
    int n;
    int num=0;//记录不同因子的个数
    scanf("%d",&n);
    if(n==1)//特殊处理
        printf("1 = 1\n");
    else
    {
        printf("%d = ",n);
        int sqr=(int)sqrt(n);
        for(int i=0;i<pNum&&prime[i]<=sqr;i++)  //列举小于根号n的素数（已存在素数表里）
        {
            if(n%prime[i]==0)  //是一个因子
            {
                fac[num].x=prime[i];
                fac[num].cnt=0;      //记录下该因子，并初始化个数为0
                while(n%prime[i]==0) //只要它还是因子，就一直除，数量加一，直到无法整除
                {
                    n/=prime[i];
                    fac[num].cnt++;
                }
                num++;  //不同因子个数加1，最终num是不同质因子的个数
            }
            if(n==1) //n等于1了，不需要再作后续计算，退出循环
                break;
        }
        if(n!=1)  //如果输入0，会跳到这一步，导致输出0 = 0 ，很合理  如果输入1，则不会添加元素1到结构体数组中
        {
            fac[num].x=n;
            fac[num++].cnt=1;
        }
        //输出结果
        for(int i=0;i<num;i++)
        {
            if(i>0)
                printf(" × ");
            printf("%d",fac[i].x);
            if(fac[i].cnt>1)
                printf("^%d",fac[i].cnt);
        }
    }
    return 1;
}
