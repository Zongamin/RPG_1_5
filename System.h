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
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Enemy.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Main.cpp>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\player.h>

/*Inhaltsverzeichnis:
      - assignment          -- Zuweisung der Werte für neue Spieler
      - charCalc            -- Charakter Rechner zum Errechnen neuer Werte bei Skillpunktverteilung
      - random              -- Zufallsgenerierte Zahlen mit Minmal und Maximal übergabe
      - getKey              -- press any key - Funktion
      - error               -- Fehlermeldung : Falsche Eingabe
      - clearScreen         -- Windows-CMD Screen leeren
      - position            -- Setzen der Cursor Position
      - miniLine            -- kleinen Trennstrich einfügen
      - line                -- Trennstrich einfügen
      - question            -- Ja/Nein - Abfrage des Spielers
      - choice              -- Zahleneingabe des Spielers (0 - 9) ohne "Enter" - Eingabe
      - condition           -- Skillpunkt ermittlung für Charactermenü 
      - lifeDisplay         -- Lebens- und Manaanzeige der Spieler
      - colorSwitch         -- Schalterfarben (Schrift mit Hintergrundfärbung) verändern
      - textColor           -- Schriftfarben verändern
      - backgroundColor     -- Verändern der Hintergrund Farbe
      - levelUp             -- Anheben von Skillpunkten, Spielerlevel & geforderten Level Exp
      - expUp               -- Anheben der Spieler Exp und Level Umbruch
      - arraySort           -- Sortierung von Waffen- und Rüstungsarrays der Spieler
      - capacityColor       -- Ermittelt den Farbwert der Traglast nach Füllstand des Inventars des Spielers in Prozent
      - weaponArmorDispose  -- Menue zur Entsorgung von Ruestungen und Waffen
      - disposeAmount       -- Menue zur Ermittlung der Anzahl der zu wegwerfenden Gegenstände
      - disposal            -- Funktion zur Entsorgung von Gegenständen für den Spieler
      - capacityCheck       -- Überprüfung und hinzufügen der Traglast des Spielers mit evtl. Übergabe an Entsorgungsfunktion für Gegenstände
      - saveGame            -- Menü zum Speichern des Spielstandes 
      - loadGame            -- Funktion zum Laden von Spielständen
      - death               -- Ausgabe des Todes des Spielers
      - trapCheck           -- Ermittelt die verbleibende Anzahl der Fallen des Spielers und löst ggf. Fallen aus
      - loot                -- Funktion für die Suche-Option des Spielers
      - textOne             -- Headline 1
      - textTwo             -- Headline 2
      - textThree           -- Headline 3
      - textFour            -- Headline 4
      - getNumber           -- Funktion zur Ermittlung und Ausgabe des Spielernummer Schriftzuges
      - dangerZone          -- Funktion zur Ermittlung der Gefahrenstufe des derzeitigen Raums
      - dangerDisplay       -- gibt die Gefahrenstufe des Raums auf den Bildschirm aus
      - trapCall            -- Ermittelt die Anzahl von Fallen in einem Raum auf Basis der Gefahrstufe des Raumes
      - trapSearch          -- Ermittelt, ob die Suche des Spielers nach einer Falle erfolgreich ist, oder sogar eine Falle auslöst
      - takeBreak           -- Ermittelt Werte beim Rasten des Spielers 
      - checkRegen          -- Ermittelt einen boolschen Wert, ob Heilung, Mana oder beides benoetigt wird
      - potionCheck         -- Ermittelt einen boolschen Wert, ob Heiltraenke, Manatraenke oder Regenerationstraenke vorhanden sind 
      - potionDrink         -- Funktion zur Heilung, Manaregeneration oder beidem durch Tränke
      - specialHeader       -- Funktion zur Anzeige der Kopfzeile "Spezial" und der Überschrift des zugehörigen Spezialraums
      - lever               -- Menü zum Spezialraum "Hebel"
      - openChest           -- Funktion zum Öffenen der Truhe zum zugehörigen "Truhe" - Spezialraums
      - chestFight          -- Funktion zum Auslösen eines Kampfes zum zugehörigen "Truhe" - Spezialraums
      - chest               -- Menü zum Spezialraum "Truhe"
      - forgeMenue          -- Funktion zur Überschrift und Anzeige der Ressourcen zum zugehörigen Spezialraum "Schmiede"
      - needMaterial        -- Funktion zur Überprüfung zum Schmieden benötigter Materialien des zugehörigen Spezialraums "Schmiede"
      - forgeWeaponArmor    -- Menü zur Herstellung verschiedener Rüstungen zum zugehörigen Spezialraum "Schmiede"
      - forge               -- Hauptmenü des Spezialraums "Schmiede"
      - headShop            -- Funktion zur Anzeige des Spielers, des Goldes und der Traglast zum zugehörigen Spezialraums "Shop"
      - shopOffer           -- Funktion zur Errechnung der Anzahl der im Spezialraum "Shop" erhältlichen Gegenstände
      - shopBuy             -- Kaufmenü des zugehörigen Spezialraums "Shop"
      - shopWeaponArmor     -- Funktion zum Erstellen der im "Shop" erhältlichen Waffen und Rüstungen
      - shopSellWeaponsArmor-- Verkaufsmenü für Waffen und Rüstungen zum zugehörigen Spezialraum "Shop"
      - shopSell            -- Menü zum Verkaufen zum zugehörigen Raum "Shop"
      - shop                -- Hauptmenü zum Spezialraum "Shop"

      - specialRoom         -- Funktion zur Ermittlung des derzeitigen Spezialraums   
    */

// Globale Variablen zum Eingrenzen von wiederholten Zufallszahlen

const int roomNumbers = 21; 
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
        case 4:
            std::cout << "\n\n\033[31mDer Haendler hat diese Ressource nicht mehr Vorraetig!\033[0m" << std::endl;
            break;
        case 5:
            std::cout << "\n\n\033[31mSie haben nicht genug Gold!\033[0m" << std::endl;
            break;
        case 6:
            std::cout << "\n\n\033[31mDer Haendler hat diesen Ausruestungsgegenstand nicht mehr Vorraetig!\033[0m" << std::endl;
            break;
        default:
            std::cout << "\n\n\033[31mUnbekannter Fehler!\033[0m" << std::endl;
            break;
    }
    getKey();
    return;
}

//Falsche cin Eingabe

void cinFail()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    error(0);
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

void hyphen(int posX, int posY)
{
    position(posX, posY); std::cout << "-------------------------------------------------------------" << std:: endl;
    return;
}

void miniLine(int posX, int posY)
{
    position(posX, posY); std::cout << "----------------------------------------------------------------------------" << std:: endl;
    return;
}

