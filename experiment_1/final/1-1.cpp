#include<iostream>
#include"mat2x2.h"

using namespace std;

int main(){
    //1-1a:
    cout<<"***********1-1a:***********"<<endl;
    double data[] = {1, 2, 3, 4};
    Mat2x2 a1(data);
    cout<<"Mat a1"<<endl;
	a1.display(); 
    Mat2x2 b1(5);
    cout<<"Mat b1"<<endl;
	b1.display(); 
    Mat2x2 c1 = a1;
    cout<<"Mat c1"<<endl;
    c1.display();
    Mat2x2 d1;
    cout<<"Mat d1"<<endl;
    d1.display();

    // 1-1b.(1):
    cout<<endl;
 	cout<<"***********1-1b(1):***********"<<endl;
    Mat2x2 a2(data);
    cout<<"初始的(0,0)为:"<<endl;
    cout << a2.at(0, 0) << endl;
    a2.at(0, 0) = 9; // 注意此特殊用法，是向元素赋值
    cout<<"向(0,0)为9赋值后(0,0)为:"<<endl;
    cout << a2.at(0, 0) << endl;
    const Mat2x2& ref_a2 = a2; // 只读引用，因此ref_a只能调用以const结尾的成员函数
    cout<<"ref_a调用成员函数后的(0,0)为："<<endl;
    cout << ref_a2.at(0, 0) << endl;

    //1-1b.(2):
//    cout<<endl;
// 	cout<<"***********1-1b(2):***********"<<endl;
    //double Mat2x2::at(int row, int col) 返回值应为相应元素的地址，不是元素的值

    //1-1c.(1):
    cout<<endl;
 	cout<<"***********1-1c(1):***********"<<endl;
    Mat2x2 a3(data), b3;
	b3 = a3;
	cout  << "[a3(data)] a3的值为：" << endl;
	a3.display();
	cout << endl << "b3的值为：" << endl;
	b3.display();
	a3.at(0, 0) = 5;
	cout << endl << "[a3.at(0,0)=5] a3的值为：" << endl;
	a3.display();
//	a3 = 5;
//	cout <<endl<< "[a3=5]  a3修改后的值为：" << endl;
//	a3.display();

    //1-1c.(2):
    cout<<endl;
 	cout<<"***********1-1c(2):***********"<<endl;
    Mat2x2 a4;
    a4 = 5; // 将a的所有元素都赋值为5，即 [5, 5; 5, 5]
    cout<<"所有元素都赋值为5的Mat为"<<endl;
    a4.display();

    
    //1.1d:
    cout<<endl;
 	cout<<"***********1-1d:***********"<<endl;
 	
 	cout<<"用例1："<<endl;
    Mat2x2 a5(data);
	cout << endl << "a5的值为：" << endl;
	a5.display();
	cout<<"a4的值为："<<endl;
	a4.display();
	a5 += a4;
	cout << endl << "a5+=a4后a5的值为：" << endl;
	a5.display();
	Mat2x2 a6= a5+a4;
	cout << endl << "a5+a4的值为：" << endl;
	a6.display();
	
	cout<<"用例2："<<endl;
	cout<<"a3的值为："<<endl;
	a3.display();
	cout<<"a2的值为："<<endl;
	a2.display();    
	a3 += a2;
	cout << endl << "a3+=a2后a3的值为：" << endl;
	a3.display();
	Mat2x2 a7= a5+a4;
	cout << endl << "a3+a2的值为：" << endl;
	a7.display();
}

