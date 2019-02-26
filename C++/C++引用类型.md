# C++引用类型

引用(&)是标识符的别名

例如：

```c++
int i,j;

int &ri = i
j = 10;
ri = j//相当于i = j
```

![1551176990140](C:\Users\WXONE\AppData\Roaming\Typora\typora-user-images\1551176990140.png)

```c++
#include<iostream>
using namespace std;
void swap(int a,int b){
    int t = a;
    a = b;
    b = t;
}
int main(){
    int x = 5,y = 10;
    cout<<"x="<<x<<"y="<<y<<endl;
    swap(x,y);
    cout<<"x="<<x<<"y="<<y<<endl;
    return 0;
}
//运行结果 x = 5,y = 10
//		  x = 5,y = 10
```

![1551177362704](C:\Users\WXONE\AppData\Roaming\Typora\typora-user-images\1551177362704.png)

```c++
#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}
int main(){
    int x = 5,y = 10;
    cout<<"x="<<x<<"y="<<y<<endl;
    swap(x,y);
    cout<<"x="<<x<<"y="<<y<<endl;
    return 0;
}
//运行结果 x = 5,y = 10
//		  x = 5,y = 10
```