void line()
{
    std::cout << "\n--------------------------------------------------------------------------------------------------------------------------------------\n\n";
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
                std::cout << "\nBitte treffen Sie Ihre Wahl erneut... (J/N)" << std::endl;
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
            if (std::cin.fail()) { cinFail(); continue; }
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
            if (std::cin.fail()) { cinFail(); continue; }
            if (input == 0) {running = false; break;}
            if (player[roundManager].armorDmgReduce > 0 && input == -1) 
            {
                std::cout << "\n\033[41;37m[Angelegte Ruestung!]\033[0;31m Sind sie sicher? (J/N)";
                bool answer = question();
                if (answer == false) { break; }
                player[roundManager].armorDmgReduce = 0;
                player[roundManager].realCapacity -= 2.5;
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
    while (std::cin.fail()) { cinFail();std::cout << "\nBitte eine gueltige Zahl eingeben? (0 - " << maxAmount << ") "; std::cin >> amount; continue; }
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

bool capacityCheck(Player player[], short roundManager, double weight, short numberOfObjects)
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
        return;
    }
    return;
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
                    experience = round(findItem * 0.125);
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
                        experience = round(findItem * (20 + player[roundManager].luck));
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
                    experience = round(findItem * (10 + player[roundManager].luck));
                    std::cout << "\033[90mAltmetall\033[0m ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.3, findItem);
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
                    experience = round(findItem * (7.5 + player[roundManager].luck));
                    std::cout << "\033[0mAluminium\033[0m ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.1, findItem);
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
                    experience = round(findItem * (5 + player[roundManager].luck));
                    std::cout << "\033[31mKupfer\033[0m ------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.2, findItem);
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
                    experience = round(findItem * (5 + player[roundManager].luck));
                    std::cout << "\033[92mKraeuter\033[0m ----------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.1, findItem);
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
                    experience = round(findItem * (10 + player[roundManager].luck));
                    std::cout << "\033[91mHeiltraenke\033[0m -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem);
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
                    experience = round(findItem * (15 + player[roundManager].luck));
                    std::cout << "\033[94mManatraenke\033[0m -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem);
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
                    experience = round(findItem * (20 + player[roundManager].luck));
                    std::cout << "\033[95mRegenerationstraenke\033[0m ----> " << findItem << " / " << experience << " Exp." << std::endl;
                    tempExp += experience;
                    dispose = capacityCheck(player, roundManager, 0.25, findItem);
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
                        findItem = random(((player[roundManager].level + player[roundManager].luck) * 0.1), ((player[roundManager].level + player[roundManager].luck) * 0.2));
                        if (findItem < 1) { findItem = 1; }
                        experience = round(findItem * (100 + player[roundManager].luck));
                        std::cout << "\033[0mWaffe\033[0m -------------------> " << findItem << " DMG / " << experience << " Exp." << std::endl;
                        tempExp += experience;
                        dispose = capacityCheck(player, roundManager, 2.5, 1);
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
                        findItem = random(((player[roundManager].level + player[roundManager].luck) * 0.1), ((player[roundManager].level + player[roundManager].luck) * 0.2)); 
                        if (findItem < 1) { findItem = 1; }
                        experience = round(findItem * (100 + player[roundManager].luck));
                        std::cout << "\033[90mRuestung\033[0m ----------------> " << findItem << " RST / " << experience << " Exp." << std::endl;
                        tempExp += experience;
                        dispose = capacityCheck(player, roundManager, 2.25, 1);
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
    if (zone == 1)
    {
        player[roundManager].traps = 0;
    }
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
    double x = 0;
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
            if (player[roundManager].realHealth > player[roundManager].health) { player[roundManager].realHealth = player[roundManager].health; }
            std::cout << "\n\n\n\033[92mSie regenerieren " << regenH << " Hitpoints!\033[0m" << std::endl;
            player[roundManager].realCapacity -= 0.25;
            lifeDisplay(player, roundManager, 0, 21);
            getKey();
            break;
            
        case 1:
            regenM = round(random((player[roundManager].mana / 100) * 15, (player[roundManager].mana /100) * 25));
            player[roundManager].manaPotion--;
            player[roundManager].realMana += regenM;
            if (player[roundManager].realMana > player[roundManager].mana) { player[roundManager].realMana = player[roundManager].mana; }
            std::cout << "\n\n\n\033[34mSie regenerieren " << regenM << " Manapoints!\033[0m" << std::endl;
            player[roundManager].realCapacity -= 0.25;
            lifeDisplay(player, roundManager, 0, 21);
            getKey();
            break;

        case 2:
            regenH = round(random((player[roundManager].health / 100) * 10, (player[roundManager].health /100) * 20));
            regenM = round(random((player[roundManager].mana / 100) * 15, (player[roundManager].mana /100) * 20));
            player[roundManager].regenPotion--;
            player[roundManager].realHealth += regenH;
            player[roundManager].realMana += regenM;
            if (player[roundManager].realHealth > player[roundManager].health) { player[roundManager].realHealth = player[roundManager].health; }
            if (player[roundManager].realMana > player[roundManager].mana) { player[roundManager].realMana = player[roundManager].mana; }
            std::cout << "\n\n\n\033[92mSie regenerieren " << regenH << " Hitpoints!\033[0m" << std::endl;
            std::cout << "\n\033[34mSie regenerieren " << regenM << " Manapoints!\033[0m" << std::endl;
            player[roundManager].realCapacity -= 0.25;
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
    if (room == 21){ std::cout << "\033[36mBrunnen des Un... Oehoem... Gluecks\033[0m" << std::endl;}
    line();
    return;
}

void lever(Player player[], short roundManager, int room, short numberOfPlayers)
{
    specialHeader(room);
    if (player[roundManager].specialRoom == true) { std::cout << "\n\033[31mDer Hebel wurde bereits betaetigt und laesst sich jetzt nicht mehr bewegen!\033[0m" << std::endl; getKey(); return; }
    std::cout << "\nSind Sie sich sicher, das Sie den Hebel betaetigen moechten? (J/N)" << std::endl;
    bool answer = question();
    if (answer == true)
    {
        player[roundManager].specialRoom = true;
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
            std::cout << "\n\033[32m...Dennoch scheint nichts zu geschehen... nochmal Glueck gehabt?\033[0m" << std::endl;
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
            std::cout << "\n\033[32mSie finden \033[33m" << gold << " Gold\033[32m und erhalten " << experience << " EXP dafuer." << std::endl;
            player[roundManager].gold += gold;
            player[roundManager].realExp += experience;
            getKey();
            expUp(player, roundManager);
            return;
        }
        std::cout << "Sie betaetigen den Hebel, doch es geschieht nichts! Die Frage ist: Glueck, oder Pech gehabt?" << std::endl;
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
        bool dispose = capacityCheck(player, roundManager, 2.25, 1);
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
        bool dispose = capacityCheck(player, roundManager, 2.5, 1);
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
                //Kampf mit Mimik implementieren
                if (player[roundManager].permaDeath == false)
                {
                clearScreen();
                std::cout << "\n\033[32mDa Sie souveraen ueberlebt haben, koennen Sie sich jetzt auch noch ueber den Inhalt der Truhe freuen! Sie treten heran....\033[0m";
                openChest(player, roundManager);
                return;
                }
                return;
}

