#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

string input1(){
    cout<<"Enter string for bit stuffing: ";
    string s;cin>>s;
    return s;
}

bitset<32> bitstuff(bitset<32> &dataword){
    int cnt=0;
    bitset<32> stuffed;
    for(int i=31;i>=0;i--){
        if(dataword[i])cnt++;
        else cnt=0;
        stuffed[i]=dataword[i];
        if(cnt==5){
            //left shift stuffed bits to add zero.
            stuffed=stuffed<<1;
            cnt=0;
        }
    }
    return stuffed;
}

bitset<32> unstuff(bitset<32> &stuffed){
    bitset<32> unstuff;
    int cnt=0;
    for(int i=31;i>=0;i--){
        if(stuffed[i])cnt++;
        else cnt=0;
        unstuff[i]=stuffed[i];
        if(cnt==5){
            //right shift bits to remove zero.
            unstuff=unstuff>>1;
            //since one zero will be used move iterator one to the right.
            i--;
            cnt=0;
        }
    }
    return unstuff;
}

string input2(){
    cout<<"Enter string for CRC Encoding: ";
    string s;cin>>s;
    return s;
}

bitset<32> crcencoder(bitset<32> &message){
    int n=4;
    bitset<32> divisor(string("1011"));
    //append divisor length - 1 zeroes to end of message.
    bitset<32> dividend=message<<(n-1);
    //shft variable stores maximum distance of most significant bits - length of divisor length.
    int shft = ceil(log2(dividend.to_ulong() + 1)) - 4;
    bitset<32> rem;
    while ((dividend.to_ulong()>=divisor.to_ulong())||(shft>=0)){
        //right shift dividend and xor with divisor to get current remainder.
        rem = (dividend >> shft) ^ divisor;
        bitset<32> sm;
        for(int i=0;i<shft;i++)sm[i].flip();
        //calculate the new dividend.
        dividend = (dividend & sm) | (rem << shft);
        //update the shift value.
        shft=ceil(log2(dividend.to_ulong() + 1)) - 4;
    }
    bitset<32> codeword;
    //append the final remainder to message.
    codeword=(message<<(n-1))|(dividend);
    return codeword;
}

int main()  
{
    string inputStr=input1();
    bitset<32> dataword(inputStr);
    bitset<32> stuffedBits=bitstuff(dataword);
    cout<<"Stuffed bits: "<<stuffedBits<<'\n';

    bitset<32> unstuffBits=unstuff(stuffedBits);
    cout<<"Unstuffed bits: "<<unstuffBits<<'\n';

    string inputSt=input2();
    bitset<32> message(inputSt);
    cout<<"Encoded Bits :"<<crcencoder(message)<<'\n';
    return 0;
}