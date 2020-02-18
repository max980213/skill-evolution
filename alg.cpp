//<algorithm>下的好用函数

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //max(x,y),min(x,y)，返回两个数中的最大最小，如果需要3个数，可以嵌套，可以是浮点数
    //abs(x)返回整数的绝对值，只能是整数，需要浮点数得用#include <math.h>下的fabs()

    //swap(x,y)，交换x，y的值

    //reverse(it,it2),将数组指针或迭代器左闭右开该区间内的元素进行反转（逆序）

    int a[5]={1,2,3,4,5};
    reverse(&a[0],&a[3]);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    string str="nihao";
    reverse(str.begin(),str.begin()+2);
    cout<<endl<<str<<endl;

    //next_permutation()，给出一个序列在全排列中的下一个序列，不太常用，不想看

    //fill()，可以把数组或容器中的某一段区间赋为某个相同的值，与memset不同，这里的赋值可以是【数组类型】对应范围内中的任意值

    fill(a,a+5,233);  //将该数组该范围内赋值为233，参数也为地址
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";

    //sort()，已经学过，注意cmp函数编写，参数为地址，注意结构体数组
    //也可以对容器，或容器内部内容进行排序，cmp中的类型为容器的类型，只能对vector，string，deque进行排序，像set、map容器内部用红黑树实现，本身有序
    //此时参数为迭代器

    string str1="hgfdz";     //对容器内容排序
    sort(str1.begin(),str1.end());
    cout<<endl<<str1<<endl;

    string str2[3]={"kkk","bbb","x"}; //对容器数组排序
    sort(str2,str2+3);
    for(int i=0;i<3;i++)
        cout<<str2[i]<<endl;
    cout<<endl;
    
    //lower_bound()和upper_bound()，需要用在有序数组或容器
    //参数为(first,last,val)，在左开右闭区间内找到：
    //第一个值大于等于，第一个值大于  val的
    //如果是数组，返回指针，如果是容器，返回迭代器
    //如果没有需要寻找的元素，返回可插入该元素位置的指针或迭代器
    //不常用，也不想看
    
    
    
    return 1;
}
