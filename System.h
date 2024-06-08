#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <iostream>
#include <limits>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <random>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Main.cpp>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\player.h>

/*Inhaltsverzeichnis:
      - assignment     -- Zuweisung der Werte für neue Spieler
      - charCalc       -- Charakter Rechner zum Errechnen neuer Werte bei Skillpunktverteilung
      - random         -- Zufallsgenerierte Zahlen mit Minmal und Maximal übergabe
      - getKey         -- press any key - Funktion
      - error          -- Fehlermeldung : Falsche Eingabe
      - clearScreen    -- Windows-CMD Screen leeren
      - position       -- Setzen der Cursor Position
      - miniLine       -- kleinen Trennstrich einfügen
      - line           -- Trennstrich einfügen
      - question       -- Ja/Nein - Abfrage des Spielers
      - choice         -- Zahleneingabe des Spielers (0 - 9) ohne "Enter" - Eingabe
      - condition      -- Skillpunkt ermittlung für Charactermenü 
      - lifeDisplay    -- Lebens- und Manaanzeige der Spieler
      - colorSwitch    -- Schalterfarben (Schrift mit Hintergrundfärbung) verändern
      - textColor      -- Schriftfarben verändern
      - backgroundColor-- Verändern der Hintergrund Farbe
      - levelUp        -- Anheben von Skillpunkten, Spielerlevel & geforderten Level Exp
      - expUp          -- Anheben der Spieler Exp und Level Umbruch
      - arraySort      -- Sortierung von Waffen- und Rüstungsarrays der Spieler
      - capacityColor  -- Ermittelt den Farbwert der Traglast nach Füllstand des Inventars des Spielers in Prozent
      - weaponArmorDispose-- Menue zur Entsorgung von Ruestungen und Waffen
      - disposeAmount  -- Menue zur Ermittlung der Anzahl der zu wegwerfenden Gegenstände
      - disposal       -- Funktion zur Entsorgung von Gegenständen für den Spieler
      - capacityCheck  -- Überprüfung und hinzufügen der Traglast des Spielers mit evtl. Übergabe an Entsorgungsfunktion für Gegenstände
      - saveGame       -- Menü zum Speichern des Spielstandes 
      - loadGame       -- Funktion zum Laden von Spielständen
      - death          -- Ausgabe des Todes des Spielers
      - trapCheck      -- Ermittelt die verbleibende Anzahl der Fallen des Spielers und löst ggf. Fallen aus
      - loot           -- Funktion für die Suche-Option des Spielers
      - textOne        -- Headline 1
      - textTwo        -- Headline 2
      - textThree      -- Headline 3
      - textFour       -- Headline 4
      - getNumber      -- Funktion zur Ermittlung und Ausgabe des Spielernummer Schriftzuges
      - dangerZone     -- Funktion zur Ermittlung der Gefahrenstufe des derzeitigen Raums
      - dangerDisplay  -- gibt die Gefahrenstufe des Raums auf den Bildschirm aus
      - trapCall       -- Ermittelt die Anzahl von Fallen in einem Raum auf Basis der Gefahrstufe des Raumes
      - trapSearch     -- Ermittelt, ob die Suche des Spielers nach einer Falle erfolgreich ist, oder sogar eine Falle auslöst
      - takeBreak      -- Ermittelt Werte beim Rasten des Spielers 
      - checkRegen     -- Ermittelt einen boolschen Wert, ob Heilung, Mana oder beides benoetigt wird
      - potionCheck    -- Ermittelt einen boolschen Wert, ob Heiltraenke, Manatraenke oder Regenerationstraenke vorhanden sind 
      - potionDrink    -- Funktion zur Heilung, Manaregeneration oder beidem durch Tränke
      - specialRoom    -- Funktion zur Ermittlung des derzeitigen Spezialraums   
    */

// Globale Variablen zum Eingrenzen von wiederholten Zufallszahlen

extern const int roomNumbers; 
extern short numberOfPlayers;
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
            player[index].capacity = (player[index].strength * 8) + (player[index].endurance * 2);
            player[index].realCapacity = 0.5;
            player[index].weaponDmg = 0;
            player[index].armorDmgReduce = 0;
            player[index].regenerationOn = 0;
            player[index].fireAura = 0;
            player[index].key = 0;
            player[index].scrapMetal = 0;
            player[index].aluminum = 0;
            player[index].copper = 0;
            player[index].herbs = 0;
            player[index].healthPotion = 1;
            player[index].manaPotion = 1;
            player[index].regenPotion = 0;
            player[index].rooms = 0;
            player[index].crafted = 0;
            player[index].monsters = 0;
            player[index].bosses = 0;
            player[index].deaths = 0;
            player[index].permaDeath = false;
            player[index].roomCleared = false;
            player[index].actionPoints = 5;
            player[index].realActionPoints = player[index].actionPoints;
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
    player[index].capacity = (player[index].strength * 8) + (player[index].endurance * 2);
    return;
}

// Generierung von Zufallszahlen mit min/max Wertübergabe

