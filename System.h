#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\player.h>

/*Inhaltsverzeichnis:
60    - assignment     -- Zuweisung der Werte für neue Spieler
100   - charCalc       -- Charkter Rechner zum errechnen neuer Werte bei Skillpunktverteilung
111   - random         -- Zufallsgenerierte Zahlen mit Minmal und Maximal übergabe
133   - getKey         -- press any key - Funktion
143   - error          -- Fehlermeldung : Falsche Eingabe
163   - clearScreen    -- Windows-CMD Screen leeren
171   - position       -- Setzen der Cursor Position
182   - miniLine       -- kleinen Trennstrich einfügen
188   - line           -- Trennstrich einfügen
196   - question       -- Ja/Nein - Abfrage des Spielers
228   - choice         -- Zahleneingabe des Spielers (0 - 9) ohne "Enter" - Eingabe
245   - condition      -- Skillpunkt ermittlung für Charactermenü 
260   - lifeDisplay    -- Lebens- und Manaanzeige der Spieler
299   - colorSwitch    -- Schalterfarben (Schrift mit Hintergrundfärbung) verändern
320   - textColor      -- Schriftfarben verändern
341   - backgroundColor-- Verändern der Hintergrund Farbe
358   - levelUp        -- Anheben von Skillpunkten, Spielerlevel & geforderten Level Exp
403   - expUp          -- Anheben der Spieler Exp und Level Umbruch
      - capacityColor  -- Ermittelt den Farbwert der Traglast nach Füllstand des Inventars des Spielers in Prozent
      - weaponDispose   -- Menue zur Entsorgung von Ruestungen
      - armorDispose  -- Menue zur Entsorgung von Waffen
      - disposal       -- Funktion zur Entsorgung von Gegenständen für den Spieler
444   - capacityCheck  -- Überprüfung und hinzufügen der Traglast des Spielers mit evtl. Übergabe an Entsorgungsfunktion für Gegenstände
456   - arraySort      -- Sortierung von Waffen- und Rüstungsarrays der Spieler
477   - loot           -- Funktion für die Suche-Option des Spielers
704   - loadGame       -- Funktion zum Laden von Spielständen
713   - one            -- Headline 1
725   - two            -- Headline 2
739   - three          -- Headline 3
753   - four           -- Headline 4
767   - getNumber      -- Funktion zur Ermittlung und Ausgabe des Spielernummer Schriftzuges
789   - dangerZone     -- Funktion zur Ermittlung der Gefahrenstufe des derzeitigen Raums
809   - dangerDisplay  -- gibt die Gefahrenstufe des Raums auf den Bildschirm aus
839   - death          -- Ausgabe des Todes des Spielers
860   - trapCall       -- Ermittelt die Anzahl von Fallen in einem Raum auf Basis der Gefahrstufe des Raumes
877   - trapCheck      -- Ermittelt die verbleibende Anzahl der Fallen des Spielers und löst ggf. Fallen aus
916   - trapSearch     -- Ermittelt, ob die Suche des Spielers nach einer Falle erfolgreich ist, oder sogar eine Falle auslöst
976   - takeBreak      -- Ermittelt Werte beim Rasten des Spielers 
1012  - checkRegen     -- Ermittelt einen boolschen Wert, ob Heilung, Mana oder beides benoetigt wird
1046  - checkPotion    -- Ermittelt einen boolschen Wert, ob Heiltraenke, Manatraenke oder Regenerationstraenke vorhanden sind 
1080  - potionDrink    -- Funktion zur Heilung, Manaregeneration oder beidem durch Tränke
    */

// Globale Variablen zum Eingrenzen von wiederholten Zufallszahlen

short repeater{};
short dangerRepeater{};
short danger{};

//Wertzuweisung neuer Spieler Objekte

void assignment(Player player[], short numberOfPlayers)
{
    for (int index = 0; index < numberOfPlayers; index++)
        {
            player[index].currentRoom = 0;
            player[index].strength = 5;
            player[index].intelligence = 5;
            player[index].endurance = 5;
            player[index].dexterity = 5;
            player[index].luck = 5;
            player[index].level = 1;
            player[index].skillPoints = 5;
            player[index].exp = 1000;   
            player[index].realExp = 0;
            player[index].health = (player[index].strength * 15) + (player[index].endurance * 5);
            player[index].mana = (player[index].intelligence * 3) + (player[index].endurance * 2);
            player[index].realHealth = player[index].health;
            player[index].realMana = player[index].mana;
            player[index].luck = (player[index].endurance * 0.01) + (player[index].dexterity * 0.1);
            player[index].capacity = (player[index].strength * 15) + (player[index].endurance * 5);
            player[index].weaponDmg = 0;
            player[index].armorDmgReduce = 0;
            player[index].regenerationOn = 0;
            player[index].fireAura = 0;
            player[index].key = 0;
            player[index].scrapMetal = 0;
            player[index].aluminum = 0;
            player[index].copper = 0;
            player[index].healthPotion = 1;
            player[index].manaPotion = 1;
            player[index].regenPotion = 0;
            player[index].rooms = 0;
            player[index].crafted = 0;
            player[index].monsters = 0;
            player[index].bosses = 0;
            player[index].deaths = 0;
            player[index].permaDeath = false;
            for (int dex = 0; dex < 500; dex++) {player[index].weapons[dex]= 0; break;}
            for (int dex = 0; dex < 500; dex++) {player[index].armor[dex] = 0; break;} 
        }
    return;
}

