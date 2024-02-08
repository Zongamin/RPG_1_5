#include <iostream>
#include <conio.h>
#include <ctime>

int repeater;

int random(int min, int max)
{
    bool running = true;
    int random;

    while(running)
    {
    srand(static_cast<unsigned int>(time(nullptr)));
    random = rand() % (max - min + 1) + min;
    if (random == repeater)
    {
        continue;
    }
    running = false;
    break;
    }
    return random;
}

void error()
{
    std::cout << "Falsche Eingabe!" << std::endl;
    return;
}

void getKey() 
{
    char key;
    std::cout << "\n\n<<<< Press any key >>>>" << std::endl;
    key = _getch();
    return;
}

void clearScreen()
{
    system("cls");
    return;
}

void line()
{
    std::cout << "\n---------------------------------------------------------------------------------------------------------------\n\n";
    return;
}

bool boolean()
{
    char key;
    bool running = true;
    bool choice;

    while(running)
    {
        key = _getch();

        switch(key)
        {
            case 'j':
                choice = true;
                running = false;
                break;

            case 'n':
                choice = false;
                running = false;
                break;

            default:
                error();
                continue;
        }
    }
    return choice;
}