int random(int min, int max)
{
   static std::random_device rd;
   static std::mt19937 gen(rd());

   std::uniform_int_distribution<> distr(min, max);

   int random;
   do
   {
        random = distr(gen);
   } 
   while (random == repeater);

   repeater = random;
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
        case 3: 
            std::cout << "\n\n\033[31mNicht genuegend Intelligenz!\033[0m" << std::endl;
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
                continue;
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
        std::cout << "\033[102m ";
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
        std::cout << "Expierience : " << player[roundManager].exp << "/" << player[roundManager].exp << "\n\n";
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
            Sleep(5);
            std::cout << "\033[0m";
        }
            std::cout << "\n\n" << std::endl;
            getKey();
            levelUp(player , roundManager);
            player[roundManager].realExp = 0;
            player[roundManager].realExp += remainingExp;
            continue;
        }
        else
        {
            range = 100 * (player[roundManager].realExp / player[roundManager].exp);
            
            for (int i = 0; i < range; i++)
            {
                std::cout << "\033[103m ";
                Sleep(5);
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
    short range{};
    range = round(100 * (player[roundManager].realCapacity / player[roundManager].capacity));
    if(range <= 25){std::cout << "\033[92m"; return;}
    if(range <= 50){std::cout << "\033[32m"; return;}
    if(range <= 75){std::cout << "\033[93m"; return;}
    if(range > 75) {std::cout << "\033[31m"; return;}
    return;
}

// Anzahl zu entsorgender Waffen bestimmen

void weaponArmorDispose(Player player[], short roundManager, std::string sortOf)
{
    bool running = true;
    int arraySize = 0;
    int input = 0;

    while (running)
    {
        clearScreen();
        textDisposal();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName();
        position(40, 10); std::cout << "\033[93mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 10); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        if (sortOf == "weapon")
        {
            if (player[roundManager].weapons[0] == 0 && player[roundManager].weaponDmg == 0)
            {
                std::cout << "\n\033[31mSie haben keine Waffen im Inventar!\033[0m" << std::endl;
                getKey();
                running = false;
                break;
            }
            std::cout << "\n\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
            if(player[roundManager].weaponDmg > 0) {std::cout << "\n\033[100;30m[-1 ]\033[0m ------> \033[90m" << player[roundManager].weaponDmg << " DMG (Vorsicht: Angelegte Waffe!)\033[0m" << std::endl;}
            for (int index = 0; index < 500; index++)
            {
                if(player[roundManager].weapons[index] == 0) { break; }
                std::cout << "\n\033[100;30m[ " << index + 1 <<" ]\033[0m ------> \033[90m" << player[roundManager].weapons[index] << " DMG\033[0m" << std::endl;
                arraySize++;
            }
            line();
            std::cout << "\nWelche Waffe moechten Sie entsorgen?"; std::cin >> input;
            if (std::cin.fail())
            {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                error(0);
                continue;
            }
            if (input == 0) {running = false; break;}
            if (player[roundManager].weaponDmg > 0 && input == -1) 
            {
                std::cout << "\n\033[41;37m[Angelegte Waffe!]\033[0;31m Sind sie sicher? (J/N)";
                bool answer = question();
                if (answer == false) { break; }
                player[roundManager].weaponDmg = 0;
                player[roundManager].realCapacity -= 2.5;
                std::cout << "\n\033[31mDie Waffe wurde entsorgt. Moechten Sie noch eine Waffe entsorgen? (J/N)"; answer = question();
                if (answer = false) {running = false; break;}
                continue; 
            }
            if (input - 1 > arraySize || input - 1 < 0) {std::cout << "\n\033[31mDas geht nicht !\033[0m"; getKey(); break;}
            std::cout << "\n\033[31mSind sie sicher? (J/N)";
            bool answer = question();
            if (answer == false) {break;}
            player[roundManager].weapons[input - 1] = 0;
            player[roundManager].realCapacity -= 2.5;
            arraySort(player, roundManager, "weapon");
            std::cout << "\n\033[31mDie Waffe wurde entsorgt. Moechten Sie noch eine Waffe entsorgen? (J/N)"; answer = question();
            if (answer = false) {running = false; break;}
            continue;
        }
        if (sortOf == "armor")
        {
            if (player[roundManager].armor[0] == 0 && player[roundManager].armorDmgReduce == 0)
            {
                std::cout << "\n\033[31mSie haben keine Ruestungen im Inventar!\033[0m" << std::endl;
                getKey();
                running = false;
                break;
            }
            std::cout << "\n\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
            if(player[roundManager].armorDmgReduce > 0) {std::cout << "\n\033[100;30m[-1 ]\033[0m ------> \033[90m" << player[roundManager].armorDmgReduce << " RST (Vorsicht: Angelegte Ruestung!)\033[0m" << std::endl;}
            for (int index = 0; index < 500; index++)
            {
                if(player[roundManager].armor[index] == 0) { break; }
                std::cout << "\n\033[100;30m[ " << index + 1 <<" ]\033[0m ------> \033[90m" << player[roundManager].armor[index] << " RST\033[0m" << std::endl;
                arraySize++;
            }
            line();
            std::cout << "\nWelche Ruestung moechten Sie entsorgen?"; std::cin >> input;
            if (std::cin.fail())
            {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                error(0);
                continue;
            }
            if (input == 0) {running = false; break;}
            if (player[roundManager].armorDmgReduce > 0 && input == -1) 
            {
                std::cout << "\n\033[41;37m[Angelegte Ruestung!]\033[0;31m Sind sie sicher? (J/N)";
                bool answer = question();
                if (answer == false) { break; }
                player[roundManager].armorDmgReduce = 0;
                player[roundManager].realCapacity -= 2.25;
                std::cout << "\n\033[31mDie Ruestung wurde entsorgt. Moechten Sie noch eine Ruestung entsorgen? (J/N)"; 
                answer = question();
                if (answer = false) {running = false; break;}
                continue; 
            }
            if (input - 1 > arraySize || input - 1 < 0) {std::cout << "\n\033[31mDas geht nicht !\033[0m"; getKey(); break;}
            std::cout << "\n\033[31mSind sie sicher? (J/N)";
            bool answer = question();
            if (answer == false) {break;}
            player[roundManager].armor[input - 1] = 0;
            player[roundManager].realCapacity -= 2.25;
            arraySort(player, roundManager, "armor");
            std::cout << "\n\033[31mDie Ruestung wurde entsorgt. Moechten Sie noch eine Ruestung entsorgen? (J/N)"; answer = question();
            if (answer = false) {running = false; break;}
            continue;
        }
    }
    return;
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
                    std::cout << "\nSie haben " << amount << " Einheiten " << sortOf << " entsorgt!\033[0m" << std::endl;
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
        numberOfWeapons = 0;
        numberOfArmor = 0;

        if (weight > 0)
        {
            needWeight = (player[roundManager].realCapacity + weight) - player[roundManager].capacity;
            if (needWeight < 0) {needWeight = 0;}
        }

        for(int index = 0; index < 500; index++) 
        {
            if (player[roundManager].weapons[index] == 0)
            {
                break;
            }
            numberOfWeapons++;
        }
        for(int index = 0; index < 500; index++) 
        {
            if(player[roundManager].armor[index] == 0)
            {
                break;
            }
            numberOfArmor++; 
        }
        if (player[roundManager].weaponDmg > 0) { numberOfWeapons++; }
        if (player[roundManager].armorDmgReduce > 0) { numberOfArmor++; }

        clearScreen();
        textDisposal();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName();
        position(40, 10); std::cout << "\033[93mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 10); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        std::cout << "                                   Gewicht pro Einheit           Anzahl              Gesamtgewicht" << std::endl;
        std::cout << "\n\n\033[47;30m[ 1 ]\033[0m -----> Altmetall                   0,3  kg"; position(65, 17); std::cout << player[roundManager].scrapMetal; position(85, 17); std::cout << player[roundManager].scrapMetal * 0.3 << std::endl; 
        std::cout << "\n\033[100;30m[ 2 ]\033[0m -----> \033[90mAluminum                    0,1  kg"; position(65, 19); std::cout << player[roundManager].aluminum; position(85, 19); std::cout << player[roundManager].aluminum * 0.1 << std::endl;
        std::cout << "\n\033[41;37m[ 3 ]\033[0m -----> \033[31mKupfer                      0,2  kg"; position(65, 21); std::cout << player[roundManager].copper; position(85, 21); std::cout << player[roundManager].copper * 0.2 << std::endl;
        std::cout << "\n\033[102;30m[ 4 ]\033[0m -----> \033[92mKraeuter                    0,1 kg"; position(65, 23); std::cout << player[roundManager].herbs; position(85, 23); std::cout << player[roundManager].herbs * 0.1 << std::endl;
        std::cout << "\n\033[101;37m[ 5 ]\033[0m -----> \033[91mHeiltraenke                 0,25 kg"; position(65, 25); std::cout << player[roundManager].healthPotion; position(85, 25); std::cout << player[roundManager].healthPotion * 0.25 << std::endl;
        std::cout << "\n\033[44;37m[ 6 ]\033[0m -----> \033[34mManatraenke                 0,25 kg"; position(65, 27); std::cout << player[roundManager].manaPotion; position(85, 27); std::cout << player[roundManager].manaPotion * 0.25 << std::endl;
        std::cout << "\n\033[45;37m[ 7 ]\033[0m -----> \033[35mRegenerationstraenke        0,25 kg"; position(65, 29); std::cout << player[roundManager].regenPotion; position(85, 29); std::cout << player[roundManager].regenPotion * 0.25 << std::endl;
        std::cout << "\n\033[47;30m[ 8 ]\033[0m -----> \033[0mWaffen                      2,5  kg"; position(65, 31); std::cout << numberOfWeapons; position(85, 31); std::cout << numberOfWeapons * 2.5 << std::endl;
        std::cout << "\n\033[100;30m[ 9 ]\033[0m -----> \033[90mRuestungen                  2,25 kg"; position(65, 33); std::cout << numberOfArmor; position(85, 33); std::cout << numberOfArmor * 2.25 << std::endl;
        std::cout << "\n\033[47;30m[ 0 ]\033[0m -----> \033[0mZurueck" << std::endl;
        line();
        if (weight > 0) {std::cout << "\033[31mSie muessen noch " << needWeight << " kg ablegen.\033[0m" << std::endl; 
        line();
        }
        std::cout << "\n\033[31mWas moechten Sie entsorgen?\033[0m" << std::endl;
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
                    amount = disposeAmount(player, roundManager, "Kraeuter", player[roundManager].herbs);
                    if (amount == -1) {break;}
                    player[roundManager].herbs -= amount;
                    player[roundManager].realCapacity -= (amount * 0.1);
                    getKey();
                    break;

                case 5:
                    amount = disposeAmount(player, roundManager, "Heiltraenke", player[roundManager].healthPotion);
                    if (amount == -1) {break;}
                    player[roundManager].healthPotion -= amount;
                    player[roundManager].realCapacity -= (amount * 0.25);
                    getKey();
                    break;
                
                case 6:
                    amount = disposeAmount(player, roundManager, "Manatraenke", player[roundManager].manaPotion);
                    if (amount == -1) {break;}
                    player[roundManager].manaPotion -= amount;
                    player[roundManager].realCapacity -= (amount * 0.25);
                    getKey();
                    break;
                
                case 7:
                    amount = disposeAmount(player, roundManager, "Regenerationstaenke", player[roundManager].regenPotion);
                    if (amount == -1) {break;}
                    player[roundManager].regenPotion -= amount;
                    player[roundManager].realCapacity -= (amount * 0.25);
                    getKey();
                    break;

                case 8:
                    weaponArmorDispose(player, roundManager, "weapon");
                    break;

                case 9:
                    weaponArmorDispose(player, roundManager, "armor");
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
        finalWeight = round(((numberOfObjects * weight) + player[roundManager].realCapacity) - player[roundManager].capacity);
        std::cout << "\n\033[31mSie sind ueberladen! Was Sie mitnehmen moechten hat ein Gewicht von " << (numberOfObjects * weight) << " kg.";
        std::cout << "\nEs fehlen Ihnen also noch " << finalWeight << " kg, moechten sie etwas wegwerfen? (J/N)\033[0m\n";
        answer = question();
        switch (answer)
        {
            case true:
                enoughWeight = disposal(player, roundManager, weight);
                if (enoughWeight == false) 
                {
                    std::cout << "\033[31mLeider haben Sie immer noch nicht genug Platz im Inventar!\033[0m" << std::endl;
                    return false;
                }
                break;

            case false:
                std::cout << "\033[0mSie entscheiden sich dazu lieber Ihre Sachen zu behalten...." << std::endl;
                return false;
        }
    }
    return true;
}

