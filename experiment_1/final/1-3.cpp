#include <iostream>
using namespace std;
class Parent { // 基类
public:
	void f1() {cout << "This is parent-f1" << endl;}
	virtual void f2() {cout << "This is parent-f2" << endl;} // 声明f2是虚函数
}parent;
class Child : public Parent { // 派生类
public:
	void f1() {cout << "This is child-f1" << endl;}
	void f2() override {cout << "This is child-f2" << endl;}
	void f3() {};
	
} child;
int main(int argc, char* argv[]) {
	Parent* p = new Child; // 定义一个基类指 
	p->f1(); // 执行哪个f1？
	p->f2(); // 执行哪个f2？	
	cout<<"****************以下为试图解释而编写的代码的运行结果*************************" <<endl;
	auto new_parent = new Parent();
	new_parent->f1();
	new_parent->f2();
//	new_parent->f3();
	delete new_parent;
	delete p;
	return 0;
}

