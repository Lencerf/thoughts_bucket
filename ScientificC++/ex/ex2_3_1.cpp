#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "Please input positive integers and input '-1' when you have finished:\n";
	int temp = 0;
	int sum = 0;
	do
	{
		std::cin >> temp;
		if (temp == -2)
		{
			sum = 0;
			std::cout << "The sum has reset to zero.\n";
		} else if (temp > 0 && sum + temp <= 100)
		{
			sum += temp;
		} else if (sum + temp > 100)
		{
			sum += temp;
			std::cout << "The sum has exceeded 100!\n";
			break;
		} else if (temp <= 0 && temp != -1)
		{
			std::cout << "Please input positive integers!\n";
		}
	} while (temp != -1 && sum <= 100);
	printf("The sum is %d.\n",sum);
	return 0;
}