// Errechnen neuer Werte bei Skillpunktverteilung

void charCalc(Player player[], short index)
{
    player[index].health = (player[index].strength * 15) + (player[index].endurance * 5);
    player[index].mana = (player[index].intelligence * 3) + (player[index].endurance * 2);
    player[index].luck = (player[index].endurance * 0.01) + (player[index].dexterity * 0.1);
    player[index].capacity = (player[index].strength * 15) + (player[index].endurance * 5);
    return;
}

// Generierung von Zufallszahlen mit min/max Wertübergabe

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
        break;
    }
    running = false;
    break;
    }
    
    return random;
}

// Press any key 

void getKey() 
{
    char key;
    std::cout << "\n\n                                            \033[30;47m<<<< Press any key >>>>\033[0m" << std::endl;
    key = _getch();
    return;
}

// Falsche Eingaben Fehlermeldungen

void error(short error)
{
    switch(error)
    {
        case 0:
            std::cout << "\n\n\033[31mFalsche Eingabe!\033[0m" << std::endl;
            break;
        case 1:
            std::cout << "\n\n\033[31mZu wenig Skillpunkte!\033[0m" << std::endl;
            break;
        case 2:
            std::cout << "\n\n\033[31mEs wurden noch keine Skillpunkte auf dieses Attribut verteilt!\033[0m" << std::endl;
            break;
    }
    getKey();
    return;
}

// Screen säubern

void clearScreen()
{
    system("cls");
    return;
}

// Position des Cursors setzen

void position(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}

// Trennlinie zeichnen

void miniLine(int posX, int posY)
{
    position(posX, posY); std::cout << "-------------------------------------------------------------" << std:: endl;
    return;
}

void line()
{
    std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
    return;
}

// Ja/Nein - Abfrage

bool question()
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
                error(0);
                break;
        }
    }
    return choice;
}

// Auswahl für Menüs

short choice()
{
    char key;
    key = _getch(); 
    if (key >= '0' && key <= '9') 
    {
        return key - '0';
    } 
    else 
    {
        return -1;
    }

}

// Skillpunkte check für Character Menü

bool condition(Player player[], short roundManager, double strength, double intelligence, double dexterity, double endurance)
{
    bool condition = false;

    if (player[roundManager].skillPoints > 0 || strength + intelligence + dexterity + endurance > 0)
    {
        condition = true;
        return condition;
    }

    return condition;
}

// Lebens-, Mana- und Exp - Anzeige des Spielers

void lifeDisplay(Player player[] , short roundManager,int posX, int posY)
{
    position(posX, posY);     std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    position(posX, posY + 1); std::cout << "| Leben |\033[41m                                                                                                    \033[0m|\n";
    position(posX, posY + 2); std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    position(posX, posY + 3); std::cout << "| Mana  |\033[41m                                                                                                    \033[0m|\n";
    position(posX, posY + 4); std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    position(posX, posY + 5); std::cout << "| Exp   |\033[41m                                                                                                    \033[0m|\n";
    position(posX, posY + 6); std::cout << "--------------------------------------------------------------------------------------------------------------\n";

    double range{};
    position((posX + 9), (posY + 1));
    round(range = 100 * (player[roundManager].realHealth / player[roundManager].health));
    for (int i = 0; i < range; i++)
    {
        std::cout << "\033[42m ";
    }
    
    range = 0;
    position((posX + 9), (posY + 3));
    round(range = 100 * (player[roundManager].realMana / player[roundManager].mana));
    for (int i = 0; i < range; i++)
    {
        std::cout << "\033[104m ";
    }
    
    range = 0;
    position((posX + 9), (posY + 5));
    round(range = 100 *(player[roundManager].realExp / player[roundManager].exp));
    for (int i = 0; i < range; i++)
    {
        std::cout << "\033[103m ";
    }
    std::cout << "\n\033[0m " << std::endl;
    return;
}

// Veränderung der Schalterfarben

void colorSwitch(int color)
{
    switch (color) 
    {   
        case 1:
            std::cout << "\033[30;102m";
            break;

        case 2:
            std::cout << "\033[30;103m";
            break;

        case 3: 
            std::cout << "\033[41m";
            break;
    }
    return;
}

// Veränderung der Textfarben

void textColor (int color)
{
    switch (color)
    {
        case 1:
            std::cout << "\033[92m";
            break;
        
        case 2:
            std::cout << "\033[93m";
            break;
            
        case 3:
            std::cout << "\033[31m";
            break;
    }
    return;
}

// Verändern der Hintergrundfarbe (case 0 = Standard)

void backgroundColor (short color)
{
    switch (color)
    {
        case 0:
            system("color");
            return;
    
        case 1:
            system("color A0");
            return;
    }

}

// Level up

void levelUp (Player player[], short roundManager)
{
    clearScreen();
    textLevelUp();
    line();
    player[roundManager].level++; 
    player[roundManager].skillPoints += 5;
    player[roundManager].exp = round(player[roundManager].exp * 1.25);
    std::cout << "\033[30;102m *** " << player[roundManager].getName() << " ist jetzt Level " << player[roundManager].level << " und die Skillpunkte sind um 5 gestiegen! *** \033[0m";
    std::cout << "\n\n";
    getKey();
    return;
}


