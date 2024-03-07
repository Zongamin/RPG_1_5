#ifndef HEADLINES_H
#define HEADLINES_H

#include <iostream>

/* Inhaltsverzeichnis:
    Schriftzugdatei. Funktionen als Überschriften selbsterklärend

    - textMainMenue 
    - textCharacter
    - textPlayer
    - textLevelUp
    - textExpUp
    - textFight
    - textInventory
    - textMagic
    - textSave
    - textLoad
    - textMenue
    - textSearch
    - textTrap
    - textBreak 
    - textPoition
    - textWeapons
    - textRising
    - textTitle
    - textEnd 
    - textDeath  
    */

void textMainMenue()
{
    std::cout << "\033[36m __  __                                __                                                                                            \n";                                                 
    std::cout << "/\\ \\/\\ \\                              /\\ \\__                                                                                           \n";                                                 
    std::cout << "\\ \\ \\_\\ \\      __     __  __   _____  \\ \\ ,_\\    ___ ___       __     ___     __  __     __                                          \n";   
    std::cout << " \\ \\  _  \\   /'__`\\  /\\ \\/\\ \\ /\\ '__`\\ \\ \\ \\/  /' __` __`\\   /'__`\\  /'_ `\\  /\\ \\/\\ \\  /'__`\\                           \n";
    std::cout << "  \\ \\ \\ \\ \\ /\\ \\L\\.\\_\\ \\ \\_\\ \\\\ \\ \\L\\ \\ \\ \\ \\_\\ \\ \\/\\ \\/\\ \\ /\\  __/ /\\ \\/\\ \\ \\ \\ \\_\\ \\/\\  __/        \n";
    std::cout << "   \\ \\_\\ \\_\\\\ \\__/.\\_\\\\ \\____/ \\ \\ ,__/  \\ \\__\\\\ \\_\\ \\_\\ \\_\\\\ \\____\\\\ \\_\\ \\_\\ \\ \\____/\\ \\____\\           \n";
    std::cout << "    \\/_/\\/_/ \\/__/\\/_/ \\/___/   \\ \\ \\/    \\/__/ \\/_/\\/_/\\/_/ \\/____/ \\/_/\\/_/  \\/___/  \\/____/                              \n";
    std::cout << "                                 \\ \\_\\                                                                                                    \n";                                                     
    std::cout << "                                  \\/_/                                                                                               \033[0m\n"; 
    return;
}

void textCharacter()
{
    std::cout << "\033[36m _____     __                                   __        __                                                 \n";                     
    std::cout << "/\\  _ `\\  /\\ \\                                 /\\ \\      /\\ \\__                                              \n";                  
    std::cout << "\\ \\ \\/\\_\\ \\ \\ \\___       __      _ __     __   \\ \\ \\/'\\  \\ \\ ,_\\     __    _ __                       \n";  
    std::cout << " \\ \\ \\/_/_ \\ \\  _ `\\   /'__`\\   /\\`'__\\ /'__`\\  \\ \\ , <   \\ \\ \\/   /'__`\\ /\\`'__\\                  \n";
    std::cout << "  \\ \\ \\L\\ \\ \\ \\ \\ \\ \\ /\\ \\L\\.\\_ \\ \\ \\/ /\\ \\L\\.\\_ \\ \\ \\ \\`\\ \\ \\ \\_ /\\  __/ \\ \\ \\/    \n";  
    std::cout << "   \\ \\____/  \\ \\_\\ \\_\\\\ \\__/.\\_\\ \\ \\_\\ \\ \\__/.\\_\\ \\ \\_\\ \\_\\ \\ \\__\\\\ \\____\\ \\ \\_\\     \n";
    std::cout << "    \\/___/    \\/_/\\/_/ \\/__/\\/_/  \\/_/  \\/__/\\/_/  \\/_/\\/_/  \\/__/ \\/____/  \\/_/                 \033[0m\n";
    return;
}

