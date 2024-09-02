#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class Matrix{
public:
    const int getheight()const{
        return m_height;
    }
    const int getwidth()const{
        return m_width;
    }
    const double *getdata()const{
        return m_data;
    }
    Matrix(int height, int width, double value=0){
        m_height=height;
        m_width=width;
        m_data=new double[height*width];
        for(int i=0;i<height*width;i++){
            m_data[i]=value;
        }
        }// 以固定值初始化所有元素
    Matrix(int height, int width, const double* data):m_height(height),m_width(width),m_data(new double[height*width]){
        if(data==nullptr){
            Matrix(height,width);
        }
        else{
            for(int i=0;i<height*width;i++)
                m_data[i]=data[i];
        }
        }

     // 以数组顺序访问的值初始化
    Matrix(const Matrix& another){
        const double* p=another.getdata();
        const int size=another.getheight()*another.getwidth();
        this->m_data=new double(size);
        for(int i=0;i<size;i++)
            m_data[i]=p[i];
        }// 拷贝初始化
    ~Matrix(void); // 释放
    void operator += (const Matrix& b){
        const double* p=b.getdata();
        const int size=b.getheight()*b.getwidth();
         this->m_data=new double(size);
        for(int i=0;i<size;i++)
            m_data[i]+=p[i];
    } // 即 a += b，其中*this即为a
    Matrix operator + (const Matrix& b) const{
        const double* p=b.getdata();
        const int size=b.getheight()*b.getwidth();
        double *array=new double(size);
        for(int i=0;i<size;i++){
            array[i]=m_data[i]+p[i];
        }
        Matrix c(b.getheight(),b.getwidth(),array);
        return c;
    } // 即 c = a + b 其中*this即为a，返回值即为c
    void display(){
        /*0 1 2      0      width-1
	    3 4 5     width   2width-1
	    6 7 8     2width
	    */
	    for (int i = 0; i < m_height * m_width; i++) {
		    cout <<setw(4)<< m_data[i];
		    if ((i + 1) % m_width == 0)cout << endl;
	    }
    }
private:
    int m_height, m_width; // 矩阵的高(行数)与宽(列数）
    double* m_data; // 矩阵元素
};
Matrix::~Matrix(){
    delete m_data;
    m_data=nullptr;
};