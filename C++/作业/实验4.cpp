#include<iostream>
using namespace std;
class Goods
{
public:
    Goods(int inBox, double inWeight);
    ~Goods();
    void Sell(int outBox, double outWeight);
    void print();
private:
    int Box;
    double weight;
    static int totalBox;
    static double totalWeight;
};

Goods::Goods(int inBox, double inWeight)
{
    Box = inBox;
    totalWeight = inWeight;
    totalBox = totalBox + inBox;
    totalWeight = totalWeight = inWeight;
}


void Goods::Sell(int outBox, double outWeight) {
    totalBox = totalBox - outBox;
    totalWeight = totalWeight - outWeight;
}

void Goods::print() {
    cout << ".当前货物总箱数为：" << totalBox << ".箱" << endl;
    cout << ".当前货物总重量为：" << totalWeight << "kg" << endl;
}
Goods::~Goods()
{
}
int Goods::totalBox = 0;
double Goods::totalWeight = 0.0;
int main()
{
    Goods gd(5, 200);
    gd.Sell(2, 50);
    gd.print();
    getchar();
    return 0;
}
