#ifndef TEXTS_H
#define TEXTS_H

#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>

/*Inhaltsverzeichnis:
    - roomTexts   -- case 0 = Eingang               -- case 8 = Treppe nach unten       -- case 16 = Kerker
                  -- case 1 = Doppeltür             -- case 9 = Schmiede                -- case 17 = Leiter nach oben
                  -- case 2 = Wand                  -- case 10 = Shop                   -- case 18 = Leiter nach unten
                  -- case 3 = Passage               -- case 11 = Casino                 -- case 19 = Toilette 
                  -- case 4 = Tuer                  -- case 12 = Wandloch               -- case 20 = Grabmal
                  -- case 5 = Hebel                 -- case 13 = Dunkler Baum
                  -- case 6 = Truhe                 -- case 14 = Bushaltestelle
                  -- case 7 = Treppe nach oben      -- case 15 = Altarraum              */

void textPosition(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}

void roomTexts(int room)
{
    switch (room)
        {
            case 0:
                
                textPosition(58, 8);  std::cout << "Sie stehen vor der gewaltigen Pforte zum sagenumwobenen";
                textPosition(58, 9);  std::cout << "endlosen Dungeon. Die Tuer scheint so alt, dass selbst der";
                textPosition(58, 10); std::cout << "Schimmel darauf in Rente gehen koennte. Doch da ist auch";
                textPosition(58, 11); std::cout << "dieser Hauch von Abenteuer, der in der Luft liegt (oder";
                textPosition(58, 12); std::cout << "vielleicht ist es einfach nur der Gestank von alten"; 
                textPosition(58, 13); std::cout << "Goblinfuerzen, der seit Aeonen in den Tiefen dieses Dungeons";
                textPosition(58, 14); std::cout << "rumhaengt). Sie wissen geanu: Der Weg vor Ihnen ist gespickt";
                textPosition(58, 15); std::cout << "mit Reichtuemern, Gefahren und vielleicht sogar einer alten,";
                textPosition(58, 16); std::cout << "vergessenen Socke eines Ogers. Also,schnappen Sie sich Ihren";
                textPosition(58, 17); std::cout << "Mut und treten Sie ein in den endlosen Dungeon!";
                break;

            case 1:

                textPosition(58, 8);  std::cout << "Sie stehen vor einer riesigen aber verschlossen Doppeltuer.";
                textPosition(58, 9);  std::cout << "Allein der Anblick suggeriert Ihnen: \"Oeffne mich!\". Ganz";
                textPosition(58, 10); std::cout << "wie ein Ueberraschungs - Ei zu Kindertagen.";
                textPosition(58, 11); std::cout << "Dies wirft natürlich sofort folgende Fragen auf: Spannung?";
                textPosition(58, 12); std::cout << "Spiel? Oder etwa etwas zu Naschen?"; 
                textPosition(58, 13); std::cout << "Fest steht jedenfalls, dass Orks, Oger und Goblins in der";
                textPosition(58, 14); std::cout << "Naehe was zu Naschen bekommen, wenn Sie nicht vorsichtig sind!";
                textPosition(58, 15); std::cout << "Btw: Kommt die Tuer nochwem bekannt vor? Ich glaube die wurde";
                textPosition(58, 16); std::cout << "bereits fuer den Eingang zum Dungeon benutzt.";
                textPosition(58, 17); std::cout << "Na toll...  noch mehr Einsparungen!";
                break;

            case 2:
                
                textPosition(58, 8);  std::cout << "Dies ist eine Wand. Sie scheint endlos zu sein, genau wie der";
                textPosition(58, 9);  std::cout << "Dungeon. Wenn man genau darueber nachdenkt ist es eigentlich";
                textPosition(58, 10); std::cout << "absolut sinnlos ein solches Bild in so ein Game reinzupacken!";
                textPosition(58, 11); std::cout << "Doch der Dev des Games hat sich wohl gedacht, dass das voll";
                textPosition(58, 12); std::cout << "Sinn macht! Denken Sie nur mal an die gesparte Arbeit etwas "; 
                textPosition(58, 13); std::cout << "halbwegs anstaendiges mit ASCII hinzubekommen!";
                textPosition(58, 14); std::cout << "Und die gesparten Kosten, einen ASCII - Artist einzustellen";
                textPosition(58, 15); std::cout << "erst! Bedenkt man die gesparten Kosten und den gesparten Auf-";
                textPosition(58, 16); std::cout << "wand, so stellt man fest: BAM! So eine Wand gehoert voll in";
                textPosition(58, 17); std::cout << "dieses Game! Fazit --> Hier: Einfach eine Wand.";
                break;

            case 3:
                
                textPosition(58, 8);  std::cout << "Eine duester wirkende Passage springt aus dem Nichts in die";
                textPosition(58, 9);  std::cout << "Wand und beschliesst, dort weiter abzuhaengen. Sicherlich eine";
                textPosition(58, 10); std::cout << "Untersuchung wert. Eventuell haengt da drin irgendwo eine";
                textPosition(58, 11); std::cout << "goldene, alte Unterhose eines grossen Hexenmeisters. Kommt es";
                textPosition(58, 12); std::cout << "hier endlich zum grossen, lange erwartete Fund? Ihre Stimmung"; 
                textPosition(58, 13); std::cout << "steigert sich schier ins unermessliche! Lediglich die Spinnen";
                textPosition(58, 14); std::cout << "in den Winkeln der Passage bleiben voellig unbeeindruckt und";
                textPosition(58, 15); std::cout << "haengen einfach weiter ab. Obwohl es sich hier letztendlich nur";
                textPosition(58, 16); std::cout << "um eine gewoehnliche Passage handelt gibt es hier noch so viel";
                textPosition(58, 17); std::cout << "zu entdecken... Was ist das? Oh! Ein vorstehender Stein!";
                break;

            case 4:
                
                textPosition(58, 8);  std::cout << "Eine morsche Kerkertuer haengt halbherzig in der Mauer. Durch";
                textPosition(58, 9);  std::cout << "die Gitterstaebe erblicken Sie ein grinsendes Skelett. Die Frage";
                textPosition(58, 10); std::cout << "ist, ob es mit Ihnen oder ueber Sie lacht. Vielleiucht freut es";
                textPosition(58, 11); std::cout << "sich auch einfach nur darueber, den Firlefanz im Dungeon nicht";
                textPosition(58, 12); std::cout << "mehr mitmachen zu muessen. Hinter dem Skelett allerdings fuehrt"; 
                textPosition(58, 13); std::cout << "eine Passage anscheinend tiefer in den Dungeon... und, wie";
                textPosition(58, 14); std::cout << "koennte es auch anders sein, natuerlich ist die Kerkertuer ver-";
                textPosition(58, 15); std::cout << "schlossen. Aber sowas von... Da kann nicht mal das Skelett im";
                textPosition(58, 16); std::cout << "Inneren keine Hilfestellung leisten... Sie ist nicht zu oeffnen,";
                textPosition(58, 17); std::cout << "es sei denn, Sie haben einen Schluessel in der Tasche!";
                break;

            case 5:
                
                textPosition(58, 8);  std::cout << "Ein Hebel an der Wand (euphorisches glucksen)! Es fehlt eigentlich";
                textPosition(58, 9);  std::cout << "nur noch die Aufschrift: \"Nicht ziehen\" um die Aufmerksamkeit und";
                textPosition(58, 10); std::cout << "den Drang, den Hebel zu ziehen noch weiter zu steigern! Aber grund-";
                textPosition(58, 11); std::cout << "saetzlich ist die Einladung den Hebel zu betaetigen da! Die Frage";
                textPosition(58, 12); std::cout << "ist: Sind Sie der geborene Hebelheber oder nicht? Allerdings spricht"; 
                textPosition(58, 13); std::cout << "auch die kaum erkenn bare Bodenplatte Baende... Aber dennoch ist nicht";
                textPosition(58, 14); std::cout << "gesagt, dass es sich hierbei zwangslaeufig um eine Falle handeln muss.";
                textPosition(58, 15); std::cout << "Auf Ihrer Linken Seite erscheint ein Engelchen und auf der Rechten";
                textPosition(58, 16); std::cout << "ein Teufelchen. Teufelchen sagt: Zieh den Hebel! Und Engelchen sagt:";
                textPosition(58, 17); std::cout << "Hast Du nicht gehoert? Du sollst den Hebel ziehen! ";
                break;

            case 6:
                
                textPosition(58, 8);  std::cout << "Da steht sie... Prächtig und doch irgendwie random....";
                textPosition(58, 9);  std::cout << "Quasi ein klassisches Element in jedem Dungeon - Abenteuer! Ein \"Muss\"";
                textPosition(58, 10); std::cout << "in jedem Spiel, dass auch nur ansatzweise was auf sich haelt! Ganz so";
                textPosition(58, 11); std::cout << "schuechternd wie eine Jungfrau ueber ihre Jungfraeulichkeit ist sie ";
                textPosition(58, 12); std::cout << "selbstverstaendlich verschlossen.... Die Frage ist: Haben Sie das er-"; 
                textPosition(58, 13); std::cout << "forderliche Geschick, die Truhe zur Oeffnung zu ueberreden, oder einfach";
                textPosition(58, 14); std::cout << "nur einen Schluessel im Gepaeck. So oder so sollten beide Optionen dazu";
                textPosition(58, 15); std::cout << "fuehren, die Truhe oeffnen zu koennen.";
                textPosition(58, 16); std::cout << "Was spricht dagegen, dass Geheimnis der Truhe loesen zu wollen? Die Ant-";
                textPosition(58, 17); std::cout << "wort ist: Nichts! Ausser, Sie haben keinen Schluessel!";
                break;

            case 7:

                textPosition(58, 8);  std::cout << "Is this the stairway to heaven? Eher weniger! Natuerlich ist es ein sehr";
                textPosition(58, 9);  std::cout << "seltsames Gefuehl in einem Dungeon des Boesen, der offensichtlich in die";
                textPosition(58, 10); std::cout << "Tiefe fuehren sollte, nach oben zu gehen! Es sei dem, Sie sind zuvor be-";
                textPosition(58, 11); std::cout << "reits mehrmals nach unten gegangen. Leider laesst sich das nicht genau ";
                textPosition(58, 12); std::cout << "vorraus sagen, denn schliesslich ist dieser Dungeon ja zufaellig aufgebaut"; 
                textPosition(58, 13); std::cout << "und es liegt durchaus im Bereich des Moeglichen, dass Sie bereits mehrmals";
                textPosition(58, 14); std::cout << "nach oben gegangen sind... Sollte dies der Fall sein, so bittet der Dev";
                textPosition(58, 15); std::cout << "mehrmals um Verzeihung und Ihr Verstaendnis, dass er keinen tiefen Einfluss";
                textPosition(58, 16); std::cout << "auf solche Nebensaechlichkeiten haben kann und so wie Sie, den Umstaenden";
                textPosition(58, 17); std::cout << "schutzlos ausgeliefert ist!";
                break;

            case 8:
                                
                textPosition(58, 8);  std::cout << "Oha, wer haette das nur Gedacht? Es geht nach unten. Tiefer in den Dungeon";
                textPosition(58, 9);  std::cout << "hinein! Es wird tatsaechlich Zeit vom hohen Ross abzusteigen und tiefer in";
                textPosition(58, 10); std::cout << "den endlosen Dungeon hinabzusteigen! Es gibt noch so viele Ogersocken und";
                textPosition(58, 11); std::cout << "Unterhosen zu finden und zu entdecken, dass Sie jetzt nicht einfach auf-";
                textPosition(58, 12); std::cout << "geben koennen! Wer weiss schon so genau, wo diese Untiefen noch hinfuehren"; 
                textPosition(58, 13); std::cout << "koennen und ob nicht doch eventuell schon ein goldenes Haeufchen eines";
                textPosition(58, 14); std::cout << "Drachens unter dieser nichtssagenden Treppe liegt! Checken Sie lieber mal";
                textPosition(58, 15); std::cout << "die Gegend ab, bevor Sie weiterziehen! Desweiteren ist es bestimmt auch mal";
                textPosition(58, 16); std::cout << "angenehm, in einem Dungeon mal weiter nach unten zu gehen. Sollte es so";
                textPosition(58, 17); std::cout << "sein, dass der Zufall sie zuvor immer wieder nach oben gefuehrt hat...";
                break;
            
            case 9:
                
                textPosition(58, 8);  std::cout << "Auch im tiefsten Dungeon kann man hier und da mal auf ein kleines Licht";
                textPosition(58, 9);  std::cout << "oder halt eben auch auf ein groesseres Feuer in einem Ofen oder eben einer";
                textPosition(58, 10); std::cout << "Schmiede treffen.... Die Glut im Schmelzofen scheint noch schoen heiss zu";
                textPosition(58, 11); std::cout << "sein. Gerade richtig um Ihre Metalle darin schmelzen zu koennen und das ein";
                textPosition(58, 12); std::cout << "oder andere brauchbare oder eben auch nicht brauchbare Schwert oder Schild"; 
                textPosition(58, 13); std::cout << "herzustellen. Bei dieser Gelegenheit zuecken Sie lieber schnell Ihre Metalle,";
                textPosition(58, 14); std::cout << "denn wer weiss schon ob und wann Sie in einem Zufallsgenerierten Dungeon mal";
                textPosition(58, 15); std::cout << "wieder an einer Schmiede vorbeikommen! Auch lassen sich Waffen und Ruestungen";
                textPosition(58, 16); std::cout << "wesentlich besser verkaufen als ein paar unanschauliche Brocken von Altmetall,";
                textPosition(58, 17); std::cout << "Aluminium oder Kupfer.... Auf gehts!";
                break;

            case 10:
                
                textPosition(58, 8);  std::cout << "Wer haette das in einem Dungeon erwartet.... es ist ein An- und Verkauf. Davor";
                textPosition(58, 9);  std::cout << "steht ein listig dreinblickender Goblin, der sich grinsend die Haende reibt.";
                textPosition(58, 10); std::cout << "\"Willkommen bei Duester Deals, wir haben Vieles was Sie suchen und vielleicht";
                textPosition(58, 11); std::cout << "sogar gar nicht erst brauchen! Unsere Waffen sind garantiert nur manchmal ver-";
                textPosition(58, 12); std::cout << "flucht und die Fallen, die Sie hier sehen sind groesstenteils nur Ausstellungs-"; 
                textPosition(58, 13); std::cout << "stuecke. Treten Sie naeher und finden Sie es heraus! Wir kaufen uebrigens Alles,";
                textPosition(58, 14); std::cout << "was Sie loswerden moechten, denn sollten Sie hinter der naechsten Ecke sterben,";
                textPosition(58, 15); std::cout << "plündern wir uns das Gold sowieso wieder zurueck! Hätten Sie eventuell Interesse";
                textPosition(58, 16); std::cout << "an diesem unsichtbaren Umhang? Man spuert tatsaechlich ueberhaupt nicht, dass man";
                textPosition(58, 17); std::cout << "ihn traegt.\", sagt der Goblin mit verwegenem Grinsen. Na dann mal shoppen gehen!";
                break;

            case 11:

                textPosition(58, 8);  std::cout << "Unfassbar was sich der Programmierer dieses Spiels noch alles ausdenkt, was hier";
                textPosition(58, 9);  std::cout << "so in einem Dungeon rum kreuchen und fleuchen soll! Langsam wird es Zeit mich mal";
                textPosition(58, 10); std::cout << "bei Rising Systems zu beschweren! Das kann ich doch als Geschichtenschreiber, bzw.";
                textPosition(58, 11); std::cout << "Erzähler hier gar nicht mehr glaubwuerdig an den Mann bringen!";
                textPosition(58, 12); std::cout << "Aber bitte: Mitten in einer stillen Ecke des Dungeons finden Sie Glorg den Ork. Er";
                textPosition(58, 13); std::cout << "ist der einzige Ork hier unten, der versucht die Herrschafft des Dungeons mittels";
                textPosition(58, 14); std::cout << "Gluecksspiel an sich zu reissen! Sein grimmiger Blick sagt Ihnen zwar, dass Sie es";
                textPosition(58, 15); std::cout << "lieber bleibenlassen sollten, aber seine mit Gold gefüllten Taschen sagen Ihnen,";
                textPosition(58, 16); std::cout << "dass Sie es auch gerne versuchen wuerden, es ihm genau aus den Selbigen zu entfer-";
                textPosition(58, 17); std::cout << "nen und in Ihre eigenen wandern zu lassen.... Wollen Sie es versuchen?";
                break;

            case 12:

                textPosition(58, 8);  std::cout << "Ein Loch ist im Eimer Karl Otto.... In diesem Fall ist es aber eher in der Wand oO";
                textPosition(58, 9);  std::cout << "Obwohl der Dungeon dahinter ganz normal weiterzuverlaufen scheint, hinterlaesst das";
                textPosition(58, 10); std::cout << "Loch nichtsdestotrotz ein seltsames Gefuehl von Beklemmung und boesen Vorahnungen.";
                textPosition(58, 11); std::cout << "Etwas furchtbar boeses koennte darin lauern... wie zum Beispiel eine gelangweilte";
                textPosition(58, 12); std::cout << "Fledermaus, die Ihr gerade beim Mittagsschlaf gestoert habt, oder schlimmer: Oglahr,";
                textPosition(58, 13); std::cout << "der Dungeon-Hausmeister, der gerade seine Mittagspause machen will. Die Situation";
                textPosition(58, 14); std::cout << "riecht geradezu förmlich nach Gefahr.... Eventuell ist es aber auch nur die Oger-";
                textPosition(58, 15); std::cout << "Socke die dort in der Ecke liegt. Genau weiss man es wohl nur, wenn man es genauer";
                textPosition(58, 16); std::cout << "ueberpruefen wuerde, die Frage ist: Haben Sie den Schneid dazu, oder lassen Sie es";
                textPosition(58, 17); std::cout << "vorerst lieber bleiben und trinken erst mal eine lauwarme Cervesia zum runterkommen.";
                break;

            case 13:

                textPosition(58, 8);  std::cout << "Willkommen beim duesteren Baum der Gesetzlosigkeit... er ist so gesetzlos, dass";
                textPosition(58, 9);  std::cout << "er sich nicht mal den Gesetzen der Botanik unterwirft und einfachso komplett ohne";
                textPosition(58, 10); std::cout << "jegliches Sonnenlicht waechst. Sein Geheimnis liegt wohl in den versteckt angebrachten";
                textPosition(58, 11); std::cout << "UV-Lampen die ebenfalls gesetzlos sind, da Strom erst in ca. 1000 Jahren oder so er-";
                textPosition(58, 12); std::cout << "funden wird. Aber sie werden von dem Magier Akkuz Batterius angetrieben, der schon";
                textPosition(58, 13); std::cout << "mal einen Nostradamus-maessigen Blick in die strahlende Zukunft der Kernkraftwerke";
                textPosition(58, 14); std::cout << "geworfen hat... Man sagt der Baum haette viel Humor und wuerde sehr viel Spass ver-";
                textPosition(58, 15); std::cout << "stehen , aber man sollte ihm allerdings keine leuchtenden Gegenstaende zeigen, da";
                textPosition(58, 16); std::cout << "er sich dadurch beleidigt fuehlen koennte. Man sagt ihm allerdings auch vitalisierende";
                textPosition(58, 17); std::cout << "Kraefte nach, die Frage ist, ob man es denn auch versuchen will ihn zu beruehren...";
                break;

            case 14:

                textPosition(58, 8);  std::cout << "Eiiiiiiiine Bushaltestelle.... Geeeeenau! Ja, Sie sehen richtig.... und genau wie ich";
                textPosition(58, 9);  std::cout << "als Geschichtenerzaehler hier, werden Sie wohl auch Ihren Augen nicht trauen... Unfassbar";
                textPosition(58, 10); std::cout << "was ich hier alles noch in einem Dungeon an den Mann bringen soll! Eins steht jedoch";
                textPosition(58, 11); std::cout << "fuer mich klipp und klar fest: Ich werde total unterbezahlt fuer den Mist den ich hier";
                textPosition(58, 12); std::cout << "verzapfen soll.... Mal ehrlich, Sie glauben mir das doch auch schon nicht mehr, oder?";
                textPosition(58, 13); std::cout << "Aber hey: Job ist Job, also: Sie stehen vor einer Bushaltestelle der Linie \"Tiefes D\"";
                textPosition(58, 14); std::cout << "Der Fahrplan sagt, dass der Bus sehr bald abfahren wird. Nachdem Sie den Busfahrer mehr-";
                textPosition(58, 15); std::cout << "mals nach seinem Fuehrerschein gefragt haben und Sie sich jetzt sicher sind das der nette";
                textPosition(58, 16); std::cout << "Oger auch tatsaechlich fahren kann, sind Sie ein wenig enttaeuscht zu hoeren, dass der";
                textPosition(58, 17); std::cout << "Fahrer lediglich hartes Gold und keine Kartoffelschalen fuer den Transport akzepiert!";
                break;

            case 15:

                textPosition(58, 8);  std::cout << "Sie finden sich selbst in einen heiligen Altarraum wieder. Man munkelt, man koenne";
                textPosition(58, 9);  std::cout << "hier die Goetter des Level-Ups anbeten um deren Segen zu bekommen. Auch werden Gold-";
                textPosition(58, 10); std::cout << "opfer gerne gesehen, nur Kreditkarte wird hier nicht genommen und wer weiss schon";
                textPosition(58, 11); std::cout << "genau ob das ganze ueberhaupt was bringt...schliesslich ist auf die meisten Goetter";
                textPosition(58, 12); std::cout << "hier im Dungeon sowieso kein Verlass mehr. Dennoch haengt an der Seite des Altars";
                textPosition(58, 13); std::cout << "ein Schild auf dem darum gebeten wird, die Gebete laut vorzutragen, da die XP-";
                textPosition(58, 14); std::cout << "Goetter aufgrund ihres Alters ueber die Jahre ein wenig taub geworden sind. Ganz";
                textPosition(58, 15); std::cout << "nebenbei bemerkt ist die kleine Schuessel mit den Opfergaben auch nicht gerade";
                textPosition(58, 16); std::cout << "leer... Nur um dem kleinen Teufelchen in Euch ein wenig Zunder zu geben ;) Und wer";
                textPosition(58, 17); std::cout << "will schliesslich auch den Frevel begehen, die Goetter des Level-Ups zu bestehlen?";
                break;

            case 16:

                textPosition(58, 8);  std::cout << "Kuess die Hand der Kerkermeister.... Herzlich willkommen in der gemuetlichsten Ecke";
                textPosition(58, 9);  std::cout << "des endlosen Dungeons! Der beruehmt-beruechtigten \"Honeydoom-Suite\"! Diese luxurioese";
                textPosition(58, 10); std::cout << "Kerkerzelle bietet alles, was das Herz begehrt: Rostige Gitterstaebe, einen fast neu-";
                textPosition(58, 11); std::cout << "wertigen Pranger und eine steinharte Schlafbank, deren Haertegrad H4 bei Weitem ueber-";
                textPosition(58, 12); std::cout << "steigt. Jeder Tag hier ist ein Feiertag! Nur halt ohne Feier und das Licht des Tages.";
                textPosition(58, 13); std::cout << "Pain und Schmerz werden hier nicht noch gross geschrieben und stehen an der Tagesordung!";
                textPosition(58, 14); std::cout << "Die Spinnweben und Blutspritzer, welche von vorherigen Insassen hinterlassen wurden";
                textPosition(58, 15); std::cout << "sind hier unangefochten das Highlight der Dekoration! Die Authentizität der trostlosen";
                textPosition(58, 16); std::cout << "Umgebeung bietet fuer jeden Anlass den gewuenschten Effekt! Buchen auch Sie noch heute";
                textPosition(58, 17); std::cout << "die Honeydoom-Suite und vergessen Ihren Eintrag im Gaestebuch bitte nicht!";
                break;

            case 17:

                textPosition(58, 8);  std::cout << "Eine krakelige Leiter fuehrt nach oben scheinbar in ein Stockwerk darueber. Sie";
                textPosition(58, 9);  std::cout << "scheint uralt zu sein. An einer Sprosse scheint auch noch ein Dinosaurierer Kau-";
                textPosition(58, 10); std::cout << "gummi zu kleben. Das Material aus dem sie gemacht ist durch das darauf wachsende";
                textPosition(58, 11); std::cout << "Moos undefinierbar. Die Dungeon-Versicherung uebernimmt bei Abstuerzen und/oder";
                textPosition(58, 12); std::cout << "weiteren Dungeon-Unfaellen keine Haftung! Haben Sie ueberhaupt eine abgeschlossen";
                textPosition(58, 13); std::cout << "bevor Sie hier unten hereingestuermt sind?";
                textPosition(58, 14); std::cout << "Ich auch nicht, denn die Beitraege sind eine wahre Unverschaemtheit! Doch ob Sie"; 
                textPosition(58, 15); std::cout << "dieses alte, glitschige Ding betreten wollen liegt allerdings voll und ganz bei";
                textPosition(58, 16); std::cout << "Ihnen. Doch bloss nicht abrutschen und runterfallen, schliesslich brauchen Sie " ;
                textPosition(58, 17); std::cout << "Ihre Knochen und Gelenke noch!";
                break;

            case 18:

                textPosition(58, 8);  std::cout << "Ein Loch im Boden... mit einer rostigen, abbruchreifen Leiter darin. Es geht hier";
                textPosition(58, 9);  std::cout << "definitiv nach unten. Von unten steigt Ihnen ein expliziter Geruch nach frischer";
                textPosition(58, 10); std::cout << "Kanalisation in die Nase. Lecker, man muss hier einfach seiner Nase folgen und";
                textPosition(58, 11); std::cout << "nach unten steigen. Jeder Sprossenabschnitt dieser antiken Leiter ist nicht nur";
                textPosition(58, 12); std::cout << "ein Schritt in eine ungewisse Zukunft, sondern auch eine Einladung zu olfaktorischen";
                textPosition(58, 13); std::cout << "Abenteurn! Ein wahres Fest für alle die, die keinen Geruchssinn mehr haben, ober";
                textPosition(58, 14); std::cout << "zufällig zuvor bei einer Ork-Leiche eine Nasenklammer oder einen Duftbaum gepluendert";
                textPosition(58, 15); std::cout << "haben! Da will ich mal das Beste fuer Sie hoffen, denn wenn ich selbst einen Wunsch";
                textPosition(58, 16); std::cout << "frei haette, so waere das Herabsteigen dieser Leiter garantiert auf dem letzten";
                textPosition(58, 17); std::cout << "Platz. Dennoch: The show must go on.... Also Nase zu und durch!";
                break;

            case 19:

                textPosition(58, 8);  std::cout << "Herzlich willkommen bei der Toilette des Gluecks. Das grosse Glueck besteht";
                textPosition(58, 9);  std::cout << "hauptsaechlich darin, sie gefunden zu haben. Wenn man schon mal hier vorbei";
                textPosition(58, 10); std::cout << "kommt, sollte man auf die Verunreinigungen und das zerfledderte Toilettenpapier";
                textPosition(58, 11); std::cout << "pfeifen und auch die Gelegenheit nutzen mal ordentlich einen ueber den Balken";
                textPosition(58, 12); std::cout << "zu donnern! ;D Schliesslich gilt: Wichtig ist was hinten raus kommt...";
                textPosition(58, 13); std::cout << "Kann ja durchaus auch sehr hilfreich sein, hier auf den Marmor-Thron zu steigen";
                textPosition(58, 14); std::cout << "und sich ein bisschen befreiter in dieser beklemmenden Umgebung zu fuehlen...";
                textPosition(58, 15); std::cout << "Wer weiss auch schon genau, warum diese Toilette diesen Namen traegt und";
                textPosition(58, 16); std::cout << "was genau bei Benutzung geschehen wird. Und den Leitspruch nicht vergessen:";
                textPosition(58, 17); std::cout << "\"Benutzt Toilettenpapier beidseitig und der Erfolg liegt auf der Hand!\"";
                break;

            case 20:

                textPosition(58, 8);  std::cout << "Das Grabmal des geschaendeten Kriegers... Die Inschrift besagt, dass hier die Gebeine";
                textPosition(58, 9);  std::cout << "von Groghar dem Schrecklichen ruhen. Die Frage ist, ob Sie nicht bereits seine Ruhe";
                textPosition(58, 10); std::cout << "durch Ihre blanke Anwesenheit stoeren. Weiter besagt die Inschrift, dass er selbst aus";
                textPosition(58, 11); std::cout << "dem Grab raus jeden vernichten wird, der vor hat sein Grab zu pluendern! Das er auferstehen";
                textPosition(58, 12); std::cout << "wird um seine Pluenderer auf ewig zu verfluchen und diese als Geist heimzusuchen... ";
                textPosition(58, 13); std::cout << "Sagen Sie mal, Sie haben nicht zufaellig eine Schaufel dabei, oder? Ein bisschen Grabraub";
                textPosition(58, 14); std::cout << "statt Ork-Leichen zu pluendern fehlt Ihnen ja eventuell noch auf der To-do-Liste...";
                textPosition(58, 15); std::cout << "Und ausserdem schien Groghar zu Lebzeiten ein sehr freundlicher und aufgeschlossener Mensch";
                textPosition(58, 16); std::cout << "gewesen zu sein! Es ist gerade so, als wuerde er Sie persoenlich aus dem Grabe heraus darum";
                textPosition(58, 17); std::cout << "bitten, seine Besitztuemer frohgemutes an sich zu nehmen...";
                break; 

            case 21:

                textPosition(58, 8);  std::cout << "Herzlichen Glueckwunsch! Sie haben sich den Weg bis zum totalitaeren Wunschbrunnen gebahnt!";
                textPosition(58, 9);  std::cout << "Sie haben nun die Moeglichkeit sich totalitaer verzaubern zu lassen! Das Ganze gegen eine";
                textPosition(58, 10); std::cout << "minimale Gebuehr von 10 Goldmuenzen. Der Dev und ich finden, dass der Preis hier vollkommen";
                textPosition(58, 11); std::cout << "klar geht. Lassen Sie sich nicht von dem Schild taeuschen, das besagt: \"Benutzung auf eigene";
                textPosition(58, 12); std::cout << "Gefahr! Die Preise im Spiegel koennen groesser sein, als sie erscheinen!\". Auch die leicht an-";
                textPosition(58, 13); std::cout << "gemooste Gummiente die auf der Oberflaeche des leicht gruenlich schimmernden Wassers schwimmt";
                textPosition(58, 14); std::cout << "sollteS ie nicht daran hindern, hier die ein oder andere Goldmuenze zu versenken!";
                textPosition(58, 15); std::cout << "Man munkelt uebrigens, dass der Brunnen das Feature unterstuetzt, auch aus ihm trinken zu";
                textPosition(58, 16); std::cout << "koennen. Soll wohl bei den ganzen Mineralien ne Art Vitalkur sein.... Allerdings wuerde ich";
                textPosition(58, 17); std::cout << "das an Ihrer Stelle auch eher unter dem Aspekt \"Auf eigene Gefahr!\" verbuchen! ";
                break;

            case 22:

                textPosition(58, 8);  std::cout << "";
                textPosition(58, 9);  std::cout << "";
                textPosition(58, 10); std::cout << "";
                textPosition(58, 11); std::cout << "";
                textPosition(58, 12); std::cout << "";
                textPosition(58, 13); std::cout << "";
                textPosition(58, 14); std::cout << "";
                textPosition(58, 15); std::cout << "";
                textPosition(58, 16); std::cout << "";
                textPosition(58, 17); std::cout << "";
                break;
        }
        return;
}

