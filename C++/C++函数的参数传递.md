# C++函数的参数传递

函数的形参在函数定义的时候是不占有内存空间的，只有当调用函数的时候，将实参传给形参的时候，才给形参分配给内存空间，将实参用来初始化形参，这叫做参数传递，参数传递分为单项传递和双向传递。

## 形参 实参

函数在被调用的时候才给形参分配存储单元，实参规定可以是常量，变量，或者是表达式，实参的类型要求和形参的类型必须相符，如果实参的类型和形参的类型不相符，编译器在编译的时候会首先试图去做类型转换，它首先试图将你的实参类型转换为形参类型，看看这种转型是否合法，如果合法就做隐含转换转过去，如果不能隐含转换，编译器将报错。实参传递给形参的默认情况下是值传递，也就是把值单向的传递过去，这样达到的效果就是将函数计算所需的数据用参数传递的方式给它，在函数体中，对参数值任何的修改，都只修改了形参，而触及不到主调函数中的实参，因为是单项传递，把值复制过去后，二者就切断了联系。

## 双向传递

有时候我们函数的计算结果有超过一个以上的值，而return语句只能返回一个值，这时候return语句就不好用了，我们需要另一种机制，让这个参数能够双向传递，也就是说，有一些参数可以将函数的计算结果再带回给主调函数。

我们的解决方案是传递引用，而不传值。而且传递引用的开销要比传值的开销要小。

```c++
void fun_1(int a);    //int类型，传值（复制产生新变量）
void fun_2(int& a);   //int类型，传引用（形参和实参是同一个东西）
void fun_3(int* arr); //指针类型，传值（复制产生新变量）
void func_4(int*& arr); //指针类型，传引用（形参和实参是同一个东西）
```

如果希望通过将参数传递到函数中，进而改变变量的值（比如变量是`T a`，T表示类型)，则可以有这2种方式选择：

1. 传a的引用：`void myfun(T& a)`
2. 传a的地址的值：`void myfun(T* a)`

## 传值

这是最简单的方式。形参意思是被调用函数的参数/变量，实参意思是主调函数中放到括号中的参数/变量。传值方式下，形参是实参的拷贝：重新建立了变量，变量取值和实参一样。

写一段测试代码，并配合gdb查看：

test：

```c++
#include <iostream>
using namespace std;

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

int main(){
    int x = 1;
    int y = 2;
    swap(x, y);
    cout << x << " " << y << endl;

    return 0;
}
```

```c++
➜  hello-cpp git:(master) ✗ g++ -g test.cc
➜  hello-cpp git:(master) ✗ gdb a.out 
(gdb) b main
Breakpoint 1 at 0x4008fa: file test.cc, line 13.
(gdb) r
Starting program: /home/chris/work/hello-cpp/a.out 

Breakpoint 1, main () at test.cc:13
13          int x = 1;
(gdb) s
14          int y = 2;
(gdb) p &x
$1 = (int *) 0x7fffffffdc58
(gdb) p &y
$2 = (int *) 0x7fffffffdc5c
(gdb) s
15          swap(x, y);
(gdb) s
swap (a=1, b=2) at test.cc:6
6           temp = a;
(gdb) p &a
$3 = (int *) 0x7fffffffdc2c
(gdb) p &b
$4 = (int *) 0x7fffffffdc28
(gdb) 
```

可以看到实参x和y的值为1和2，形参a和b的值也是1和2，但是x，y与a，b的地址并不相同，表明形参a和b是新建的变量，也就是**实参从形参复制了一份**，这就是所谓的传值

## 传指针

test:

```c++
#include <iostream>
using namespace std;

void test(int *p){
    int a = 1;
    p = &a;
    cout << p << " " << *p << endl;
}

int main(void){
    int *p = NULL;
    test(p);
    if(p==NULL){
        cout << "指针p为NULL" << endl;
    }
    return 0;
}
```

```c++
➜  hello-cpp git:(master) ✗ g++ -g test2.cc 
➜  hello-cpp git:(master) ✗ gdb a.out 
(gdb) b main
Breakpoint 1 at 0x4009e0: file test2.cc, line 11.
(gdb) r
Starting program: /home/chris/work/hello-cpp/a.out 

Breakpoint 1, main () at test2.cc:11
11          int *p = NULL;
(gdb) s
12          test(p);
(gdb) p p
$1 = (int *) 0x0
(gdb) p &p
$2 = (int **) 0x7fffffffdc58
(gdb) s
test (p=0x0) at test2.cc:4
4       void test(int *p){
(gdb) s
5           int a = 1;
(gdb) p p
$3 = (int *) 0x0
(gdb) p &p
$4 = (int **) 0x7fffffffdc18
(gdb) 
```

可以看到，`main()`函数内和`test()`函数内，变量p的值都是0,也就是都是空指针；但是它们的地址是不同的。也就是说，形参p只是从形参p那里复制了一份值（空指针的取值），形参是新创建的变量。

直接运行程序的结果也表明了这一点：

```c++
➜  hello-cpp git:(master) ✗ ./a.out 
0x7fff2a329e24 1
指针p为NULL
```

## 传引用

传值是C和C++都能用的方式。传引用则是C++比C所不同的地方。**传引用，传递的是实参本身，而不是实参的一个拷贝，形参的修改就是实参的修改**。相比于传值，传引用的好处是省去了复制，节约了空间和时间。假如不希望修改变量的值，那么请选择传值而不是传引用。

**test3.cc**

```c++
#include <iostream>
using namespace std;

void test(int &a){
    cout << &a << " " << a << endl;
}

int main(void){
    int a = 1;
    cout << &a << " " << a << endl;
    test(a);
    return 0;
}
```

再次开gdb调试（依然是多此一举的gdb...直接运行a.out看结果就可以）：

```c++
➜  hello-cpp git:(master) ✗ g++ -g test3.cc
➜  hello-cpp git:(master) ✗ gdb a.out 
(gdb) b main
Breakpoint 1 at 0x4009af: file test3.cc, line 8.
(gdb) r
Starting program: /home/chris/work/hello-cpp/a.out 

Breakpoint 1, main () at test3.cc:8
8       int main(void){
(gdb) s
9           int a = 1;
(gdb) s
10          cout << &a << " " << a << endl;
(gdb) s
0x7fffffffdc44 1
11          test(a);
(gdb) s
test (a=@0x7fffffffdc44: 1) at test3.cc:5
5           cout << &a << " " << a << endl;
(gdb) s
0x7fffffffdc44 1
6       }
(gdb) 
```

直接运行`./a.out`的结果：

```c++
➜  hello-cpp git:(master) ✗ ./a.out
0x7ffec97399e4 1
0x7ffec97399e4 1
```

显然，形参a和实参a完全一样：值相同，地址也相同。说明形参不是实参的拷贝，而是就是实参本身。