void textPlayer()
{
    std::cout << "    ____                               ___                                          \n";
    std::cout << "   /\\  _`\\               __           /\\_ \\                                      \n";
    std::cout << "   \\ \\,\\L\\_\\    _____   /\\_\\      __  \\//\\ \\       __    _ __              \n";
    std::cout << "    \\/_\\__ \\   /\\ '__`\\ \\/\\ \\   /'__`\\  \\ \\ \\    /'__`\\ /\\`'__\\       \n";
    std::cout << "      /\\ \\L\\ \\ \\ \\ \\L\\ \\ \\ \\ \\ /\\  __/   \\_\\ \\_ /\\  __/ \\ \\ \\/   \n";
    std::cout << "      \\ `\\____\\ \\ \\ ,__/  \\ \\_\\\\ \\____\\  /\\____\\\\ \\____\\ \\ \\_\\        \n";
    std::cout << "       \\/_____/  \\ \\ \\/    \\/_/ \\/____/  \\/____/ \\/____/  \\/_/              \n";
    std::cout << "                  \\ \\_\\                                                           \n";
    std::cout << "                   \\/_/                                                             \n";
    return;
}

void textLevelUp()
{
    std::cout << "\033[36m __                                 ___          __  __               __                            \n";
    std::cout << "/\\ \\                               /\\_ \\        /\\ \\/\\ \\             /\\ \\                         \n";
    std::cout << "\\ \\ \\         __    __  __     __  \\//\\ \\       \\ \\ \\ \\ \\    _____   \\ \\ \\                    \n";
    std::cout << " \\ \\ \\  __  /'__`\\ /\\ \\/\\ \\  /'__`\\  \\ \\ \\       \\ \\ \\ \\ \\  /\\ '__`\\  \\ \\ \\           \n";
    std::cout << "  \\ \\ \\L\\ \\/\\  __/ \\ \\ \\_/ |/\\  __/   \\_\\ \\_      \\ \\ \\_\\ \\ \\ \\ \\L\\ \\  \\ \\_\\      \n";
    std::cout << "   \\ \\____/\\ \\____\\ \\ \\___/ \\ \\____\\  /\\____\\      \\ \\_____\\ \\ \\ ,__/   \\/\\_\\           \n";
    std::cout << "    \\/___/  \\/____/  \\/__/   \\/____/  \\/____/       \\/_____/  \\ \\ \\/     \\/_/                     \n";
    std::cout << "                                                               \\ \\_\\                                     \n";
    std::cout << "                                                                \\/_/                               \033[0m \n";
    return;
}

void textExpUp()
{
    std::cout << "\033[36m ____     __   __    ____           __  __                                 \n";             
    std::cout << "/\\  _`\\  /\\ \\ /\\ \\  /\\  _`\\        /\\ \\/\\ \\                            \n";           
    std::cout << "\\ \\ \\__  \\ `\\`\\/'/' \\ \\ \\L\\ \\      \\ \\ \\ \\ \\    _____              \n";  
    std::cout << " \\ \\  _\\  `\\/ > <    \\ \\ ,__/       \\ \\ \\ \\ \\  /\\ '__`\\               \n";
    std::cout << "  \\ \\ \\____ \\/'/\\`\\   \\ \\ \\/         \\ \\ \\_\\ \\ \\ \\ \\L\\ \\        \n";
    std::cout << "   \\ \\____/ /\\_\\  \\_\\  \\ \\_\\          \\ \\_____\\ \\ \\ ,__/             \n";
    std::cout << "    \\/___/  \\/_/ \\/_/   \\/_/           \\/_____/  \\ \\ \\/                    \n";
    std::cout << "                                                  \\ \\_\\                         \n"; 
    std::cout << "                                                   \\/_/                    \n\033[0m";
    return;
}

