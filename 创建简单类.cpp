
**题目描述
设计一个 Product 类保存商品名称、单价和购买数量，并提供计算商品总价的成员函数。

输入一种商品的信息，创建商品对象并输出该商品的总价。
输入

输入一行，包含商品名称 name、单价 price 和购买数量 quantity。
商品名称不包含空格，0 <= price <= 100000，0 <= quantity <= 10000。
输出

输出商品名称和总价，总价保留两位小数：

Product=商品名称 Total=总价
--------------------------------------------------------------------------
**样例输入

Pen 2.5 4

**样例输出

Product=Pen Total=10.00

--------------------------------------------------------------------------

**解答
/*
简单类的定义：
    类的变量有哪些
    类的函数有那些
    函数具体内容需要做什么
    如何调用函数
*/
#include <iostream>
#include <string>
using namespace std;

class Product{
  private:
  string name;
  double price;
  int quantity;
  
  public:
  Product();
  void input();
  double Total_cost();
  string get_name();
  
};
//类内外都需要声明返回类型
Product::Product(){
    name="";
    price=0.0;
    quantity=0;
}

void Product::input(){
    cin>>name>>price>>quantity;
}

double Product::Total_cost(){
    double total_cost=price*quantity;
    return total_cost;
}

string Product::get_name(){
    return name;
}

int main(){
    //Product Product1(); 这是在建立函数而不是对象
    Product Product1;
    Product1.input();
    printf("Product=%s Total=%.2f\n",
    Product1.get_name().c_str(),
    Product1.Total_cost());
}
