#include <iostream>
#include <sstream>
#include <string>

std::string int2str(int num)
{
	std::ostringstream cnvrt;
	cnvrt << num;
	
	return ( cnvrt.str() );
}

int	main( void )
{
	int			num = 7655886;
	std::string	res;
	
	// std::ostringstream cnvrt;
	// cnvrt << num;
	// res = cnvrt.str();

	// res = static_cast<std::ostringstream*>( &(std::ostringstream() << num) ) -> str();

	res = int2str( num );

	std::cout << res << std::endl;
}