// Experience up

void expUp(Player player[], short roundManager)
{
    int range = 0;
    double remainingExp = 0;
    bool running = true;
        
    while(running)
    {
    clearScreen();
    textExpUp();
    line();

    if (player[roundManager].realExp > player[roundManager].exp)
    {
        std::cout << "Expierience : " << player[roundManager].realExp - player[roundManager].realExp << "/" << round(player[roundManager].exp * 1.2) << "\n\n";
    }
    else
    {
        std::cout << "Expierience : "<< player[roundManager].realExp << "/" << player[roundManager].exp << "\n\n";
    }
        std::cout << "------------------------------------------------------------------------------------------------------------\n";
        std::cout << "| Exp |\033[41m                                                                                                    \033[0m|\n";
        std::cout << "------------------------------------------------------------------------------------------------------------\n";

        position(7, 15);
    
        if (player[roundManager].realExp > player[roundManager].exp)
        {
        
        remainingExp = player[roundManager].realExp - player[roundManager].exp;
        range = 100;
        
        for (int i = 0; i < range; i++)
        {
            std::cout << "\033[103m ";
            Sleep(10);
            std::cout << "\033[0m";
        }
            std::cout << "\n\n" << std::endl;
            getKey();
            levelUp(player , roundManager);
            player[roundManager].realExp = 0;
            player[roundManager].realExp += remainingExp;
            break;
        }
        else
        {
            range = 100 * (player[roundManager].realExp / player[roundManager].exp);
            
            for (int i = 0; i < range; i++)
            {
                std::cout << "\033[103m ";
                Sleep(10);
                std::cout << "\033[0m";
            }

            running = false;
            break;
        }
    }
    getKey();
    return;
}

// Sortierung und Nachrutschen von Arrays

void arraySort(Player player[], short roundManager, std::string type)
{
    if (type == "weapon")
    {
        int arraySize = sizeof(player[roundManager].weapons) / sizeof(player[roundManager].weapons[0]);
        std::sort(player[roundManager].weapons, player[roundManager].weapons + arraySize, std::greater<int>());
        return;
    }
    
    if (type == "armor")
    {
        int arraySize = sizeof(player[roundManager].armor) / sizeof(player[roundManager].armor[0]);
        std::sort(player[roundManager].armor, player[roundManager].armor + arraySize, std::greater<int>());
        return;
    }
    
    std::cout << "Error!" << std::endl;
    getKey();
    return;
}

void capacityColor(Player player[], short roundManager)
{
    double range{};
    round(range = 100 * (player[roundManager].realCapacity / player[roundManager].capacity));
    if (range <= 25)  {std::cout << "\033[92m"; return;}
    if (range <= 50)  {std::cout << "\033[32m"; return;}
    if (range <= 75)  {std::cout << "\033[43m"; return;}
    std::cout << "\033[31m"; 
    return;
}

// Anzahl zu entsorgender Waffen bestimmen

void weaponDispose(Player player[], short roundManager)
{
    std::cout << "\n[ 0 ] -----> Zurueck" << std::endl;

    for (int index = 0; player[roundManager].weapons[index] = !0; index++) 
    {
        std::cout << "\n[ " << index + 1 << " ] -----> " << player[roundManager].weapons[index] << " DMG" << std::endl;
    }
    std::cout << "\nWelche Waffe moechten Sie entsorgen?";
}

// Anzahl zu entsorgender Gegenstände bestimmen

double disposeAmount (Player player[], short roundManager, std::string sortOf, double maxAmount)
{
    double amount = 0;
    bool answer = false;

    std::cout << "\n\nSie moechten " << sortOf << " entsorgen. Wie viele Einheiten sollen entsorgt werden? (0 - " << maxAmount << ") "; std::cin >> amount;
                    if (amount > maxAmount || amount < 0){std::cout << "\n\033[31mDas ist nicht moeglich!"; getKey(); return -1;}
                    if (amount == 0) {return -1;}
                    std::cout << "\nSind Sie sicher? (J/N)" << std::endl;
                    answer = question();
                    if (answer == false) {return -1;} 
                    std::cout << "\nSie haben " << amount << " Einheiten " << sortOf << " entsorgt!" << std::endl;
                    return amount;
}

// Gegenstände entsorgen