void textFight()
{
    std::cout << "\033[36m __  __                                        ___                      \n";  
    std::cout << "/\\ \\/\\ \\                                     /'___\\                        \n"; 
    std::cout << "\\ \\ \\/'/'      __       ___ ___     _____   /\\ \\__/                        \n";
    std::cout << " \\ \\ , <     /'__`\\   /' __` __`\\  /\\ '__`\\ \\ \\ ,__\\                   \n";
    std::cout << "  \\ \\ \\`\\  /\\ \\L\\.\\_ /\\ \\/\\ \\/\\ \\ \\ \\ \\L\\ \\ \\ \\ \\_/       \n";
    std::cout << "   \\ \\_\\ \\_\\ \\__/.\\_\\ \\_\\ \\_\\ \\_\\ \\ \\ ,__/  \\ \\_\\            \n";
    std::cout << "    \\/_/\\/_/ \\/__/\\/_/ \\/_/\\/_/\\/_/  \\ \\ \\/    \\/_/                  \n";
    std::cout << "                                      \\ \\_\\                                  \n";
    std::cout << "                                       \\/_/                            \033[0m \n";
    return;
}

void textInventory()
{
    std::cout << "\033[36m ______                                       __                                            \n";   
    std::cout << "/\\__  _\\                                     /\\ \\__                                             \n";   
    std::cout << "\\/_/\\ \\/      ___     __  __     __     ___  \\ \\ ,_\\     __      _ __                         \n";  
    std::cout << "   \\ \\ \\    /' _ `\\  /\\ \\/\\ \\  /'__`\\ /' _ `\\ \\ \\ \\/   /'__`\\   /\\`'__\\             \n";
    std::cout << "    \\_\\ \\__ /\\ \\/\\ \\ \\ \\ \\_/ |/\\  __/ /\\ \\/\\ \\ \\ \\ \\_ /\\ \\L\\.\\_ \\ \\ \\/     \n";
    std::cout << "    /\\_____\\\\ \\_\\ \\_\\ \\ \\___/ \\ \\____\\ \\_\\ \\_\\ \\ \\__\\ \\__/.\\_\\ \\ \\_\\       \n";
    std::cout << "    \\/_____/ \\/_/\\/_/  \\/__/   \\/____/ \\/_/\\/_/  \\/__/ \\/__/\\/_/  \\/_/           \033[0m \n";
    return;
}

void textMagic()
{
    std::cout << "\033[36m /'\\_/`\\                      __                           \n";           
    std::cout << "/\\      \\      __        __  /\\_\\      __                        \n";
    std::cout << "\\ \\ \\__\\ \\   /'__`\\    /'_ `\\\\/\\ \\   /'__`\\               \n";
    std::cout << " \\ \\ \\_/\\ \\ /\\ \\L\\.\\_ /\\ \\L\\ \\\\ \\ \\ /\\  __/         \n";
    std::cout << "  \\ \\_\\\\ \\_\\\\ \\__/.\\_\\\\ \\____ \\\\ \\_\\ \\____\\        \n";
    std::cout << "   \\/_/ \\/_/ \\/__/\\/_/ \\/___L\\ \\/_/ \\/____/                  \n";
    std::cout << "                         /\\____/                                    \n";
    std::cout << "                         \\_/__/                             \033[0m \n";
    return;
}

void textSave()
{
    std::cout << "\033[36m ____                                                 \n";
    std::cout << "/\\  _`\\                                                     \n";
    std::cout << "\\ \\,\\L\\_\\      __      __  __     __                     \n";
    std::cout << " \\/_\\__ \\    /'__`\\   /\\ \\/\\ \\  /'__`\\               \n";
    std::cout << "   /\\ \\L\\ \\ /\\ \\L\\.\\_ \\ \\ \\_/ |/\\  __/            \n";
    std::cout << "   \\ `\\____\\ \\__/.\\_\\ \\ \\___/ \\ \\____\\             \n";
    std::cout << "    \\/_____/ \\/__/\\/_/  \\/__/   \\/____/           \033[0m\n";
    return;
}

