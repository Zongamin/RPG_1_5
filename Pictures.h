#ifndef PICTURES_H
#define PICTURES_H

#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>

/* Inhaltsverzeichnis
        - wall     
        - door
        - doubleDoor
        - crate
        - stairWayUp
        - stairWayDown
        - imp
        - goblin
        - oger
        - killerRabbit   
*/ 
void wall() 
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\033[0m\n";    
    return;
}

void door()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|                 |_____|_____|_____|\n";
    std::cout << "|__|_____|_____|__|    _________    |__|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|   | ||   || |   |_____|_____|_____|\n";
    std::cout << "|__|_____|_____|__|   | ||   || |   |__|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|   | ||   || |   |_____|_____|_____|\n";
    std::cout << "|__|_____|_____|__|   |_||___||_|   |__|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|                 |_____|_____|_____|\n";
    std::cout << "|__|_____|_____|__|  [o~            |__|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|   ||            |_____|_____|_____|\n";
    std::cout << "|__|_____|_____|__|  [o~            |__|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|                 |_____|_____|_____|\n";
    std::cout << "|__|_____|_____|__|                 |__|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|                 |_____|_____|_____|\n";
    std::cout << "|__|_____|_____|__|                 |__|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|                 |_____|_____|_____|\n";
    std::cout << "|__|_____|_____|__|_________________|__|_____|_____|__|\033[0m\n";
    return;
}

void doubleDoor()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____/ ___________________________ \\_____|_____|\n";             
    std::cout << "|__|_____|_/ /             |             \\ \\_|_____|__|\n";
    std::cout << "|_____|___/ /              |              \\ \\___|_____|\n";
    std::cout << "|__|_____| |               |               | |_____|__|\n";
    std::cout << "|_____|__| |               |               | |__|_____|\n";
    std::cout << "|__|_____| |               |               | |_____|__|\n"; 
    std::cout << "|_____|__| |               |               | |__|_____|\n";
    std::cout << "|__|_____| |               |               | |_____|__|\n";
    std::cout << "|_____|__| |          ~(O  |  O)~          | |__|_____|\n";
    std::cout << "|__|_____| |            0  |  0            | |_____|__|\n";
    std::cout << "|_____|__| |               |               | |__|_____|\n";
    std::cout << "|__|_____| |               |               | |_____|__|\n";
    std::cout << "|_____|__| |               |               | |__|_____|\n";
    std::cout << "|__|_____| |               |               | |_____|__|\n";
    std::cout << "|_____|__| |               |               | |__|_____|\n";
    std::cout << "|__|_____|_|_______________|_______________|_|_____|__|\033[0m\n";
    return;
}

void crate()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____/                            /|_____|__|\n";
    std::cout << "|_____|_____|_/             __             / /__|_____|\n";
    std::cout << "|__|_____|___/_____________/ /____________/ /|_____|__|\n";
    std::cout << "|_____|_____|_____________| |_____________|/ |__|_____|\n";
    std::cout << "|__|_____|__|   _____     | |     _____   |  |_____|__|\n";
    std::cout << "|_____|_____|  |     |   {[O]}   |     |  |  |__|_____|\n";
    std::cout << "|           |  |     |     0     |     |  |  /        |\n";
    std::cout << "|           |  |_____|           |_____|  | /         |\n";
    std::cout << "|           |_____________________________|/          |\n";
    std::cout << "|                                                     |\n";
    std::cout << "|_____________________________________________________|\033[0m\n";
    return;
}

void stairWayUp()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|__|\\ |\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____| \\|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|__|\\    \\  |\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____| \\    \\ |\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|__|\\    \\  \\    \\|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____| \\    \\  \\    |\n";
    std::cout << "|_____|_____|_____|_____|_____|__|\\    \\  \\    \\  \\   |\n";
    std::cout << "|__|_____|_____|_____|_____|_____| \\    \\  \\    \\  \\__|\n";
    std::cout << "|_____|_____|_____|_____|__|\\    \\  \\    \\  \\    \\ |__|\n";
    std::cout << "|__|_____|_____|_____|_____| \\    \\  \\    \\  \\____\\|__|\n";
    std::cout << "|                          \\  \\    \\  \\    \\ |__|_____|\n";
    std::cout << "|                           \\  \\    \\  \\____\\|_____|__|\n";
    std::cout << "|                            \\  \\    \\ |__|__|__|_____|\n";
    std::cout << "|                             \\  \\____\\|_____|_____|__|\n";
    std::cout << "|                              \\ |__|_____|_____|_____|\n";
    std::cout << "|                               \\|_____|_____|_____|__|\n";
    std::cout << "|                                                     |\n";
    std::cout << "|_____________________________________________________|\033[0m\n";
    return;
}

void stairWayDown()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|                            /|_____|_____|_____|_____|\n";
    std::cout << "|                           / |__|_____|_____|_____|__|\n";
    std::cout << "|                          /  /    /|_____|_____|_____|\n";
    std::cout << "|                         /  /    / |__|_____|_____|__|\n";
    std::cout << "|                        /  /    /  /    /|_____|_____|\n";
    std::cout << "|                       /__/____/__/____/_|__|_____|__|\n";
    std::cout << "|                                                     |\n";
    std::cout << "|_____________________________________________________|\033[0m\n";
    return;
}

void imp()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____|_IMP_|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|\\___/|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|__(O) (O)__|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____| o o |_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|__{-v-v-}__|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|\\___/|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|____) (____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|___/  .   .  \\___|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____| /       \\ |_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|__|| \\    / ||__|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|____(((__| | |__)))____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|) | ( |_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|__[__|__]__|_____|_____|_____|__|\033[0m\n";    
    return;
}

void goblin()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____Goblin!_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|\\/\\/\\/|____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|__[ _  _ ]_|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|____[( o\\/o )]___|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|__[ (..) ]_|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|{v~~v}_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|____(~~)___|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|___ ____)(____ __|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|/          \\_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|__/ /| ---- |\\ \\_|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|____/ / |  --  | \\ \\___|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_| | |      | | ||_____|_____|_____|\n";
    std::cout << "|__|_____|_____|____| | \\______/ | |___|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|((() [  {}  ] ()))_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|__|  ||  |_|_____|_____|_____|__|\033[0m\n";
}

void oger()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_____|OGER!|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_\"^\".|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|___/   \\___|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____/ _=_ \\.~\\__|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_(,(ovo),) ##}___|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|___,-\\(v\"v)/{  #)\\_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|{  '^_^' ('}}   #\\_____|_____|__|\n";
    std::cout << "|_____|_____|_____|___{{).__._.(´}}--/##)_|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|{{)__|__ ( }}((  (_____|_____|__|\n";
    std::cout << "|_____|_____|_____|___{{)_____ (,}} \\  \\_|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|(((__|____))) --`--\"___|_____|__|\033[0m\n";
    return;
}

void killerRabbit()
{
    position(0, 7);
    std::cout << "\033[0m_______________________________________________________\n";
    std::cout << "|_____|_____|_____|_Killer Karnickel_|____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_()_()_____|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|____(o.O)__|_____|_____|_____|__|\n";
    std::cout << "|_____|_____|_____|_____|_(v v)}*___|_____|_____|_____|\n";
    std::cout << "|__|_____|_____|_____|___(\")(\")__|_____|_____|_____|__|\033[0m\n";
    return;
}

#endif