bool disposal(Player player[], short roundManager, double weight)
{
    short input = 0;
    bool running = true;
    bool answer = false;
    double numberOfWeapons = 0;
    double numberOfArmor = 0;
    double amount = 0;
    double needWeight = 0;

    while(running)
    {
        if (weight > 0)
        {
            needWeight = (player[roundManager].realCapacity + weight) - player[roundManager].capacity;
            if (needWeight < 0) {needWeight = 0;}
        }

        for(int index; player[roundManager].weapons[index] > 0; index++) {numberOfWeapons = index; break;}
        for(int index; player[roundManager].armor[index] > 0; index++) {numberOfArmor = index; break;}
        if (player[roundManager].weaponDmg > 0){numberOfWeapons += 1;}
        if (player[roundManager].armorDmgReduce > 0){numberOfWeapons += 1;}

        clearScreen();
        textDisposal();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName();
        position(40, 10); std::cout << "\033[93mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 10); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        std::cout << "                                   Gewicht pro Einheit           Anzahl              Gesamtgewicht" << std::endl;
        std::cout << "[ 1 ] -----> Altmetall                   0,3  kg"; position(65, 15); std::cout << player[roundManager].scrapMetal; position(85, 15); std::cout << player[roundManager].scrapMetal * 0.3 << std::endl; 
        std::cout << "[ 2 ] -----> Aluminum                    0,1  kg"; position(65, 16); std::cout << player[roundManager].aluminum; position(85, 16); std::cout << player[roundManager].aluminum * 0.1 << std::endl;
        std::cout << "[ 3 ] -----> Kupfer                      0,2  kg"; position(65, 17); std::cout << player[roundManager].copper; position(85, 17); std::cout << player[roundManager].copper * 0.2 << std::endl;
        std::cout << "[ 4 ] -----> Heiltraenke                 0,25 kg"; position(65, 18); std::cout << player[roundManager].healthPotion; position(85, 18); std::cout << player[roundManager].healthPotion * 0.25 << std::endl;
        std::cout << "[ 5 ] -----> Manatraenke                 0,25 kg"; position(65, 19); std::cout << player[roundManager].manaPotion; position(85, 19); std::cout << player[roundManager].manaPotion * 0.25 << std::endl;
        std::cout << "[ 6 ] -----> Regenerationstraenke        0,25 kg"; position(65, 20); std::cout << player[roundManager].regenPotion; position(85, 20); std::cout << player[roundManager].regenPotion * 0.25 << std::endl;
        std::cout << "[ 7 ] -----> Waffen                      2,5  kg"; position(65, 21); std::cout << numberOfWeapons; position(85, 21); std::cout << numberOfWeapons * 2.5 << std::endl;
        std::cout << "[ 8 ] -----> Ruestungen                  2,25 kg"; position(65, 22); std::cout << numberOfArmor; position(85, 22); std::cout << numberOfArmor * 2.25 << std::endl;
        std::cout << "[ 0 ] -----> Zurueck";
        line();
        if (weight > 0) {std::cout << " Sie muessen noch " << needWeight << " kg ablegen." << std::endl; line();}
        std::cout << "\n\033[31mWas moechten Sie entsorgen?" << std::endl;
        input = choice();
        switch (input)
            {
                case 0:
                    running = false;
                    break;

                case 1:
                    amount = disposeAmount(player, roundManager, "Altmetall", player[roundManager].scrapMetal);
                    if (amount == -1) {break;}
                    player[roundManager].scrapMetal -= amount;
                    player[roundManager].realCapacity -= (amount * 0.3);
                    getKey();
                    break;

                case 2:
                    amount = disposeAmount(player, roundManager, "Aluminium", player[roundManager].aluminum);
                    if (amount == -1) {break;}
                    player[roundManager].aluminum -= amount;
                    player[roundManager].realCapacity -= (amount * 0.1);
                    getKey();
                    break;
                
                case 3:
                    amount = disposeAmount(player, roundManager, "Kupfer", player[roundManager].copper);
                    if (amount == -1) {break;}
                    player[roundManager].copper -= amount;
                    player[roundManager].realCapacity -= (amount * 0.2);
                    getKey();
                    break;
                    
                case 4:
                    amount = disposeAmount(player, roundManager, "Heiltraenke", player[roundManager].healthPotion);
                    if (amount == -1) {break;}
                    player[roundManager].healthPotion -= amount;
                    player[roundManager].realCapacity -= (amount * 0.25);
                    getKey();
                    break;
                
                case 5:
                    amount = disposeAmount(player, roundManager, "Manatraenke", player[roundManager].manaPotion);
                    if (amount == -1) {break;}
                    player[roundManager].manaPotion -= amount;
                    player[roundManager].realCapacity -= (amount * 0.25);
                    getKey();
                    break;
                
                case 6:
                    amount = disposeAmount(player, roundManager, "Regenerationstaenke", player[roundManager].regenPotion);
                    if (amount == -1) {break;}
                    player[roundManager].regenPotion -= amount;
                    player[roundManager].realCapacity -= (amount * 0.25);
                    getKey();
                    break;

                case 7:
                    break;

                case 8:
                    break;
                
                default:
                    break;
            }
    }
    if (needWeight == 0) {return true;}
    return false;
}

// Überprüfung der Traglast

bool capacityCheck(Player player[], short roundManager, double weight, short numberOfObjects, std::string typeOf)
{
    bool answer = false;
    bool enoughWeight = false;
    double finalWeight = 0;


    if ((numberOfObjects * weight) + player[roundManager].realCapacity > player[roundManager].capacity)
    {
        finalWeight = ((numberOfObjects * weight) + player[roundManager].realCapacity) - player[roundManager].capacity;
        std::cout << "\n\n\033[31mSie sind ueberladen! Was Sie mitnehmen moechten hat ein Gewicht von " << (numberOfObjects * weight) << " kg.";
        std::cout << "\nEs fehlen Ihnen also noch " << finalWeight << " kg, möchten sie etwas wegwerfen? (J/N)";
        answer = question();
        switch (answer)
        {
            case true:
                enoughWeight = disposal(player, roundManager, weight);
                if (enoughWeight = false) {return false;}
                break;

            case false:
                return false;
        }
    }
    return true;
}

