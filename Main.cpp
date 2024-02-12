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
    
    for( int i = 0; i < numberOfPlayers; i++ )
    {
        switch (i)
        {
            case 0:
                player[i].setName("Max Mustermann");
                break;
            
            case 1:
                player[i].setName("Maxine Mustermann");
                break;
            
            case 2:
                player[i].setName("Lasmiranda Densivilla");
                break;
            
            case 3:
                player[i].setName("Hans Wurst");
                break;

            default: 
                std::cout << "Etwas ist schief gelaufen!" << std::endl;
                break;
        }
        

    }

    std::cout << player[0].getName() << std::endl;
    
    assignment(player, numberOfPlayers);
          
    std::cout << "Gesundheit : " << player[0].health << std::endl;
    std::cout << "Spielername : " << player[0].getName() << std::endl;
    std::cout << "Gesundheit : " << player[1].health << std::endl;
    std::cout << "Spielername : " << player[1].getName() << std::endl;
    std::cout << "Gesundheit : " << player[2].health << std::endl;
    std::cout << "Spielername : " << player[2].getName() << std::endl;
    return 0;
}



