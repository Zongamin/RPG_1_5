#ifndef TEXTS_H
#define TEXTS_H

#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>

/*Inhaltsverzeichnis:
    - roomTexts   -- case 0 = Eingang
                  -- case 1 = Doppeltür
                  -- case 2 = Wand
                  -- case 3 = Passage  
                  -- case 4 = Tuer
                  -- case 5 = Hebel
                  -- case 6 = Truhe
                  -- case 7 = Treppe nach oben*/

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
                position(58, 17); std::cout << "dieses Game! Fazit --> Hier: Einfach eine Wand.";
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
                
                position(58, 8);  std::cout << "Eine morsche Kerkertuer haengt halbherzig in der Mauer. Durch";
                position(58, 9);  std::cout << "die Gitterstaebe erblicken Sie ein grinsendes Skelett. Die Frage";
                position(58, 10); std::cout << "ist, ob es mit Ihnen oder ueber Sie lacht. Vielleiucht freut es";
                position(58, 11); std::cout << "sich auch einfach nur darueber, den Firlefanz im Dungeon nicht";
                position(58, 12); std::cout << "mehr mitmachen zu muessen. Hinter dem Skelett allerdings fuehrt"; 
                position(58, 13); std::cout << "eine Passage anscheinend tiefer in den Dungeon... und, wie";
                position(58, 14); std::cout << "koennte es auch anders sein, natuerlich ist die Kerkertuer ver-";
                position(58, 15); std::cout << "schlossen. Aber sowas von... Da kann nicht mal das Skelett im";
                position(58, 16); std::cout << "Inneren keine Hilfestellung leisten... Sie ist nicht zu oeffnen,";
                position(58, 17); std::cout << "es sei denn, Sie haben einen Schluessel in der Tasche!";
                break;

            case 5:
                
                position(58, 8);  std::cout << "Ein Hebel an der Wand (euphorisches glucksen)! Es fehlt eigentlich";
                position(58, 9);  std::cout << "nur noch die Aufschrift: \"Nicht ziehen\" um die Aufmerksamkeit und";
                position(58, 10); std::cout << "den Drang, den Hebel zu ziehen noch weiter zu steigern! Aber grund-";
                position(58, 11); std::cout << "saetzlich ist die Einladung den Hebel zu betaetigen da! Die Frage";
                position(58, 12); std::cout << "ist: Sind Sie der geborene Hebelheber oder nicht? Allerdings spricht"; 
                position(58, 13); std::cout << "auch die kaum erkenn bare Bodenplatte Baende... Aber dennoch ist nicht";
                position(58, 14); std::cout << "gesagt, dass es sich hierbei zwangslaeufig um eine Falle handeln muss.";
                position(58, 15); std::cout << "Auf Ihrer Linken Seite erscheint ein Engelchen und auf der Rechten";
                position(58, 16); std::cout << "ein Teufelchen. Teufelchen sagt: Zieh den Hebel! Und Engelchen sagt:";
                position(58, 17); std::cout << "Hast Du nicht gehört? Du sollst den Hebel ziehen! ";
                break;

            case 6:
                
                position(58, 8);  std::cout << "Da steht sie... Prächtig und doch irgendwie random....";
                position(58, 9);  std::cout << "Quasi ein klassisches Element in jedem Dungeon - Abenteuer! Ein \"Muss\"";
                position(58, 10); std::cout << "in jedem Spiel, dass auch nur ansatzweise was auf sich haelt! Ganz so";
                position(58, 11); std::cout << "schuechternd wie eine Jungfrau ueber ihre Jungfraeulichkeit ist sie ";
                position(58, 12); std::cout << "selbstverstaendlich verschlossen.... Die Frage ist: Haben Sie das er-"; 
                position(58, 13); std::cout << "forderliche Geschick, die Truhe zur Oeffnung zu ueberreden, oder einfach";
                position(58, 14); std::cout << "nur einen Schluessel im Gepaeck. So oder so sollten beide Optionen dazu";
                position(58, 15); std::cout << "fuehren, die Truhe oeffnen zu koennen.";
                position(58, 16); std::cout << "Was spricht dagegen, dass Geheimnis der Truhe loesen zu wollen? Die Ant-";
                position(58, 17); std::cout << "wort ist: Nichts! Ausser, Sie haben keinen Schluessel!";
                break;

            case 7:

                position(58, 8);  std::cout << "Is this the stairway to heaven? Eher weniger! Natuerlich ist es ein sehr";
                position(58, 9);  std::cout << "seltsames Gefuehl in einem Dungeon des Boesen, der offensichtlich in die";
                position(58, 10); std::cout << "Tiefe fuehren sollte, nach oben zu gehen! Es sei dem, Sie sind zuvor be-";
                position(58, 11); std::cout << "reits mehrmals nach unten gegangen. Leider laesst sich das nicht genau ";
                position(58, 12); std::cout << "vorraus sagen, denn schliesslich ist dieser Dungeon ja zufaellig aufgebaut"; 
                position(58, 13); std::cout << "und es liegt durchaus im Bereich des Moeglichen, dass Sie bereits mehrmals";
                position(58, 14); std::cout << "nach oben gegangen sind... Sollte dies der Fall sein, so bittet der Dev";
                position(58, 15); std::cout << "mehrmals um Verzeihung und Ihr Verstaendnis, dass er keinen tiefen Einfluss";
                position(58, 16); std::cout << "auf solche Nebensaechlichkeiten haben kann und so wie Sie, den Umstaenden";
                position(58, 17); std::cout << "schutzlos ausgeliefert ist!";
                break;

            case 8:
                                
                position(58, 8);  std::cout << "Oha, wer haette das nur Gedacht? Es geht nach unten. Tiefer in den Dungeon";
                position(58, 9);  std::cout << "hinein! Es wird tatsaechlich Zeit vom hohen Ross abzusteigen und tiefer in";
                position(58, 10); std::cout << "den endlosen Dungeon hinabzusteigen! Es gibt noch so viele Ogersocken und";
                position(58, 11); std::cout << "Unterhosen zu finden und zu entdecken, dass Sie jetzt nicht einfach auf-";
                position(58, 12); std::cout << "geben koennen! Wer weiss schon so genau, wo diese Untiefen noch hinfuehren"; 
                position(58, 13); std::cout << "koennen und ob nicht doch eventuell schon ein goldenes Haeufchen eines";
                position(58, 14); std::cout << "Drachens unter dieser nichtssagenden Treppe liegt! Checken Sie lieber mal";
                position(58, 15); std::cout << "die Gegend ab, bevor Sie weiterziehen! Desweiteren ist es bestimmt auch mal";
                position(58, 16); std::cout << "angenehm, in einem Dungeon mal weiter nach unten zu gehen. Sollte es so";
                position(58, 17); std::cout << "sein, dass der Zufall sie zuvor immer wieder nach oben gefuehrt hat...";
                break;
            
            case 9:
                
                position(58, 8);  std::cout << "Auch im tiefsten Dungeon kann man hier und da mal auf ein kleines Licht";
                position(58, 9);  std::cout << "oder halt eben auch auf ein groesseres Feuer in einem Ofen oder eben einer";
                position(58, 10); std::cout << "Schmiede treffen.... Die Glut im Schmelzofen scheint noch schoen heiß zu";
                position(58, 11); std::cout << "sein. Gerade richtig um Ihre Metalle darin schmelzen zu koennen und das ein";
                position(58, 12); std::cout << "oder andere brauchbare oder eben auch nicht brauchbare Schwert oder Schild"; 
                position(58, 13); std::cout << "herzustellen. Bei dieser Gelegenheit zuecken Sie lieber schnell Ihre Metalle,";
                position(58, 14); std::cout << "denn wer weiss schon ob und wann Sie in einem Zufallsgenerierten Dungeon mal";
                position(58, 15); std::cout << "wieder an einer Schmiede vorbeikommen! Auch lassen sich Waffen und Ruestungen";
                position(58, 16); std::cout << "wesentlich besser verkaufen als ein paar unanschauliche Brocken von Altmetall,";
                position(58, 17); std::cout << "Aluminium oder Kupfer.... Auf gehts!";
                break;

            case 10:
                
                position(58, 8);  std::cout << "Wer haette das in einem Dungeon erwartet.... es ist ein An- und Verkauf. Davor";
                position(58, 9);  std::cout << "steht ein listig dreinblickender Goblin, der sich grinsend die Haende reibt.";
                position(58, 10); std::cout << "\"Willkommen bei Duester Deals, wir haben Vieles was Sie suchen und vielleicht";
                position(58, 11); std::cout << "sogar gar nicht erst suchen! Unsere Waffen sind garantiert nur manchmal ver-";
                position(58, 12); std::cout << "flucht und die Fallen, die Sie hier sehen sind groesstenteils nur Ausstellungs-"; 
                position(58, 13); std::cout << "stuecke. Treten Sie naeher und finden Sie es heraus! Wir kaufen uebrigens Alles,";
                position(58, 14); std::cout << "was Sie loswerden moechten, denn sollten Sie hinter der naechsten Ecke sterben,";
                position(58, 15); std::cout << "plündern wir uns das Gold sowieso wieder zurueck! Hätten Sie eventuell Interesse";
                position(58, 16); std::cout << "an diesem unsichtbaren Umhang? Man spuert tatsaechlich ueberhaupt nicht, dass man";
                position(58, 17); std::cout << "ihn traegt.\", sagt der Goblin mit verwegenem Grinsen. Na dann mal shoppen gehen!";
                break;

            case 11:

                position(58, 8);  std::cout << "Unfassbar was sich der Programmierer dieses Spiels noch alles ausdenkt, was hier";
                position(58, 9);  std::cout << "so in einem Dungeon rum kreuchen und fleuchen soll! Langsam wird es Zeit mich mal";
                position(58, 10); std::cout << "bei Rising Systems zu beschweren! Das kann ich doch als Geschichtenschreiber, bzw.";
                position(58, 11); std::cout << "Erzähler hier gar nicht mehr glaubwuerdig an den Mann bringen!";
                position(58, 12); std::cout << "Aber bitte: Mitten in einer stillen Ecke des Dungeons finden Sie Glorg den Ork. Er";
                position(58, 13); std::cout << "ist der einzige Ork hier unten, der versucht die Herrschafft des Dungeons mittels";
                position(58, 14); std::cout << "Glücksspiel an sich zu reissen! Sein grimmiger Blick sagt Ihnen zwar, dass Sie es";
                position(58, 15); std::cout << "lieber bleibenlassen sollten, aber seine mit Gold gefüllten Taschen sagen Ihnen,";
                position(58, 16); std::cout << "dass Sie es auch gerne versuchen wuerden, es ihm genau aus den Selbigen zu entfer-";
                position(58, 17); std::cout << "nen und in Ihre eigenen wandern zu lassen.... Wollen Sie es versuchen?";
                break;

            case 12:

                position(58, 8);  std::cout << "";
                position(58, 9);  std::cout << "";
                position(58, 10); std::cout << "";
                position(58, 11); std::cout << "";
                position(58, 12); std::cout << "";
                position(58, 13); std::cout << "";
                position(58, 14); std::cout << "";
                position(58, 15); std::cout << "";
                position(58, 16); std::cout << "";
                position(58, 17); std::cout << "";
                break;
        }
        return;
}
#endif