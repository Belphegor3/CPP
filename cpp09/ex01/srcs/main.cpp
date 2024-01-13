#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>

void	check_args(char *av){
	int i = 0;
	int count_nb = 0;
	int count_ope = 0;

	while (av[i]){
		if (av[i] == ' '){
			i++;
			continue ;
		}
		if (!((av[i] >= '0' && av[i] <= '9') || av[i] == '+' || av[i] == '-' || av[i] == 42 || av[i] == '/' || av[i] == ' '))
			exit((std::cout << "Error" << std::endl, 1));
		if (av[i] >= '0' && av[i] <= '9')
			count_nb++;
		if (av[i] == '+' || av[i] == '-' || av[i] == 42 || av[i] == '/'){
			count_ope++;
		}
		i++;
	}
	if (count_nb != count_ope + 1)
		exit((std::cout << "Error" << std::endl, 3));
}

int evaluateRPN(std::string rpn) {
    std::stack<int> operands;

    for (std::string::iterator it = rpn.begin(); it != rpn.end(); it++) {
		char c = *it;
        if (isdigit(c)) {
            operands.push(c - '0');
        }
		else if (c == '+' || c == '-' || c == 42 || c == '/') {
			if (operands.empty()){
				std::cout << "Error" << std::endl;
				break ;
			}
            int op1 = operands.top();
            operands.pop();
			if (operands.empty()){
				std::cout << "Error" << std::endl;
				break ;
			}
            int op2 = operands.top();
            operands.pop();

            switch (c) {
                case '+':
                    operands.push(op2 + op1);
                    break;
                case '-':
                    operands.push(op2 - op1);
                    break;
                case '*':
                    operands.push(op2 * op1);
                    break;
                case '/':
					if (op1 == 0){
						std::cout << "non non non trou du cul tu m'auras pas \x1b[5m😉\x1b[0m\n";
						exit(127);
						break ;
					}
						operands.push(op2 / op1);
                    break;
            }
        }
    }
	if (operands.size() == 0)
		return -1;
    return operands.top();
}

int main(int ac, char **av) {
	std::cout << "\x1b[2J\x1b[H";
	if (ac != 2)
		return (std::cout << "./RPN takes numerical arguments with operations -, +, *, /" << std::endl, 0);
	check_args(av[1]);
    std::string rpn = av[1];
    int result = evaluateRPN(rpn);
	if (result == -1)
		return 1;
    std::cout << "The result is: " << result << std::endl;
    return 0;
}



























/*int	main(int ac, char **av){
	if (ac == 1)
		return (std::cout << "./RPN takes numerical arguments with operations -, +, *, /", 0);
	// int i = check_args(av);
	std::vector<int> numbers;
	std::vector<char> operations;
	int i = 1;
	while (av[i])
	{
		while ((av[i][0] >= '0' && av[i][0] <= '9')){
			numbers.push_back(atoi(av[i++]));
		}



		if (av[i][0] >= '0' && av[i][0] <= '9')
			numbers.push_back(atoi(av[i]));
		else
		{
			if (numbers.empty() == true)
				exit((std::cout << "Error" << std::endl, 2));
			else
				operations.push_back(av[i][0]);
		}
	}
}*/