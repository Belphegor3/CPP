#include "span.class.hpp"
#define NB_TO_ADD 10000

void	multi_addNumber(Span *sp, int nb_to_add){
	for (int i = 0; i < nb_to_add; i++){
		sp->addNumber(rand());
	}	
}

int main()
{
srand(time(NULL));
Span sp = Span(7);
sp.addNumber(5);
try{
	sp.shortestSpan();
}
catch(std::exception & e){
	std::cout << e.what() << std::endl;
}
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(44);
sp.addNumber(140);
sp.addNumber(110);

std::cout << "shortest Span: " << sp.shortestSpan() << std::endl;
std::cout << "longest Span: " << sp.longestSpan() << std::endl;

try{
sp.addNumber(111);
}
catch(std::exception & e){
	std::cout << e.what() << std::endl << std::endl;
}
Span sp2 = Span(10000);
multi_addNumber(&sp2, NB_TO_ADD);
std::cout << "shortest Span over " << sp2.getNb() << " values: " << sp2.shortestSpan() << std::endl;
std::cout << "longest Span over " << sp2.getNb() << " values: " << sp2.longestSpan() << std::endl;
return 0;
}