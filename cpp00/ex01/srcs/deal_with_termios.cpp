#include "Phonebook.hpp"

int	quit_or_again(void) {

	Term::setRaw();
	std::atexit(Term::restoreTerm);
	std::cout << CURSOR_OFF;
	char buff[BUFFER_SIZE + 1];

	while (true) {
		int r = read(STDIN_FILENO, buff, BUFFER_SIZE);
		buff[r] = 0;
		if (buff[0] == 'q')
			break;
		if (buff[0] == 's')
			break;
	}
	std::cout << CURSOR_ON;
	if (buff[0] == 's')
		return (Term::restoreTerm(), EXIT_FAILURE);
	return (Term::restoreTerm(), EXIT_SUCCESS);
}

void	disable_term(int count) {

	Term::setRaw();
	std::atexit(Term::restoreTerm);
	std::cout << CURSOR_OFF;
	godisplay(count);
	std::cout << BEGIN_LINE;
	std::cout << CURSOR_ON;
	Term::restoreTerm();
}

void	term_window(void) {
	Term::setRaw();
	std::atexit(Term::restoreTerm);
	std::cout << CLEAR;
	std::cout << CURSOR_OFF;
	std::cout << "\x1b[26;75H\x1b[1;38;5;57mThere are no contacts yet, go ADD some !\x1b[0m";
	std::cout << "\x1b[24;75H\x1b[1;38;5;57mThere are no contacts yet, go ADD some !\x1b[0m";
	std::cout << "\x1b[28;75H\x1b[1;38;5;57mThere are no contacts yet, go ADD some !\x1b[0m";
	std::flush(std::cout);
	sleep(4);
	std::cout << CLEAR;
	std::cout << CURSOR_ON;
	Term::restoreTerm();
}