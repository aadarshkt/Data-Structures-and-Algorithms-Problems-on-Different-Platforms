#include <bits/stdc++.h>
using namespace std;

class Vehicle{
    int number_of_tyres;
    protected:
        bool usesFuel=true;
        Vehicle(int y){
            number_of_tyres=y;
        }
};

class Car : public Vehicle{
    private:
        int serialNo;
    public:
        int tireSize;
        Car(int x,int y) : Vehicle(y){
            serialNo = x;
        }
        int getSerialNo(){
            return serialNo;
        }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Car car1(123,4);
    cout<<car1.getSerialNo()<<'\n';

    return 0;
}