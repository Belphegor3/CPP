/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:27:46 by lfchouch          #+#    #+#             */
/*   Updated: 2022/10/23 19:00:54 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <sstream>

// const char	*sentence0[] = { "\033[1;38;5;28mDo", "you", "want", "to", "\"\033[38;5;118mADD\033[0m\033[1;38;5;28m\"", "a", "new", "contact,", "\"\033[38;5;118mSEARCH\033[0m\033[1;38;5;28m\"", "a", "specific", "contact", "or", "are", "you", "done", "and", "wanna", "\"\033[38;5;118mEXIT\033[0m\033[1;38;5;28m\"", "😁\033[0m" };
// const char	*sentence1[] = { "\033[1;38;5;28mCan", "you", "please", "write", "\"\033[7;38;5;256mADD\033[0m\033[1;38;5;28m\",", "\"\033[7;38;5;256mSEARCH\033[0m\033[1;38;5;28m\"", "or", "\"\033[7;38;5;256mEXIT\033[0m\033[1;38;5;28m\"", "\033[4mWITH\033[24m", "\033[4mCAPITAL\033[24m", "\033[4mLETTERS\033[24m", "😑\033[0m" };
// const char	*sentence2[] = { "\033[1;38;5;28mCan", "you", "please", "write", "\"\033[38;5;45mADD\033[0m\033[1;38;5;28m\",", "\"\033[38;5;45mSEARCH\033[0m\033[1;38;5;28m\"", "or", "\"\033[38;5;45mEXIT\033[0m\033[1;38;5;28m\"", "\033[4mWITH\033[24m", "\033[4mCAPITAL\033[24m", "\033[4mLETTERS\033[24m", "😤\033[0m" };
// const char	*sentence3[] = { "\033[1;38;5;28mCan", "you", "please", "write", "\"\033[38;5;166mADD\033[0m\033[1;38;5;28m\",", "\"\033[38;5;166mSEARCH\033[0m\033[1;38;5;28m\"", "or", "\"\033[38;5;166mEXIT\033[0m\033[1;38;5;28m\"", "\033[4mWITH\033[24m", "\033[4mCAPITAL\033[24m", "\033[4mLETTERS\033[24m", "😡\033[0m" };
// const char	*sentence4[] = { "\033[1;38;5;129mDon't", "try", "me", "bitch" };
// const char	*sentence5[] = { "\033[1;38;5;198mJust", "write", "\"\033[5;38;5;196mADD\033[0m\033[1;38;5;198m\",", "\"\033[5;38;5;196mSEARCH\033[0m\033[1;38;5;198m\"", "or", "\"\033[5;38;5;196mEXIT\033[0m\033[1;38;5;198m\"", "👿\033[0m" };
// const char	*sentence6[] = { "Ok", "you", "got", "it,", "I'm", "out", "\033[5m🖕\033[0m🤬\033[5m🖕\033[0m", "\033[5m🖕\033[0m🤬\033[5m🖕\033[0m" };

// enum	Text{
// 	sentence0,	
// 	sentence1,	
// 	sentence2,	
// 	sentence3,	
// 	sentence4,	
// 	sentence5,	
// 	sentence6,
// 	nb_sentences	
// };

// const char	*sentences[][] = {
// 	sentence0,	
// 	sentence1,	
// 	sentence2,	
// 	sentence3,
// 	sentence4,	
// 	sentence5,	
// 	sentence6
// };

void	godisplay(int i)
{
	char		*splitted;

	if (i == 0){
		char	line0[] = "\033[1;38;5;28mDo you want to \"\033[38;5;118mADD\033[0m\033[1;38;5;28m\" a new contact, \"\033[38;5;118mSEARCH\033[0m\033[1;38;5;28m\" a specific contact or are you done and wanna \"\033[38;5;118mEXIT\033[0m\033[1;38;5;28m\" 😁\033[0m";
		splitted = std::strtok(line0, " ");
	}
	if (i == 1){
		char	line1[] = "\033[1;38;5;28mCan you please write \"\033[7;38;5;256mADD\033[0m\033[1;38;5;28m\", \"\033[7;38;5;256mSEARCH\033[0m\033[1;38;5;28m\" or \"\033[7;38;5;256mEXIT\033[0m\033[1;38;5;28m\" \033[4mWITH\033[24m \033[4mCAPITAL\033[24m \033[4mLETTERS\033[24m 😑\033[0m";
		splitted = std::strtok(line1, " ");
	}
	if (i == 2){
		char	line2[] = "\033[1;38;5;28mCan you please write \"\033[38;5;45mADD\033[0m\033[1;38;5;28m\", \"\033[38;5;45mSEARCH\033[0m\033[1;38;5;28m\" or \"\033[38;5;45mEXIT\033[0m\033[1;38;5;28m\" \033[4mWITH\033[24m \033[4mCAPITAL\033[24m \033[4mLETTERS\033[24m 😤\033[0m";
		splitted = std::strtok(line2, " ");
	}
	if (i == 3){
		char	line3[] = "\033[1;38;5;28mCan you please write \"\033[38;5;166mADD\033[0m\033[1;38;5;28m\", \"\033[38;5;166mSEARCH\033[0m\033[1;38;5;28m\" or \"\033[38;5;166mEXIT\033[0m\033[1;38;5;28m\" \033[4mWITH\033[24m \033[4mCAPITAL\033[24m \033[4mLETTERS\033[24m 😡\033[0m";
		splitted = std::strtok(line3, " ");
	}
	if (i == 4){
		char	line4[] = "\033[1;38;5;129mDon't try me bitch";
		splitted = std::strtok(line4, " ");
	}
	if (i == 5){
		char	line5[] = "\033[1;38;5;198mJust write \"\033[5;38;5;196mADD\033[0m\033[1;38;5;198m\", \"\033[5;38;5;196mSEARCH\033[0m\033[1;38;5;198m\" or \"\033[5;38;5;196mEXIT\033[0m\033[1;38;5;198m\" 👿\033[0m";
		splitted = std::strtok(line5, " ");
	}
	if (i == 6){
		char	line6[] = "Ok you got it, I'm out \033[5m🖕\033[0m🤬\033[5m🖕\033[0m \033[5m🖕\033[0m🤬\033[5m🖕\033[0m";
		splitted = std::strtok(line6, " ");
	}
	while (splitted)
	{
		std::cout << splitted << " ";
		std::flush(std::cout);
		usleep(TPS_LATENCE);
		splitted = std::strtok(NULL, " ");
	}
	if (i != 4)
		std::cout << std::endl;






	
	// for (int j = 0; *sentences[i][j]; j++){
	// 	std::cout << sentences[i][j] << " " << std::flush;
	// 	usleep(TPS_LATENCE);
	// }



	
	// std::string	line0 = "\033[1;38;5;28mDo you want to \"\033[38;5;118mADD\033[0m\033[1;38;5;28m\" a new contact, \"\033[38;5;118mSEARCH\033[0m\033[1;38;5;28m\" a specific contact or are you done and wanna \"\033[38;5;118mEXIT\033[0m\033[1;38;5;28m\" 😁\033[0m";
	// std::string	line1 = "\033[1;38;5;28mCan you please write \"\033[7;38;5;256mADD\033[0m\033[1;38;5;28m\", \"\033[7;38;5;256mSEARCH\033[0m\033[1;38;5;28m\" or \"\033[7;38;5;256mEXIT\033[0m\033[1;38;5;28m\" \033[4mWITH\033[24m \033[4mCAPITAL\033[24m \033[4mLETTERS\033[24m 😑\033[0m";
	// std::string	line2 = "\033[1;38;5;28mCan you please write \"\033[38;5;45mADD\033[0m\033[1;38;5;28m\", \"\033[38;5;45mSEARCH\033[0m\033[1;38;5;28m\" or \"\033[38;5;45mEXIT\033[0m\033[1;38;5;28m\" \033[4mWITH\033[24m \033[4mCAPITAL\033[24m \033[4mLETTERS\033[24m 😤\033[0m";
	// std::string	line3 = "\033[1;38;5;28mCan you please write \"\033[38;5;166mADD\033[0m\033[1;38;5;28m\", \"\033[38;5;166mSEARCH\033[0m\033[1;38;5;28m\" or \"\033[38;5;166mEXIT\033[0m\033[1;38;5;28m\" \033[4mWITH\033[24m \033[4mCAPITAL\033[24m \033[4mLETTERS\033[24m 😡\033[0m";
	// std::string	line4 = "\033[1;38;5;129mDon't try me bitch";
	// std::string	line5 = "\033[1;38;5;198mJust write \"\033[5;38;5;196mADD\033[0m\033[1;38;5;198m\", \"\033[5;38;5;196mSEARCH\033[0m\033[1;38;5;198m\" or \"\033[5;38;5;196mEXIT\033[0m\033[1;38;5;198m\" 👿\033[0m";
	// std::string	line6 = "Ok you got it, I'm out \033[5m🖕\033[0m🤬\033[5m🖕\033[0m \033[5m🖕\033[0m🤬\033[5m🖕\033[0m";

	// std::string output;

	// switch (i){
	// 	case (0):
	// 		output = line0;
	// 		break ;
	// 	case (1):
	// 		output = line1;
	// 		break ;
	// 	case (2):
	// 		output = line2;
	// 		break ;
	// 	case (3):
	// 		output = line3;
	// 		break ;
	// 	case (4):
	// 		output = line4;
	// 		break ;
	// 	case (5):
	// 		output = line5;
	// 		break ;
	// 	case (6):
	// 		output = line6;
	// 		break ;
	// 	default:
	// 		break ;
	// }
	// std::stringstream	stream;
	// stream << output;
	// std::string	word;
	// // output.clear();
	// while (stream >> word){
	// 	output.append(word + " ");
	// }
}

static void	chtagisplay(int start, int end)
{
	for (int i = start; i < end; i++){
		std::cout << "\033[38;5;" << i << "m#\033[0m";
	}
	for (int j = end - 1; j > start - 1; j--){
		std::cout << "\033[38;5;" << j << "m#\033[0m";
	}
	std::cout << std::endl;
}

static void	display_ragequit(char lettre)
{
	if (lettre == 'D')
	{
		std::cout << "\033[48;5;40m \033[31m" << lettre << "\033[48;5;40m \033[0m";
		std::flush(std::cout);
	}
	else
	{
		std::cout << "\033[48;5;40m\033[31m" << lettre << "\033[48;5;40m \033[0m";
		std::flush(std::cout);	
	}
	usleep(200000);
}

static void	ragequit(void)
{
	int	i = 0;
	char	lettre[11] = "DESTROYING";

	Term::setRaw();
	// std::cout << BEGIN_LINE;
	// std::cout << "\033[48;5;196m";//                     \033[0m\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	// std::flush(std::cout);
	while (lettre[i])
	{
		display_ragequit(lettre[i]);
		i++;
	}
	std::cout << std::endl;
	Term::restoreTerm();
}

int	basic_display(Phonebook *phonebook, int *count, int *aff, std::string line, int *bug)
{
	
	if (line == "ADD"){
		*count = 0;
		*aff = 0;
		std::cout << "\x1b[2J\x1b[H";
		phonebook->add_contact();
		std::cout << "\x1b[2J\x1b[H";
		*bug = 0;
		return (EXIT_SUCCESS);
	}
	else if (line == "SEARCH"){
		*count = 0;
		*aff = 0;
		std::cout << "\x1b[2J\x1b[H";
		*bug = 1;
		if (phonebook->getIndex() == 0)
			return (term_window(), EXIT_SUCCESS);
		phonebook->search_contact();
		return (EXIT_SUCCESS);
	}
	else if (line == "EXIT" || std::cin.eof()){
		ragequit();
		// std::cout << BEGIN_LINE;
		Term::restoreTerm();
		// std::cout << BEGIN_LINE;
		_exit(0);
	}
	return (*aff = 1, EXIT_FAILURE);
}

void	default_display(int	*count, int *bug)
{
	if (*bug == 1)
		return ;
	if (*count < 3){
		chtagisplay(203, 208);
		disable_term(++(*count));	
	}
	else if (*count == 3){
		chtagisplay(196, 201);
		disable_term(4);
		disable_term(5);
		(*count)++;
	}
	else if (*count == 4){
		ragequit();
		std::cout << BEGIN_LINE;
		disable_term(6);
		Term::restoreTerm();
		system("echo '\x1b[?25h'");
		_exit(4);
	}
}