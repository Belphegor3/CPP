#include "Term.hpp"

Term::Termios Term::_origin;
Term::Termios Term::_raw;

Term::Term(void) {
	return ;
}

Term::~Term(void) {
	return ;
}

Term::Term(const Term&) {
	return ;
}

Term&	Term::operator=(const Term&) {
	return *this;
}

void	Term::setRaw(void){
	tcgetattr(STDIN_FILENO, &_origin);
	_raw = _origin;
	_raw.c_iflag &= ~(IXON | ICRNL);
	_raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	_raw.c_oflag &= ~(OPOST);
	tcsetattr(STDIN_FILENO, TCSANOW, &_raw);
}

void	Term::restoreTerm(void){
	tcsetattr(STDIN_FILENO, TCSANOW, &_origin);
}