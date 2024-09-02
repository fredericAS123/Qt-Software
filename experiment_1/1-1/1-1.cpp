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
    cout<<"��ʼ��(0,0)Ϊ:"<<endl;
    cout << a2.at(0, 0) << endl;
    a2.at(0, 0) = 9; // ע��������÷�������Ԫ�ظ�ֵ
    cout<<"��(0,0)Ϊ9��ֵ��(0,0)Ϊ:"<<endl;
    cout << a2.at(0, 0) << endl;
    const Mat2x2& ref_a2 = a2; // ֻ�����ã����ref_aֻ�ܵ�����const��β�ĳ�Ա����
    cout<<"ref_a���ó�Ա�������(0,0)Ϊ��"<<endl;
    cout << ref_a2.at(0, 0) << endl;

    //1-1b.(2):
//    cout<<endl;
// 	cout<<"***********1-1b(2):***********"<<endl;
    //double Mat2x2::at(int row, int col) ����ֵӦΪ��ӦԪ�صĵ�ַ������Ԫ�ص�ֵ

    //1-1c.(1):
    cout<<endl;
 	cout<<"***********1-1c(1):***********"<<endl;
    Mat2x2 a3(data), b3;
	b3 = a3;
	cout  << "[a3(data)] a3��ֵΪ��" << endl;
	a3.display();
	cout << endl << "b3��ֵΪ��" << endl;
	b3.display();
	a3.at(0, 0) = 5;
	cout << endl << "[a3.at(0,0)=5] a3��ֵΪ��" << endl;
	a3.display();
//	a3 = 5;
//	cout <<endl<< "[a3=5]  a3�޸ĺ��ֵΪ��" << endl;
//	a3.display();

    //1-1c.(2):
    cout<<endl;
 	cout<<"***********1-1c(2):***********"<<endl;
    Mat2x2 a4;
    a4 = 5; // ��a������Ԫ�ض���ֵΪ5���� [5, 5; 5, 5]
    cout<<"����Ԫ�ض���ֵΪ5��MatΪ"<<endl;
    a4.display();

    
    //1.1d:
    cout<<endl;
 	cout<<"***********1-1d:***********"<<endl;
 	
 	cout<<"����1��"<<endl;
    Mat2x2 a5(data);
	cout << endl << "a5��ֵΪ��" << endl;
	a5.display();
	cout<<"a4��ֵΪ��"<<endl;
	a4.display();
	a5 += a4;
	cout << endl << "a5+=a4��a5��ֵΪ��" << endl;
	a5.display();
	Mat2x2 a6= a5+a4;
	cout << endl << "a5+a4��ֵΪ��" << endl;
	a6.display();
	
	cout<<"����2��"<<endl;
	cout<<"a3��ֵΪ��"<<endl;
	a3.display();
	cout<<"a2��ֵΪ��"<<endl;
	a2.display();    
	a3 += a2;
	cout << endl << "a3+=a2��a3��ֵΪ��" << endl;
	a3.display();
	Mat2x2 a7= a5+a4;
	cout << endl << "a3+a2��ֵΪ��" << endl;
	a7.display();
}

