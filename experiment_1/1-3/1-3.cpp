#include <iostream>
using namespace std;
class Parent { // ����
public:
	void f1() {cout << "This is parent-f1" << endl;}
	virtual void f2() {cout << "This is parent-f2" << endl;} // ����f2���麯��
}parent;
class Child : public Parent { // ������
public:
	void f1() {cout << "This is child-f1" << endl;}
	void f2() override {cout << "This is child-f2" << endl;}
	void f3() {};
	
} child;
int main(int argc, char* argv[]) {
	Parent* p = new Child; // ����һ������ָ 
	p->f1(); // ִ���ĸ�f1��
	p->f2(); // ִ���ĸ�f2��	
	cout<<"****************����Ϊ��ͼ���Ͷ���д�Ĵ�������н��*************************" <<endl;
	auto new_parent = new Parent();
	new_parent->f1();
	new_parent->f2();
//	new_parent->f3();
	delete new_parent;
	delete p;
	return 0;
}