// looten nach erfolgreicher Suche

void loot(Player player[], short roundManager)
{
    int chance = 0;
    bool dispose = false;
    double tempExp = 0;
    double findItem = 0;
    double experience = 0;
        
    clearScreen();
    textSearch();
    line();
    std::cout << "Sie begeben sich auf die Suche und finden:" << std::endl;
    line();
    
    for (int index = 0; index < 10; index++)
    {
        switch (index)
        {
            case 0: // Gold
                experience = 0;
                chance = 0; chance = round(random(1,100));
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 5), (player[roundManager].level * 25)) + player[roundManager].luck * 1);
                    experience = round((findItem * 0.125) * (player[roundManager].level * 1.25));
                    std::cout << "---------------------------------------------------" << std::endl;
                    std::cout << "\033[93mGold\033[0m --------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].gold += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 1: // Schlüssel
                if (round(player[roundManager].key <= 1 + player[roundManager].luck))
                {
                    experience = 0;
                    chance = 0; chance = round(random(1,100));
                    if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                    {
                        findItem = 1;
                        experience = round((findItem * 20) * (player[roundManager].level * 1.25));
                        std::cout << "\033[36mSchluessel\033[0m --------------> " << findItem << " / " << experience << " Exp." << std::endl;
                        std::cout << "---------------------------------------------------" << std::endl;
                        player[roundManager].key += findItem;
                        tempExp += experience;
                        break;
                    }
                    break;
                }
                break;

            case 2: // Scrapmetal
                experience = 0;
                chance = round(random(1,100));
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25)) + player[roundManager].luck * 1);
                    if (findItem < 1) {findItem = 1;} 
                    experience = round((findItem * 10) * (player[roundManager].level * 1.25));
                    std::cout << "\033[90mAltmetall\033[0m ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    dispose = capacityCheck(player, roundManager, 0.3, findItem, "Altmetall");
                    tempExp += experience;
                    if (dispose = false) { break; }
                    player[roundManager].scrapMetal += findItem;
                    player[roundManager].realCapacity += findItem * 0.3;
                    break;
                }
                break;
            
            case 3: // Aluminum
                experience = 0;
                chance = 0; chance = round(random(1,100));
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25)) + player[roundManager].luck * 1);
                    if (findItem < 1) {findItem = 1;}
                    experience = round((findItem * 7.5) * (player[roundManager].level * 1.25));
                    std::cout << "\033[0mAluminium\033[0m ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    dispose = capacityCheck(player, roundManager, 0.1, findItem, "Aluminium");
                    tempExp += experience;
                    if (dispose = false) { break; }
                    player[roundManager].aluminum += findItem;
                    player[roundManager].realCapacity += findItem * 0.1;
                    break;
                }
                break;
            
            case 4: // Copper
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25)) + player[roundManager].luck);
                    if (findItem < 1 ) {findItem = 1;} 
                    experience = round((findItem * 5) * (player[roundManager].level * 1.25));
                    std::cout << "\033[31mKupfer\033[0m ------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    dispose = capacityCheck(player, roundManager, 0.2, findItem, "Kupfer");
                    tempExp += experience;
                    if (dispose = false) { break; }
                    player[roundManager].copper += findItem;
                    player[roundManager].realCapacity += findItem * 0.2;
                    break;
                }
                break;
            
            case 5: // Healpotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)) + player[roundManager].luck * 1);
                    experience = round((findItem * 10) * (player[roundManager].level * 1.25));
                    std::cout << "\033[91mHeiltraenke\033[0m -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem, "Heiltraenke");
                    tempExp += experience;
                    if (dispose = false) { break; }
                    player[roundManager].healthPotion += findItem;
                    player[roundManager].realCapacity += findItem * 0.25;
                    break;
                }
                break;
            
            case 6: // Manapotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)) + player[roundManager].luck * 1);
                    if (findItem < 1 ) {findItem = 1;}
                    experience = round((findItem * 15) * (player[roundManager].level * 1.25));
                    std::cout << "\033[94mManatraenke\033[0m -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem, "Manatraenke");
                    tempExp += experience;
                    if (dispose = false) { break; }
                    player[roundManager].manaPotion += findItem;
                    player[roundManager].realCapacity += findItem * 0.25;
                    break;
                }
                break;
            
            case 7: // Regenerationpotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)) + player[roundManager].luck * 1);
                    if (findItem < 1) {findItem = 1;}
                    experience = round((findItem * 20) * (player[roundManager].level * 1.25));
                    std::cout << "\033[95mRegenerationstraenke\033[0m ----> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem, "Regenerationstraenke");
                    tempExp += experience;
                    if (dispose = false) { break; }
                    player[roundManager].regenPotion += findItem;
                    player[roundManager].realCapacity += findItem * 0.25;
                    break;
                }
                break;
            
            case 8: //
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    chance = 0; chance = random(1,100);
                    if (chance > 39 & chance < 61)
                    {
                        findItem = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                        findItem++;
                        experience = round((findItem * 100) * (player[roundManager].level * 1.25));
                        std::cout << "\033[0mWaffe\033[0m -------------------> " << findItem << " DMG / " << experience << " Exp." << std::endl;
                        std::cout << "---------------------------------------------------" << std::endl;
                        dispose = capacityCheck(player, roundManager, findItem , 2.5 , "Waffe");
                        tempExp += experience;
                        if (dispose = false) { break; }
                        for (int i = 0; player[roundManager].weapons[i] = !0; i++)
                        {
                            player[roundManager].weapons[i] += findItem;
                            arraySort(player, roundManager, "weapon");
                            player[roundManager].realCapacity += findItem * 2.5;
                            break;
                        }
                        
                    }
                    break;
                }
                break;

            case 9: // Rüstung
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    chance = 0; chance = random(1,100);
                    if (chance > (44 - player[roundManager].luck) & chance < round (56 + player[roundManager].luck))
                    {
                        findItem = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2)); 
                        findItem++;
                        experience = round((findItem * 100) * (player[roundManager].level * 1.25));
                        std::cout << "\033[90mRuestung\033[0m ----------------> " << findItem << " RST / " << experience << " Exp." << std::endl;
                        std::cout << "---------------------------------------------------" << std::endl;
                        dispose = capacityCheck(player, roundManager, findItem , 2.25 , "Ruestung");
                        tempExp += experience;
                        if (dispose = false) { break; }
                        for (int i = 0; player[roundManager].armor[i] = !0; i++)
                        {
                            player[roundManager].armor[i] += findItem;
                            arraySort(player, roundManager, "armor");
                            player[roundManager].realCapacity += findItem * 2.25;
                            break; 
                        }
                    }
                    break;
                }
                break;
                
                
        }
  
    }
    if (tempExp < 1)
    {
        std::cout << "\n\nNichts!\n\n";
        getKey();
        return;
    }
    
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Gesamt EXP --------------> " << tempExp << " EXP" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    player[roundManager].realExp += tempExp;
    getKey();
    expUp(player, roundManager);
    std::cout << "\n\n" << std::endl;
    return;
}

