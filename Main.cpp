#include <string>
#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Enemy.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>

short numberOfPlayers = 2;
    short roundManager = 0;
    Player player[4];

int main() 
{
    std::cout << "Wie viele Mitspieler ? "; std::cin >> numberOfPlayers; 
    assignment(numberOfPlayers);
          
    std::cout << "Gesundheit : " << player[0].health << std::endl;
    std::cout << "Spielername : " << player[0].getName() << std::endl;
    return 0;
}