void chest(Player player[], short roundManager, int room, short danger)
{
    specialHeader(room);
    if (player[roundManager].specialRoom == true) { std::cout << "\033[31mDie Truhe wurde bereits geoeffnet!\033[0m" << std::endl; getKey(); return; }
    std::cout << "\nMoechten Sie die Truhe oeffnen? (J/N)" << std::endl;
    bool answer = question();
    if (answer == true)
    {
        std::cout << "\n\033[33mSie naehern sich der Truhe....\033[0m" << std::endl;

        if (danger == 1)
        {
            openChest(player, roundManager);
            player[roundManager].specialRoom = true;
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
            player[roundManager].specialRoom = true;
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
            openChest(player, roundManager);
            player[roundManager].specialRoom = true;
            return;
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
    std::cout << "\033[90mAltmetall\033[0m ---> \033[90m" << player[roundManager].scrapMetal << "\033[0m" << std::endl;
    std::cout << "\033[31mKupfer\033[0m ------> \033[31m" << player[roundManager].copper << "\033[0m" << std::endl;
    std::cout << "Aluminium ---> " << player[roundManager].aluminum << std::endl;
    line();
    return;
}

void needMaterial(std::string name)
{
    std::cout << "\033[31mSie haben zu wenig "<< name << "!\033[0m" << std::endl;
    getKey();
    return;
}

void forgeWeaponArmor(Player player[], short roundManager, short room, std::string sortOf)
{
    bool running = true;
    bool dispose = false;
    bool answer = false;
    double craftedWeaponArmor = 0;
    double experience = 0;

    while(running)
    {
        forgeMenue(player, roundManager, room);
        std::cout << "\033[90mZur Herstellung einer normalen " << sortOf << " benoetigen Sie auf Ihrem derzeitigen Level:\033[0m" << std::endl;
        double neededScrap = (round((player[roundManager].level * 5) - player[roundManager].luck));
        double neededCopper = (round((player[roundManager].level * 3) - player[roundManager].luck));
        double neededAluminum = (round((player[roundManager].level * 2) - player[roundManager].luck));
        std::cout << "Altmetall: " << neededScrap << " | Kupfer: " << neededCopper << " | Aluminium: " << neededAluminum << std::endl;
        std::cout << "\n\033[94mZur Herstellung einer besonderen " << sortOf << " benoetigen Sie auf Ihrem derzeitigen Level:\033[0m" << std::endl;
        double goodScrap = (round((player[roundManager].level * 7.5) - player[roundManager].luck));
        double goodCopper = (round((player[roundManager].level * 4.25) - player[roundManager].luck));
        double goodAluminum = (round((player[roundManager].level * 3.5) - player[roundManager].luck));
        std::cout << "Altmetall: " << goodScrap << " | Kupfer: " << goodCopper << " | Aluminium: " << goodAluminum << std::endl;
        std::cout << "\n\033[95mZur Herstellung der bestmoeglichen " << sortOf << " benoetigen Sie auf Ihrem derzeitigen Level:\033[0m" << std::endl;
        double bestScrap = (round((player[roundManager].level * 12.5) - player[roundManager].luck));
        double bestCopper = (round((player[roundManager].level * 7.5) - player[roundManager].luck));
        double bestAluminum = (round((player[roundManager].level * 5) - player[roundManager].luck));
        std::cout << "Altmetall: " << bestScrap << " | Kupfer: " << bestCopper << " | Aluminium: " << bestAluminum << std::endl;
        line();
        position(10, 38); std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck\n" << std::endl;
        position(10, 40); std::cout << "\033[100;30m[ 1 ]\033[0m ------> \033[90mNormal\n" << std::endl;
        position(45, 38); std::cout << "\033[104;30m[ 2 ]\033[0m ------> \033[94mBesonders\033[0m\n" << std::endl;
        position(45, 40); std::cout << "\033[105;30m[ 3 ]\033[0m ------> \033[95mBestmoeglich\033[0m\n" << std::endl;

        short input = choice();
        switch(input)
        {
        
            case 0:
                running = false;
                break; 
            
            case 1:
                if (player[roundManager].scrapMetal < neededScrap) { needMaterial("Altmetall"); continue; }
                if (player[roundManager].copper < neededCopper) { needMaterial("Kupfer"); continue; }
                if (player[roundManager].aluminum < neededAluminum) { needMaterial("Aluminium"); continue; }
                player[roundManager].scrapMetal -= neededScrap; 
                player[roundManager].realCapacity -= (neededScrap * 0.3);
                player[roundManager].copper -= neededCopper;
                player[roundManager].realCapacity -= (neededCopper * 0.2);
                player[roundManager].aluminum -= neededAluminum;
                player[roundManager].realCapacity -= (neededAluminum * 0.1);
                player[roundManager].crafted++;
                craftedWeaponArmor = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                if (craftedWeaponArmor < 1) { craftedWeaponArmor = 1; }
                std::cout << "Sie haben eine normale " << sortOf << " mit dem Wert: " << craftedWeaponArmor << " hergestellt." << std::endl; 
                experience = round(craftedWeaponArmor * (25 + player[roundManager].luck));
                std::cout << "dafuer erhalten Sie " << experience << " Erfahrungspunkte." << std::endl;
                player[roundManager].realExp + experience;

                if (sortOf == "Ruestung") { dispose = capacityCheck(player, roundManager, 2.25, 1); }
                if (sortOf == "Waffe"){ dispose = capacityCheck(player, roundManager, 2.5, 1);}
                if (dispose == false) 
                { 
                    std::cout << "\033[91mSie koennen die " << sortOf << " nicht mitnehmen! Aber die Erfahrungspunkte werden Ihnen dennoch gutgeschrieben.\n" << std::endl;
                    getKey();
                    expUp(player, roundManager);
                    std::cout << "\nMoechten Sie noch etwas herstellen? (J/N)" << std::endl;
                    if(answer == false) { running = false; break; }
                    continue;
                } 
                for(int i = 0; i < 500; i++)
                {
                    if (sortOf == "Ruestung")
                    {
                        if (player[roundManager].armor[i] == 0) 
                        {
                            player[roundManager].armor[i] = craftedWeaponArmor;
                            arraySort(player, roundManager, "armor");
                            player[roundManager].realCapacity += 2.25;
                            break;
                        }
                    
                    }
                    if (sortOf == "Waffe")
                    {
                        if (player[roundManager].weapons[i] == 0) 
                        {
                            player[roundManager].weapons[i] = craftedWeaponArmor;
                            arraySort(player, roundManager, "weapon");
                            player[roundManager].realCapacity += 2.5;
                            break;
                        }
                    
                    }
                }
                std::cout << "Die " << sortOf << " wurde Ihrem Inventar hinzugefuegt!" << std::endl;
                craftedWeaponArmor = 0;
                getKey();
                expUp(player, roundManager);
                std::cout << "\nMoechten Sie noch etwas herstellen? (J/N)" << std::endl;
                answer = question();
                if(answer == false) { running = false; break; }
                continue;

            case 2:
                if (player[roundManager].scrapMetal < goodScrap) { needMaterial("Altmetall"); continue; }
                if (player[roundManager].copper < goodCopper) { needMaterial("Kupfer"); continue; }
                if (player[roundManager].aluminum < goodAluminum) { needMaterial("Aluminium"); continue; }
                player[roundManager].scrapMetal -= goodScrap; 
                player[roundManager].realCapacity -= (goodScrap * 0.3);
                player[roundManager].copper -= neededCopper;
                player[roundManager].realCapacity -= (goodCopper * 0.2);
                player[roundManager].aluminum -= neededAluminum;
                player[roundManager].realCapacity -= (goodAluminum * 0.1);
                player[roundManager].crafted++;
                craftedWeaponArmor = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                if (craftedWeaponArmor < 1){ craftedWeaponArmor = 1; }
                craftedWeaponArmor++;
                std::cout << "\033[94mSie haben eine besondere " << sortOf << " mit dem Wert: " << craftedWeaponArmor<< " hergestellt.\033[0m" << std::endl;
                experience = round(craftedWeaponArmor * (25 + player[roundManager].luck));
                std::cout << "dafuer erhalten Sie " << experience << " Erfahrungspunkte." << std::endl;
                player[roundManager].realExp + experience;
                if (sortOf == "Ruestung") { dispose = capacityCheck(player, roundManager, 2.25, 1); }
                if (sortOf == "Waffe"){ dispose = capacityCheck(player, roundManager, 2.5, 1);}
                if (dispose == false) 
                { 
                    std::cout << "\033[91mSie koennen die " << sortOf << " nicht mitnehmen! Aber die Erfahrungspunkte werden Ihnen dennoch gutgeschrieben.\n" << std::endl;
                    getKey();
                    expUp(player, roundManager);
                    std::cout << "\nMoechten Sie noch etwas herstellen? (J/N)" << std::endl;
                    if(answer == false) { running = false; break; }
                    continue;
                } 
                for (int i = 0; i < 500; i++)
                {
                    if (sortOf == "Ruestung")
                    {
                        if (player[roundManager].armor[i] == 0) 
                        {
                            player[roundManager].armor[i] = craftedWeaponArmor;
                            arraySort(player, roundManager, "armor");
                            player[roundManager].realCapacity += 2.25;
                            break;
                        }
                    
                    }
                    if (sortOf == "Waffe")
                    {
                        if (player[roundManager].weapons[i] == 0) 
                        {
                            player[roundManager].weapons[i] = craftedWeaponArmor;
                            arraySort(player, roundManager, "weapon");
                            player[roundManager].realCapacity += 2.5;
                            break;
                        }
                    
                    }
                }
                std::cout << "Die " << sortOf << " wurde Ihrem Inventar hinzugefuegt!" << std::endl;
                craftedWeaponArmor = 0;
                getKey();
                expUp(player, roundManager);
                std::cout << "\nMoechten Sie noch etwas herstellen? (J/N)" << std::endl;
                answer = question();
                if(answer == false) { running = false; break; }
                continue;
                                
            case 3:
                if (player[roundManager].scrapMetal < bestScrap) { needMaterial("Altmetall"); continue; }
                if (player[roundManager].copper < bestCopper) { needMaterial("Kupfer"); continue; }
                if (player[roundManager].aluminum < bestAluminum) { needMaterial("Aluminium"); continue; }
                player[roundManager].scrapMetal -= bestScrap; 
                player[roundManager].realCapacity -= (bestScrap * 0.3);
                player[roundManager].copper -= bestCopper;
                player[roundManager].realCapacity -= (bestCopper * 0.2);
                player[roundManager].aluminum -= bestAluminum;
                player[roundManager].realCapacity -= (bestAluminum * 0.1);
                player[roundManager].crafted++;
                craftedWeaponArmor = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                if (craftedWeaponArmor < 1) { craftedWeaponArmor= 1; }
                craftedWeaponArmor += 2;
                std::cout << "\033[95mSie haben die bestmoegliche " << sortOf << " mit dem Wert: " << craftedWeaponArmor<< " hergestellt.\033[0m" << std::endl;
                experience = round(craftedWeaponArmor * (25 + player[roundManager].luck));
                std::cout << "dafuer erhalten Sie " << experience << " Erfahrungspunkte." << std::endl;
                player[roundManager].realExp + experience;
                if (sortOf == "Ruestung") { dispose = capacityCheck(player, roundManager, 2.25, 1); }
                if (sortOf == "Waffe"){ dispose = capacityCheck(player, roundManager, 2.5, 1);}
                if (dispose == false) 
                { 
                    std::cout << "\033[91mSie koennen die " << sortOf << " nicht mitnehmen! Aber die Erfahrungspunkte werden Ihnen dennoch gutgeschrieben.\n" << std::endl;
                    getKey();
                    expUp(player, roundManager);
                    std::cout << "\nMoechten Sie noch etwas herstellen? (J/N)" << std::endl;
                    if(answer == false) { running = false; break; }
                    continue;
                }
                for (int i = 0; i < 500; i++)
                {
                    if (sortOf == "Ruestung")
                    {
                        if (player[roundManager].armor[i] == 0) 
                        {
                            player[roundManager].armor[i] = craftedWeaponArmor;
                            arraySort(player, roundManager, "armor");
                            player[roundManager].realCapacity += 2.25;
                            break;
                        }
                    
                    }
                    if (sortOf == "Waffe")
                    {
                        if (player[roundManager].weapons[i] == 0) 
                        {
                            player[roundManager].weapons[i] = craftedWeaponArmor;
                            arraySort(player, roundManager, "weapon");
                            player[roundManager].realCapacity += 2.5;
                            break;
                        }
                    
                    }
                }
                std::cout << "Die " << sortOf << " wurde Ihrem Inventar hinzugefuegt!" << std::endl;
                getKey();
                expUp(player, roundManager);
                std::cout << "\nMoechten Sie noch etwas herstellen? (J/N)" << std::endl;
                answer = question();
                if(answer == false) { running = false; break; }
                continue;
        
            default:
                error(0);
                continue;
        }
        running = false;
        break;
    }
    return;
}
        
double dismantleAmount(Player player[], short roundManager, double dmg, std::string sortOf)
{
    double material = 0;

    if (sortOf == "Altmetall")
    {
        material = round((dmg * 10) + player[roundManager].luck);
        return material; 
    }
    if (sortOf == "Kupfer")
    {
        material = round((dmg * 7) + player[roundManager].luck);
        return material;
    }
    if (sortOf == "Aluminium")
    {
        material = round((dmg * 5) + player[roundManager].luck);
        return material;
    }
    error(7);
    return 0;
} 

void dismantleWeaponArmor(Player player[], short roundManager, std::string sortOf)
{
    bool running = true;
    bool answer = false;
    short counter = 0;
    short input = 0;
    double experience = 0;
    double price = 0;
    double scrapMetal = 0;
    double copper = 0;
    double aluminum = 0;

    while(running)
    {
        counter = 0;
        clearScreen();
        textDismantle();
        line();
        if (sortOf == "Waffe" && player[roundManager].weaponDmg > 0) { std::cout << "\033[100;30m[-1 ]\033[0m ------> \033[90mAngelegte Waffe\033[0m ------> \033[90m" << player[roundManager].weaponDmg << " DMG\033[0m" << std::endl; }
        if (sortOf == "Ruestung" && player[roundManager].armorDmgReduce > 0) { std::cout << "\033[100;30m[-1 ]\033[0m ------> \033[90mAngelegte Ruestung\033[0m ------> \033[90m" << player[roundManager].armorDmgReduce << " RST\033[0m" << std::endl; }
        std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
        if (sortOf == "Waffe")
        {
            for (int index = 0; index < 500; index++)
            {
                if (player[roundManager].weapons[index] == 0) { break; }
                counter++;
                std::cout << "\n\033[100;30m[ " << counter << " ]\033[0m ------> \033[90mWaffe\033[0m ------> \033[90m" << player[roundManager].weapons[index] << " DMG\033[0m" << std::endl;
            }
        }
        if (sortOf == "Ruestung")
        {
            for (int index = 0; index < 500; index++)
            {
                if (player[roundManager].weapons[index] == 0) { break; }
                counter++;
                std::cout << "\n\033[100;30m[ " << counter << " ]\033[0m ------> \033[90mRuestung\033[0m ------> \033[90m" << player[roundManager].armor[index] << " RST\033[0m" << std::endl;
            }
        }
        line();
        std::cout << "\033[91mWelche " << sortOf << " moechten Sie zerlegen?"; std::cin >> input;
        if (std::cin.fail()) { cinFail(); continue; }
        if (input == 0) { running = false; break; }
        if (input > counter) { error(0); continue; }
        if (input == -1 && sortOf == "Waffe") 
        { 
            if (player[roundManager].weaponDmg <= 0) { error(0); continue; };
            scrapMetal = dismantleAmount(player, roundManager, player[roundManager].weaponDmg, "Altmetall");
            copper = dismantleAmount(player, roundManager, player[roundManager].weaponDmg, "Kupfer");
            aluminum = dismantleAmount(player, roundManager, player[roundManager].weaponDmg, "Aluminium");
            experience = round(player[roundManager].weaponDmg * 25);
            std::cout << "\nFuer das Zerlegen dieser Waffe erhalten Sie: \033[90m" << scrapMetal << " Altmetall \033[0m| \033[31m" << copper << "Kupfer \033[0m| " << aluminum << " Aluminium." << std::endl;
            std::cout << "\nDesweiteren erhalten Sie fuer das Zerlegen " << experience << " Erfahrungspunkte." << std::endl;
            std::cout << "\n\033[91mSind Sie sicher, dass Sie Ihre angelegte Waffe zerlegen moechten? (J/N)\033[0m" << std::endl;
            answer = question();
            if (answer == false) { break; }
            player[roundManager].realCapacity -= 2.5;
            player[roundManager].scrapMetal += scrapMetal;
            player[roundManager].copper += copper;
            player[roundManager].aluminum += aluminum;
            player[roundManager].weaponDmg = 0;
            player[roundManager].realExp += experience;
            std::cout << "\nDie Waffe wurde zerlegt. Sie haben das Material und die Erfahrungspunkte erhalten." << std::endl;
            getKey();
            expUp(player, roundManager);
            std::cout << "\nMoechten Sie noch eine Waffe zerlegen? (J/N)" << std::endl;
            answer = question();
            if (answer == false) { break; } 
            continue; 
        }
        if (input == -1 && sortOf == "Ruestung")
        { 
            if (player[roundManager].armorDmgReduce <= 0) { error(0); continue; };
            scrapMetal = dismantleAmount(player, roundManager, player[roundManager].armorDmgReduce, "Altmetall");
            copper = dismantleAmount(player, roundManager, player[roundManager].armorDmgReduce, "Kupfer");
            aluminum = dismantleAmount(player, roundManager, player[roundManager].armorDmgReduce, "Aluminium");
            experience = round(player[roundManager].armorDmgReduce * 25);
            std::cout << "\nFuer das Zerlegen dieser Ruestung erhalten Sie: \033[90m" << scrapMetal << " Altmetall \033[0m| \033[31m" << copper << "Kupfer \033[0m| " << aluminum << " Aluminium." << std::endl;
            std::cout << "\nDesweiteren erhalten Sie fuer das Zerlegen " << experience << " Erfahrungspunkte." << std::endl;
            std::cout << "\n\033[91mSind Sie sicher, dass Sie Ihre angelegte Ruestung zerlegen moechten? (J/N)\033[0m" << std::endl;
            answer = question();
            if (answer == false) { break; }
            player[roundManager].realCapacity -= 2.25;
            player[roundManager].scrapMetal += scrapMetal;
            player[roundManager].copper += copper;
            player[roundManager].aluminum += aluminum;
            player[roundManager].weaponDmg = 0;
            player[roundManager].realExp += experience;
            std::cout << "\nDie Ruestung wurde zerlegt. Sie haben das Material und die Erfahrungspunkte erhalten." << std::endl;
            getKey();
            expUp(player, roundManager);
            std::cout << "\nMoechten Sie noch eine Ruestung zerlegen? (J/N)" << std::endl;
            answer = question();
            if (answer == false) { break; } 
            continue; 
        }
        if (sortOf == "Waffe")
        { 
            if (player[roundManager].weapons[input - 1] <= 0) { error(0); continue; };
            scrapMetal = dismantleAmount(player, roundManager, player[roundManager].weapons[input - 1], "Altmetall");
            copper = dismantleAmount(player, roundManager, player[roundManager].weapons[input - 1], "Kupfer");
            aluminum = dismantleAmount(player, roundManager, player[roundManager].weapons[input -1], "Aluminium");
            experience = round(player[roundManager].weapons[input -1] * 25);
            std::cout << "\nFuer das Zerlegen dieser Waffe erhalten Sie: \033[90m" << scrapMetal << " Altmetall \033[0m| \033[31m" << copper << "Kupfer \033[0m| " << aluminum << " Aluminium." << std::endl;
            std::cout << "\nDesweiteren erhalten Sie fuer das Zerlegen " << experience << " Erfahrungspunkte." << std::endl;
            std::cout << "\n\033[91mSind Sie sicher, dass Sie Ihre angelegte Waffe zerlegen moechten? (J/N)\033[0m" << std::endl;
            answer = question();
            if (answer == false) { break; }
            player[roundManager].realCapacity -= 2.5;
            player[roundManager].scrapMetal += scrapMetal;
            player[roundManager].copper += copper;
            player[roundManager].aluminum += aluminum;
            player[roundManager].weapons[input -1] = 0;
            arraySort(player, roundManager, "weapon");
            player[roundManager].realExp += experience;
            std::cout << "\nDie Waffe wurde zerlegt. Sie haben das Material und die Erfahrungspunkte erhalten." << std::endl;
            getKey();
            expUp(player, roundManager);
            std::cout << "\nMoechten Sie noch eine Waffe zerlegen? (J/N)" << std::endl;
            answer = question();
            if (answer == false) { break; } 
            continue; 
        }
        if (sortOf == "Ruestung")
        { 
            if (player[roundManager].armor[input -1] <= 0) { error(0); continue; };
            scrapMetal = dismantleAmount(player, roundManager, player[roundManager].armor[input -1], "Altmetall");
            copper = dismantleAmount(player, roundManager, player[roundManager].armor[input -1], "Kupfer");
            aluminum = dismantleAmount(player, roundManager, player[roundManager].armor[input -1], "Aluminium");
            experience = round(player[roundManager].armor[input - 1] * 25);
            std::cout << "\nFuer das Zerlegen dieser Ruestung erhalten Sie: \033[90m" << scrapMetal << " Altmetall \033[0m| \033[31m" << copper << "Kupfer \033[0m| " << aluminum << " Aluminium." << std::endl;
            std::cout << "\nDesweiteren erhalten Sie fuer das Zerlegen " << experience << " Erfahrungspunkte." << std::endl;
            std::cout << "\n\033[91mSind Sie sicher, dass Sie Ihre angelegte Ruestung zerlegen moechten? (J/N)\033[0m" << std::endl;
            answer = question();
            if (answer == false) { break; }
            player[roundManager].realCapacity -= 2.25;
            player[roundManager].scrapMetal += scrapMetal;
            player[roundManager].copper += copper;
            player[roundManager].aluminum += aluminum;
            player[roundManager].armor[input -1] = 0;
            arraySort(player, roundManager, "armor");
            player[roundManager].realExp += experience;
            std::cout << "\nDie Ruestung wurde zerlegt. Sie haben das Material und die Erfahrungspunkte erhalten." << std::endl;
            getKey();
            expUp(player, roundManager);
            std::cout << "\nMoechten Sie noch eine Ruestung zerlegen? (J/N)" << std::endl;
            answer = question();
            if (answer == false) { break; } 
            continue; 
        }
         
    }
}

void dismantleMenue(Player player[], short roundManager)
{
    bool running = true;

    while(running)
    {
        clearScreen();
        textDismantle();
        line();
        std::cout << "\033[91mWas moechten Sie zerlegen?\033[0m" << std::endl;
        line();
        std::cout << "\033[47;30m[ 1 ]\033[0m ------> Ruestung" << std::endl;
        std::cout << "\033[100;30m[ 2 ]\033[0m ------> \033[90mWaffe\033[0m" << std::endl;
        std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
        line();
        short input = choice();

        switch(input)
        {
            case 0:
                running = false;
                break;

            case 1:
                dismantleWeaponArmor(player, roundManager, "Waffe");
                break;

            case 2:
                dismantleWeaponArmor(player, roundManager, "Ruestung");
                break;

            default:
                error(0);
                continue;
        }
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
        std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck\n" << std::endl;
        std::cout << "\033[100;30m[ 1 ]\033[0m ------> \033[90mRuestung\033[0m\n" << std::endl;
        std::cout << "\033[47;30m[ 2 ]\033[0m ------> Waffe\n" << std::endl;
        std::cout << "\033[101;30[ 3 ]\033[0m ------> \033[91mZerlegen\033[0m" << std::endl;
        short input = choice();
        switch (input)
        {
            case 0:
                running = false;
                break;
            
            case 1:
                forgeWeaponArmor(player, roundManager, room, "Ruestung");
                break;
            
            case 2: 
                forgeWeaponArmor(player, roundManager, room, "Waffe");
                break;

            case 3:
                dismantleMenue(player, roundManager);
                break;
            
            default:
                error(0);
                break;
        }
        running = false;
        break;
    }
    return;
}

void headShop(Player player[], short roundManager)
{
    std::cout << "\033[36mSpieler: " << player[roundManager].getName();
    position(40, 16); std::cout << "\033[33mGold: " << player[roundManager].gold << "\033[0m";
    capacityColor(player, roundManager); position(80, 16); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
    line();
    return;
}

int shopOffer(Player player[], short roundManager)
{
    int offer = 0;
    offer = random(0, round(player[roundManager].level + player[roundManager].luck));
    if (offer > 100) { offer = 100; } 
    return offer;
}

double shopWeaponArmor(Player player[], short roundManager)
{
    double damage = 0;
    short factor = 0;
    factor = random(0, 2);
    damage = random(((player[roundManager].level + player[roundManager].luck) * 0.1), ((player[roundManager].level + player[roundManager].luck) * 0.2));
    if (damage < 1) { damage = 1; }
    return damage;
}

void shopBuy(Player player[], short roundManager)
{
    bool running = true;
    bool answer = false;
    bool dispose = false;
    int counter = 0;
    static int dealerScrap;
    static int dealerCopper;
    static int dealerAluminum;
    static int dealerHerbs;
    static int dealerHealth;
    static int dealerMana;
    static int dealerRegen;
    static int dealerWeapon;
    static int dealerArmor;

    if (player[roundManager].specialRoom == false)
    {
    dealerScrap = shopOffer(player, roundManager);
    dealerCopper = shopOffer(player, roundManager);
    dealerAluminum = shopOffer(player, roundManager);
    dealerHerbs = shopOffer(player, roundManager);
    dealerHealth = shopOffer(player, roundManager);
    dealerMana = shopOffer(player, roundManager);
    dealerRegen = shopOffer(player, roundManager);
    dealerWeapon = shopWeaponArmor(player, roundManager);
    dealerArmor = shopWeaponArmor(player, roundManager);
    player[roundManager].specialRoom = true;
    }
    while(running)
    {
        specialHeader(player[roundManager].currentRoom);
        headShop(player, roundManager);
        std::cout << "Der Haendler hat folgende Angebote:" << std::endl;
        line();
        std::cout << "\033[100;30m[ 1 ]\033[0m ------> \033[90mAltmetall\033[0m ------------- Anzahl: " << dealerScrap << " \033[93m30 Gold\033[0m / Einheit\n" << std::endl;
        std::cout << "\033[41;37m[ 2 ]\033[0m ------> \033[31mKupfer\033[0m ---------------- Anzahl: " << dealerCopper << " \033[93m45 Gold\033[0m / Einheit\n" << std::endl;
        std::cout << "\033[47;30m[ 3 ]\033[0m ------> Aluminium ------------- Anzahl: " << dealerAluminum << " \033[93m60 Gold\033[0m / Einheit\n" << std::endl;
        std::cout << "\033[42;37m[ 4 ]\033[0m ------> \033[32mKraeuter\033[0m -------------- Anzahl: " << dealerHerbs << " \033[93m75 Gold\033[0m / Einheit\n" << std::endl;
        std::cout << "\033[101;37m[ 5 ]\033[0m ------> \033[91mHeiltraenke\033[0m ----------- Anzahl: " << dealerHealth << " \033[93m45 Gold\033[0m / Einheit\n" << std::endl;
        std::cout << "\033[44;37m[ 6 ]\033[0m ------> \033[34mManatraenke\033[0m ----------- Anzahl: " << dealerMana << " \033[93m60 Gold\033[0m / Einheit\n" << std::endl;
        std::cout << "\033[45;37m[ 7 ]\033[0m ------> \033[35mRegenerationstraenke\033[0m -- Anzahl: " << dealerRegen << " \033[93m75 Gold\033[0m / Einheit\n" << std::endl;
        std::cout << "\033[100;30m[ 8 ]\033[0m ------> \033[90mWaffe\033[0m ----------------- DMG   : " << dealerWeapon << " \033[93m" << (dealerWeapon * 150) << " Gold\033[0m\n" << std::endl;
        std::cout << "\033[47;30m[ 9 ]\033[0m ------> Ruestung -------------- RST   : " << dealerArmor << " \033[93m" << (dealerArmor * 150) << " Gold\033[0m\n" << std::endl;
        std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
        line();
        short input = choice();
        switch (input)
        {
            case 0:
                running = false;
                break;

            case 1:
                if (dealerScrap <= 0) { error(4); break; }
                std::cout << "Wie viele Einheiten Altmetall moechten Sie kaufen? (0 - " << dealerScrap << ") " << std::endl;
                while (!(std::cin >> counter) || counter < 0 || counter > dealerScrap) 
                {
                error(0);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
                }
                if (counter == 0) { break; }
                if ((counter * 30) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 0.3, counter);
                if (dispose == false) 
                {
                    std::cout << "\033[91m\nAus Platzmangel koennen Sie das Altmetall nicht kaufen!\033[0m" << std::endl;
                    getKey();
                    break;
                }
                std::cout << "\033[92m\nSie haben " << counter << " Einheiten Altmetall fuer \033[93m" << (counter * 30) << " Gold\033[92m gekauft.\033[0m" << std::endl;
                dealerScrap -= counter;
                player[roundManager].scrapMetal += counter;
                player[roundManager].gold -= (counter * 30);
                player[roundManager].realCapacity += (counter * 0.3);
                std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                break;

            case 2:
                if (dealerCopper <= 0) { error(4); break; }
                std::cout << "Wie viele Einheiten Kupfer moechten Sie kaufen? (0 - " << dealerCopper << ") ";
                while (!(std::cin >> counter) || counter < 0 || counter > dealerCopper) 
                {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                error(0);
                continue;
                }
                if (counter == 0) { break; }
                if ((counter * 45) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 0.2, counter);
                if (dispose == false) 
                {
                    std::cout << "\033[91m\nAus Platzmangel koennen Sie das Kupfer nicht kaufen!\033[0m" << std::endl;
                    getKey();
                    break;
                }
                std::cout << "\033[92m\nSie haben " << counter << " Einheiten Kupfer fuer \033[93m" << (counter * 45) << " Gold\033[92m gekauft.\033[0m" << std::endl;
                dealerCopper -= counter;
                player[roundManager].copper += counter;
                player[roundManager].gold -= (counter * 45);
                player[roundManager].realCapacity += (counter * 0.2);
                std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                break;

            case 3:
                if (dealerAluminum <= 0) { error(4); break; }
                std::cout << "Wie viele Einheiten Aluminium moechten Sie kaufen? (0 - " << dealerAluminum << ") ";
                while (!(std::cin >> counter) || counter < 0 || counter > dealerAluminum) 
                {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                error(0);
                continue;
                }
                if (counter == 0) { break; }
                if ((counter * 60) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 0.1, counter);
                if (dispose == false) 
                {
                    std::cout << "\033[91m\nAus Platzmangel koennen Sie das Aluminium nicht kaufen!\033[0m" << std::endl;
                    getKey();
                    break;
                }
                std::cout << "\033[92m\nSie haben " << counter << " Einheiten Aluminium fuer \033[93m" << (counter * 60) << " Gold\033[92m gekauft.\033[0m" << std::endl;
                dealerAluminum -= counter;
                player[roundManager].aluminum += counter;
                player[roundManager].gold -= (counter * 60);
                player[roundManager].realCapacity += (counter * 0.1);
                std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                break;

            case 4:
                if (dealerHerbs <= 0) { error(4); break; }
                std::cout << "Wie viele Einheiten Kraeuter moechten Sie kaufen? (0 - " << dealerHerbs << ") ";
                while (!(std::cin >> counter) || counter < 0 || counter > dealerHerbs) 
                {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                error(0);
                continue;
                }
                if (counter == 0) { break; }
                if ((counter * 75) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 0.3, counter);
                if (dispose == false) 
                {
                    std::cout << "\033[91m\nAus Platzmangel koennen Sie die Kraeuter nicht kaufen!\033[0m" << std::endl;
                    getKey();
                    break;
                }
                std::cout << "\033[92m\nSie haben " << counter << " Einheiten Kraeuter fuer \033[93m" << (counter * 75) << " Gold\033[92m gekauft.\033[0m" << std::endl;
                dealerHerbs -= counter;
                player[roundManager].herbs += counter;
                player[roundManager].gold -= (counter * 75);
                player[roundManager].realCapacity += (counter * 0.1);
                std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                break;
            
            case 5:
                if (dealerHealth <= 0) { error(4); break; }
                std::cout << "Wie viele Einheiten Heiltraenke moechten Sie kaufen? (0 - " << dealerHealth << ") ";
                while (!(std::cin >> counter) || counter < 0 || counter > dealerHealth) 
                {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                error(0);
                continue;
                }
                if (counter == 0) { break; }
                if ((counter * 45) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 0.25, counter);
                if (dispose == false) 
                {
                    std::cout << "\033[91m\nAus Platzmangel koennen Sie die Heiltraenke nicht kaufen!\033[0m" << std::endl;
                    getKey();
                    break;
                }
                std::cout << "\033[92m\nSie haben " << counter << " Einheiten Heiltraenke fuer \033[93m" << (counter * 45) << " Gold\033[92m gekauft.\033[0m" << std::endl;
                dealerHealth -= counter;
                player[roundManager].healthPotion += counter;
                player[roundManager].gold -= (counter * 45);
                player[roundManager].realCapacity += (counter * 0.25);
                std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                break;

            case 6:
                if (dealerMana <= 0) { error(4); break; }
                std::cout << "Wie viele Einheiten Manatraenke moechten Sie kaufen? (0 - " << dealerMana << ") ";
                while (!(std::cin >> counter) || counter < 0 || counter > dealerMana) 
                {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                error(0);
                continue;
                }
                if (counter == 0) { break; }
                if ((counter * 60) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 0.25, counter);
                if (dispose == false) 
                {
                    std::cout << "\033[91m\nAus Platzmangel koennen Sie die Manatraenke nicht kaufen!\033[0m" << std::endl;
                    getKey();
                    break;
                }
                std::cout << "\033[92m\nSie haben " << counter << " Einheiten Manatraenke fuer \033[93m" << (counter * 60) << " Gold\033[92m gekauft.\033[0m" << std::endl;
                dealerMana -= counter;
                player[roundManager].manaPotion += counter;
                player[roundManager].gold -= (counter * 60);
                player[roundManager].realCapacity += (counter * 0.25);
                std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                break;
            
            case 7:
                if (dealerRegen <= 0) { error(4); break; }
                std::cout << "Wie viele Einheiten Regenerationstraenke moechten Sie kaufen? (0 - " << dealerRegen << ") ";
                while (!(std::cin >> counter) || counter < 0 || counter > dealerRegen) 
                {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                error(0);
                continue;
                }
                if (counter == 0) { break; }
                if ((counter * 75) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 0.25, counter);
                if (dispose == false) 
                {
                    std::cout << "\033[91m\nAus Platzmangel koennen Sie die Regenerationstraenke nicht kaufen!\033[0m" << std::endl;
                    getKey();
                    break;
                }
                std::cout << "\033[92m\nSie haben " << counter << " Einheiten Regenerationstraenke fuer \033[93m" << (counter * 75) << " Gold\033[92m gekauft.\033[0m" << std::endl;
                dealerRegen -= counter;
                player[roundManager].regenPotion += counter;
                player[roundManager].gold -= (counter * 75);
                player[roundManager].realCapacity += (counter * 0.25);
                std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                break;
            
            case 8:
                if (dealerWeapon <= 0) { error(6); break; }
                std::cout << "Sind Sie sicher, dass Sie die Waffe kaufen moechten? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { break; }
                if ((dealerWeapon * 150) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 2.5, 1);
                if (dispose == false) { std::cout << "\033[91mSie koennen die Waffe nicht kaufen, da Sie nicht genuegend Inventarplatz haben!\033[0m" << std::endl; break; }
                for (int i = 0; i < 500; i++)
                {
                    if (player[roundManager].weapons[i] == 0) 
                    {
                        player[roundManager].weapons[i] = dealerWeapon;
                        player[roundManager].gold -= (dealerWeapon * 150);
                        player[roundManager].realCapacity += 2.5;
                        arraySort(player, roundManager, "weapon");
                        std::cout << "\033[92mDie Waffe wurde fuer \033[93m" << (dealerWeapon * 150) << " Gold\033[92m Ihrem Inventar hinzugefuegt!\033[0m" << std::endl;
                        dealerWeapon = 0;
                        std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                        answer = question();
                        if (answer == false) { running = false; break; }
                        break;
                    }                        
                }
                break;

            case 9:
                if (dealerArmor <= 0) { error(6); break; }
                std::cout << "Sind Sie sicher, dass Sie die Ruestung kaufen moechten? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { break; }
                if ((dealerArmor * 150) > player[roundManager].gold) { error(5); break; }
                dispose = capacityCheck(player, roundManager, 2.25, 1);
                if (dispose == false) { std::cout << "\033[91mSie koennen die Ruestung nicht kaufen, da Sie nicht genuegend Inventarplatz haben!\n" << std::endl; break; }
                for (int i = 0; i < 500; i++)
                {
                    if (player[roundManager].armor[i] == 0) 
                    {
                        player[roundManager].armor[i] = dealerArmor;
                        player[roundManager].gold -= (dealerArmor * 150);
                        player[roundManager].realCapacity += 2.25;
                        arraySort(player, roundManager, "armor");
                        std::cout << "\033[92mDie Ruestung wurde fuer \033[93m" << (dealerArmor * 150) << " Gold\033[92m Ihrem Inventar hinzugefuegt!\033[0m" << std::endl;
                        dealerArmor = 0;
                        std::cout << "Moechten Sie noch etwas kaufen? (J/N)" << std::endl;
                        answer = question();
                        if (answer == false) { running = false; break; }
                        break;
                    }                        
                }
                break;

            default:
                error(0);
                break;    
        } 
    }
    return;
}

void shopSellWeaponsArmor(Player player[], short roundManager, std::string sortOf)
{
    bool running = true;
    bool answer = false;
    double sellingPrice = 0;
    short counter = 0;
    short input = 0;

    while(running)
    {
        specialHeader(player[roundManager].currentRoom);
        headShop(player, roundManager);
        if (player[roundManager].weaponDmg > 0 && sortOf == "Waffe" || player[roundManager].armorDmgReduce > 0 && sortOf == "Ruestung") 
        {
            sellingPrice = 0;
            if (sortOf == "Waffe") { sellingPrice = round((player[roundManager].weaponDmg * 50) + player[roundManager].luck); }
            if (sortOf == "Ruestung") { sellingPrice = round((player[roundManager].armorDmgReduce * 50) + player[roundManager].luck); }
            std::cout << "\033[100;30m[-1 ]\033[0m ------> \033[90mAngelegte " << sortOf << "\033[0m ------> ";
            if (sortOf == "Waffe") { std::cout << player[roundManager].weaponDmg << " DMG ------> Verkaufspreis: \033[93m" << sellingPrice << " Gold\033[0m" << std::endl; }
            if (sortOf == "Ruestung") { std::cout << player[roundManager].armorDmgReduce << " RST ------> Verkaufspreis: \033[93m" << sellingPrice << " Gold\033[0m" << std::endl; }
        }
        std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
        if (player[roundManager].weapons[0] > 0 && sortOf == "Waffe" || player[roundManager].armor[0] > 0 && sortOf == "Ruestung")
        {
            sellingPrice = 0;
            if (sortOf == "Waffe") { sellingPrice = round((player[roundManager].weapons[0] * 50) + player[roundManager].luck); }
            if (sortOf == "Ruestung") { sellingPrice = round((player[roundManager].armor[0] * 50) + player[roundManager].luck); }
            std::cout << "\033[100;30m[ 1 ]\033[0m ------> \033[90m" << sortOf << "\033[0m ------> ";
            if (sortOf == "Waffe") { std::cout << player[roundManager].weapons[0] << " DMG ------> Verkaufspreis: \033[93m" << sellingPrice << " Gold\033[0m" << std::endl; }
            if (sortOf == "Ruestung") { std::cout << player[roundManager].armor[0] << " RST ------> Verkaufspreis: \033[93m" << sellingPrice << " Gold\033[0m" << std::endl; }
        }
        counter = 0;
        if (sortOf == "Waffe")
        {
            for (int index = 0; index < 500; index++)
            {
                if (player[roundManager].weapons[index] == 0) { break; }
                sellingPrice = 0;
                sellingPrice = round((player[roundManager].weapons[index] * 50) + player[roundManager].luck);
                std::cout << "\033[100;30m[ " << index + 1 << " ]\033[0m ------> \033[90mWaffe\033[0m ------> " << player[roundManager].weapons[index] << " DMG ------> Verkaufspreis: \033[93m" << sellingPrice << " Gold\033[0m\n" << std::endl;
                counter++;
            }
        }
        if (sortOf == "Ruestung")
        {
            for (int index = 0; index < 500; index++)
            {
                if (player[roundManager].armor[index] == 0) { break; }
                sellingPrice = 0;
                sellingPrice = round((player[roundManager].armor[index] * 50) + player[roundManager].luck);
                std::cout << "\033[100;30m[ " << index + 1 << " ]\033[0m ------> \033[90mRuestung\033[0m ------> " << player[roundManager].armor[index] << " RST ------> Verkaufspreis: \033[93m" << sellingPrice << " Gold\033[0m\n" << std::endl;
                counter++;
            }
        }
        line();
        std::cout << "Welche " << sortOf << " moechten Sie verkaufen?" << std::endl; std::cin >> input; 
        if (std::cin.fail()) { cinFail(); continue; }
        if (input == 0) { running = false; break; }
        if (sortOf == "Waffe")
        {
            if (input - 1 > counter || input < -1 || input == -1 && player[roundManager].weaponDmg == 0) { std::cout << "Das geht nicht!" << std::endl; getKey(); continue; }
            if (input == -1 && player[roundManager].weaponDmg > 0)
            {
                std::cout << "Sind Sie sicher, dass Sie Ihre angelegte Waffe verkaufen moechten? (J/N)" << std::endl;
                answer = question();
                if(answer == true) 
                {
                    sellingPrice = round((player[roundManager].weaponDmg * 50) + player[roundManager].luck);
                    player[roundManager].weaponDmg = 0;
                    player[roundManager].realCapacity -= 2.5;
                    player[roundManager].gold += sellingPrice;
                    std::cout << "Ihre angelegte Waffe wurde fuer " << sellingPrice << " Gold verkauft." << std::endl;
                    std::cout << "Moechten Sie noch eine Waffe verkaufen? (J/N)" << std::endl;
                    answer = question();
                    if (answer == true) { break; }
                    running = false;
                    break; 
                }
            }
            std::cout << "Sind Sie sicher, dass Sie die ausgewaehlte Waffe verkaufen moechten? (J/N)" << std::endl;
            answer = question();
            if (answer == false) { break; }
            sellingPrice = round((player[roundManager].weapons[input - 1] * 50) + player[roundManager].luck);
            player[roundManager].weapons[input - 1] = 0;
            player[roundManager].realCapacity -= 2.5;
            player[roundManager].gold += sellingPrice;
            arraySort(player, roundManager, "weapon");
            std::cout << "Die ausgewaehlte Waffe wurde fuer " << sellingPrice << " Gold verkauft." << std::endl;
            std::cout << "Moechten Sie noch eine Waffe verkaufen? (J/N)" << std::endl;
            answer = question();
            if (answer == true) { break; }
            running = false;
            break; 
        }
        if (sortOf == "Ruestung")
        {
            if (input - 1 > counter || input < -1 || input == -1 && player[roundManager].armorDmgReduce == 0) { std::cout << "Das geht nicht!" << std::endl; getKey(); continue; }
            if (input == -1 && player[roundManager].armorDmgReduce > 0)
            {
                std::cout << "Sind Sie sicher, dass Sie Ihre angelegte Ruestung verkaufen moechten? (J/N)" << std::endl;
                answer = question();
                if(answer == true) 
                {
                    sellingPrice = round((player[roundManager].armorDmgReduce * 50) + player[roundManager].luck);
                    player[roundManager].armorDmgReduce = 0;
                    player[roundManager].realCapacity -= 2.25;
                    player[roundManager].gold += sellingPrice;
                    std::cout << "Ihre angelegte Ruestung wurde fuer " << sellingPrice << " Gold verkauft." << std::endl;
                    std::cout << "Moechten Sie noch eine Ruestung verkaufen? (J/N)" << std::endl;
                    answer = question();
                    if (answer == true) { break; }
                    running = false;
                    break; 
                }
            }
            std::cout << "\033[31mSind Sie sicher, dass Sie die ausgewaehlte Ruestung verkaufen moechten? (J/N)\033[0m" << std::endl;
            answer = question();
            if (answer == false) { break; }
            sellingPrice = round((player[roundManager].armor[input - 1] * 50) + player[roundManager].luck);
            player[roundManager].armor[input - 1] = 0;
            player[roundManager].realCapacity -= 2.25;
            player[roundManager].gold += sellingPrice;
            arraySort(player, roundManager, "armor");
            std::cout << "Die ausgewaehlte Ruestung wurde fuer " << sellingPrice << " Gold verkauft." << std::endl;
            std::cout << "Moechten Sie noch eine Ruestung verkaufen? (J/N)" << std::endl;
            answer = question();
            if (answer == true) { break; }
            running = false;
            break;
        }
        error(0);
        return;
    }
}

void shopSell(Player player[], short roundManager)
{
    bool running = true;
    bool answer = false;
    double counter = 0;
    double armorAmount = 0;
    double weaponAmount = 0;
        
    while (running)
    {
        armorAmount = 0;
        weaponAmount = 0;

        for(int index = 0; player[roundManager].armor[index] < 500; index++)
        {
            if (player[roundManager].armor[index] == 0) { break; }
            armorAmount++;
        }
        for(int index = 0; player[roundManager].weapons[index] < 500; index++)
        {
            if (player[roundManager].weapons[index] == 0) { break; }
            weaponAmount++;
        }
        if (player[roundManager].armorDmgReduce > 0) { armorAmount++; }
        if (player[roundManager].weaponDmg > 0) { weaponAmount++; }

        specialHeader(player[roundManager].currentRoom);
        headShop(player, roundManager);
        std::cout << "Was moechten Sie verkaufen? Ihr Inventar:" << std::endl;
        line();
        std::cout << "\033[100;30m[ 1 ]\033[0m ------> \033[90mAltmetall\033[0m -------------> " << player[roundManager].scrapMetal << " Einheiten (\033[93m10 Gold\033[0m / Einheit)\n" << std::endl;
        std::cout << "\033[41;37m[ 2 ]\033[0m ------> \033[31mKupfer\033[0m ----------------> " << player[roundManager].copper << " Einheiten (\033[93m15 Gold\033[0m / Einheit)\n" << std::endl;
        std::cout << "\033[47;30m[ 3 ]\033[0m ------> Aluminium -------------> " << player[roundManager].aluminum << " Einheiten (\033[93m20 Gold\033[0m / Einheit)\n" << std::endl;
        std::cout << "\033[42;37m[ 4 ]\033[0m ------> \033[32mKraeuter\033[0m --------------> " << player[roundManager].herbs << " Einheiten (\033[93m25 Gold\033[0m / Einheit)\n" << std::endl;
        std::cout << "\033[101;37m[ 5 ]\033[0m ------> \033[91mHeiltraenke\033[0m -----------> " << player[roundManager].healthPotion << " Einheiten (\033[93m15 Gold\033[0m / Einheit)\n" << std::endl;
        std::cout << "\033[44;37m[ 6 ]\033[0m ------> \033[34mManatraenke\033[0m -----------> " << player[roundManager].manaPotion << " Einheiten (\033[93m20 Gold\033[0m / Einheit)\n" << std::endl;
        std::cout << "\033[45;37m[ 7 ]\033[0m ------> \033[35mRegenerationstraenke\033[0m --> " << player[roundManager].regenPotion << " Einheiten (\033[93m25 Gold\033[0m / Einheit)\n" << std::endl;
        std::cout << "\033[100;30m[ 8 ]\033[0m ------> \033[90mWaffen\033[0m ----------------> " << weaponAmount << " Einheiten (Preis nach Schaden)\n" << std::endl;
        std::cout << "\033[47;30m[ 9 ]\033[0m ------> Ruestungen ------------> " << armorAmount << " Einheiten (Preis nach Ruestwert)\n" << std::endl;
        std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
        line();
        short input = choice();
        switch (input)
        {
            case 0:
                running = false;
                break;

            case 1:
                std::cout << "Wie viele Einheiten Altmetall sollen verkauft werden? (0 - " << player[roundManager].scrapMetal << ")"; std::cin >> counter;
                if (std::cin.fail()) { cinFail(); continue; }
                if (counter <= 0) { continue; }
                if (counter > player[roundManager].scrapMetal) { std::cout << "Das geht nicht!"; getKey(); continue; }
                player[roundManager].scrapMetal -= counter;
                player[roundManager].gold += (counter * 10);
                player[roundManager].realCapacity -= (counter * 0.3);
                std::cout << "Sie haben " << counter << " Einheiten Altmetall fuer insgesamt " << (counter * 10) << " Gold verkauft." << std::endl;
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);

            case 2:
                std::cout << "Wie viele Einheiten Kupfer sollen verkauft werden? (0 - " << player[roundManager].copper << ")"; std::cin >> counter;
                if (std::cin.fail()) { cinFail(); continue; }
                if (counter <= 0) { continue; }
                if (counter > player[roundManager].copper) { std::cout << "Das geht nicht!"; getKey(); continue; }
                player[roundManager].copper -= counter;
                player[roundManager].gold += (counter * 15);
                player[roundManager].realCapacity -= (counter * 0.2);
                std::cout << "Sie haben " << counter << " Einheiten Kupfer fuer insgesamt " << (counter * 15) << " Gold verkauft." << std::endl;
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);
            
            case 3:
                std::cout << "Wie viele Einheiten Aluminium sollen verkauft werden? (0 - " << player[roundManager].aluminum << ")"; std::cin >> counter;
                if (std::cin.fail()) { cinFail(); continue; }
                if (counter <= 0) { continue; }
                if (counter > player[roundManager].aluminum) { std::cout << "Das geht nicht!"; getKey(); continue; }
                player[roundManager].aluminum -= counter;
                player[roundManager].gold += (counter * 20);
                player[roundManager].realCapacity -= (counter * 0.1);
                std::cout << "Sie haben " << counter << " Einheiten Aluminium fuer insgesamt " << (counter * 20) << " Gold verkauft." << std::endl;
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);
            
            case 4:
                std::cout << "Wie viele Einheiten Kraeuter sollen verkauft werden? (0 - " << player[roundManager].herbs << ")"; std::cin >> counter;
                if (std::cin.fail()) { cinFail(); continue; }
                if (counter <= 0) { continue; }
                if (counter > player[roundManager].herbs) { std::cout << "Das geht nicht!"; getKey(); continue; }
                player[roundManager].herbs -= counter;
                player[roundManager].gold += (counter * 25);
                player[roundManager].realCapacity -= (counter * 0.1);
                std::cout << "Sie haben " << counter << " Einheiten Kraeuter fuer insgesamt " << (counter * 25) << " Gold verkauft." << std::endl;
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);
            
            case 5:
                std::cout << "Wie viele Heiltraenke sollen verkauft werden? (0 - " << player[roundManager].healthPotion << ")"; std::cin >> counter;
                if (std::cin.fail()) { cinFail(); continue; }
                if (counter <= 0) { continue; }
                if (counter > player[roundManager].healthPotion) { std::cout << "Das geht nicht!"; getKey(); continue; }
                player[roundManager].healthPotion -= counter;
                player[roundManager].gold += (counter * 15);
                player[roundManager].realCapacity -= (counter * 0.25);
                std::cout << "Sie haben " << counter << " Heiltraenke fuer insgesamt " << (counter * 15) << " Gold verkauft." << std::endl;
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);

            case 6:
                std::cout << "Wie viele Manatraenke sollen verkauft werden? (0 - " << player[roundManager].manaPotion << ")"; std::cin >> counter;
                if (std::cin.fail()) { cinFail(); continue; }
                if (counter <= 0) { continue; }
                if (counter > player[roundManager].manaPotion) { std::cout << "Das geht nicht!"; getKey(); continue; }
                player[roundManager].manaPotion -= counter;
                player[roundManager].gold += (counter * 20);
                player[roundManager].realCapacity -= (counter * 0.25);
                std::cout << "Sie haben " << counter << " Manatraenke fuer insgesamt " << (counter * 20) << " Gold verkauft." << std::endl;
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);

            case 7:
                std::cout << "Wie viele Regenerationstraenke sollen verkauft werden? (0 - " << player[roundManager].regenPotion << ")"; std::cin >> counter;
                if (std::cin.fail()) { cinFail(); continue; }
                if (counter <= 0) { continue; }
                if (counter > player[roundManager].regenPotion) { std::cout << "Das geht nicht!"; getKey(); continue; }
                player[roundManager].regenPotion -= counter;
                player[roundManager].gold += (counter * 25);
                player[roundManager].realCapacity -= (counter * 0.25);
                std::cout << "Sie haben " << counter << " Regenerationstraenke fuer insgesamt " << (counter * 25) << " Gold verkauft." << std::endl;
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);

            case 8:
                shopSellWeaponsArmor(player, roundManager, "Waffe");
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);

            case 9:
                shopSellWeaponsArmor(player, roundManager, "Ruestung");
                std::cout << "Moechten Sie noch weitere Gegenstaende verkaufen? (J/N)" << std::endl;
                answer = question();
                if (answer == false) { running = false; break; }
                if (answer == true) { continue; }
                error(0);
        }
        running = false;
        break;
    }
}

void shop(Player player[], short roundManager, short room)
{
    specialHeader(room);
    headShop(player, roundManager);
    std::cout << "Was moechten Sie tun?" << std::endl;
    line();
    std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck\n" << std::endl;
    std::cout << "\033[37;102m[ 1 ]\033[0m ------> \033[92mKaufen\033[0m\n" << std::endl;
    std::cout << "\033[37;101m[ 2 ]\033[0m ------> \033[91mVerkaufen\033[0m\n" << std::endl;
    short input = choice();
    switch(input)
    {
        case 0:
            return;

        case 1:
            shopBuy(player, roundManager);
            return;

        case 2:
            shopSell(player, roundManager);
            return;
    } 
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

void spring(Player player[], short roundManager, short room)
{
    specialHeader(room);
    return;
}

void specialRoom(Player player[], short roundManager, int room, short danger, short numberOfPlayers)
{
    if (room == 5) { lever(player, roundManager, room, numberOfPlayers); return; }
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
    if (room == 21){ spring(player, roundManager, room); return; }
    error(0);
    return;
}
#endif

