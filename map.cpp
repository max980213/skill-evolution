#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map> //map容器

using namespace std;

//C++的许多容器
//4.map容器，映射，可从任何基本数据类型映射到另一种基本类型

void mapuse()  //string内容访问
{
   // map<string,int> mp; //如果是字符串作键值，则只能是string容器，不能是char[]数组（容器也可以用作映射）
    //元素访问的两种方式：下标，即键（只能唯一），（其他容器可认为键是int型），或通过迭代器访问
    map<char,int> mp;     //重复定义会报错
    mp['c']=30;  //可直接建立映射
    cout<<mp['c']<<endl;
    map<char,int>::iterator it=mp.begin();//定义迭代器
    //映射是一对值，一个it能同时访问键和值，通过it->first访问键，和it->second访问值
    cout<<it->first<<" "<<it->second<<endl;  //此时it指向第一个元素(begin())，map的迭代器可以自加，所以可用for循环遍历
    //因为map内部同set相同，也是通过红黑树实现，故map中元素会依据键值排增序

    //常用函数
    //1.mp.find(key)，返回键值为key的迭代器，时间复杂度O(logN)
    mp['a']=101;
    it=mp.find('a');   //如果find()的key不存在，会返回一个乱码，输出也是乱码
    cout<<it->first<<" "<<it->second<<endl;
    //2.mp.erase(),删除单个元素，删除区间元素
    //删除单个元素，可接受迭代器、键为参数
    //删除区间，接受迭代器为参数，左闭右开
    //3.mp.size()返回映射的对数
    //4。mp.clear()清空所有映射
    //如果一个键对应多个值，需要用multimap
    //映射类题目常用

}

int main() //multiset用来处理只排序不去重的情况      unordered_set用来处理只去重不排序的情况
{
    mapuse();
    return 0;
}