void textLoad()
{
    std::cout << "\033[94m __                            __                                                             \n";
    std::cout << "/\\ \\                          /\\ \\    __                                                          \n";
    std::cout << "\\ \\ \\        ___      __      \\_\\ \\  /\\_\\     ___       __                                    \n";
    std::cout << " \\ \\ \\  __  / __`\\  /'__`\\    /'_` \\ \\/\\ \\  /' _ `\\   /'_ `\\                               \n";
    std::cout << "  \\ \\ \\L\\ \\/\\ \\L\\ \\/\\ \\L\\.\\_ /\\ \\L\\ \\ \\ \\ \\ /\\ \\/\\ \\ /\\ \\L\\ \\             \n";
    std::cout << "   \\ \\____/\\ \\____/\\ \\__/.\\_\\\\ \\___,_\\ \\ \\_\\\\ \\_\\ \\_\\\\ \\____ \\                  \n";
    std::cout << "    \\/___/  \\/___/  \\/__/\\/_/ \\/__,_ /  \\/_/ \\/_/\\/_/ \\/___L\\ \\                            \n";  
    std::cout << "                                                         /\\____/                                     \n";
    std::cout << "                                                         \\_/__/                               \033[0m\n";
    return;
}

void textMenue()
{
    std::cout << "\033[36m /'\\_/`\\                                                         \n";
    std::cout << "/\\      \\      __     ___     __  __     __                              \n";
    std::cout << "\\ \\ \\__\\ \\   /'__`\\ /' _ `\\  /\\ \\/\\ \\  /'__`\\                  \n";
    std::cout << " \\ \\ \\_/\\ \\ /\\  __/ /\\ \\/\\ \\ \\ \\ \\_\\ \\/\\  __/              \n";
    std::cout << "  \\ \\_\\ \\_\\ \\____\\ \\_\\ \\_\\ \\ \\____/\\ \\____\\                \n";
    std::cout << "   \\/_/ \\/_/ \\/____/ \\/_/\\/_/  \\/___/  \\/____/               \033[0m\n";
    return;
}

void textSearch()
{
    std::cout << "\033[36m ____                        __                                \n";
    std::cout << "/\\  _`\\                     /\\ \\                                   \n";
    std::cout << "\\ \\,\\L\\_\\    __  __    ___  \\ \\ \\___       __                  \n";
    std::cout << " \\/_\\__ \\   /\\ \\/\\ \\  /'___\\ \\ \\  _ `\\   /'__`\\            \n";
    std::cout << "   /\\ \\L\\ \\ \\ \\ \\_\\ \\/\\ \\__/  \\ \\ \\ \\ \\ /\\  __/       \n";
    std::cout << "   \\ `\\____\\ \\ \\____/\\ \\____\\  \\ \\_\\ \\_\\\\ \\____\\       \n";
    std::cout << "    \\/_____/  \\/___/  \\/____/   \\/_/\\/_/ \\/____/         \033[0m \n";
    return;
}

void textTrap()
{
    std::cout << "\033[36m ____             ___     ___                                    \n";
    std::cout << "/\\  __\\          /\\_ \\   /\\_ \\                                     \n";
    std::cout << "\\ \\ \\_/     __   \\//\\ \\  \\//\\ \\       __                        \n";
    std::cout << " \\ \\  _\\  /'__`\\   \\ \\ \\   \\ \\ \\    /'__`\\                    \n";
    std::cout << "  \\ \\ \\/ /\\ \\L\\.\\_  \\_\\ \\_  \\_\\ \\_ /\\  __/                 \n";
    std::cout << "   \\ \\_\\ \\ \\__/.\\_\\ /\\____\\ /\\____\\\\ \\____\\                \n";
    std::cout << "    \\/_/  \\/__/\\/_/ \\/____/ \\/____/ \\/____/                 \033[0m\n";
    return;
}

void textBreak()
{
    std::cout << "\033[36m ____                         __                       	               \n";
    std::cout << "/\\  _`\\                      /\\ \\__                                          \n";
    std::cout << "\\ \\ \\L\\ \\      __       ____ \\ \\ ,_\\     __     ___                      \n";
    std::cout << " \\ \\ ,  /    /'__`\\    /',__\\ \\ \\ \\/   /'__`\\  /'_ `\\                   \n";
    std::cout << "  \\ \\ \\\\ \\  /\\ \\L\\.\\_ /\\__, `\\ \\ \\ \\_ /\\  __/ /\\ \\/\\ \\        \n";
    std::cout << "   \\ \\_\\ \\_\\\\ \\__/.\\_\\\\/\\____/  \\ \\__\\\\ \\____\\\\ \\_\\ \\_\\    \n";
    std::cout << "    \\/_/\\/_/ \\/__/\\/_/ \\/___/    \\/__/ \\/____/ \\/_/\\/_/          \033[0m\n";
}

