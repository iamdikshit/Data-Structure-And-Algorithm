#include<bits/stdc++.h>
using namespace std;
class Car
{
	public:
		int wheel;
		string color;
	public:
		Car(int a, string b)
		{
			wheel = a;
			color = b;
		}
		void start()
		{
			cout<<"Car start...";	
		}	
};
int main()
{
	Car car(6,"Yellow");
	cout<<"**********************************"<<endl;
	cout<<car.wheel<<endl;
	cout<<car.color<<endl;
	car.start();
	return 0;
}