void loadGame()
{
    clearScreen();
    textLoad();
    line();
    getKey();
    return;
}

void textOne()
{
    position(70, 0); std::cout << "   _               \n";
    position(70, 1); std::cout << " /' \\    		  \n";
    position(70, 2); std::cout << "/\\_, \\           \n";
    position(70, 3); std::cout << "\\/_/\\ \\         \n";
    position(70, 4); std::cout << "   \\ \\ \\        \n";
    position(70, 5); std::cout << "    \\ \\_\\       \n";
    position(70, 6); std::cout << "     \\/_/         \n\n";
    return;
}

void textTwo()
{
    position(70, 0); std::cout << "   ___             \n";
    position(70, 1); std::cout << " /'___`\\          \n";
    position(70, 2); std::cout << "/\\_\\ /\\ \\      \n";
    position(70, 3); std::cout << "\\/_/// /__        \n";
    position(70, 4); std::cout << "   // /_\\ \\      \n";
    position(70, 5); std::cout << "  /\\______/       \n";
    position(70, 6); std::cout << "  \\/_____/        \n\n";
    return;
}

void textThree()
{
    position(70, 0); std::cout << "   __              \n";
    position(70, 1); std::cout << " /'__`\\           \n";
    position(70, 2); std::cout << "/\\_\\L\\ \\       \n";
    position(70, 3); std::cout << "\\/_/_\\_<_        \n";
    position(70, 4); std::cout << "  /\\ \\L\\ \\     \n";
    position(70, 5); std::cout << "  \\ \\____/       \n";
    position(70, 6); std::cout << "   \\/___/         \n\n";
    return;
}

void textFour()
{
    position(70, 0); std::cout << " __ __             \n";
    position(70, 1); std::cout << "/\\ \\\\ \\        \n";
    position(70, 2); std::cout << "\\ \\ \\\\ \\      \n";
    position(70, 3); std::cout << " \\ \\ \\\\ \\_    \n";
    position(70, 4); std::cout << "  \\ \\__ ,__\\    \n";
    position(70, 5); std::cout << "   \\/_/\\_\\_/    \n";
    position(70, 6); std::cout << "      \\/_/        \n\n";
    return;
}

// Ermittlung und Ausgabe der Spielernummer

void getNumber(short roundManager)
{
    switch (roundManager)
    {
        case 0:
            textOne();
            break;
        case 1:
            textTwo();
            break;
        case 2:
            textThree();
            break;
        case 3:
            textFour(); 
            break;       
    }
    return;
}

// Ermittlung der Gefahrenstufe der Räume

short dangerZone()
{
    short zone;
    bool running = true;

    while(running)
    {
        zone = round(random(1, 3));
        if (zone == dangerRepeater) {danger++;} else {danger = 0;}
        if (danger >= 2) {continue;}
        dangerRepeater = zone;
        running = false;
        danger = 0;
        break;
    }
    return zone;
}

// Anzeige der Gefahrenstufe des Raums

void dangerDisplay(short zone)
{
    switch(zone)
    {
        case 1:
            std::cout << "\033[30;102m Gefahrenstufe : Sicher \033[0m" << std::endl;
            break;
        case 2:
            std::cout << "\033[30;43m Gefahrenstufe : Unsicher \033[0m" << std::endl;
            break;
        case 3:
            std::cout << "\033[97;41m Gefahrenstufe : Gefahr \033[0m" << std::endl;
            break;
    }
    return;
}

