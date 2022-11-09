#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Term.hpp"
# include <cstring>
# include <string>
# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include "Contact.class.hpp"
# include "Phonebook.class.hpp"
# include <ctime>
# include <unistd.h>
# define TPS_LATENCE	75000

void	default_display(int	*count, int *bug);
int		basic_display(Phonebook *phonebook, int *count, int *aff, std::string line, int *bug);
void	godisplay(int i);
void	show_phonebook(Phonebook phonebook);
int		quit_or_again(void);
void 	disable_term(int utime);
void	term_window(void);

#endif