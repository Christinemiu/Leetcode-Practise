/*
涉及到类成员排序，使用了vector来储存成员，compare来比较类的特性
sort对vector内成员按照compare排序
*/

题目描述

设计一个 Student 类保存学生的学号、姓名和三门课程成绩，并提供计算总分的成员函数。

输入若干名学生的信息，按总分从高到低输出。总分相同时，学号字典序较小的学生排在前面。
-----------------------------------------------------------------------------------------------
输入

第一行输入整数 n，满足 1 <= n <= 100。
接下来 n 行，每行包含学号、姓名和三个整数成绩。学号和姓名均不包含空格，每门成绩均在 0 到 100 之间。
输出

按排序结果每行输出一名学生：

学号 姓名 总分
-----------------------------------------------------------------------------------------------
样例输入 

3
S03 Li 80 70 90
S01 Wang 90 90 90
S02 Chen 100 70 70

样例输出 

S01 Wang 270
S02 Chen 240
S03 Li 240
------------------------------------------------------------------------------------------------
回答：
  #include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student {
	private:
	    string id;
	string name;
	int total;
	public:
	    Student() {
		id="";
		name="";
		total=0;
	}
	void get_info();
	string get_name() const;
	int get_total() const;
	void print() const;
};

void Student::get_info() {
	string line;
	//getline(line);
	//getline(cin,line); 如果不写ws,getline会把num后面的空格也读进去
	//导致输出会多处一行0
	getline(cin>>ws,line);
	istringstream data(line);
	data>>id>>name;
	total=0;
	int grade;
	while(data>>grade) {
		total+=grade;
	}
}

//在后续的比较当中不允许修改id和total
//获取，查看信息通常都需要加const
string Student::get_name() const {
	return name;
}

int Student::get_total() const {
	return total;
}

bool compare(const Student& a, const Student& b) {
	if(a.get_total()!=b.get_total()){
	    return a.get_total()>b.get_total();
	}
	else{
	    return a.get_name()<b.get_name();
	}
}

void Student::print() const{
    cout<<id<<" "<<name<<" "<<total<<endl;
}
int main() {
	int num;
	cin>>num;
	vector<Student> students;
	for (int i=0;i<num;i++) {
		Student a;
		a.get_info();
		students.push_back(a);
	}

    sort(students.begin(),students.end(),compare);
    for(const Student&a :students){
        a.print();
    }
	return 0;
	
}
