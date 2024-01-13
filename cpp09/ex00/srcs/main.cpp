#include "BitcoinExchange.hpp"
#include "Term.hpp"
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
# include <sys/time.h>

int	val(void){
	int res;

	pthread_mutex_lock(&shit);
	res = stop;
	pthread_mutex_unlock(&shit);
	return res;
}

long long	get_time(void)
{
	struct timeval	t;
	int				i;

	if (gettimeofday(&t, NULL) == -1)
		return (-1);
	i = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (i);
}

void	ft_usleep(int time)
{
	long long	current_time;

	current_time = get_time();
	while (time--)
	{
		if (val() == 1)
			break ;
		usleep(100);
	}
}

void	*routine(void *arg){
	int	rand_color;

	(void)arg;
	pthread_mutex_lock(&lock);
	pthread_mutex_unlock(&lock);
	usleep(1000);
	// Term::setRaw();
	while (1){
		rand_color = rand() % 256;
		if (rand_color % 2){
			pthread_mutex_lock(&lock);
			std::cout << "\x1b[0;11H\x1b[38;5;" << rand_color << "mf\x1b[0m";
			ft_usleep(1000);
			std::cout << " me right? 😈\n";
			pthread_mutex_unlock(&lock);
		}
		else{
			pthread_mutex_lock(&lock);
			std::cout << "\x1b[0;11H\x1b[38;5;" << rand_color << "m🖕\x1b[0m";
			ft_usleep(1000);		
			std::cout << " me right? 😈\n";
			pthread_mutex_unlock(&lock);
		}
		ft_usleep(1000);
		if (stop == 1)
			break ;
	}
	// Term::restoreTerm();
	return NULL;
}

void	*routine1(void *arg){
	int	rand_color;

	(void)arg;
		
	pthread_mutex_lock(&lock);
	pthread_mutex_unlock(&lock);
	usleep(1000);
	// Term::setRaw();
	while (1){
		rand_color = rand() % 256;
		if (rand_color % 2){
			pthread_mutex_lock(&lock);
			std::cout << "\x1b[0;12H\x1b[38;5;" << rand_color << "mu\x1b[0m";
			ft_usleep(1000);
			std::cout << " me right? 😈\n";
			pthread_mutex_unlock(&lock);
		}
		else{
			pthread_mutex_lock(&lock);
			std::cout << "\x1b[0;12H\x1b[38;5;" << rand_color << "m🖕\x1b[0m";
			ft_usleep(1000);
			std::cout << " me right? 😈\n";
			pthread_mutex_unlock(&lock);
		}
		ft_usleep(1000);
		if (stop == 1)
			break ;
	}
	// Term::restoreTerm();
	return NULL;
}

void	*routine2(void *arg){
	int	rand_color;
	(void)arg;

	pthread_mutex_lock(&lock);
	pthread_mutex_unlock(&lock);
	usleep(1000);
	// Term::setRaw();
	while (1){
		rand_color = rand() % 256;
		if (rand_color % 2){
			pthread_mutex_lock(&lock);
			std::cout << "\x1b[0;13H\x1b[38;5;" << rand_color << "mc\x1b[0m";
			ft_usleep(1000);
			std::cout << " me right? 😈\n";
			pthread_mutex_unlock(&lock);
		}
		else{
			pthread_mutex_lock(&lock);
			std::cout << "\x1b[0;13H\x1b[38;5;" << rand_color << "m🖕\x1b[0m";
			ft_usleep(1000);
			
			std::cout << " me right? 😈\n";
			ft_usleep(1000);
			pthread_mutex_unlock(&lock);
		}
		ft_usleep(1000);
		if (stop == 1)
			break ;
	}
	// Term::restoreTerm();
	return NULL;
}

void	*routine3(void *arg){
	int	rand_color;
	(void)arg;

	pthread_mutex_lock(&lock);
	pthread_mutex_unlock(&lock);
	usleep(1000);
	// Term::setRaw();
	while (1){
		rand_color = rand() % 256;
		if (rand_color % 2){
			pthread_mutex_lock(&lock);
			std::cout << "\x1b[0;14H\x1b[38;5;" << rand_color << "mk\x1b[0m";
			std::cout << " me right? 😈\n";
			ft_usleep(1000);
			pthread_mutex_unlock(&lock);
		}
		else{
			pthread_mutex_lock(&lock);
			std::cout << "\x1b[0;14H\x1b[38;5;" << rand_color << "m🖕\x1b[0m";
			std::cout << " me right? 😈\n";
			ft_usleep(1000);
			pthread_mutex_unlock(&lock);
		}
		ft_usleep(1000);
		if (stop == 1)
			break ;
	}
	// Term::restoreTerm();
	return NULL;
}

