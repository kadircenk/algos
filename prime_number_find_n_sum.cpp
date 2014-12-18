#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	bool arr[2000001];
	int kok=(int)sqrt(2000000);
	long long syc=0;
	
	for (int i = 0; i < 2000000; arr[i++]=true);
	
	for (int i = 2; i <= kok; i++)
		if(arr[i])
			for (long long int k=0,j = i*i; j <= 2000000; j=i*i+(++k)*i)
				arr[j]=false;
	
	for (int i = 2; i < 2000000; i++)
		if(arr[i])
			syc+=i;
	
	cout<<syc<<endl;

	return 0;
	}
