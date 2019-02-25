# C++选择结构

## if语句

### if语句的语法形式

if (表达式) 语句

例：if (x > y) cout << x;

if (表达式) 语句1 else 语句2

例：if (x > y) cout << x;

else cout << y;

if (表达式1) 语句1
else if (表达式2) 语句2
else if (表达式3) 语句3
​           …
else 语句 n

### 例：判断闰年

```c++
#include <iostream>
using namespace std;
int main()
{
    int year;
    bool isLeapYear;
    cout<<"Enter the year:";
    cin>>year;
    isLeapYear = ((year%4 == 0&&year%100!=0)||(year%400 == 0));
    if(isLeapYear)
        cout<<year<<"is a leap year"<<endl;
    else
        cout<<year<<"is not a leap year"<<endl;
    return 0;
}
```

## 嵌套的if结构

* 语法形式

  if()

  ​	if()语句1

  ​	else 语句2

  else

  ​	if()语句3

  ​	else 语句4

###  例：输入两整数，比较两数大小：

```c++
#include<iostream>

using namespace std;

int main() {

          int x, y;

          cout << "Enter x and y:";

          cin >> x >> y;

          if (x != y)

                   if (x > y)

                             cout << "x > y" << endl;

                   else

                             cout << "x < y" << endl;

          else

                   cout << "x = y" << endl;

          return 0;

}
```

