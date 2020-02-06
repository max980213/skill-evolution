//数字黑洞
//给定不完全相同的4个数字，将4个数字按非递增排序再按非递减排序
//两个数（大减小）得到一个新的数字，一直重复，会得到“黑洞数字”6174
//编写算法模拟该过程，输入4个重复数字，输出“N-N=0"

//思路：编写两个函数，分别实现数字的每一位存到数组（可不在相应位置，因为还要排序）和数组中的数字排序后转化为整数
//递归（或循环），直到出现0或6174则return

#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a>b;  //按递减排序
}

void to_array(int n,int num[])
{
    for(int i=0;i<4;i++)
    {
        num[i]=n%10;
        n/=10;
    }
}

int to_number(int num[])
{
    int sum=0;
    for(int i=0;i<4;i++)
    {
        sum=sum*10+num[i];   //每位每次左移一位
    }
    return sum;
}

int main()
{
    int n,MIN,MAX,num[5],flag=0;  //sort()函数第二个参数需要指针+1
    scanf("%d",&n);
    while(1)
    {
        to_array(n,num);
        sort(&num[0],&num[4],cmp);   //sort()函数默认（无cmp()）为递增排序
        MAX=to_number(num);
        sort(num,num+4);
        MIN=to_number(num);
        n=MAX-MIN;
        printf("%d - %d = %d\n",MAX,MIN,n);
        if(n==6174)
            flag++;
        if(n==0||flag==3)
            break;
    }
    return 0;
}
