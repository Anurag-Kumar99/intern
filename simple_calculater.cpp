#include<iostream>
using namespace std;
int main()
{


double num1,num2;
char op;
cout<<"enter first number :  ";
cin>>num1;
cout<<"enter second number :  ";
cin>>num2;
cout<<"choose an operation :  ";
cin>>op;
switch(op)
{
    case '+':
    cout<<"Result:  "<<num1 + num2<<endl;
    break;
    case '-':
    cout<<"result: "<< num1 - num2<<endl;
    break;
    case '*':
    cout<<"result: "<< num1 * num2<<endl;
    break;
    case '/':
    if(num2 != 0)
    cout<<"result: "<< num1/num2<<endl;
    else
    cout<<"error: division by zero"<<endl;
    break;
default:
cout<<"invalid operation "<<endl;
}
return 0;


}

