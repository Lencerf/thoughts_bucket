#include <iostream>
int main()
{
	int x,y;
	std::cin >> x >> y;
	if(y==0)
	{
		std::cerr << "Error!\n";
	} else
	{
		std::cout << x/y;
	}
	return 0;
}
