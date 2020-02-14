//#include <stdio.h>
#include <iostream>
#include <set> //set容器

using namespace std;

//C++的许多容器
//2.set容器，可理解为一个集合，内部自动有序，不含重复元素

void setdef() //set的定义
{
    set<int> name;  //与vector定义类似
    set<int> arrayname[100]; //第一维长固定，数组中每一个元素都是一个set容器
    set<set<int> > arrayname1; //注意> >之间有空格
}

void setvisit()
{
    //set只能通过迭代器访问
    set<int> st;
    st.insert(3);
    set<int>::iterator it=st.begin();    //最开始的时候set是个空的，st.begin()没有返回，（这里此时it指向元素3）
    //除了vector和string之外的容器（类似数组）都不支持*(it+i)的访问方式，只能利用循环使it自加，逐个枚举
    for(int i=1;i<6;i++)
        st.insert(2*i);
    for(it=st.begin();it!=st.end();it++)   //这时it指向元素3，1和2都被插到了前面，所以不会输出，所以在for循环里应it=st.begin()
        cout<<*it<<" ";   //可看出，set自动去掉了重复元素3  迭代器只能进行相等比较
    //cout<<endl<<*(it+2);  不行，set不支持*(it+i)

    //st.insert(x)将元素x插入容器set中，自动递增排序和去重，时间复杂度为O(logN)，N为元素个数
    //st.find(x)返回st中元素值为x的迭代器，复杂度同上
    it=st.find(4);
    cout<<endl<<*it<<endl;
    //st.erase()，同样的删除迭代器位置元素（可结合find()），也可删除区间（左闭右开）
    st.erase(st.begin(),st.find(6));    //如果是如果find()没有查询到有的元素，则会删掉所有元素
                                        //但如果是st.erase(st.find(7),st.end())，对于查不到元素，不会进行删除
    // st.erase(st.find(7),st.find(9));    //这种也不会进行删除   （考虑左闭右开）
    st.erase(st.find(6));
    for(it=st.begin();it!=st.end();it++)
        cout<<*it<<" ";
    //st.size()用来获得set内元素个数，时间复杂度为O(1)
    cout<<endl<<st.size();
    //st.clear()用来清空所有元素
    //st.clear();  （一个面向对象的语句）
}

int main() //multiset用来处理只排序不去重的情况      unordered_set用来处理只去重不排序的情况
{
    setvisit();
    return 0;
}