void textPotion()
{
    std::cout << "\033[36m ____            __                              			       \n";
    std::cout << "/\\  _`\\         /\\ \\__   __                     			           \n";
    std::cout << "\\ \\ \\L\\ \\  ___  \\ \\ ,_\\ /\\_\\     ___     ___    			   \n";
    std::cout << " \\ \\ ,__/ / __`\\ \\ \\ \\/ \\/\\ \\   / __`\\ /' _ `\\  			   \n";
    std::cout << "  \\ \\ \\/ /\\ \\L\\ \\ \\ \\ \\_ \\ \\ \\ /\\ \\L\\ \\/\\ \\/\\ \\ 	   \n";
    std::cout << "   \\ \\_\\ \\ \\____/  \\ \\__\\ \\ \\_\\ \\____/\\ \\_\\ \\_\\		   \n";
    std::cout << "    \\/_/  \\/___/    \\/__/  \\/_/ \\/___/  \\/_/\\/_/			\033[0m\n";
    return;
}

void textWeapons()
{
    std::cout << "\033[36m __      __                ___     ___                                        \n";
    std::cout << "/\\ \\  __/\\ \\             /'___\\  /'___\\                  		                \n";
    std::cout << "\\ \\ \\/\\ \\ \\ \\     __    /\\ \\__/ /\\ \\__/    __     ___    		            \n";
    std::cout << " \\ \\ \\ \\ \\ \\ \\  /'__`\\  \\ \\ ,__\\ \\ ,__\\ /'__`\\  /' _`\\  		        \n";
    std::cout << "  \\ \\ \\_/ \\_\\ \\/\\ \\L\\.\\_ \\ \\ \\_/ \\ \\ \\_//\\  __/ /\\ \\/\\ \\ 	    \n";
    std::cout << "   \\ `\\___x___/\\ \\__/.\\_\\ \\ \\_\\   \\ \\_\\ \\ \\____\\\\ \\_\\ \\_\\		    \n";
    std::cout << "    '\\/__//__/  \\/__/\\/_/  \\/_/    \\/_/  \\/____/ \\/_/\\/_/		         \033[0m\n";
    return;
}

void textRising()
{
    std::cout << "\033[36m __________ .__         .__                     _________                  __                                  \n";
    std::cout << " \\______   \\|__|  ______|__|  ____     ____    /   _____/ ___.__.  _______/  |_   ____    _____    ______            \n";
    std::cout << "  |       _/|  | /  ___/|  | /    \\   / ___\\   \\_____  \\ <   |  | /  ___/\\   __\\_/ __ \\  /     \\  /  ___/      \n";
    std::cout << "  |    |   \\|  | \\___ \\ |  ||   |  \\ / /_/  >  /        \\ \\___  | \\___ \\  |  |  \\  ___/ |  Y Y  \\ \\___ \\   \n";
    std::cout << "  |____|_  /|__|/____  >|__||___|  / \\___  /  /_______  / / ____|/____  > |__|   \\___  >|__|_|  / /___  >            \n";
    std::cout << "         \\/          \\/          \\/ /_____/           \\/  \\/          \\/             \\/       \\/      \\/      \n";
    std::cout << "                 _________          _____   __                             __                                          \n";
    std::cout << "                /   _____/  ____  _/ ____\\_/  |_ __  _  __  ____  _______ |  | __  ______                             \n";
    std::cout << "                \\_____  \\  /  _ \\ \\   __\\ \\   __\\\\ \\/ \\/ / /  _ \\ \\_  __ \\|  |/ / /  ___/   TM            \n";
    std::cout << "                /        \\(  <_> ) |  |    |  |   \\     / (  <_> ) |  | \\/|    <  \\___ \\                          \n";
    std::cout << "               /_______  / \\____/  |__|    |__|    \\/\\_/   \\____/  |__|   |__|_ \\/____  >                         \n";
    std::cout << "                       \\/                                                      \\/     \\/                    \033[0m \n";
    return;
}

