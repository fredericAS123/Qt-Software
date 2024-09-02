#pragma once
#include<iostream>
using namespace std;

class  Mat2x2{
private:
    double m_data[4];
public:
    Mat2x2(double init_value = 0): 
		m_data{ init_value ,init_value ,init_value ,init_value } 
	{}; // ����ֵͬ��ʼ������Ԫ��  
    Mat2x2(const Mat2x2& another){
        const double* pa=another.getdata();
        for(int i=0;i<4;i++)
            m_data[i]=pa[i];
    } // �����ƹ��캯��
    Mat2x2(const double* elements){
        for(int i=0;i<4;i++)
            m_data[i]=elements[i];
    }// ��˳����������ֵ��ʼ������Ԫ��
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
    double &at(int y, int x) { // ����д����
        return m_data[y * 2 + x];
    }
    const double &at(int y, int x) const { // ֻ�����ʣ�ע��ǰ������const
        return m_data[y * 2 + x]; // ʵ�ֲ��ֺ�ǰһ������һ��
    }
    void operator = (const Mat2x2& b){
        const double* p=b.getdata();
        for(int i=0;i<4;i++)
            m_data[i]=p[i];
    } // �� a = b������*this��Ϊa
    void operator = (int n){
        for(int i=0;i<4;i++)
            m_data[i]=n;
    }
    void operator += (const Mat2x2& b){
        const double* p=b.getdata();
        for(int i=0;i<4;i++)
            m_data[i]+=p[i];
    } // �� a += b������*this��Ϊa
    Mat2x2 operator + (const Mat2x2& b) const{
        const double* p=b.getdata();
        double array[4];
        for(int i=0;i<4;i++){
            array[i]=m_data[i]+p[i];
        }
        Mat2x2 c=array;
        return c;
    } // �� c = a + b ����*this��Ϊa������ֵ��Ϊc
};
