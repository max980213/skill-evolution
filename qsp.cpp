#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue> //queue和priority_queue
#include <stack> //栈
#include <utility> //pair（微型结构体） //<map>中也包含了它，如果记不住直接#include <map>
#include <map>

using namespace std;

//C++的许多容器
//5.1 queue，队列，先进先出
//5.2 priority_queue 带优先级排序的队列
//6.stack，栈
//7.pair，一个微型结构体，用于捆绑两个元素

    struct fruit
    {
        string name;
        int price;
    }f1,f2,f3;

    struct cmp  //结构体名字就是cmp
    {
        bool operator() (fruit f1,fruit f2)   //格式就是这么写，是重载的写法
        {
            return f1.price>f2.price;
        }
    };

void queueuse()  //string内容访问
{
    queue<int> qu;//定义队列
    for(int i=1;i<6;i++)
        qu.push(i);//插入元素
    cout<<qu.front()<<" "<<qu.back()<<endl;  //取头尾元素
    qu.pop();//出队
    cout<<qu.size()<<endl;//返回元素个数
    cout<<qu.empty()<<endl<<endl;//判断是否空，空返回真
    //没有清空队列方法
}

void priority_queueuse() //带优先级排序的队列，内部利用堆实现，保证队首一定是优先级最大的，每次利用堆调整（调整一次），而优先级是规定出来的
{
    priority_queue<int> qu;  //定义优先级队列
    qu.push(3);//入队
    qu.push(4);
    qu.push(1);
    cout<<qu.top()<<endl;  //优先级队列没有front()和back()函数，只能通过top()访问队首，栈顶，优先级最高的元素
    qu.pop();//出队
    cout<<qu.empty()<<endl;//判空
    cout<<qu.size()<<endl;;//返回元素个数

    //对于基本数据类型，一般是大的优先级高。优先级的定义：
    priority_queue<int, vector<int>, greater<int> > q;  //定义新的队列，设置数字小的优先级大
    //多出来的两部分分别是一个vector容器，用来承载底层的堆，类型与第一个参数对应；第三个参数是对第一个参数的比较类，
    //less<int>表示数字大的优先级大，greater<int>表示数字小的优先级大
    q.push(3);
    q.push(4);
    q.push(1);
    cout<<q.top()<<endl;

    //结构体的优先级设置有两种方法，第一种是在结构体中对比较符号进行重载（不想学重载）
    //二是像sort()函数一样，在一个新结构体中编写cmp()函数，但要记住与sort()的cmp函数排序方式是相反的

   /* struct fruit    //这一部分需要定义在调用的函数的外部，同sort()函数一样
    {
        string name;
        int price;
    }f1,f2,f3;

    struct cmp  //结构体名字就是cmp
    {
        bool operator() (fruit f1,fruit f2)   //格式就是这么写，是重载的写法
        {
            return f1.price>f2.price;  //与sort()函数反，这里大于号，但优先级小的在前
        }
    };*/
    priority_queue<fruit,vector<fruit>,cmp> que;
    f1.name="桃子";
    f1.price=60;
    f2.name="西瓜";
    f2.price=30;
    f3.name="苹果";
    f3.price=10;
    que.push(f1);
    que.push(f2);
    que.push(f3);
    cout<<que.top().name<<" "<<que.top().price<<endl<<endl;
}

void stackuse()
{
    //与之前的完全类似，push()  pop()  top()  size()  empty()
}

void pairuse()  //pair将两个元素捆绑为一个元素，如果不想因此定义一个结构体，可以用pair
{
    pair<string,int> p;  //定义一个pair。一个pair中有两个参数，分别为first和second（与map类似，map是it->first）
    p.first="你好";
    p.second=123;
    cout<<p.first<<" "<<p.second<<endl;
    p=make_pair("hehe",3);  //利用自带函数进行初始化
    cout<<p.first<<" "<<p.second<<endl;
    p=pair<string,int>("haha",10);  //临时构造pair
    cout<<p.first<<" "<<p.second<<endl;
    pair<string,int> pai("njdnk",1010);  //定义时初始化
    cout<<pai.first<<" "<<pai.second<<endl;

    //两个pair类型可以直接用比较操作符比较，规则是先比较first，当且仅当first相等时才比较second
    cout<<(pai>p)<<endl<<endl;

    //pair应用：1.代替二元结构体
    //2.作为map键值进行插入
    map<string,int> mp;
    mp.insert(make_pair("nihaoaaaaa",333));
    cout<<mp.begin()->first<<" "<<mp.begin()->second<<endl;
}

int main() //multiset用来处理只排序不去重的情况      unordered_set用来处理只去重不排序的情况
{
    queueuse();
    priority_queueuse();
    pairuse();
    return 0;
}





