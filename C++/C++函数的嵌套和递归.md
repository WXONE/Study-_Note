# C++函数的嵌套和递归

## 嵌套调用

![img](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043X_2015_T2+sp+type@asset+block/image001qiantao.jpg)

## 递归调用

* ### 定义

  * 函数直接或间接的调用自身，称为递归调用

* ### 例：计算n！

  * 公式1：n!=n×(n-1)×(n-2)×(n-3)×...×2×1
  * 公式2：![img](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043X_2015_T2+sp+type@asset+block/image001digui.png)

    * ### 例如，计算4！的两个阶段：

      * 递推：

      * ![img](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043X_2015_T2+sp+type@asset+block/image002digui.jpg)

      * 回归：

      * ![img](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043X_2015_T2+sp+type@asset+block/image003digui.jpg)

        ```c++
        #include<iostream>
        using namespace std;
        unsigned fac(unsigned n){
            unsigned f;
            if(n == 0)
                f = 1;
            else
                f = fac(n - 1) * n;
            return f;
        }
        int main()
        {
            unsigned n;
            cout<<"Enter a positive integer：";
            cin>>n;
            unsigned y = fac(n);
            cout<<n<<"!="<<y<<endl;
            return 0;
        }
        ```
