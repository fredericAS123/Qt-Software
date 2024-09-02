#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
 class MatBase { // ������࣬���а����˾���Ԫ�ض�ȡ�Ĵ��麯��
public:
    virtual double& at(int y, int x)=0; // ���崿�麯��
    virtual const double& at(int y, int x) const=0; // ���崿�麯��
};


class Mat2x2 : public MatBase { // �޸� Mat2x2��ʹ��Ϊ�����࣬��ʵ���麯������
private:
    double m_data[4];
public:
    Mat2x2(double init_value = 0): m_data{ init_value ,init_value ,init_value ,init_value } {}; // ����ֵͬ��ʼ������Ԫ��  
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

    virtual double& at(int y, int x){
        return m_data[y*2+x];
    } // �����麯��
    virtual const double& at(int y, int x) const{// �����麯��
        return m_data[y*2+x];
    }
};


class Matrix : public MatBase { // �޸� Matrix��ʹ��Ϊ�����࣬��ʵ���麯������
private:
    double* m_data;
    int m_height;
    int m_width;
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
        }// �Թ̶�ֵ��ʼ������Ԫ��
    Matrix(int height, int width, const double* data):m_height(height),m_width(width),m_data(new double[height*width]){
        if(data==nullptr){
            Matrix(height,width);
        }
        else{
            for(int i=0;i<height*width;i++)
                m_data[i]=data[i];
        }
        }

     // ������˳����ʵ�ֵ��ʼ��
    Matrix(const Matrix& another){
        const double* p=another.getdata();
        const int size=another.getheight()*another.getwidth();
        // this->m_data=new double(size);
        for(int i=0;i<size;i++)
            m_data[i]=p[i];
        }// ������ʼ��

//    virtual double& at(int y, int x){
//        return m_data[y*m_width+x];
//    } // �����麯��
//    virtual const double& at(int y, int x) const{
//        return m_data[y*m_width+x];
//    } // �����麯��
    
    
//    void MatBase::display() {
//	/*0 1 2      0      width-1
//	  3 4 5     width   2width-1
//	  6 7 8     2width
//	  */
//	for (int i = 0; i < m_height * m_width; i++) {
//		cout <<setw(4)<< m_data[i];
//		if ((i + 1) % m_width == 0)cout << endl;
//	}
//	cout<<endl;
//}

};
