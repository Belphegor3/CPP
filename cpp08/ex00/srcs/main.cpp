#include "easyfind.hpp"

#include "easyfind.hpp"

int	main()
{
	{	
		std::cout << "TRYING WITH THE LIST: 1, 17, 42" << std::endl;
		std::list<int>	lst1;
		
		lst1.push_back(1);
		lst1.push_back(17);
		lst1.push_back(42);

		std::cout << "The container contains " << easyfind(lst1, 17) << std::endl;
		try
		{
			std::cout << easyfind(lst1, 28) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout << "TRYING WITH THE VECTOR: 1, 17, 42" << std::endl;
		std::vector<int>	vec1;

		vec1.push_back(1);
		vec1.push_back(17);
		vec1.push_back(42);

		std::cout << "The container contains " << easyfind(vec1, 42) << std::endl;
		try
		{
			std::cout << easyfind(vec1, 58) << std::endl;
		}
		catch (const std::exception	&e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}