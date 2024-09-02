#pragma once
#include<iostream>
using namespace std;

class  Mat2x2{
private:
    double m_data[4];
public:
    Mat2x2(double init_value = 0): 
		m_data{ init_value ,init_value ,init_value ,init_value } 
	{}; // 以相同值初始化矩阵元素  
    Mat2x2(const Mat2x2& another){
        const double* pa=another.getdata();
        for(int i=0;i<4;i++)
            m_data[i]=pa[i];
    } // 矩阵复制构造函数
    Mat2x2(const double* elements){
        for(int i=0;i<4;i++)
            m_data[i]=elements[i];
    }// 以顺序访问数组的值初始化矩阵元素
    const double* getdata()const{
        return m_data;
    }
    void display(){
        for(int i=0;i<4;i++){
            cout<<m_data[i]<<" ";
            if(i==1) cout<<endl;
        }
        cout<<endl;
    }
    double &at(int y, int x) { // 读和写访问
        return m_data[y * 2 + x];
    }
    const double &at(int y, int x) const { // 只读访问，注意前后两个const
        return m_data[y * 2 + x]; // 实现部分和前一个函数一样
    }
    void operator = (const Mat2x2& b){
        const double* p=b.getdata();
        for(int i=0;i<4;i++)
            m_data[i]=p[i];
    } // 即 a = b，其中*this即为a
    void operator = (int n){
        for(int i=0;i<4;i++)
            m_data[i]=n;
    }
    void operator += (const Mat2x2& b){
        const double* p=b.getdata();
        for(int i=0;i<4;i++)
            m_data[i]+=p[i];
    } // 即 a += b，其中*this即为a
    Mat2x2 operator + (const Mat2x2& b) const{
        const double* p=b.getdata();
        double array[4];
        for(int i=0;i<4;i++){
            array[i]=m_data[i]+p[i];
        }
        Mat2x2 c=array;
        return c;
    } // 即 c = a + b 其中*this即为a，返回值即为c
};
