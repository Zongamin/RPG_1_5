#ifndef TEXTS_H
#define TEXTS_H

#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>

/*Inhaltsverzeichnis:
    - roomTexts   -- case 0 = Eingang | case 1 = Doppeltür | case 2 = Wand | case 3 = Passage |*/

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

            case 1:

                position(58, 8);  std::cout << "Sie stehen vor einer riesigen aber verschlossen Doppeltuer.";
                position(58, 9);  std::cout << "Allein der Anblick suggeriert Ihnen: \"Oeffne mich!\". Ganz";
                position(58, 10); std::cout << "wie ein Ueberraschungs - Ei zu Kindertagen.";
                position(58, 11); std::cout << "Dies wirft natürlich sofort folgende Fragen auf: Spannung?";
                position(58, 12); std::cout << "Spiel? Oder etwa etwas zu Naschen?"; 
                position(58, 13); std::cout << "Fest steht jedenfalls, dass Orks, Oger und Goblins in der";
                position(58, 14); std::cout << "Naehe was zu Naschen bekommen, wenn Sie nicht vorsichtig sind!";
                position(58, 15); std::cout << "Btw: Kommt die Tuer nochwem bekannt vor? Ich glaube die wurde";
                position(58, 16); std::cout << "bereits fuer den Eingang zum Dungeon benutzt.";
                position(58, 17); std::cout << "Na toll...  noch mehr Einsparungen!";
                break;

            case 2:
                
                position(58, 8);  std::cout << "Dies ist eine Wand. Sie scheint endlos zu sein, genau wie der";
                position(58, 9);  std::cout << "Dungeon. Wenn man genau darueber nachdenkt ist es eigentlich";
                position(58, 10); std::cout << "absolut sinnlos ein solches Bild in so´n Game reinzupacken!";
                position(58, 11); std::cout << "Doch der Dev des Games hat sich wohl gedacht, dass das voll";
                position(58, 12); std::cout << "Sinn macht! Denken Sie nur mal an die gesparte Arbeit etwas "; 
                position(58, 13); std::cout << "halbwegs anstaendiges mit ASCII hinzubekommen!";
                position(58, 14); std::cout << "Und die gesparten Kosten, einen ASCII - Artist einzustellen";
                position(58, 15); std::cout << "erst! Bedenkt man die gesparten Kosten und den gesparten";
                position(58, 16); std::cout << "Aufwand, so stellt man fest: BAM! So eine Wand gehört voll in";
                position(58, 17); std::cout << "diesen Dungeon! Fazit --> Hier: Einfach eine Wand.";
                break;

            case 3:
                
                position(58, 8);  std::cout << "Eine duester wirkende Passage springt aus dem Nichts in die";
                position(58, 9);  std::cout << "Wand und beschliesst, dort weiter abzuhaengen. Sicherlich eine";
                position(58, 10); std::cout << "Untersuchung wert. Eventuell haengt da drin irgendwo eine";
                position(58, 11); std::cout << "goldene, alte Unterhose eines grossen Hexenmeisters. Kommt es";
                position(58, 12); std::cout << "hier endlich zum grossen, lange erwartete Fund? Ihre Stimmung"; 
                position(58, 13); std::cout << "steigert sich schier ins unermessliche! Lediglich die Spinnen";
                position(58, 14); std::cout << "in den Winkeln der Passage bleiben völlig unbeeindruckt und";
                position(58, 15); std::cout << "haengen einfach weiter ab. Obwohl es sich hier letztendlich nur";
                position(58, 16); std::cout << "um eine gewoehnliche Passage handelt gibt es hier noch so viel";
                position(58, 17); std::cout << "zu entdecken... Was ist das? Oh! Ein vorstehender Stein!";
                break;

            case 4:
                
                position(58, 8);  std::cout << "Eine duester wirkende Passage springt aus dem Nichts in die";
                position(58, 9);  std::cout << "Wand und beschliesst, dort weiter abzuhaengen. Sicherlich eine";
                position(58, 10); std::cout << "Untersuchung wert. Eventuell haengt da drin irgendwo eine";
                position(58, 11); std::cout << "goldene, alte Unterhose eines grossen Hexenmeisters. Kommt es";
                position(58, 12); std::cout << "hier endlich zum grossen, lange erwartete Fund? Ihre Stimmung"; 
                position(58, 13); std::cout << "steigert sich schier ins unermessliche! Lediglich die Spinnen";
                position(58, 14); std::cout << "in den Winkeln der Passage bleiben völlig unbeeindruckt und";
                position(58, 15); std::cout << "haengen einfach weiter ab. Obwohl es sich hier letztendlich nur";
                position(58, 16); std::cout << "um eine gewoehnliche Passage handelt gibt es hier noch so viel";
                position(58, 17); std::cout << "zu entdecken... Was ist das? Oh! Ein vorstehender Stein!";
                break;
        }
        return;
}
#endif