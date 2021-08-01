#include "phonebook.hpp"
// #include "utils.hpp"

void	err_message(const std::string &err)
{
	std::cout << "Error!" << err << std::endl;
	exit(1);
}

static	int	size(int n)
{
	size_t			i;
	unsigned int	m;

	i = 0;
	m = n;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		m = n * (-1);
		i += 1;
	}
	while (m > 0)
	{
		m /= 10;
		i++;
	}
	return (i);
}

std::string ft_itoa(int n)
{
	std::string		str_cpp;
	char			*arr;
	size_t			c;
	unsigned int	m;

	c = size(n);
	arr = (char *)malloc((c + 1) * sizeof(char));
	if (!arr)
		err_message("Memory allocation error!");
	arr[c] = '\0';
	m = n;
	if (n == 0)
		arr[--c] = '0';
	if (n < 0)
	{
		arr[0] = '-';
		m = -n;
	}
	while (m > 0)
	{
		arr[--c] = ((m % 10) + '0');
		m /= 10;
	}
	str_cpp = static_cast<std::string>(arr);
	return (str_cpp);
}

unsigned long long int	ovrloading_protection(unsigned long long int n, int sign)
{
	if (n > 9223372036854775807)
	{
		if (sign > 0)
			n = -1;
		else if (sign < 0)
			n = 0;
	}
	return (n);
}

int	ft_atoi(const std::string &str)
{
	size_t					i;
	int						sign;
	unsigned long long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	number = ovrloading_protection(number, sign);
	return (sign * (int)number);
}