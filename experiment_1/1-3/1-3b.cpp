#include<iostream>
#include"Matderive.h"
using namespace std;


void print_element(const MatBase& m, int y, int x) { // ע������ǻ���
    std::cout << m.at(y, x) << std::endl; // �����麯��������Ľӿ�
}
int main(){
    Mat2x2 a(9.0);
    Matrix b(2, 2, 7.0);
//    cout<<"Mat a"<<endl;
//	a.display();
//	cout<<endl;
//	cout<<"Mat b"<<endl; 
//    b.display();
//    cout<<endl;
    print_element(a, 0, 0); // ��� Mat2x2 ���� a �ĵ�һ��Ԫ�أ�ע��������������
    print_element(b, 0, 0); // ��� Matrix ���� b �ĵ�һ��Ԫ�أ�ע��������������

    return 0;
}

