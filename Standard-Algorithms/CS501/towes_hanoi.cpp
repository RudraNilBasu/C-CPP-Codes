#include<iostream>

void hanoi(int n, char from, char to, char via)
{
	if(n==1) {
		std::cout<<"Move disk 1 from "<<from<<" to "<<to<<std::endl;
		return;
	}
	// move n-1 rods to "via" tower
	hanoi(n-1, from, via, to);
	std::cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<std::endl;
	hanoi(n-1, via, to, from);
}

int main()
{
	std::cout<<"Enter no of rods:";
	int n;
	std::cin>>n;
	hanoi(n,'A','C','B');
	return 0;
}