// Ausgabe Tod des Spielers

void death(Player player[], short roundManager)
{
    player[roundManager].permaDeath = true;
    clearScreen();
    textDeath();
    line();
    position(16, 64); std::cout << player[roundManager].level;
    position(17, 64); std::cout << player[roundManager].rooms;
    position(18, 64); std::cout << player[roundManager].gold;
    position(19, 64); std::cout << player[roundManager].crafted;
    position(20, 64); std::cout << player[roundManager].monsters;
    position(21, 64); std::cout << player[roundManager].bosses;
    position(21, 64); std::cout << player[roundManager].deaths;    
    bool answer = question();
    if (answer == true)
    {
        loadGame();
    } 
    return;
}

void trapCall(Player player[], short roundManager, short zone)
{
    if (zone == 2) 
    {
        player[roundManager].traps = round(random(1, 5));
        round(player[roundManager].traps -= player[roundManager].luck);
        if (player[roundManager].traps < 1) {player[roundManager].traps = 0;}
    }
    if (zone >= 3)
    {
        player[roundManager].traps = round(random(1, 10));
        round(player[roundManager].traps -= player[roundManager].luck);
        if (player[roundManager].traps < 1) {player[roundManager].traps = 1;}
    }
    return;
}

void trapCheck(Player player[], short roundManager)
{
    double damage = 0;
    double vari = 0;
    short rand = round(random(1, 100));

    if (rand > 0 & rand < 26 + player[roundManager].luck || rand > 49 & rand < 76 + player[roundManager].luck)
    {
        if (player[roundManager].traps > 0)
        {
        
            clearScreen();
            textTrap();
            line();
            std::cout << "Um es mit den Worten Admiral Ackbars zu sagen: \033[37;41m *** Das ist eine Falle! *** \033[0m" << std::endl;
            line();
            player[roundManager].traps--;
            damage = (player[roundManager].health / 100 ) * 10;
            vari = round((damage / 100) * 10);
            damage = damage + (round(random(1, vari)) - player[roundManager].luck);
            std::cout << "Als Sie, natuerlich Ihren Geschaeften nachgehend, ziellos... aehm... zielstrebig durch die Gegend wandern, erwischt Sie eine Falle!\n" << std::endl;
            line();
            std::cout << "\033[37;41m *** Schaden: *** \033[0m \033[31m" << damage << " DMG.\033[0m\n\n" << std::endl;
            player[roundManager].realHealth -= damage;
            if (player[roundManager].realHealth < 0)
            {
                player[roundManager].realHealth = 0;
                lifeDisplay(player, roundManager, 0, 16);
                getKey();
                death(player, roundManager);
                return;
            }
            lifeDisplay(player, roundManager, 0, 16);
            getKey();
            return;
        }
    }
}

void trapSearch(Player player[], short roundManager, short danger)
{
    short zone = 0;
    short x = 0;
    double damage = 0;
    double vari = 0;
    double xp = 0;

    clearScreen();
    textTrap();
    line();
    textColor(danger); std::cout << "Sie begeben sich auf die Such nach Fallen.....\033[0m" << std::endl;
    line();
    textColor(danger);
    if (danger == 1)
    {
        std::cout << "\nDoch da der Raum \033[30;102m * Sicher * \033[0m"; textColor(danger); std::cout << " ist, gibt es keine Fallen....\033[0m" << std::endl;
        getKey();
        return;
    }
    if (player[roundManager].traps < 1)
    {
        std::cout << "\nSelbst nach langer Suche koennen Sie keine Fallen entdecken! Koennte es sein, dass Sie bereits alle gefunden haben?\033[0m" << std::endl;
        getKey();
        return;
    }
    std::cout << "\nIhre Suche ergibt" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << ".";
        Sleep(30);
    }
    zone = round(random(1, 100));
    if (danger == 2){ x = 14;}
    if (danger >= 2){ x = 25;}
    if (zone < (50 -x) - player[roundManager].luck & zone > (50 + x) + player[roundManager].luck)
    {
        std::cout << "\n\nSie entdecken eine Falle!\n\nDoch beim Entschärfen unterlaeuft Ihnen ein Missgeschick!\n" << std::endl;
        player[roundManager].traps--;
        damage = (player[roundManager].health / 100 ) * 10;
        vari = round((damage / 100) * 10);
        damage = damage + (round(random(1, vari)) - player[roundManager].luck);
        std::cout << "\033[37;41m *** Schaden: *** \033[0m \033[31m" << damage << " DMG.\033[0m\n\n" << std::endl;
        player[roundManager].realHealth -= damage;
        if (player[roundManager].realHealth < 0)
        {
                player[roundManager].realHealth = 0;
                lifeDisplay(player, roundManager, 0, 16);
                getKey();
                death(player, roundManager);
                return;
        }
        lifeDisplay(player, roundManager, 0, 16);
        getKey();
        return;
    }
    std::cout << "\n\nSie entdecken eine Falle!\n\nUnd Ihr Skill ist hoch genug sie zu entschaerfen!\n\n" << std::endl;
    player[roundManager].traps -= 1;
    xp = round(random(40, 50));
    std::cout << "Sie erhalten: " << xp << " EXP!\033[0m\n\n" << std::endl;
    player[roundManager].realExp += xp;
    getKey();
    expUp(player, roundManager); 
    return;
}

