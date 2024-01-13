#ifndef TERM_HPP
#define TERM_HPP

#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <signal.h>
#include <vector>
#include <time.h>

#define BUFFER_SIZE	1
#define ENTERSCREEN	"\x1b[?1049h"  // enables the alternative buffer
#define EXITSCREEN	"\x1b[?1049l" 	// disables the alternative buffer
#define HOME		"\x1b[H" // cursor home position
#define ERASESCREEN	"\x1b[2J"
#define CLEAR		"\x1b[2J\x1b{H"
#define CURSOR_OFF	"\x1b[?25l"
#define CURSOR_ON	"\x1b[?25h"

class Term
{
	public:
		static void setRaw(void);
		static void restoreTerm(void);

	private:
		typedef struct termios Termios;

		static Termios	_origin;
		static Termios	_raw;
		static bool		_isRaw;
		static bool		_error;

		static Termios getOriginTerm(void);



		Term(void);
		~Term(void);
		Term(const Term&);
		Term& operator=(const Term&);


};

Term::Termios Term::_origin = Term::getOriginTerm();
Term::Termios Term::_raw;
bool Term::_isRaw = false;
bool Term::_error = false;

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

Term::Termios Term::getOriginTerm(void) {
	Termios origin;
	if (tcgetattr(STDIN_FILENO, &origin))
		_error = true;
	_raw = _origin;
	_raw.c_iflag &= ~(ICRNL);
	_raw.c_lflag &= ~(ECHO);
	_raw.c_oflag &= ~(OPOST);

	// std::atexit(Term::restoreTerm);
	return (origin);
}

void	Term::setRaw(void){	
	if (!tcsetattr(STDIN_FILENO, TCSANOW, &_raw))
		_isRaw = true;
	else
		_isRaw = false;
}

void	Term::restoreTerm(void){
	tcsetattr(STDIN_FILENO, TCSANOW, &_origin);
}	

#endif