void textTitle()
{
    std::cout << "\033[32m                                                  The Big Random\n\n";
    std::cout << "\033[31m #################    #################           ############       #######             ##################\n"; 
    std::cout << " #::::::::::::::::#   #::::::::::::::::#       ###:::::::::::#      #::::::#             #::::::::::::::::#\n"; 
    std::cout << " #::::::######:::::#  #::::::######:::::#    ##::::::::::::::#     #:::::::#             #::::::::::::::::#\n"; 
    std::cout << " ##:::::#     #:::::###:::::#     #:::::#  #:::::########::::#     ###:::::#             #:::::############\n"; 
    std::cout << "   #::::#     #:::::#  #::::#     #:::::# #:::::#       ######        #::::#             #:::::#\n";            
    std::cout << "   #::::#     #:::::#  #::::#     #:::::##:::::#                      #::::#             #:::::#\n";            
    std::cout << "   #::::######:::::#   #::::######:::::# #:::::#                      #::::#             #:::::##########\n";     
    std::cout << "   #:::::::::::::##    #:::::::::::::##  #:::::#    ##########        #::::#             #:::::::::::::::#\n";  
    std::cout << "   #::::######:::::#   #::::#########    #:::::#    #::::::::#        #::::#             ############:::::#\n"; 
    std::cout << "   #::::#     #:::::#  #::::#            #:::::#    #####::::#        #::::#                         #:::::#\n";
    std::cout << "   #::::#     #:::::#  #::::#            #:::::#        #::::#        #::::#                         #:::::#\n";
    std::cout << "   #::::#     #:::::#  #::::#             #:::::#       #::::#        #::::#             #######     #:::::#\n";
    std::cout << " ##:::::#     #:::::###::::::##            #:::::########::::#     ###::::::###          #::::::#####::::::#\n";
    std::cout << " #::::::#     #:::::##::::::::#             ##:::::::::::::::#     #::::::::::#  ######   ##:::::::::::::##\n"; 
    std::cout << " #::::::#     #:::::##::::::::#               ###::::::###:::#     #::::::::::#  #::::#     ##:::::::::##\n";   
    std::cout << " ########     #################                  ######   ####     ############  ######       #########\033[0m\n";  
    std::cout << "\n\n                                       Written in 2023/2024 by \033[34mZongamin\033[0m\n";
    std::cout << "\n                                       In an advisory function: \033[33mDecade\033[0m\n";
    std::cout << "\n                              \033[92mChris\033[0m,\033[91m Herr Schmidt\033[0m,\033[95m Herr Lehmann\033[0m and \033[93mHerr Holz\033[0m\n";
    std::cout << "\n                                               © in 2023/24 by\n\n\n";
    return;
}

