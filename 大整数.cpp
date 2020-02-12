//大整数运算（比如有上千位的那种，int型根本存不下来）
//大整数的存储可以用数组，数组中的每一位都代表了大整数的一位，数组的低位存放大整数的低位，数组的高位存放大整数的高位
//读入的时候，利用字符串可直接读入，但要注意读入时是反的，即大整数的高位在字符数组的低位
//所以在再转化为整型数组时，要反一下
//位方便随时获取整数长度，一般再int len，与数组结合为结构体

//考虑到数的正负问题，可以在结构体中增加一个符号位：0为负，1为正

#include <stdio.h>
#include <string.h>  //包含memset()函数

struct bign
{
    int d[1000];
    int sign;
    int len;
    bign()  //结构体的构造函数，无返回值，函数名与结构体名相同，用来初始化结构体
    {
        memset(d,0,sizeof(d));   //将数组初始化为0（参考memset()函数用法）
        sign=1;//默认为正
        len=0;
    }
};

bign getbign();//得到一个大整数
void printbign(bign a)//打印大整数
{
    if(a.sign==0)
        printf("-");
    for(int i=a.len-1;i>-1;i--)  //从高位开始输出
        printf("%d",a.d[i]);
}
bign change(char str[]);//转换
int compare(bign a,bign b);//比较大小，但是有bug，0123和123比较会返回1  //已修复，有待优化
bign add(bign a,bign b);
bign sub(bign a,bign b);

//大数如何进行运算？很好的思路是像小学列竖式一样进位借位

//加减法利用该思想便很容易写出
bign add(bign a,bign b)
{
    bign c;
    int carry=0;//carry是进位
    if(a.sign==b.sign)  //如果是两个同号的数相加
    {
        for(int i=0;i<a.len||i<b.len;i++)  //以较长的那个位界限，每一位最开始已经初始化为0，所以不需担心乱码
        {
            int temp=a.d[i]+b.d[i]+carry;
            c.d[c.len++]=temp%10;  //将得到的位数存到新的大整数中
            carry=temp/10;//保存进位
        }
        if(carry!=0)
        {
            c.d[c.len++]=carry;
        }
        c.sign=a.sign;  //保留符号
        return c;
    }
    else if(a.sign>b.sign) //两个异号数相加，化位相减
    {
        b.sign=1;  //改变减数的符号，再相减
        return sub(a,b);
    }
    else
    {
        a.sign=1;
        return sub(b,a);
    }
}

bign sub(bign a,bign b)
{
    if(compare(a,b)==-1)   //先比较大小，保证是大减小
    {
        bign c=sub(b,a);
        c.sign=0;
        return c;
    }
    else
    {
        bign c;
        if(a.sign==b.sign&&a.sign==0)  //两个负数相减，且一定是大减小或两数相等
        {
            b.sign=1;  //负负得正
            return sub(a,b);
        }
        else if(a.sign==b.sign&&a.sign==1) //都为正
        {
            for(int i=0;i<a.len||i<b.len;i++)   //还有bug 未考虑借位为0的情况
            {
                if(a.d[i]<b.d[i]) //如果不够减
                {
                    a.d[i+1]--;  //向高位借位（未考虑高位为0的情况）
                    a.d[i]+=10;  //当前位加10
                    //c.d[c.len++]=a.d[i]-b.d[i];
                }
                c.d[c.len++]=a.d[i]-b.d[i];
            }
        }
        else if(a.sign>b.sign) //正减负
        {
            b.sign=1;
            return add(a,b);
        }
        else  //负减正
        {
            a.sign=1;
            c=add(a,b); //先加，再更换符号
            c.sign=0;
            return c;
        }
        return c;
    }
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
    int flag=0; //标记位，用来标记符号位是否被占用
    bign a;
    a.len=strlen(str);
    if(str[0]=='-')//是个负数
    {
        a.len--;
        a.sign=0;
        flag=1;
    }
    for(int j=0+flag;j<a.len+1;j++)  //先处理高位0（上一步a.len--了）
    {
        if(str[j]=='0')
        {
           cnt++;
           //a.len--;
        }
        else
        {
            a.len-=cnt; //更新len
            break;
        }
    }
    for(int i=0;i<a.len;i++)  //这部分有待优化
    {
        a.d[i]=str[a.len-1+flag-i+cnt]-'0';   //字符串数组中存的是ASC码，要减一个字符'0'
    }
    return a;
}

int compare(bign a,bign b) //比较大小，先比较长度，如果想等，则从高位开始比较,返回-1 0 1分别为小于等于大于
{
    if(a.sign==b.sign&&a.sign==1)  //同正
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
    else if(a.sign==b.sign&&a.sign==0)  //同负
    {
        if(a.len>b.len)
            return -1;
        else if(a.len<b.len)
            return 1;
        for(int i=a.len-1;i>-1;i--)  //从高位到低位比较
        {
            if(a.d[i]>b.d[i])
                return -1;
            else if(a.d[i]<b.d[i])
                return 1;
        }
        return 0;
    }
    else  //异号的话 比较符号位即可
        return a.sign>b.sign;
}





int main()
{
    bign a=getbign();
    bign b=getbign();
   // printbign(a);
    printbign(add(a,b));
    return 0;
}





