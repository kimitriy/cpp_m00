#include <iostream>
#include <string>
#include <ctime>

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

int	main()
{
	time_t rawtime;
	struct tm *tinfo;

	time(&rawtime);
	tinfo = localtime(&rawtime);

	std::string year = ft_itoa(tinfo->tm_year + 1900);
	std::string month;
	month = tinfo->tm_mon < 10 ? month = "0" + ft_itoa(tinfo->tm_mon + 1) : month = ft_itoa(tinfo->tm_mon + 1);
	std::string day;
	day = tinfo->tm_mday < 10 ? day = "0" + ft_itoa(tinfo->tm_mday) : day = ft_itoa(tinfo->tm_mday);
	std::string hour;
	hour = tinfo->tm_hour < 10 ? hour = "0" + ft_itoa(tinfo->tm_hour) : hour = ft_itoa(tinfo->tm_hour);
	std::string min;
	min = tinfo->tm_min < 10 ? min = "0" + ft_itoa(tinfo->tm_min) : min = ft_itoa(tinfo->tm_min);
	std::string sec;
	sec = tinfo->tm_sec < 10 ? sec = "0" + ft_itoa(tinfo->tm_sec) : sec = ft_itoa(tinfo->tm_sec);

	std::cout << "[" << year << month << day << "_" << hour << min << sec << "]" << std::endl;

	return (0);
}