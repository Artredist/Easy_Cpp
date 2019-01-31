#include <iostream>

using namespace std;

class Complex{

private:
    float real, imaginary;
public:
    //Constructors - "General" initialisation + user-defined initialisation
    Complex():real(0.0f), imaginary(0.0f){}
    Complex(float real, float imaginary):real(real), imaginary(imaginary){}

    //Copy-constructor:
    Complex(const Complex& other){real=other.real; imaginary=other.imaginary;}

    //Destructor:
    ~Complex(){}

    //Overloaded left bit shift operator:
    friend ostream& operator<<(ostream& out, const Complex& c){
        out<<c.real<<" + j"<<c.imaginary;
        return out;
    }

    //Overloaded addition operator:
    const friend Complex operator+(const Complex& c1, const Complex& c2){
        return Complex(c1.real+c2.real, c1.imaginary+c2.imaginary);
    }

    //Overloaded assignment operator:
    const Complex& operator=(const Complex& c){real=c.real; imaginary=c.imaginary; return *this;}

    //Equality test:
    bool operator==(const Complex& other) const{
        return ((real==other.real) && (imaginary==other.imaginary));
    }

    //Not-equality test:
    bool operator!=(const Complex& other) const{
        return (!(*this==other));
    }

    //Overloaded dereference operator - for complex conjugates:
    Complex operator*() const{
        return Complex(real, -imaginary);
    }
};

int main()
{
    Complex c1(10.2f,43.2f);;
    Complex c2(12.2f,23.2f);
    Complex c3;
    c3=c2;

    cout<<c1+c2<<endl;
    cout<<(c1==c3)<<endl;
    cout<<*c1<<endl;
    return 0;
}
