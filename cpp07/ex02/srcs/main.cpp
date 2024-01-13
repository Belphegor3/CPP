#include <iostream>
#include <Array.class.hpp>
// #include <time.h>
// #include <stdlib.h>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand() % 10;
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int main()
{
    Array<int> j(5);
    Array<std::string> list(2);

    list[0] = "test";
    list[1] = "plop";
	j[0] = 0;
	j[1] = 2;
	j[2] = 4;
	j[3] = 6;
	j[4] = 8;

    std::cout << "String array content : " << std::endl;
    for (int i = 0; i < list.size(); i++)
        std::cout << "list[" << i << "] = " << list[i] << std::endl;

    std::cout << std::endl;
    std::cout << "Copy list :" << std::endl;
    Array<std::string> listcopy(list);
    std::cout << "Change list[0] to \"murp\"" << std::endl;
    list[0] = "murp";
    std::cout << "Listcopy[0] = " << listcopy[0] << std::endl;
    std::cout << "List[0] = " << list[0] << std::endl;

    std::cout << std::endl;
    std::cout << "Int array content : " << std::endl;
    for (int i = 0; i < j.size(); i++)
        std::cout << "j" << i << " = " << j[i] << std::endl;

    std::cout << std::endl;
    Array<int> intassign = j;
    std::cout << "Int array content : " << std::endl;
    for (int i = 0; i < j.size(); i++)
        std::cout << "intassign[" << i << "] = " << intassign[i] << std::endl;

    std::cout << std::endl;
    std::cout << "Modify value (previous + 1): " << std::endl;
    for (int i = 0; i < j.size(); i++)
        intassign[i] = intassign[i] + 1;
    for (int i = 0; i < j.size(); i++)
        std::cout << "intassign[" << i << "] = " << intassign[i] << std::endl;

    std::cout << std::endl;
    try{
    std::cout << "See out of the bound : " << std::endl;
	j[6] = 6;
    }
    catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}