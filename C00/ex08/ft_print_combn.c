#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *tab, int n)
{
	int		i;
	bool		low;

	i = 1;
	low = 1;
	while (i < n)
	{
		if (tab[i - 1] >= tab[i]) //check each digit in a number combination if any digit is greater than the one follows it, low will be = 0 and the combi wont be printed 
			low = 0;
		i++; // if low is alr set to 0, i++ doesnt matter
	}
	if (low)
	{
		i = 0;
		while (i < n) // n is the number of digits in a combi
			ft_putchar(tab[i++] + 48); // print each digits
		if (tab[0] < (10 - n)) // the largest combi of n number we can have is (10 - n)(10 - n + 1)(10 - n + 2)... eg: n = 4 then largest combi is 6789, n = 5 is 56789, n = 6 is 456789 etc.
		{
			ft_putchar(','); // if haven't reached the largest combi we can print ',' after alr ft_putchar each combi
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		tab[n];

	i = 0;
	while (i < n)
		tab[i++] = 0; //when index i is smaller than no. of digits n => tab[i + 1] = 0. the value stored at the next index will start from 0 again.
	while (tab[0] <= (10 - n) && n >= 1 && n < 10) //when haven't reach the last combi
	{
		print(tab, n); //print combi
		tab[n - 1]++; // value stored at the last index (n - 1) cuz i counts from 0 is increases by 1. this means the value of combi is increased by 1
		i = n - 1; //start from the last digit of the combi
		while (i && n > 1) //while i != 0 and n > 1
		{
			if (tab[i] > 9) //once the value stored at index i reach 10
			{
				tab[i - 1]++; //the value of the digit in front is +1
				tab[i] = 0; //the value at i is set to 0. this is because we can only print digit by digit
			}
			i--; // if not move to the digit in front
		} 
	}
}
int	main()
{
	ft_print_combn(4);
}