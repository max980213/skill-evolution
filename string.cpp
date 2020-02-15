#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>  //<string>和<string.h>是不一样的头文件
//#include <string.h>  //这里有strlen()函数，但字符数组和string容器不是一个东西

using namespace std;

//C++的许多容器
//3.string容器，封装了对字符串的常用功能

void stringdef() //string的定义
{
    string str;
    string str1="abcd";  //字符串定义时可以初始化
}

void stringvisit()  //string内容访问
{
    //一般可以像字符数组一样，通过下标（真的下标）直接访问
    string str="abcd";
    //str[1]="b";  这样不行，字符数组和string是两个类型，string中每一个str[i]都是常量
    for(unsigned i=0;i<str.length();i++)  //不可strlen(str)，因为str的类型是string容器，不是字符数组
        printf("%c",str[i]);
    cout<<endl;
    scanf("%c",&str[2]);
    cout<<str<<endl;;
    //同理，输入输出整个字符串均不可用printf进行格式化输入输出了，因为是string容器类型，不是字符数组类型
    //输入输出整个字符串只能用cin和cout，但str中单个字符输入输出可以用scanf/printf("%c",(&)str[i])

    //有方法使用printf，需要用str.c_str()方法将string类型转化为字符数组
    printf("%s",str.c_str());

    //string为容器，也可定义迭代器。因为字符容器类型已经固定，所以不像其它迭代器一样需要参数
    string::iterator it=str.begin();
    cout<<endl;
    for(it;it!=str.end();it++)   //只有vector和string容器可以用*(it+i)（迭代器加整数）的形式访问
        cout<<*it;

    //string的常用方法
    //1.  “+”操作符，实现将两个字符串进行拼接,中间没有空格，（+=同样可用）
    string str1="abc";
    string str2="def";
    cout<<endl<<str1+str2;
    //2.  比较符，==、!=、<、<=、>、>=，比较规则是字典序
    string str3="aaa";
    string str4="abc";
    //printf("\n%d",str3<str4);   //
    cout<<endl<<(str3<str4);
    //3. str.length()/size() 方法，返回string的长度，即存放的字符数
    cout<<endl<<(str3+str4).length()<<str4.size();
    //4. str.insert()方法，写法有两种 复杂度均为O(N)
    //1°insert(index,string)在index处插入string
    cout<<endl<<str3.insert(2,str4); //第2+1个位置，也可理解为下标从0开始，但这里不可以用迭代器
    cout<<endl<<str3;
    //2°insert(index,it1,it2)index为插入位置的迭代器，it1和it2为待插入字符串的首尾迭代器（左闭右开）
    str3.insert(str3.begin()+2,str1.begin(),str1.begin()+2);  //str3.begin()+2是第3个位置，就是在第3个位置开始，可理解为下标从0开始，begin()为0
    cout<<endl<<str3;
    //5. str.erase() 删除单个元素 删除区间元素 复杂度均为O(N)
    string str5="aaabababnc";
    str5.erase(str5.begin()+3);   //只能接收迭代器为参数，删除单个元素
    cout<<endl<<str5;
    str5.erase(str5.begin()+2,str5.end()); //左闭右开，删除区间，只能接受迭代器
    cout<<endl<<str5;
    str5="aabbccdd";
    str5.erase(2,3);   //从下标2开始，删除3个元素，只能接受数字
    cout<<endl<<str5;
    //6.str.clear()，清空str，复杂度为O(1)
    //7.str.substr(index,length)，返回下标index开始，长度为length的子串
    cout<<endl<<str5.substr(2,3);
    //8.  常数string::npos，本身值为-1，但是unsigned_int类型，可认为是该类型的最大值，作为find()函数查找失败的返回值
    //该值可认为是-1，或4294967295，即string::npos==这两个值均成立
    //9.str.find(str2),若str2是str的子串。返回第一次出现的位置，如果不是，返回那个常数
    //10.str.replace(index,len,str2)，将str下标index开始长度为len的子串替换为str2
    //   str.replace(it1,it2,str2),将迭代器范围内的子串换为str2


}

int main() //multiset用来处理只排序不去重的情况      unordered_set用来处理只去重不排序的情况
{
    stringvisit();
    return 0;
}
