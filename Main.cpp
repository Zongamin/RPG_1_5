#include <string>
#include <iostream>
#include <Headlines.h>
#include <System.h>
#include <Enemy.h>
#include <Player.h>

int main() 
{
    short roundManager = 0;
    Player player[4];
   
    player[0].setName("Hans Wurst");
    player[0].health = 100;
    player[0].realHealth = 100;
    player[0].realMana= 50;
    player[0].mana = 50;
    
    std::cout << "Gesundheit : " << player[0].health << std::endl;
    std::cout << "Spielername : " << player[0].getName() << std::endl;
    return 0;
}