void takeBreak(Player player[], short roundManager, short danger)
{
    short zone = 0;
    int mana = 0;
    int health = 0;
    int x = 0;
     
    mana = round(random(((player[roundManager].mana / 100) * 25), ((player[roundManager].mana / 100) * 50)));
    health = round(random(((player[roundManager].health / 100) * 25), ((player[roundManager].health / 100) * 50)));
    zone = round(random(1, 100));
    
    if (danger == 1){ x = 50; }
    if (danger == 2){ x = 14; }
    if (danger >= 2){ x = 25; }
    if (zone < (50 -x) - player[roundManager].luck & zone > (50 + x) + player[roundManager].luck)
    {
        // Kampf und/oder Falle eintragen 
        return;
    }
    clearScreen();
    textBreak();
    line();
    textColor(danger); std::cout << "Sie Suchen sich eine stille Ecke um Sich auszuruhen.\033[0m" << std::endl;
    line();
    textColor(danger); std::cout << "Beim Rasten regenerieren Sie:\033[0m" << std::endl;
    line();
    std::cout << "\033[31mLeben: " << health << std::endl;
    std::cout << "\n\033[34mMana : " << mana << "\033[0m" << std::endl;
    line();
    player[roundManager].realHealth += health;
    player[roundManager].realMana += mana;
    if(player[roundManager].realHealth > player[roundManager].health) {player[roundManager].realHealth = player[roundManager].health;}
    if(player[roundManager].realMana > player[roundManager].mana) {player[roundManager].realMana = player[roundManager].mana;}
    lifeDisplay(player, roundManager, 0, 23);
    getKey();
    return;
}

bool checkRegen(Player player[], short roundManager, short sort)
{
    switch (sort)
    {
        case 0: // Heal
            if (player[roundManager].realHealth >= player[roundManager].health)
            {
                std::cout << "\n\n\033[31mSie benoetigen keine Heilung!" << std::endl;
                getKey();
                return false;
            }
            break;
        
        case 1: //Mana
            if (player[roundManager].realMana >= player[roundManager].mana)
            {
                std::cout << "\n\n\033[31mSie benoetigen kein Mana!" << std::endl,
                getKey();
                return false;
            }
            break;

        case 2: //regen
            if (player[roundManager].realMana >= player[roundManager].mana && player[roundManager].realHealth >= player[roundManager].health)
            {
                std::cout << "\n\n\033[31m Sie benoetigen weder Heilung noch Mana!" << std::endl;
                getKey();
                return false;
            }
            break;
    }
    return true;
}

bool potionCheck (Player player[], short roundManager, short sort)
{
    switch (sort)
    {
        case 0:
            if (player[roundManager].healthPotion < 1)
                {
                    std::cout << "\n\n\033[31mSie haben nicht genug Heiltraenke!\033[0m" << std::endl;
                    getKey();
                    return false;
                }
                break;
        
        case 1:
            if (player[roundManager].manaPotion < 1)
                {
                    std::cout << "\n\n\033[31mSie haben nicht genug Manatraenke!\033[0m]" << std::endl;
                    getKey();
                    return false;
                }
                break;

        case 2:
            if (player[roundManager].regenPotion < 1)
                {
                    std::cout << "\n\n\033[31mSie haben nicht genug Regenerationstraenke!\033[0m" << std::endl;
                    getKey();
                    return false;
                }
                break;
    }
    return true;
}

void potionDrink (Player player[], short roundManager, short sort)
{
    double regenH = 0;
    double regenM = 0;

    switch (sort)
    {
        case 0:
            regenH = round(random((player[roundManager].health / 100) * 15, (player[roundManager].health /100) * 25));
            player[roundManager].healthPotion--;
            player[roundManager].realHealth += regenH;
            std::cout << "\n\n\033[92mSie regenerieren " << regenH << " Hitpoints!\033[0m" << std::endl;
            lifeDisplay(player, roundManager, 0, 20);
            getKey();
            break;
            
        case 1:
            regenM = round(random((player[roundManager].mana / 100) * 15, (player[roundManager].mana /100) * 25));
            player[roundManager].manaPotion--;
            player[roundManager].realMana += regenM;
            std::cout << "\n\n\033[34mSie regenerieren " << regenH << " Manapoints!\033[0m" << std::endl;
            lifeDisplay(player, roundManager, 0, 20);
            getKey();
            break;

        case 2:
            regenH = round(random((player[roundManager].health / 100) * 10, (player[roundManager].health /100) * 20));
            regenM = round(random((player[roundManager].mana / 100) * 15, (player[roundManager].mana /100) * 20));
            player[roundManager].regenPotion--;
            player[roundManager].realHealth += regenH;
            player[roundManager].realMana += regenM;
            std::cout << "\n\n\033[92mSie regenerieren " << regenH << " Hitpoints!\033[0m" << std::endl;
            std::cout << "\n\033[34mSie regenerieren " << regenH << " Manapoints!\033[0m" << std::endl;
            lifeDisplay(player, roundManager, 0, 22);
            getKey();
            break;
    }
    return;
}
#endif