void textEnd()
{
    std::cout << "\033[31m                                                    ########                      \n";
    std::cout << "######################                              #::::::#                              \n";                    
    std::cout << "#::::::::::::::::::::#                              #::::::#                              \n";
    std::cout << "#::::::::::::::::::::#                              #::::::#                              \n";
    std::cout << "##::::::#########::::#                              #:::::#                               \n";
    std::cout << "  #:::::#       ###### ###  ########        #########:::::#     #############             \n";    
    std::cout << "  #:::::#             #:::##::::::::##    ##::::::::::::::#   ##::::::::::::##            \n";  
    std::cout << "  #::::::##########   #::::::::::::::##  #::::::::::::::::#  #::::::####:::::##           \n";
    std::cout << "  #:::::::::::::::#   ##:::::::::::::::##:::::::#####:::::# #::::::#     #:::::#          \n";
    std::cout << "  #:::::::::::::::#     #:::::####:::::##::::::#    #:::::# #:::::::#####::::::#          \n";
    std::cout << "  #::::::##########     #::::#    #::::##:::::#     #:::::# #:::::::::::::::::#           \n"; 
    std::cout << "  #:::::#               #::::#    #::::##:::::#     #:::::# #::::::###########            \n";  
    std::cout << "  #:::::#       ######  #::::#    #::::##:::::#     #:::::# #:::::::#                     \n";           
    std::cout << "##::::::########:::::#  #::::#    #::::##::::::#####::::::###::::::::#                    \n";          
    std::cout << "#::::::::::::::::::::#  #::::#    #::::# #:::::::::::::::::# #::::::::########            \n";  
    std::cout << "#::::::::::::::::::::#  #::::#    #::::#  #:::::::::###::::#  ##:::::::::::::#            \n";  
    std::cout << "######################  ######    ######   #########   #####    ##############     \033[0m\n";
    std::cout << "\n\nHaben Sie noch einen schoenen Tag :)                                                  \n";
    return;
}

void textDeath()
{
    std::cout << "\033[31m              ####              \033[0m                                                                      \n";
    std::cout << "\033[31m            ########            \033[0m       ---------------------------------------------------------------\n";
    std::cout << "\033[31m           ##########           \033[0m       ---              \033[31mLeider wurden Sie getoetet!\033[0m                ---\n";
    std::cout << "\033[31m           ##########           \033[0m       ---------------------------------------------------------------\n";
    std::cout << "\033[31m             ######             \033[0m       ---   Oger, Goblins, Orks, Imps und Gewürm fallen ueber     ---\n";
    std::cout << "\033[31m         ooo ###### ooo         \033[0m       --- Ihren kalten Leichnam her und was noch von Ihnen uebrig ---\n";
    std::cout << "\033[31m           o ###### o           \033[0m       ---   geblieben ist wird von Ihren Gegnern verwurstet und   ---\n";
    std::cout << "\033[31m    ####  oo ###### oo  ####    \033[0m       --- abgehangen, um es auch später noch genießen zu koennen! ---\n";
    std::cout << "\033[31m   #####     ######     #####   \033[0m       ---  Wenigstens haben Sie sich als gute Wurst einen Namen   ---\n";
    std::cout << "\033[31m ############################## \033[0m       ---                        gemacht!                         ---\n"; 
    std::cout << "\033[31m ############################## \033[0m       ---------------------------------------------------------------\n";
    std::cout << "\033[31m   ##########################   \033[0m                                                                      \n";
    std::cout << "\033[31m    ####     ######     ####    \033[0m       ---------------------------------------------------------------\n";
    std::cout << "\033[31m             ######             \033[0m       ---                        \033[32mStatistik\033[0m                        ---\n";
    std::cout << "\033[31m      ooooo  ######  ooooo      \033[0m       ---------------------------------------------------------------\n";
    std::cout << "\033[31m         oo  ######  oo         \033[0m       --- Spieler Level ----->                                    ---\n";
    std::cout << "\033[31m          o  ######  o          \033[0m       --- Besuchte Raeume --->                                    ---\n";
    std::cout << "\033[31m          o  ######  o          \033[0m       --- Erbeutetes Gold --->                                    ---\n";
    std::cout << "\033[31m        ooo  ######  ooo        \033[0m       --- Gecraftets Items -->                                    ---\n";
    std::cout << "\033[31m             ######             \033[0m       --- Getoetete Monster ->                                    ---\n";
    std::cout << "\033[31m             ######             \033[0m       --- Getoetete Bosse --->                                    ---\n";
    std::cout << "\033[31m           ##########           \033[0m       --- Tode -------------->                                    ---\n";
    std::cout << "\033[31m           ##########           \033[0m       ---------------------------------------------------------------\n";
    std::cout << "\033[31m            ########            \033[0m       ---        \033[31mMoechten Sie einen Spielstand laden (J/N)?\033[0m       ---\n";
    std::cout << "\033[31m              ####              \033[0m       ---------------------------------------------------------------\n";
    return;
}

#endif