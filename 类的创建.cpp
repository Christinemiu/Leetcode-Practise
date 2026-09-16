//类的创建，初始化以及类函数调用
'''
题目：
定义一个名为 Student 的类，用来记录学生信息和计算班级平均分：
私有数据成员：学号 id (string)，分数 score (double)。
静态私有数据成员：total_score (double，记录全班总分) 和 count (int，记录全班人数)。
公有成员函数：  
构造函数 Student(string id, double score)：初始化学号和分数，并在构造时将分数累加到 total_score，使 count 加 1。
static double getAverage()：静态成员函数，返回全班平均分（若人数为0则返回0）。
主函数首先输入学生人数 n，接着输入 n 个学生的学号和分数，最后调用静态函数输出全班的平均分。
--------------------------------------------------------------------------------------------------------------
输入
第一行一个整数 n；接下来 n 行，每行包含一个字符串（学号）和一个浮点数（分数）。
输出
一个浮点数，表示平均分（保留两位小数）
--------------------------------------------------------------------------------------------------------------
样例输入：
3
S001 85.5
S002 90.0
S003 78.5
样例输出:
84.67
--------------------------------------------------------------------------------------------------------------
'''

//解答
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
    private:
    string id;
    double score;
    //error: in-class initializer for static data member of type 'double' requires 'constexpr'
    //static double不允许类内初始化
    static double total_score;
    int count;
    //return type specification for constructor invalid
    //类中的构造函数(和类名相同)不可以返回类型，连void也不可以
    public:
    //d和s应该写在函数的参数列表当中
    Student(string d,double s){
        id=d;
        score=s;
        total_score+=score;
    }
    static void get_Average(int n){
        if(n==0){
            cout<<"0"<<endl;
        }
        else{
            static double average_score=total_score/n;
            cout<<fixed<<setprecision(2)<<average_score<<endl;
        }
    }
};

//静态成员还需要在类外定义一次
double Student::total_score=0;

int main(){
    int n;
    cin>>n;
    string id;
    double score;
    //内部的s不会被外部再次调用
    for(int j=0;j<n;j++){
        cin>>id>>score;
        Student s(id,score);
    }
    //需要再循环外设置一个对象才能达到Student::get_Average(n);
    //将函数改成静态，可以不依赖某个对象即可调用
    Student::get_Average(n);
    return 0;
}