void saveGame() 
{
    clearScreen();
    textSave();
    line();
    std::cout << "\n\033[47;30m[ 1 ]\033[0m ------> Spielstand 1 :" << std::endl;
    line();
    std::cout << "\n\033[47;30m[ 2 ]\033[0m ------> Spielstand 2 :" << std::endl;
    line();
    std::cout << "\n\033[47;30m[ 3 ]\033[0m ------> Spielstand 3 :" << std::endl;
    line();
    std::cout << "\n\033[47;30m[ 4 ]\033[0m ------> Zurueck" << std::endl;
    short input = choice();
    switch(input)
    {
        case 1:
        
        case 4:
            return;
        
        default:
            error(0);
    }
    return;
}

void loadGame()
{
    clearScreen();
    textLoad();
    line();
    std::cout << "\n\033[47;30m[ 1 ]\033[0m ------> Spielstand 1 :" << std::endl;
    line();
    std::cout << "\n\033[47;30m[ 2 ]\033[0m ------> Spielstand 2 :" << std::endl;
    line();
    std::cout << "\n\033[47;30m[ 3 ]\033[0m ------> Spielstand 3 :" << std::endl;
    line();
    std::cout << "\n\033[47;30m[ 4 ]\033[0m ------> Zurueck" << std::endl;
    short input = choice();
    switch(input)
    {
        case 1:
        
        case 4:
            return;
        
        default:
            error(0);
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
    position(64, 15); std::cout << "\033[35m" << player[roundManager].level << "\033[0m";
    position(64, 16); std::cout << "\033[36m" << player[roundManager].rooms << "\033[0m";
    position(64, 17); std::cout << "\033[93m" << player[roundManager].gold << "\033[0m";
    position(64, 18); std::cout << "\033[90m" << player[roundManager].crafted << "\033[0m";
    position(64, 19); std::cout << "\033[92m" << player[roundManager].monsters << "\033[0m";
    position(64, 20); std::cout << "\033[32m" << player[roundManager].bosses << "\033[0m";
    position(64, 21); std::cout << "\033[31m" << player[roundManager].deaths << "\033[0m";    
    position(0, 50);
    bool answer = question();
    if (answer == true)
    {
        loadGame();
    } 
    return;
}

void trapCheck(Player player[], short roundManager, std::string room)
{
    double damage = 0;
    double vari = 0;
    short rand = round(random(1, 100));

    if (rand >= 1 && rand <= round(25 - player[roundManager].luck) || rand >= 50 && rand <= round(75 - player[roundManager].luck))
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
            damage = round(damage + ((random(1, vari)) - player[roundManager].luck));
            std::cout << "\nAls Sie, natuerlich Ihren Geschaeften nachgehend, ziellos... aehm... zielstrebig durch die Gegend wandern, erwischt Sie eine Falle!\n" << std::endl;
            std::cout << "\033[37;41m *** Schaden: *** \033[0m \033[31m" << damage << " DMG.\033[0m\n" << std::endl;
            line();
            player[roundManager].realHealth -= damage;
            if (player[roundManager].realHealth < 0)
            {
                player[roundManager].realHealth = 0;
                lifeDisplay(player, roundManager, 0, 22);
                getKey();
                death(player, roundManager);
                return;
            }
            lifeDisplay(player, roundManager, 0, 22);
            line();
            if (room == "loot") { std::cout << "Nichtsdestotrotz begeben Sie sich auf die Suche....." << std::endl;}
            if (room == "sleep") { std::cout << "Dennoch suchen Sie sich ein Plaetzchen zum Ausruhen....." << std::endl;}
            getKey();
            return;
        }
    }
}

