//大整数运算（比如有上千位的那种，int型根本存不下来）
//大整数的存储可以用数组，数组中的每一位都代表了大整数的一位，数组的低位存放大整数的低位，数组的高位存放大整数的高位
//读入的时候，利用字符串可直接读入，但要注意读入时是反的，即大整数的高位在字符数组的低位
//所以在再转化为整型数组时，要反一下
//位方便随时获取整数长度，一般再int len，与数组结合为结构体

#include <stdio.h>
#include <string.h>  //包含memset()函数

struct bign
{
    int d[1000];
    int len;
    bign()  //结构体的构造函数，无返回值，函数名与结构体名相同，用来初始化结构体
    {
        memset(d,0,sizeof(d));   //将数组初始化为0（参考memset()函数用法）
        len=0;
    }
};

bign getbign();//得到一个大整数
bign change(char str[]);//转换
int compare(bign a,bign b);//比较大小，但是有bug，0123和123比较会返回1  //已修复，有待优化

int main()
{
    bign a=getbign();
    bign b=getbign();
        printf("%d",compare(a,b));
    return 0;
}

bign getbign()
{
    char str[1000];
    gets(str);
    bign a=change(str);
    return a;
}

bign change(char str[])   //将用字符串读入的整数转化为整型数组
{
    int cnt=0; //记录高位0的个数
    bign a;
    a.len=strlen(str);
    for(int j=0;j<a.len;j++)  //先处理高位0
    {
        if(str[j]=='0')
        {
            cnt++;
        }
        else
        {
            a.len-=cnt; //更新len
            break;
        }
    }
    for(int i=0;i<a.len;i++)  //这部分有待优化
    {
        a.d[i]=str[a.len-1-i+cnt]-'0';   //字符串数组中存的是ASC码，要减一个字符'0'
    }
    return a;
}

int compare(bign a,bign b) //比较大小，先比较长度，如果想等，则从高位开始比较,返回-1 0 1分别为小于等于大于
{
    if(a.len>b.len)
        return 1;
    else if(a.len<b.len)
        return -1;
    for(int i=a.len-1;i>-1;i--)  //从高位到低位比较
    {
        if(a.d[i]>b.d[i])
            return 1;
        else if(a.d[i]<b.d[i])
            return -1;
    }
    return 0;
}






