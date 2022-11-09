#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include <cstring>
# include <iostream>
# include <ctime>
# include <unistd.h>
# include "Contact.class.hpp"

class Phonebook {

public:
	
	Phonebook(void);
	~Phonebook(void);
	void	contact_data(void) const;
	void	search_contact(void);
	void	add_contact(void);
	int		getIndex(void);


	void		show_phonebook(void);
	void		line_format(int i, int oldest);
	std::string	overflow_10(int i, char which);


private:
	int 	_index;
	Contact	_contacts[8];
};

void	show_phonebook(void);

#endif