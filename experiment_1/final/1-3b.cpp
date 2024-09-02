#include<iostream>
#include"Matderive.h"
using namespace std;


void print_element(const MatBase& m, int y, int x) { // 注意参数是基类
    std::cout << m.at(y, x) << std::endl; // 调用虚函数所定义的接口
}
int main(){
    Mat2x2 a(9.0);
    Matrix b(2, 2, 7.0);
    print_element(a, 0, 0); // 输出 Mat2x2 变量 a 的第一个元素，注意输入是派生类
    print_element(b, 0, 0); // 输出 Matrix 变量 b 的第一个元素，注意输入是派生类

    return 0;
}
