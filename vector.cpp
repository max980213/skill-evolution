#include <stdio.h>
#include <iostream>
#include <vector> //vector容器

using namespace std;

//C++的许多容器
//1.vector容器，可理解为一个可变长数组

typedef struct node
{
    int date;
    struct node* next;
}node;

void vectordef()
{
    vector<int> name;  //相当于定义一个int型的名为name的一维数组  这种初始化方式初始size均为0
    vector<node> link;  //node是自定义链表节点类型
    //typename也可以是vector，联想到二维数组
    vector<vector<int> > vi;  //>>之间要加空格，否则有的编译器会认为是移位操作
                                //这是一个第一维和第二维都可变的向量
    vector<int> arrayname[100];      //这是第一维固定，第二维可变的向量
}

void vectorvisit()//在常用容器中，只有vector和string支持迭代器加整数的写法（类似数组）
{
    //访问方式有两种
    int index=0;
    vector<int> vi;  //初始化size为0，故不可使用vi[0]=3
    vi.push_back(3);  //在vi的尾部添加一个元素，复杂度为O(1)
    printf("%d",vi[index]);  //直接通过下标访问，区间为0~vi.size()-1

    vector<int>::iterator it;  //定义一个迭代器，一种类似指针的东西
    for(int i=0;i<5;i++)
        vi.push_back(i);
    it=vi.begin(); //vi.begin()获取vi的首地址，好像只能这么用,it=&vi等写法都不行
    //迭代器可以进行比较（只能进行是否相等比较，不可比较大小），指向同一元素时相等
    for(int i=0;i<6;i++)
        printf(" %d",*(it+i));   //可看出，vi[i]和*(vi.begin()+i)是等价的，与指针完全类似
    cout<<endl;
    //迭代器还可以进行自加自减操作，与数组指针完全类似
    for(int i=0;i<6;i++)
        printf("%d ",*(it++));
    cout<<endl;
    //vector的迭代器不支持it < vi.end()写法，因此只能使用!=
    //vi.end()使取尾元素的下一个地址（与sort()函数一样，左闭右开）
    for(it=vi.begin();it!=vi.end();it++)
        cout<<*it<<" ";
    //尾添为push_back(x)，那么尾删为pop_back(x)
    cout<<endl;
    vi.pop_back();
    for(it=vi.begin();it!=vi.end();it++)
        cout<<*it<<" ";
    //vi.size()用来返回vector的元素个数，可用%d输出，迭代器好像不能直接输出
    cout<<endl<<vi.size();
    //vi.clear()用来清空vector，时间复杂度为O(vi.size())
    vi.clear();
    cout<<endl<<vi.size()<<endl;
    //insert(it,x)用来向迭代器it位置处添加元素x，时间复杂度为O(vi.size())，（后面的依次后移）（下标从0开始）
    for(int i=0;i<5;i++)
        vi.push_back(i);
    vi.insert(vi.begin()+3,-1);
    for(it=vi.begin();it!=vi.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //vi.erase()用法有两种：删除单个元素，删除一个区间内所有的元素，时间复杂度均为O(vi.size())
    vi.erase(vi.begin()+2);
    for(it=vi.begin();it!=vi.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //区间删除，左闭右开
    vi.erase(vi.begin(),vi.begin()+2);
    for(it=vi.begin();it!=vi.end();it++)
        cout<<*it<<" ";
}

int main()
{
    vectorvisit();
    return 1;
}
