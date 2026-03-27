Hinweis für Nutzer dieses Repositories

An alle, die dieses Repository testen oder forken möchten, vorab eine wichtige Information:

Der bereitgestellte Code ist aktuell nicht für die Ausführung auf GitHub geeignet. Dies liegt daran, dass die dort verwendete Terminalumgebung auf Linux basiert, während der Code speziell für Windows entwickelt wurde. Entsprechend werden Windows-spezifische Bibliotheken wie conio.h und windows.h verwendet, die unter Linux nicht unterstützt werden und daher Fehlermeldungen verursachen.

Darüber hinaus enthält das Projekt ANSI-Escape-Sequenzen zur Textformatierung (z. B. \033[94m oder \033[0m), deren Darstellung in Linux-basierten Shells nur eingeschränkt oder gar nicht funktioniert.

Bitte beachten Sie außerdem, dass sich das Projekt noch in einem frühen Entwicklungsstadium („work in progress“) befindet. In einigen Fällen kann es erforderlich sein, das Programm manuell (z. B. mit Strg + C) zu beenden.

Die Nutzung erfolgt daher auf eigene Verantwortung.

Viel Spaß beim Ausprobieren!

Mit freundlichen Grüßen
D.Bastian