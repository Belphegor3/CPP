#ifndef TERM_HPP
#define TERM_HPP

#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <signal.h>

#define BUFFER_SIZE	1
#define ENTERSCREEN	"\x1b[?1049h"  // enables the alternative buffer
#define EXITSCREEN	"\x1b[?1049l" 	// disables the alternative buffer
#define HOME		"\x1b[H" // cursor home position
#define ERASESCREEN	"\x1b[2J"
#define CLEAR		"\x1b[2J\x1b[H"
#define CURSOR_OFF	"\x1b[?25l"
#define CURSOR_ON	"\x1b[?25h"
#define BEGIN_LINE	"\033[0E"

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
		Term(void);
		~Term(void);
		Term(const Term&);
		Term& operator=(const Term&);


};

#endif