#include <iostream>
using namespace std;
template<typename T>
T Operation(T num1,T num2,char type)
{
	if(type == '+' || type== 'a' || type== 'A')
	{
		return num1+num2;
	}
	else if(type == '-' || type== 's' || type== 'S')
	{
		return num1-num2;
	}
	else if(type == '*' || type== 'm' || type== 'M')
	{
		return num1*num2;
	}
	else if(type == '/' || type== 'd' || type== 'D')
	{
		if(num2!=0)
		{
			return num1/num2;	
		}
	}
	else
	{
		cout<<"Enter valid Opertion";
		return 0;
	}
};
int main()
{
	double num1=0,num2=1,count=1;
	double result;
	char type;
	while(count!=0)
	{
		cout<<"Generalized Calculator For all Datatype and 2 value calculator"<<endl;
		cout<<"Enter the Value 1: "; cin>>num1;
		cout<<"Enter the Value 2: "; cin>>num2;
		cout<<"Operation: Enter the sign OR first letter Of operation"<<endl<<" + -> ADDITION"<<endl<<" - -> SUBTRACTION"<<endl<<" * -> MULTIPLICATION"<<endl<<" / ->DIVISION"<<endl;
		cout<<"Enter the Valid Operation:"; cin>>type;
		cout<<"Result:"<<Operation<double>(num1,num2,type);
		cout<<endl<<"Do you want perform another operation"<<endl<<"1 for yes & 0 for No:"; cin>>count;
		system("cls");
	}
	
	
	
}
