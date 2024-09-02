
#include<iostream>
//#include"Matrix.h"
#include<iomanip>
// #include<vector>
using namespace std;

class Matrix {
private:
	int m_height, m_width; // 矩阵的高(行数)与宽(列数）
	double* m_data; // 矩阵元素
public:

	Matrix(int height, int width, double value = 0); // 以固定值初始化所有元素
	Matrix(int height, int width, const double* data); // 以数组顺序访问的值初始化
	Matrix(const Matrix& another); // 拷贝初始化
	~Matrix(void); // 释放

	const double* getData() const { return  m_data; };
	const int getHeight() const { return m_height; }
	const int getWidth()  const { return m_width; }
	void display();
	Matrix operator + (const Matrix& b) const;
	Matrix calculate1 (const Matrix& b,int size) const;
	void operator += (const Matrix& b) ;
	void calculate2(const Matrix& b, int size) ;
	double& at(int y, int x) { // 读和写访问
		return m_data[y * 2 + x];

	}
};




// 以固定值初始化所有元素
Matrix::Matrix(int height, int width, double value ) :
	m_height(height), m_width(width), m_data(new double[height * width]) {
	for (int i = 0; i < height * width; i++)m_data[i] = value;
}



// 以数组顺序访问的值初始化
Matrix::Matrix(int height, int width, const double* data) :
	m_height(height), m_width(width), m_data(new double[height * width]) {
	if (data == nullptr)Matrix(height, width);//if data空指针 调用0初始化所有元素的构造函数
	else { for (int i = 0; i < height * width; i++) { m_data[i] = data[i]; } }
}//若data size < 矩阵尺寸？




// 拷贝初始化
Matrix::Matrix(const Matrix& another) {
	const double* p = another.getData();
	const int size = another.getHeight() * another.getWidth();
	this->m_data = new double[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = p[i];
	}
}

Matrix::~Matrix() { delete m_data; m_data = nullptr; };

//两个大小不同的矩阵是不能相加的
Matrix Matrix::operator+(const Matrix& b) const
{
	int size = m_height * m_width;
	int size2 = b.getHeight() * b.getWidth();
	if (size2 != size)cout << "矩阵尺寸有误" << endl;
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
	if (size2 != size)cout << "矩阵尺寸有误" << endl;
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
	cout << "请输入矩阵的尺寸（高*宽）" << endl;
	cin >> height >> width;
	Matrix m(height, width);
	size = height * width;


	cout << "请输入"<<size<<"个矩阵的元素" << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int temp;
			cin >> temp;
			m.at(i, j) = temp;
		}
	}
	cout << "输入的矩阵为：" << endl;
	m.display();
	double data1[]{ 1,2,3,4,5,6 };
	double data2[]{ 6,5,4,3,2,1 };
	double data3[]{ 6,5,4,3,2,1,1 };

	
	cout << "矩阵-1（默认初始值为data3）：" << endl;
	m.display();
	cout << "矩阵0（默认初始值为0）：" << endl;
	Matrix m0(2, 3);
	m0.display();
	cout << "矩阵1（默认初始值为2）：" << endl;
	Matrix m1(2, 3, 2);
	m1.display();
	cout << "矩阵2（默认初始值为数组data1）：" << endl;
	Matrix m2(2, 3, data1);
	m2.display();
	cout << "矩阵3（矩阵1+矩阵2）：" << endl;

	Matrix m3=m2 + m1;
	m3.display();
	cout << "矩阵4（默认初始值为数组data2）：" << endl;

	Matrix m4(2, 3, data2);
	m4.display();
	cout << "矩阵5（矩阵3+矩阵4）：" << endl;

	(m3 + m4).display();

	m3 += m;
	cout << "矩阵6（矩阵3+=矩阵-1）" << endl;
	m3.display();
	m0 += m2;
	cout << "矩阵6（矩阵0+=矩阵2）" << endl;

	m0.display();


	return 0;
}

