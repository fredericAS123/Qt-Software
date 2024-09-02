
#include<iostream>
//#include"Matrix.h"
#include<iomanip>
// #include<vector>
using namespace std;

class Matrix {
private:
	int m_height, m_width; // ����ĸ�(����)���(������
	double* m_data; // ����Ԫ��
public:

	Matrix(int height, int width, double value = 0); // �Թ̶�ֵ��ʼ������Ԫ��
	Matrix(int height, int width, const double* data); // ������˳����ʵ�ֵ��ʼ��
	Matrix(const Matrix& another); // ������ʼ��
	~Matrix(void); // �ͷ�

	const double* getData() const { return  m_data; };
	const int getHeight() const { return m_height; }
	const int getWidth()  const { return m_width; }
	void display();
	Matrix operator + (const Matrix& b) const;
	Matrix calculate1 (const Matrix& b,int size) const;
	void operator += (const Matrix& b) ;
	void calculate2(const Matrix& b, int size) ;
	double& at(int y, int x) { // ����д����
		return m_data[y * 2 + x];

	}
};




// �Թ̶�ֵ��ʼ������Ԫ��
Matrix::Matrix(int height, int width, double value ) :
	m_height(height), m_width(width), m_data(new double[height * width]) {
	for (int i = 0; i < height * width; i++)m_data[i] = value;
}



// ������˳����ʵ�ֵ��ʼ��
Matrix::Matrix(int height, int width, const double* data) :
	m_height(height), m_width(width), m_data(new double[height * width]) {
	if (data == nullptr)Matrix(height, width);//if data��ָ�� ����0��ʼ������Ԫ�صĹ��캯��
	else { for (int i = 0; i < height * width; i++) { m_data[i] = data[i]; } }
}//��data size < ����ߴ磿




// ������ʼ��
Matrix::Matrix(const Matrix& another) {
	const double* p = another.getData();
	const int size = another.getHeight() * another.getWidth();
	this->m_data = new double[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = p[i];
	}
}

Matrix::~Matrix() { delete m_data; m_data = nullptr; };

//������С��ͬ�ľ����ǲ�����ӵ�
Matrix Matrix::operator+(const Matrix& b) const
{
	int size = m_height * m_width;
	int size2 = b.getHeight() * b.getWidth();
	if (size2 != size)cout << "����ߴ�����" << endl;
	else return this->calculate1(b,size);
	 
}
Matrix Matrix::calculate1(const Matrix& b,int size) const {
	double* p = new double[size];
	const double* q = b.getData();
	for (int i = 0; i < size; i++) { p[i] = m_data[i] + q[i]; }
	return Matrix(m_height, m_width, p);
};

void Matrix::operator += (const Matrix& b) {
	int size = m_height * m_width;
	int size2 = b.getHeight() * b.getWidth();
	if (size2 != size)cout << "����ߴ�����" << endl;
	else return this->calculate2(b, size);

};

void Matrix::calculate2(const Matrix& b, int size) {
	double* p = new double[size];
	const double* q = b.getData();
	for (int i = 0; i < size; i++) { m_data[i] = m_data[i] + q[i]; }
	
};


void Matrix::display() {
	/*0 1 2      0      width-1
	  3 4 5     width   2width-1
	  6 7 8     2width
	  */
	for (int i = 0; i < m_height * m_width; i++) {
		cout << setw(4) << m_data[i];
		if ((i + 1) % m_width == 0)cout << endl;
	}
}





int main() {
	int height,width,size;
	cout << "���������ĳߴ磨��*��" << endl;
	cin >> height >> width;
	Matrix m(height, width);
	size = height * width;


	cout << "������"<<size<<"�������Ԫ��" << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int temp;
			cin >> temp;
			m.at(i, j) = temp;
		}
	}
	cout << "����ľ���Ϊ��" << endl;
	m.display();
	double data1[]{ 1,2,3,4,5,6 };
	double data2[]{ 6,5,4,3,2,1 };
	double data3[]{ 6,5,4,3,2,1,1 };

	
	cout << "����-1��Ĭ�ϳ�ʼֵΪdata3����" << endl;
	m.display();
	cout << "����0��Ĭ�ϳ�ʼֵΪ0����" << endl;
	Matrix m0(2, 3);
	m0.display();
	cout << "����1��Ĭ�ϳ�ʼֵΪ2����" << endl;
	Matrix m1(2, 3, 2);
	m1.display();
	cout << "����2��Ĭ�ϳ�ʼֵΪ����data1����" << endl;
	Matrix m2(2, 3, data1);
	m2.display();
	cout << "����3������1+����2����" << endl;

	Matrix m3=m2 + m1;
	m3.display();
	cout << "����4��Ĭ�ϳ�ʼֵΪ����data2����" << endl;

	Matrix m4(2, 3, data2);
	m4.display();
	cout << "����5������3+����4����" << endl;

	(m3 + m4).display();

	m3 += m;
	cout << "����6������3+=����-1��" << endl;
	m3.display();
	m0 += m2;
	cout << "����6������0+=����2��" << endl;

	m0.display();


	return 0;
}

