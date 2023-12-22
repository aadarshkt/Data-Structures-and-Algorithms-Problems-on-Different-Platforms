#include <bits/stdc++.h>
using namespace std;

class Complex {
    private:
        int real,imag;
    
    public:
        Complex(int r = 0,int i = 0){
            real = r;
            imag = i;
        }

        Complex operator+ (const Complex& obj){
            Complex res;
            res.real = real + obj.real; //real is implicit and obj.real is the second object.
            res.imag = imag + obj.imag;
            return res;
        }
        void print(){
            cout<<real<<" + "<<imag<<"j"<<'\n';
        }
};



int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Complex c1(2,3);
    Complex c2(3,2);

    Complex c3 = c1 + c2;

    c3.print();

    return 0;
}