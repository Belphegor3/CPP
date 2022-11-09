#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <cstring>
# include <iostream>
# include <ctime>
# include <unistd.h>
# include <stdlib.h>

class Contact {

public:
	Contact(void);
	~Contact(void);
	void	set_contact(void);
	std::string	get_contact(char which);
	void	show_contact(void);
	void	reset_contact(void);
	
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

void	show_phonebook(void);

#endif