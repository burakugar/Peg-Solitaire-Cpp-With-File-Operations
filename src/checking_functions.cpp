#include <iostream>
int check_the_valid_input_start(void) // Function that checks whether the menu choice of the
// user is valid or not until user enters a valid input (1-2)
{
    int choice;
flag1:
    std::cin >> choice;
    if (std::cin.fail())
    {
        std::cout << "Please enter an integer: " << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        goto flag1;
    }
    else
    {
        if (choice > 2 || choice < 1)
        {
            std::cout << "Please enter a valid integer: " << std::endl;
            goto flag1;
        }
        else
            return choice;
    }
}
int check_the_valid_input_grid(void) // Function that checks whether the menu choice of the
// user is valid or not until user enters a valid grid input
{
    int choice;
    std::cout << std::endl
              << "Please choose one of the grids: " << std::endl;
flag2:
    std::cin >> choice;
    if (std::cin.fail())
    {
        std::cout << std::endl
                  << "Please enter an integer: " << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        goto flag2;
    }
    else
    {
        if (choice > 9 || choice < 1)
        {
            std::cout << std::endl
                      << "Please enter a valid integer: " << std::endl;
            goto flag2;
        }
        else
            return choice;
    }
}