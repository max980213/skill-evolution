//题目描述：对输入数据进行排序，规则如下：
//1.位数多的在前，位数少的在后
//2.位数相同时，小的在前，大的在后

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct TEST
{
    int data;
    int carry; //位数
}test[1000];

void TEST0(TEST* a)
{
    for(int i=a->data;i!=0;i/=10)
        a->carry++;
}

bool cmp(TEST a,TEST b)
{
    if(a.carry==b.carry)
        return a.data<b.data;
    else
        return a.carry>b.carry;
}

int main()
{
    int n;
    int i=0;
    while(scanf("%d",&n)!=EOF)
    {
        test[i++].data=n;
        TEST0(&test[i-1]);
    }
    sort(&test[0],&test[i],cmp);
    for(int j=0;j<i;j++)
        cout<<test[j].data<<" ";
    return 0;
}
