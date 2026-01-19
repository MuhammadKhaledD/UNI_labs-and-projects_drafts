#include <iostream>

using namespace std;

class Complex {
private:
	double real, img;
public:
	Complex(double r=0.0, double i=0.0)
	{
		real = r;
		img = i;
	}

	Complex operator * (const Complex& C)
	{
		double Real = real * C.real;
		double Img = C.img * img; 
		return Complex(Real, Img);
	}

	Complex operator ! ()
	{
		return Complex(real, -img);
	}

	bool operator == (const Complex& C)
	{
		return (real == C.real && img == C.img);
	}

	double& operator ~()
	{
		return img;
	}

	double get_r() const { return real; }
	double get_i() const { return img; }
	void ser_r(double r) { real = r; }
	void ser_i(double i) { img = i; }


};

Complex operator * (const Complex& C1, const Complex& C2)
{
	double real1 = C1.get_r();
	double real2 = C2.get_r();
	double img1 = C1.get_i();
	double img2 = C2.get_i();
	
	double Real = real1 * real2;
	double Img = img1* img2;
	return Complex(Real, Img);
}

ostream& operator << (ostream& O, const Complex& C)
{
	O << C.get_r() << " " << C.get_i() << endl;
	return O;
}

istream& operator >> (istream& I, Complex& C)
{
	double num = 0.0;
	I >> num; 
	C.ser_r(num);
	I.ignore();
	I >> num;
	C.ser_i(num);
	return I;
}

int main()
{
		Complex a(1, 1);
		Complex b(2, 2);
		Complex c(3, 3);
		cout << a << b << c;
		cin >> a >> b;
		cout << a << b << c << endl;
		a = b * c;
		cout << a << b << c << endl;
		a = b * !c;
		cout << a << b << c << endl;

		return 0;
}