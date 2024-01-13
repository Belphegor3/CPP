#include <set>
#include <list>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <time.h>
#include <iomanip>
#include <ctime>


void	deal_with_args(char **av){
	int i = 1;

	while (av[i]){
		if (!av[i][0])
			exit((std::cout << "Error" << std::endl, 1));
		for (int j = 0; av[i][j]; j++)
			if (!isdigit(av[i][j]))
				exit((std::cout << "Error" << std::endl, 1));
		if (atol(av[i]) < 0 || atol(av[i]) > 2147483647)
			exit((std::cout << "Error" << std::endl, 2));
		i++;
	}
}

void	deal_with_vector(char **av){
	unsigned int	i = 1;
	std::vector<unsigned int>	myVector;
	clock_t	t = clock();
	double		time = 0;

	while (av[i])
		myVector.push_back(atol(av[i++]));
	i = 0;
	size_t	size = myVector.size();
	std::vector<unsigned int>	result;
	unsigned int	k;
	while (i < static_cast<unsigned int>(size)){
		k = i + 1;
		while (k < size){
			if (myVector.at(i) > myVector.at(k++)){
				break ;
			}
		}
		if (k == size){
			result.insert(result.end(), myVector.at(i));
			myVector.erase(myVector.begin()+i);
			i = 0;
			size = myVector.size();
			continue ;
		}
		i++;
	}
	t = clock() - t;
	time = (static_cast<double>(t))/CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << result.size() << " elements with vector:\t" << std::fixed << std::setprecision(6) << time << " us" << std::endl;
	std::cout << "After:\t";
	for(std::vector<unsigned int>::iterator it = result.begin(); it != result.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}



std::pair<int, int>	insert_sort(int n1, int n2){
	std::pair<int, int> to_sort = std::make_pair(n1, n2);
	int	tmp;
	
	if (to_sort.first > to_sort.second){
		tmp = to_sort.first;
		to_sort.first = to_sort.second;
		to_sort.second = tmp;
	}
	return to_sort;
}

std::vector<int>	ford_vect(int ac, char **av){
	std::pair<int, int>	to_split;
	std::vector<int>	firstt(0);
	std::vector<int>	second(0);

	for (int i = 1; i < ac - 1; i+=2){
		to_split = insert_sort(atoi(av[i]), atoi(av[i + 1]));
		firstt.push_back(to_split.first);
		second.push_back(to_split.second);
	}
	if (ac % 2 == 0)
		firstt.push_back(atoi(av[ac - 1]));
	std::sort(firstt.begin(), firstt.end());
	std::sort(second.begin(), second.end());
	std::vector<int>	res(firstt.size()+second.size());
	std::merge(firstt.begin(), firstt.end(), second.begin(), second.end(), res.begin());
	return res;
}

std::list<int>	ford_list(int ac, char **av){
	std::pair<int, int>	to_split;
	std::list<int>	firstt(0);
	std::list<int>	second(0);

	for (int i = 1; i < ac - 1; i+=2){
		to_split = insert_sort(atoi(av[i]), atoi(av[i + 1]));
		firstt.push_back(to_split.first);
		second.push_back(to_split.second);
	}
	if (ac % 2 == 0)
		firstt.push_back(atoi(av[ac - 1]));
	firstt.sort();
	second.sort();
	std::list<int>	res(firstt.size()+second.size());
	std::merge(firstt.begin(), firstt.end(), second.begin(), second.end(), res.begin());
	return res;
}

int main(int ac, char **av) {
	clock_t	t;
	double	time = 0;

	std::cout << "\x1b[2J\x1b[H";
	if (ac == 1)
		return (std::cout << "./PmergeMe takes a list of positive numbers as parameters" << std::endl, EXIT_FAILURE);
	deal_with_args(av);
	std::cout << "Before:\t";
	for (int i = 1; i < ac; i++){
		if (i != ac - 1)
			std::cout << atol(av[i]) << " ";
		else
			std::cout << atol(av[i]);
	}
	std::cout << std::endl;


	// deal_with_vector(av);


	t = clock();
	std::vector<int> res_vect = ford_vect(ac, av);
	t = clock() - t;
	time = (static_cast<double>(t))/CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << res_vect.size() << " elements with vector:\t" << std::fixed << std::setprecision(6) << time << " us" << std::endl;
	t = clock();
	ford_list(ac, av);
	t = clock() - t;
	std::list<int> res_list = ford_list(ac, av);
	time = (static_cast<double>(t))/CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << res_list.size() << " elements with list:\t" << std::fixed << std::setprecision(6) << time << " us" << std::endl;
	std::vector<int>::iterator it = res_vect.begin();
	std::cout << "After:\t";
	for (;it != res_vect.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
    return 0;
}