// looten nach erfolgreicher Suche

void loot(Player player[], short roundManager)
{
    int chance = 0;
    bool dispose = false;
    double tempExp = 0;
    double findItem = 0;
    double experience = 0;
        
    trapCheck(player, roundManager, "loot");

    clearScreen();
    textSearch();
    line();
    std::cout << "Sie begeben sich auf die Suche und finden:" << std::endl;
    line();
    std::cout << "---------------------------------------------------" << std::endl;
    
    for (int index = 0; index <= 10; index++)
    {
        switch (index)
        {
            case 0: // Gold
                experience = 0;
                chance = 0; chance = round(random(1,100));
                if ((chance >= 1 && chance <= 35) || (chance >= 50 && chance <= 85))
                {
                    findItem = random(round(player[roundManager].level * 5), round(player[roundManager].level * 25) + round(player[roundManager].luck));
                    experience = round((findItem * 0.125) * (player[roundManager].level * 1.25));
                    std::cout << "\033[93mGold\033[0m --------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].gold += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 1: // Schlüssel
                if (player[roundManager].key < 1)
                {
                    experience = 0;
                    chance = 0; chance = round(random(1,100));
                    if (chance >= 1 && chance <= 35 || chance >= 40 && chance <= 75)
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
                chance = 0; chance = round(random(1,100));
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    findItem = random(round((player[roundManager].level * 0.125)), round(player[roundManager].level * 0.25) + round(player[roundManager].luck));
                    if (findItem < 1) {findItem = 1;} 
                    experience = round((findItem * 10) * (player[roundManager].level * 1.25));
                    std::cout << "\033[90mAltmetall\033[0m ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.3, findItem, "Altmetall");
                    if (dispose == false) { std::cout << "\033[91mDas Material wurde liegengelassen!\n" <<  "---------------------------------------------------" << std::endl; break; }
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].scrapMetal += findItem;
                    player[roundManager].realCapacity += findItem * 0.3;
                    break;
                }
                break;
            
            case 3: // Aluminum
                experience = 0;
                chance = 0; chance = round(random(1,100));
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    findItem = random(round((player[roundManager].level * 0.125)), round(player[roundManager].level * 0.25) + round(player[roundManager].luck));
                    if (findItem < 1) {findItem = 1;}
                    experience = round((findItem * 7.5) * (player[roundManager].level * 1.25));
                    std::cout << "\033[0mAluminium\033[0m ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.1, findItem, "Aluminium");
                    if (dispose == false) { std::cout << "\033[91mDas Material wurde liegengelassen!\n" <<  "---------------------------------------------------" << std::endl; break; }
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].aluminum += findItem;
                    player[roundManager].realCapacity += findItem * 0.1;
                    break;
                }
                break;
            
            case 4: // Copper
                experience = 0;
                chance = 0; chance = random(1,100);
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    findItem = random(round((player[roundManager].level * 0.125)), round(player[roundManager].level * 0.25) + round(player[roundManager].luck));
                    if (findItem < 1 ) {findItem = 1;} 
                    experience = round((findItem * 5) * (player[roundManager].level * 1.25));
                    std::cout << "\033[31mKupfer\033[0m ------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.2, findItem, "Kupfer");
                    if (dispose == false) { std::cout << "\033[91mDas Material wurde liegengelassen!\n" <<  "---------------------------------------------------" << std::endl; break; }
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].copper += findItem;
                    player[roundManager].realCapacity += findItem * 0.2;
                    break;
                }
                break;

            case 5: // Herbs
                experience = 0;
                chance = 0; chance = random(1,100);
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    findItem = random(round((player[roundManager].level * 0.125)), round(player[roundManager].level * 0.25) + round(player[roundManager].luck));
                    if (findItem < 1 ) {findItem = 1;} 
                    experience = round((findItem * 5) * (player[roundManager].level * 1.25));
                    std::cout << "\033[92mKraeuter\033[0m ----------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.1, findItem, "Kraut");
                    if (dispose == false) { std::cout << "\033[91mDas Material wurde liegengelassen!\n" <<  "---------------------------------------------------" << std::endl; break; }
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].herbs += findItem;
                    player[roundManager].realCapacity += findItem * 0.1;
                    break;
                }
                break;
            
            case 6: // Healpotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    findItem = random(round((player[roundManager].level * 0.125)), round(player[roundManager].level * 0.25) + round(player[roundManager].luck));
                    if (findItem < 1) {findItem = 1;}
                    experience = round((findItem * 10) * (player[roundManager].level * 1.25));
                    std::cout << "\033[91mHeiltraenke\033[0m -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem, "Heiltraenke");
                    if (dispose == false) { std::cout << "\033[91mDer Trank wurde liegengelassen!\n" <<  "---------------------------------------------------" << std::endl; break; }
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].healthPotion += findItem;
                    player[roundManager].realCapacity += findItem * 0.25;
                    break;
                }
                break;
            
            case 7: // Manapotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    findItem = random(round((player[roundManager].level * 0.125)), round(player[roundManager].level * 0.25) + round(player[roundManager].luck));
                    if (findItem < 1 ) {findItem = 1;}
                    experience = round((findItem * 15) * (player[roundManager].level * 1.25));
                    std::cout << "\033[94mManatraenke\033[0m -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem, "Manatraenke");
                    if (dispose == false) { std::cout << "\033[91mDer Trank wurde liegengelassen!\n" <<  "---------------------------------------------------" << std::endl; break; }
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].manaPotion += findItem;
                    player[roundManager].realCapacity += findItem * 0.25;
                    break;
                }
                break;
            
            case 8: // Regenerationpotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    findItem = random(round((player[roundManager].level * 0.125)), round(player[roundManager].level * 0.25) + round(player[roundManager].luck));
                    if (findItem < 1) {findItem = 1;}
                    experience = round((findItem * 20) * (player[roundManager].level * 1.25));
                    std::cout << "\033[95mRegenerationstraenke\033[0m ----> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem, "Regenerationstraenke");
                    if (dispose == false) { std::cout << "\033[91mDer Trank wurde liegengelassen!\n" << "---------------------------------------------------" << std::endl; break; }
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].regenPotion += findItem;
                    player[roundManager].realCapacity += findItem * 0.25;
                    break;
                }
                break;
            
            case 9: // Waffen
                experience = 0;
                chance = 0; chance = random(1,100);
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    chance = 0; chance = random(1,100);
                    if (chance >= (45 - player[roundManager].luck) && chance <= (55 + player[roundManager].luck))
                    {
                        findItem = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                        findItem++;
                        experience = round((findItem * 100) * (player[roundManager].level * 1.25));
                        std::cout << "\033[0mWaffe\033[0m -------------------> " << findItem << " DMG / " << experience << " Exp." << std::endl;
                        tempExp += experience;
                        dispose = capacityCheck(player, roundManager, 2.5, 1, "Waffe");
                        if (dispose == false) { std::cout << "\033[91mDie Waffe wurde liegengelassen!\n" << "---------------------------------------------------" << std::endl; break; }
                        std::cout << "---------------------------------------------------" << std::endl;
                        if (player[roundManager].weapons[0] == 0) {player[roundManager].weapons[0] = findItem; break;}
                        for (int i = 0; i < 500; i++)
                        {
                            if (player[roundManager].weapons[i] == 0) 
                            {
                                player[roundManager].weapons[i] = findItem;
                                arraySort(player, roundManager, "weapon");
                                player[roundManager].realCapacity += (1 * 2.5);
                                break;
                            }                        
                        }
                    }
                    break;
                    }
                break;

            case 10: // Rüstung
                experience = 0;
                chance = 0; chance = random(1,100);
                if ((chance >= 1 && chance <= 25) || (chance >= 50 && chance <= 75))
                {
                    chance = 0; chance = random(1,100);
                    if (chance >= (45 - player[roundManager].luck) & chance <=  (55 + player[roundManager].luck))
                    {
                        findItem = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2)); 
                        findItem++;
                        experience = round((findItem * 100) * (player[roundManager].level * 1.25));
                        std::cout << "\033[90mRuestung\033[0m ----------------> " << findItem << " RST / " << experience << " Exp." << std::endl;
                        tempExp += experience;
                        dispose = capacityCheck(player, roundManager, 2.25, 1, "Ruestung");
                        if (dispose == false) { if (dispose = false) { std::cout << "\033[91mDie Ruestung wurde liegengelassen!\n" << "---------------------------------------------------" << std::endl; break; } }
                        std::cout << "---------------------------------------------------" << std::endl;
                        if (player[roundManager].armor[0] == 0) {player[roundManager].armor[0] = findItem; break;}
                        for (int i = 0; i < 500; i++)
                        {
                            if (player[roundManager].armor[i] == 0) 
                            {
                                player[roundManager].armor[i] = findItem;
                                arraySort(player, roundManager, "armor");
                                player[roundManager].realCapacity += (1 * 2.25);
                                break;
                            }
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
        if (zone == dangerRepeater) { continue; }
        dangerRepeater = zone;
        running = false;
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
            std::cout << "\033[30;103m Gefahrenstufe : Unsicher \033[0m" << std::endl;
            break;
        case 3:
            std::cout << "\033[97;41m Gefahrenstufe : Gefahr \033[0m" << std::endl;
            break;
    }
    return;
}

