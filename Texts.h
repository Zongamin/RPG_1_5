#ifndef TEXTS_H
#define TEXTS_H

#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>

void roomTexts(int room)
{
    switch (room)
        {
            case 0:
                position(58, 8);  std::cout << "Sie stehen vor der gewaltigen Pforte zum sagenumwobenen";
                position(58, 9);  std::cout << "endlosen Dungeon. Die Tuer scheint so alt, dass selbst der";
                position(58, 10); std::cout << "Schimmel darauf in Rente gehen koennte. Doch da ist auch";
                position(58, 11); std::cout << "dieser Hauch von Abenteuer, der in der Luft liegt (oder";
                position(58, 12); std::cout << "vielleicht ist es einfach nur der Gestank von alten"; 
                position(58, 13); std::cout << "Goblinfuerzen, der seit Aeonen in den Tiefen dieses Dungeons";
                position(58, 14); std::cout << "rumhaengt). Sie wissen geanu: Der Weg vor Ihnen ist gespickt";
                position(58, 15); std::cout << "mit Reichtuemern, Gefahren und vielleicht sogar einer alten,";
                position(58, 16); std::cout << "vergessenen Socke eines Ogers. Also,schnappen Sie sich Ihren";
                position(58, 17); std::cout << "Mut und treten Sie ein in den endlosen Dungeon!";
                break;
        }
        return;
}
#endif