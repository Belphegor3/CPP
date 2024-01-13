#include "Fixed.class.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << "valeur de a: " << a << std::endl;
std::cout << "pre increment de a: " << ++a << std::endl;
std::cout << "valeur de a: " << a << std::endl;
std::cout << "post increment de a: " << a++ << std::endl << std::endl;
std::cout << "valeur de a: " << a << std::endl;
std::cout << "valeur de b: " << b << std::endl << std::endl;
std::cout << "max entre a et b: " << Fixed::max( a, b ) << std::endl;
std::cout << "min entre a et b: " << Fixed::min( a, b ) << std::endl;
std::cout << "tes de < entre a et b: " << (a < b) <<  std::endl;
std::cout << "tes de > entre a et b: " << (a > b) <<  std::endl;
std::cout << "tes de <= entre a et b: " << (a <= b) <<  std::endl;
std::cout << "tes de >= entre a et b: " << (a >= b) <<  std::endl;
std::cout << "tes de != entre a et b: " << (a != b) <<  std::endl;
std::cout << "tes de == entre a et b: " << (a == b) <<  std::endl << std::endl;
std::cout << "post decrement de a: " << a-- << std::endl;
std::cout << "valeur de a: " << a << std::endl;
std::cout << "pre decrement de a: " << --a << std::endl;
std::cout << "valeur de a: " << a << std::endl << std::endl;
Fixed const c( Fixed( 10.0f ) / Fixed( 2 ) );
Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );
std::cout << "division de 10.0f par 2 = " << c << std::endl;
std::cout << "addition de 5.05f et 2 = " << d << std::endl;
std::cout << "soustraction de 5.05f et 2 = " << e << std::endl;
return 0;
}