void freeds(void){
	pthread_join(t, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_mutex_destroy(&lock);
}

void	gros_bordel(void){
	// Term::setRaw();
	srand(time(NULL));
	// std::cout << "\x1b[?25l";
	usleep(10000);
	pthread_mutex_init(&lock, NULL);
	pthread_mutex_init(&shit, NULL);
	// pthread_mutex_lock(&lock);
	pthread_create(&t, NULL, &routine, NULL);
	pthread_create(&t1, NULL, &routine1, NULL);
	pthread_create(&t2, NULL, &routine2, NULL);
	pthread_create(&t3, NULL, &routine3, NULL);
	// sleep(1);
	usleep(250000);
	// pthread_mutex_unlock(&lock);
	// pthread_join(t, NULL);
	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);
	// pthread_join(t3, NULL);
	// pthread_mutex_destroy(&lock);

	// std::cout << "\x1b[?25h";
	// Term::restoreTerm();
}

std::string get_value(std::string line, std::string sep){
	std::string	value;

	std::size_t found = line.find(sep);
	value = line.substr(found+sep.size(), line.size());
	return (value);
}

std::string	get_date(std::string line, std::string sep){
	std::string	date;

	std::size_t found = line.find(sep);
	date = line.substr(0, found);
	return (date);
}