void enemyText(int kindOf)
{
    switch(kindOf)
    {
        case 0:

            textPosition(58, 12); std::cout << "Der gemeine Imp:";
            textPosition(58, 13); std::cout << "Ein garstiges kleines Biest, das hier im Dungeon herumstreunt und";
            textPosition(58, 14); std::cout << "eigentlich nur nervt. Allerdings sollte man diese kleinen Viehcher";
            textPosition(58, 15); std::cout << "aufgrund ihrer oftmals groesseren Anzahl nicht unterschaetzen!";
            textPosition(58, 16); std::cout << "----------------------------------------------------------------------------";
            break;
        
        case 1:
            textPosition(58, 12); std::cout << "Der garstige Goblin:";
            textPosition(58, 13); std::cout << "zaehlt nicht gerade zu den Endgegnern, kann aber, gerade in groesserer";
            textPosition(58, 14); std::cout << "Anzahl, dennoch ziemlich gefaehrlich werden! Also dennoch ein ernst- ";
            textPosition(58, 15); std::cout << "zunehmender Gegner....";
            textPosition(58, 16); std::cout << "----------------------------------------------------------------------------";
            break;

        case 2:

            textPosition(58, 12); std::cout << "Der grunzende Ork:";
            textPosition(58, 13); std::cout << "Er mag nach leckerem Schinken riechen, ist aber vor dem Verwursten";
            textPosition(58, 14); std::cout << "erstmal tot zu kriegen! Sicherlich nicht einer der leichteren Gegner!";
            textPosition(58, 15); std::cout << "Behalten Sie Ihren Gesundheitsstand unbedingt im Auge!";
            textPosition(58, 16); std::cout << "----------------------------------------------------------------------------";
            break;

        case 3:
            
            textPosition(58, 12); std::cout << "Der affige Oger:";
            textPosition(58, 13); std::cout << "Auch wenn es schon ganz witzig sein kann ihn auf Distanz dabei zu be-";
            textPosition(58, 14); std::cout << "bachten, wie er seinen Kot durch die Gegend wirft, ist er ein nicht";
            textPosition(58, 15); std::cout << "zu unterschaetzender boeswilliger Gegner!";
            textPosition(58, 16); std::cout << "----------------------------------------------------------------------------";
            break;

        case 4:
            
            textPosition(58, 12); std::cout << "Das putzige Killer-Karnickel:";
            textPosition(58, 13); std::cout << "So putzig und pelzig dieses Fellknaeuel auch ist, ist es quasi der";
            textPosition(58, 14); std::cout << "Hauptgewinn unter den boesen, gemeinen Gegner und kann sehr garstig";
            textPosition(58, 15); std::cout << "werden. Schaut euch nur seine todbringenden, gefaehrlichen Augen an!";
            textPosition(58, 16); std::cout << "----------------------------------------------------------------------------";
            break;
        
        case 5:

            textPosition(58, 12); std::cout << "Der toedliche Drache:";
            textPosition(58, 13); std::cout << "Auch wenn er auf den ersten Blick nicht ganz so schlimm aussieht, liegt das nur";
            textPosition(58, 14); std::cout << "an den ASCII - Kuensten des Programmierers! Lassen Sie sich nicht taeuschen! Ein";
            textPosition(58, 15); std::cout << "gefaehrlicher und toedlicher Gegner! Heilung vor Sonderangriff nicht vergessen!";
            textPosition(58, 16); std::cout << "----------------------------------------------------------------------------";
            break;

        case 6:

            textPosition(58, 12); std::cout << "Der heimtueckische Mimik:";
            textPosition(58, 13); std::cout << "Da will man nur mal seiner Gier froehnen und schon hat man mir nichts,";
            textPosition(58, 14); std::cout << "dir nichts dieses heimtueckische und zaehe Biest vor sich. Seine Angriffe";
            textPosition(58, 15); std::cout << "sind zwar nicht gerade die staerksten, aber er kann einstecken!";
            textPosition(58, 16); std::cout << "----------------------------------------------------------------------------";
            break;

        case 7:

            textPosition(58, 12); std::cout << "Groghar der Geschaendete:";
            textPosition(58, 13); std::cout << "Ihr konntet es nicht lassen und habt es herausgefordert. So habt Ihr";
            textPosition(58, 14); std::cout << "Seinen Zorn erweckt! Jetzt muesst Ihr mit seiner boeswilligkeit klar";
            textPosition(58, 15); std::cout << "kommen... Dabei war er zu Lebzeiten echt ein netter Kerl!";
            textPosition(58, 16); std::cout << "----------------------------------------------------------------------------";
            break;


    }
    return;
}
#endif