void trapCall(Player player[], short roundManager, short zone)
{
    if (zone == 2) 
    {
        player[roundManager].traps = round(random(1, 3));
        round(player[roundManager].traps -= player[roundManager].luck);
        if (player[roundManager].traps < 1) {player[roundManager].traps = 0;}
    }
    if (zone >= 3)
    {
        player[roundManager].traps = round(random(1, 5));
        round(player[roundManager].traps -= player[roundManager].luck);
        if (player[roundManager].traps < 1) {player[roundManager].traps = 1;}
    }
    return;
}

void trapSearch(Player player[], short roundManager, short danger)
{
    short zone = 0;
    float x = 0;
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
    std::cout << "\nIhre Suche ergibt";
    for (int i = 0; i < 5; i++)
    {
        std::cout << ".";
        Sleep(30);
    }
    zone = round(random(1, 100));
    if (danger == 2){ x = 12.5;}
    if (danger >= 3){ x = 17.5;}
    if (zone >= round((25 - x) - player[roundManager].luck) && zone <= round((25 + x) + player[roundManager].luck) || zone >= round((50 - x) - player[roundManager].luck) && zone <= round((50 + x) + player[roundManager].luck))
    {
        std::cout << "\n\nSie entdecken eine Falle!\n\nDoch beim Entschaerfen unterlaeuft Ihnen ein Missgeschick!\n" << std::endl;
        player[roundManager].traps--;
        damage = (player[roundManager].health / 100 ) * 10;
        vari = round((damage / 100) * 10);
        damage = round(damage + ((random(1, vari)) - player[roundManager].luck));
        std::cout << "\033[37;41m *** Schaden: *** \033[0m \033[31m" << damage << " DMG.\033[0m\n\n" << std::endl;
        player[roundManager].realHealth -= damage;
        if (player[roundManager].realHealth < 0)
        {
                player[roundManager].realHealth = 0;
                lifeDisplay(player, roundManager, 0, 24);
                getKey();
                death(player, roundManager);
                return;
        }
        lifeDisplay(player, roundManager, 0, 24);
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
    float x = 0;
     
    mana = round(random(((player[roundManager].mana / 100) * 25), ((player[roundManager].mana / 100) * 50)));
    health = round(random(((player[roundManager].health / 100) * 25), ((player[roundManager].health / 100) * 50)));
    zone = round(random(1, 100));

    if (danger >= 2)
    { 
        if (danger == 2) { x = 12.5; }
        if (danger == 3) { x = 17.5; }
        if (zone >= round((25 - x) - player[roundManager].luck) && zone <= round((25 + x) + player[roundManager].luck) || zone >= round((75 - x) - player[roundManager].luck) && zone <= round((75 + x) + player[roundManager].luck))
        {
            trapCheck(player, roundManager, "sleep");
        }
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
    lifeDisplay(player, roundManager, 0, 24);
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

void specialHeader(int room)
{
    clearScreen();
    textSpecial();
    line();
    if (room == 5) { std::cout << "\033[36mHebel\033[0m" << std::endl; }
    if (room == 6) { std::cout << "\033[36mTruhe\033[0m" << std::endl; }
    if (room == 9) { std::cout << "\033[36mSchmiede\033[0m" << std::endl; }
    if (room == 10){ std::cout << "\033[36mGeschaeft\033[0m" << std::endl; }
    if (room == 11){ std::cout << "\033[36mCasino\033[0m" << std::endl; }
    if (room == 12){ std::cout << "\033[36mLoch in der Wand\033[0m" << std::endl; }
    if (room == 13){ std::cout << "\033[36mDunkler Baum\033[0m" << std::endl; }
    if (room == 14){ std::cout << "\033[36mBushaltestelle\033[0m" << std::endl; }
    if (room == 15){ std::cout << "\033[36mAltarraum\033[0m" << std::endl; }
    if (room == 19){ std::cout << "\033[36mToilette des Gluecks\033[0m" << std::endl; }
    if (room == 20){ std::cout << "\033[36mGrabstaette des Kriegers\033[0m" << std::endl; }
    line();
    return;
}

void lever(Player player[], short roundManager, int room)
{
    specialHeader(room);
    std::cout << "\nSind Sie sich sicher, das Sie den Hebel betaetigen moechten? (J/N)" << std::endl;
    bool answer = question();
    if (answer == true)
    {
        if (numberOfPlayers > 1) { player[roundManager].realActionPoints--; }
        int event = random(1,100);
        if (event >= 1 && event <= 25)
        {
            std::cout << "\n\033[33mSie vernehmen ein seltsames Klicken in der Wand....\033[0m" << std::endl;

            short chance = random(1,100);
            if (chance >= 1 && chance <=25 || chance >= 50 && chance <=75)
            {
                std::cout << "\n\033[33m....gefolgt von einem gewaltigen Rollgeraeusch!....\033[0m" << std::endl;
                std::cout << "\n\033[33mEin riesiger Felsen rollt, ganz in Indiana Jones Manier, auf Sie zu!...." << std::endl;
                chance = 0; chance = random(1,100);
                if (chance >= 1 && chance <=25 + player[roundManager].luck || chance >= 50 && chance <=75 + player[roundManager].luck)
                {
                    std::cout << "\n\033[32mDoch Ihren Katzenartigen Reflexen ist es zu verdanken, dass Sie es schaffen rechtzeitig auszuweichen!" << std::endl;
                    getKey();
                    return;
                }
                else
                {
                    std::cout << "\n\033[31mAber Sie werden so ueberrascht, dass Sie von der Situation (und vom Felsen) quasi ueberrollt werden!...." << std::endl;
                    double damage = random(1, round((player[roundManager].health / 50) - player[roundManager].luck));
                    std::cout << "\n\033[31mSie nehmen \033[41;37m* " << damage << " Schaden *\033[0m" << std::endl;
                    player[roundManager].realHealth -= damage;
                    if (player[roundManager].realHealth < 0) {player[roundManager].realHealth = 0;}
                    if (player[roundManager].realHealth <= 0) 
                    {
                        std::cout << "\n\033[31mSie sind bei dieser Aktion leider gestorben!" << std::endl;
                        lifeDisplay(player, roundManager, 0, 30);
                        getKey();
                        death(player, roundManager);
                        return;
                    }
                    lifeDisplay(player, roundManager, 0, 30);
                    getKey();
                    return;
                }
            }
            std::cout << "\n\033[32m...Dennoch scheint nichts zu geschehen... nochmal Glück gehabt?\033[0m" << std::endl;
            getKey();
            return; 
        }
        if (event > 25 && event <= 50)
        {
            std::cout << "\n\033[33mDirekt unter Ihren Fuessen oeffnet sich eine Klappe und Sie stehen ploetzlich fuer einen Augenblick in der Luft!" << std::endl;
            std::cout << "\nNach einem kurzen Moment sausen Sie nach unten.... in den naechsten Raum....\033[0m" << std::endl;
            double damage = random(1, round((player[roundManager].realHealth / 10) - player[roundManager].luck));
            player[roundManager].currentRoom = random(1,roomNumbers);
            std::cout << "\n\033[31mDabei nehmen Sie \033[41;37m* " << damage << " Schaden *\033[0m" << std::endl;
            player[roundManager].realHealth -= damage;
            lifeDisplay(player, roundManager, 0, 30);
            getKey();
            return;
        } 
        if (event > 50 && event <= 75)
        {
            std::cout << "\n\033[33mSie vernehmen ein seltsames Klicken in der Wand....\033[0m" << std::endl;
            double gold = random(round((player[roundManager].level * 10) + player[roundManager].luck), round((player[roundManager].level * 25) + player[roundManager].luck));
            double experience = round(gold * 0.125);
            std::cout << "\n\033[32m....Und es rasselt Gold von der Decke!" << std::endl;
            std::cout << "\n\033[32mSie finden \033[33m" << gold << "\033[32m und erhalten " << experience << " EXP dafuer." << std::endl;
            player[roundManager].gold += gold;
            player[roundManager].realExp += experience;
            getKey();
            expUp(player, roundManager);
            return;
        }
        std::cout << "Sie betaetigen den Hebel, doch es geschieht nichts! Die Frage ist: Glück, oder Pech gehabt?" << std::endl;
        getKey();
        return;
    }
    return;
}

void openChest(Player player[], short roundManager)
{
    double exp = 0;
    
    std::cout << "\n\033[32m....und oeffnen diese!" << std::endl;
    std::cout << "\n\033[32mSie finden:\033[0m" << std::endl;
    line();
    double gold = random(round((player[roundManager].level * 20) + player[roundManager].luck), round((player[roundManager].level * 30) + player[roundManager].luck));
    double experience = round(gold * 0.125);
    std::cout << "\033[93mGold\033[0m --------------------> " << gold << " / " << experience << " Exp." << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    player[roundManager].gold += gold;
    exp += experience;

    short opportunity = random(1,100);
    if (opportunity >=1 && opportunity <= 50)
    {
        double armor = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2)); 
        armor++;
        experience = 0; experience = round(armor * 100);
        std::cout << "\033[90mRuestung\033[0m ----------------> " << armor << " RST / " << experience << " Exp." << std::endl;
        exp += experience;
        bool dispose = capacityCheck(player, roundManager, 2.25, 1, "Ruestung");
        if (dispose == false) { std::cout << "\033[91mDie Ruestung wurde liegengelassen!\n" << "---------------------------------------------------" << std::endl;} 
        std::cout << "---------------------------------------------------" << std::endl;
        if (player[roundManager].armor[0] == 0) {player[roundManager].armor[0] = armor;}
        for (int i = 0; i < 500; i++)
        {
            if (player[roundManager].armor[i] == 0) 
            {
                player[roundManager].armor[i] = armor;
                arraySort(player, roundManager, "armor");
                player[roundManager].realCapacity += (1 * 2.25);
                break;
            }
        }
    }
    
    opportunity = 0; opportunity = random(1,100);
    if (opportunity >=1 && opportunity <= 50)
    {
        double weapon = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
        weapon++;
        experience = round(weapon * 100);
        std::cout << "\033[0mWaffe\033[0m -------------------> " << weapon << " DMG / " << experience << " Exp." << std::endl;
        exp += experience;
        bool dispose = capacityCheck(player, roundManager, 2.5, 1, "Waffe");
        if (dispose == false) { std::cout << "\033[91mDie Waffe wurde liegengelassen!\n" << "---------------------------------------------------" << std::endl; }
        std::cout << "---------------------------------------------------" << std::endl;
        if (player[roundManager].weapons[0] == 0) {player[roundManager].weapons[0] = weapon;}
        for (int i = 0; i < 500; i++)
        {
            if (player[roundManager].weapons[i] == 0) 
            {
                player[roundManager].weapons[i] = weapon;
                arraySort(player, roundManager, "weapon");
                player[roundManager].realCapacity += (1 * 2.5);
                break;
            }                        
        }
    }
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Gesamt EXP --------------> " << exp << " EXP" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    player[roundManager].realExp += exp;
    getKey();
    expUp(player, roundManager);
    std::cout << "\n\n" << std::endl;
    return;
}

void chestFight(Player player[], short roundManager)
{
    std::cout << "\n\033[31mDoch als Sie sich der Truhe naehern verwandelt sich diese in einen Mimik und es kommt zum Kampf!\033[0m";
                getKey();                
                //Kampf implementieren
                if (player[roundManager].permaDeath == false)
                {
                std::cout << "\n\033[32mDa Sie souveraen ueberlebt haben, koennen Sie sich jetzt auch noch ueber den Inhalt der Truhe freuen! Sie treten heran....\033[0m";
                openChest(player, roundManager);
                return;
                }
                return;
}

void chest(Player player[], short roundManager, int room, short danger)
{
    specialHeader(room);
    std::cout << "\nMoechten Sie die Truhe oeffnen? (J/N)" << std::endl;
    bool answer = question();
    if (answer == true)
    {
        std::cout << "\n\033[33mSie naehern sich der Truhe....\033[0m" << std::endl;

        if (danger == 1)
        {
            openChest(player, roundManager);
            return;
        }

        if (danger == 2)
        {
            short chance = random(1, 100);
            if (chance >= 1 && chance <= 25 || chance >= 50 && chance <= 75)
            {
                chestFight(player, roundManager);
                return;
            }
            openChest(player, roundManager);
            return;
        }

        if (danger == 3)
        {
            short chance = random(1, 100);
            if (chance >= 1 && chance <= 35 || chance >= 50 && chance <= 85)
            {
                chestFight(player, roundManager);
                return;
            }
        }
        error(0);
        return;
    }
    return;
}

void forgeMenue(Player player[], short roundManager, short room)
{
    specialHeader(room);
    std::cout << player[roundManager].getName() << ", Ihre Ressourcen:" << std::endl;
    line();
    std::cout << "Altmetall ---> " << player[roundManager].scrapMetal << std::endl;
    std::cout << "Kupfer ------> " << player[roundManager].copper << std::endl;
    std::cout << "Aluminium ---> " << player[roundManager].aluminum << std::endl;
    line();
    return;
}

void needMaterial(std::string name)
{
    std::cout << "Sie haben zu wenig "<< name << "!" << std::endl;
    getKey();
    return;
}

void forgeArmor(Player player[], short roundManager, short room)
{
    bool running = true;
    while(running)
    {
        forgeMenue(player, roundManager, room);
        std::cout << "Zur Herstellung einer normalen Ruestung benoetigen Sie auf Ihrem derzeitigen Level:" << std::endl;
        double neededScrap = (round((player[roundManager].level * 5) - player[roundManager].luck));
        double neededCopper = (round((player[roundManager].level * 3) - player[roundManager].luck));
        double neededAluminum = (round((player[roundManager].level * 2) - player[roundManager].luck));
        std::cout << "Altmetall: " << neededScrap << " | Kupfer: " << neededCopper << " | Aluminium: " << neededAluminum << std::endl;
        line();
        std::cout << "Zur Herstellungen einer besonderen Ruestung benoetigen Sie auf Ihrem derzeitigen Level:" << std::endl;
        double goodScrap = (round((player[roundManager].level * 7.5) - player[roundManager].luck));
        double goodCopper = (round((player[roundManager].level * 4.25) - player[roundManager].luck));
        double goodAluminum = (round((player[roundManager].level * 3.5) - player[roundManager].luck));
        std::cout << "Altmetall: " << goodScrap << " | Kupfer: " << goodCopper << " | Aluminium: " << goodAluminum << std::endl;
        line();
        std::cout << "Zur Herstellung der best moeglichen Ruestung benoetigen Sie auf Ihrem derzeitigen Level:" << std::endl;
        double bestScrap = (round((player[roundManager].level * 12.5) - player[roundManager].luck));
        double bestCopper = (round((player[roundManager].level * 7.5) - player[roundManager].luck));
        double bestAluminum = (round((player[roundManager].level * 5) - player[roundManager].luck));
        std::cout << "Altmetall: " << bestScrap << " | Kupfer: " << bestCopper << " | Aluminium: " << bestAluminum << std::endl;
        line();
        std::cout << "Welche Ruestungsart moechten Sie herstellen?" << std::endl;
        line();
        std::cout << "[ 0 ] ------> Zurueck" << std::endl;
        std::cout << "[ 1 ] ------> Normal" << std::endl;
        std::cout << "[ 2 ] ------> Besonders" << std::endl;
        std::cout << "[ 3 ] ------> Bestmoeglich" << std::endl;
        short input = choice();
        switch(input)
        {
            case 0:
                return;
            
            case 1:
                if (player[roundManager].scrapMetal < neededScrap) { needMaterial("Altmetall"); break;}
                if (player[roundManager].copper < neededCopper) { needMaterial("Kupfer"); break;}
                if (player[roundManager].aluminum < neededAluminum) {needMaterial("Aluminium"); break;}
                player[roundManager].scrapMetal -= neededScrap; 
                player[roundManager].realCapacity -= (neededScrap * 0.3);
                player[roundManager].copper -= neededCopper;
                player[roundManager].realCapacity -= (neededCopper * 0.2);
                player[roundManager].aluminum -= neededAluminum;
                player[roundManager].realCapacity -= (neededAluminum * 0.1);
                player[roundManager].crafted++;
                double craftedArmor = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                std::cout << "Sie haben eine normale Ruestung mit dem Wert: " << craftedArmor<< " RST hergestellt." << std::endl;
                bool dispose = capacityCheck(player, roundManager, 2.25, 1, "Ruestung");
                if (dispose == false) { std::cout << "\033[91mSie koennen die Ruestung nicht mitnehmen!\n" << std::endl; } 
                if (player[roundManager].armor[0] == 0) {player[roundManager].armor[0] = craftedArmor; break;}
                        for (int i = 0; i < 500; i++)
                        {
                            if (player[roundManager].armor[i] == 0) 
                            {
                                player[roundManager].armor[i] = craftedArmor;
                                arraySort(player, roundManager, "armor");
                                player[roundManager].realCapacity += 2.25;
                                std::cout << "Die Ruestung wurde Ihrem Inventar hinzugefuegt!" << std::endl;
                                getKey();
                                break;
                            }
                        }

            case 2:
                if (player[roundManager].scrapMetal < goodScrap) { needMaterial("Altmetall"); break;}
                if (player[roundManager].copper < goodCopper) { needMaterial("Kupfer"); break;}
                if (player[roundManager].aluminum < goodAluminum) {needMaterial("Aluminium"); break;}
                player[roundManager].scrapMetal -= goodScrap; 
                player[roundManager].realCapacity -= (goodScrap * 0.3);
                player[roundManager].copper -= neededCopper;
                player[roundManager].realCapacity -= (goodCopper * 0.2);
                player[roundManager].aluminum -= neededAluminum;
                player[roundManager].realCapacity -= (goodAluminum * 0.1);
                player[roundManager].crafted++;
                double craftedArmor = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                craftedArmor++;
                std::cout << "Sie haben eine normale Ruestung mit dem Wert: " << craftedArmor<< " RST hergestellt." << std::endl;
                bool dispose = capacityCheck(player, roundManager, 2.25, 1, "Ruestung");
                if (dispose == false) { std::cout << "\033[91mSie koennen die Ruestung nicht mitnehmen!\n" << std::endl; } 
                if (player[roundManager].armor[0] == 0) {player[roundManager].armor[0] = craftedArmor; break;}
                        for (int i = 0; i < 500; i++)
                        {
                            if (player[roundManager].armor[i] == 0) 
                            {
                                player[roundManager].armor[i] = craftedArmor;
                                arraySort(player, roundManager, "armor");
                                player[roundManager].realCapacity += 2.25;
                                std::cout << "Die Ruestung wurde Ihrem Inventar hinzugefuegt!" << std::endl;
                                getKey();
                                break;
                            }
                        }
            
            case 3:
                if (player[roundManager].scrapMetal < bestScrap) { needMaterial("Altmetall"); break;}
                if (player[roundManager].copper < bestCopper) { needMaterial("Kupfer"); break;}
                if (player[roundManager].aluminum < bestAluminum) {needMaterial("Aluminium"); break;}
                player[roundManager].scrapMetal -= bestScrap; 
                player[roundManager].realCapacity -= (bestScrap * 0.3);
                player[roundManager].copper -= bestCopper;
                player[roundManager].realCapacity -= (bestCopper * 0.2);
                player[roundManager].aluminum -= bestAluminum;
                player[roundManager].realCapacity -= (bestAluminum * 0.1);
                player[roundManager].crafted++;
                double craftedArmor = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                craftedArmor += 2;
                std::cout << "Sie haben eine normale Ruestung mit dem Wert: " << craftedArmor<< " RST hergestellt." << std::endl;
                bool dispose = capacityCheck(player, roundManager, 2.25, 1, "Ruestung");
                if (dispose == false) { std::cout << "\033[91mSie koennen die Ruestung nicht mitnehmen!\n" << std::endl; } 
                if (player[roundManager].armor[0] == 0) {player[roundManager].armor[0] = craftedArmor; break;}
                        for (int i = 0; i < 500; i++)
                        {
                            if (player[roundManager].armor[i] == 0) 
                            {
                                player[roundManager].armor[i] = craftedArmor;
                                arraySort(player, roundManager, "armor");
                                player[roundManager].realCapacity += 2.25;
                                std::cout << "Die Ruestung wurde Ihrem Inventar hinzugefuegt!" << std::endl;
                                getKey();
                                break;
                            }
                        }
            default:
                error(0);
                break;

        }
        getKey();
        running = false;
        break;
    }
    return;
}

void forge(Player player[], short roundManager, short room)
{
    bool running = true;

    while(running)
    {
        forgeMenue(player, roundManager, room);
        std::cout << "Was moechten Sie herstellen?" << std::endl;
        line();
        std::cout << "[ 0 ] ------> Zurueck" << std::endl;
        std::cout << "[ 1 ] ------> Ruestung" << std::endl;
        std::cout << "[ 2 ] ------> Waffe" << std::endl;
        short input = choice();
        switch (input)
        {
            case 0:
                running = false;
                break;
            
            case 1:
                forgeArmor(player, roundManager, room);
                break;
        }
        running = false;
        break;
    }
    return;
}

void shop(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void casinoRoyal(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void wallHole(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void darkTree(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void busStop(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void chancel(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void toiletOfLuck(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void grave(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void specialRoom(Player player[], short roundManager, int room, short danger)
{
    if (room == 5) { lever(player, roundManager, room); return; }
    if (room == 6) { chest(player, roundManager, room, danger); return; }
    if (room == 9) { forge(player, roundManager, room); return; }
    if (room == 10){ shop(player, roundManager, room); return; }
    if (room == 11){ casinoRoyal(player, roundManager, room); return; }
    if (room == 12){ wallHole(player, roundManager, room); return; }
    if (room == 13){ darkTree(player, roundManager, room); return; }
    if (room == 14){ busStop(player, roundManager, room); return; }
    if (room == 15){ chancel(player, roundManager, room); return; }
    if (room == 19){ toiletOfLuck(player, roundManager, room); return; }
    if (room == 20){ grave(player, roundManager, room); return; }
    error(0);
    return;
}
#endif