int	check_date(std::string date){
	if (date.size() != 10){
		pthread_mutex_lock(&lock);
		ERR_DATE(date);
		pthread_mutex_unlock(&lock);
		return (EXIT_FAILURE);
	}
	int count = 0;
	for (size_t i = 0; i < date.size(); i++){
		if (date[i] == '-')
			count++;
	}
	if (count != 2){
		pthread_mutex_lock(&lock);
		ERR_DATE(date);
		pthread_mutex_unlock(&lock);
		return EXIT_FAILURE;
	}
	std::size_t found = date.find("-");

	if (!std::string::npos){
		pthread_mutex_lock(&lock);
		ERR_DATE(date);
		pthread_mutex_unlock(&lock);
		return (EXIT_FAILURE);
	}
	int	year = atoi(date.substr(0, found).c_str());

	date = date.substr(found + 1, date.size());
	found = date.find("-");
	if (!std::string::npos){
		pthread_mutex_lock(&lock);
		ERR_DATE(date);
		pthread_mutex_unlock(&lock);
		return (EXIT_FAILURE);
	}
	int	month = atoi(date.substr(0, found).c_str());

	date = date.substr(found + 1, date.size());
	found = date.find("-");
	if (!std::string::npos){
		pthread_mutex_lock(&lock);
		ERR_DATE(date);
		pthread_mutex_unlock(&lock);
		return (EXIT_FAILURE);
	}
	int	day = atoi(date.substr(0, found).c_str());
	if (year > 2023){
		pthread_mutex_lock(&lock);
		ERR_YEAR(year);
		pthread_mutex_unlock(&lock);
		return EXIT_FAILURE;
	}
	if (year < 2009){
		pthread_mutex_lock(&lock);
		ERR_NODATA(year);
		pthread_mutex_unlock(&lock);
		return EXIT_FAILURE;
	}
	if (year == 2009 && month == 1 && day == 1){
		// ERR_SHHH;
		std::cout << "\x1b[2J\x1b[H";
		std::cout << "You wanna ";
		gros_bordel();
		return EXIT_FAILURE;
	}
	if (month < 1 || month > 12){
		pthread_mutex_lock(&lock);
		ERR_MONTH(month);
		pthread_mutex_unlock(&lock);
		return EXIT_FAILURE;
	}
	if ((day < 1 || day > 31)){
		pthread_mutex_lock(&lock);
		ERR_DAY(day, month);
		pthread_mutex_unlock(&lock);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int	check_value(std::string value){
	float check_val = std::strtof(value.c_str(), NULL);
	if (check_val < 0){
		pthread_mutex_lock(&lock);
		ERR_NEGATIVE;
		pthread_mutex_unlock(&lock);
		return EXIT_FAILURE;
	}
	if (check_val > 1000){
		pthread_mutex_lock(&lock);
		ERR_TOOLARGE;
		pthread_mutex_unlock(&lock);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int	get_year(std::string date){
	std::size_t found = date.find("-");
	return (atoi(date.substr(0, found).c_str()));
}

int	get_month(std::string date){
	std::size_t found = date.find("-");
	date = date.substr(found + 1, date.size());
	found = date.find("-");
	return (atoi(date.substr(0, found).c_str()));
}

int	get_day(std::string date){
	std::size_t found = date.find("-");
	date = date.substr(found + 1, date.size());
	found = date.find("-");
	date = date.substr(found + 1, date.size());
	found = date.find("-");
	return (atoi(date.substr(0, found).c_str()));
}

void	create_data_map(t_stock *m, std::ifstream *data_file){
	std::string line;

	while (std::getline(*data_file, line)){
		m->data_map.insert(std::make_pair(get_date(line, ","), std::strtof(get_value(line, ",").c_str(), NULL)));
	}
}

float	find_date(std::string line, t_stock *m){
	int input_year = get_year(line);
	int	input_month = get_month(line);
	int	input_day = get_day(line);
	std::map<std::string, float>::reverse_iterator it = m->data_map.rbegin();

	for (; it != m->data_map.rend(); ++it){
		std::string data_date = it->first;
		int data_year = get_year(data_date);
		int data_month = get_month(data_date);
		int data_day = get_day(data_date);
		if (data_year == input_year && data_month == input_month && data_day <= input_day){
			break ;
		}
		if (data_year == input_year && data_month < input_month){
			break ;
		}
	}
	return (it->second);
}

float	convert(t_stock *m, float input_val, std::string input_date){
	float	data_val = find_date(input_date, m);

	return (input_val * data_val);
}

void	sig_handler(int signum){
	(void)signum;
	pthread_mutex_lock(&shit);
	stop = 1;
	pthread_mutex_unlock(&shit);
}

int	main(int ac, char **av){
	std::ifstream	data_file;
	std::ifstream	input_file;
	struct stat		sb;

	if (ac != 3){
		ERR_ARGS;
		return (EXIT_FAILURE);
	}
	std::cout << "\x1b[2J\x1b[H";
	std::cout << "\x1b[?25l";
	Term::setRaw();
	signal(SIGINT, &sig_handler);
	signal(SIGQUIT, &sig_handler);
	if (stat(av[1], &sb) == 0 && S_ISDIR(sb.st_mode)){
       std::cout << av[1] << " is a directory." << std::endl;
	   return EXIT_FAILURE;
	}
	data_file.open(av[1], std::ifstream::in);
	if (!data_file.good()){
		ERR_OPENNING(av[1]);
		return (EXIT_FAILURE);
	}
	if (stat(av[2], &sb) == 0 && S_ISDIR(sb.st_mode)){
       std::cout << av[2] << " is a directory." << std::endl;
	   return EXIT_FAILURE;
	}
	input_file.open(av[2], std::ifstream::in);
	if (!input_file.good()){
		ERR_OPENNING(av[2]);
		return (EXIT_FAILURE);
	}
	t_stock	m;
	create_data_map(&m, &data_file);

	std::string	line;
	std::string input_date;
	std::string input_value;
	while (std::getline(input_file, line)){
		input_date = get_date(line, " | ");
		input_value = get_value(line, " | ");
		if (check_date(input_date) == EXIT_FAILURE)
			continue ;
		if (check_value(input_value) == EXIT_FAILURE)
			continue ;
		pthread_mutex_lock(&lock);
		std::cout << input_date << " => " << input_value << " = " << convert(&m, std::strtof(input_value.c_str(), NULL), input_date) << std::endl;
		pthread_mutex_unlock(&lock);
	}
	input_file.close();
	data_file.close();
	freeds();
	Term::restoreTerm();
	std::cout << "\x1b[?25h";
	return 0;
}