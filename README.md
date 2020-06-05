# Informatik_4_Projekt
Veröffentlicht im GitHub Repository: https://github.com/iMazze/Informatik_4_Projekt
## Aufgabenstellung
Rechner für komplexe Zahlen
- Einlesen einer komplexen Zahl über die Konsole (Koeffizienten ODER Exponential- Darstellung)
- Einlesen einer zweiten komplexen Zahl über die Konsole (Koeffizienten ODER Exponential- Darstellung)
- Verarbeitung der beiden Zahlen (Grundrechenarten)
- Speicherung von Eingaben und Ergebnis als XML (Koeffizienten- UND Exponential-
Darstellung)
- Ausgabe des Ergebnisses über die Konsole (mit Nachfrage, ob Koeffizienten ODER
Exponential-Darstellung) 

Anstöße:
- Empfohlene XML-Bibliothek: LibXml2 (via NuGet)
- Einlesen/Ausgabe und BL als Bibliotheken/Module des Hauptprogramms

## Von uns verwendete Conventions
Documentation Style C++: http://doxygen.nl/manual/docblocks.html <br/>
Markdownfile Readme: https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet

## Diagramme
Activity<br/>
![Activitydiagram](UML/export/Activity.png)
Class<br/>
![Classdiagram](UML/export/Class.png)
Domain<br/>
![Domainmodel](UML/export/Domain.png)
Sequenzdiagram<br/>
![Sequenzdiagram](UML/export/Sequence.png)
Use-Case<br/>
![UseCaseModel](UML/export/Use_Case.png)


## Compilieren der Software Complex_Calculator
Abgabe des "Rohprojekts" via Moodle:
- Entpacken der *.zip Datei "Informatik_4_Projekt.zip"
- Öffnen der Datei Source/complex_calculator/complex_calculator.sln mit Visual Studio (2017)
- Umstellen auf Debug -> x86 Projekt
- Fehlende Packages laut Datei Source\complex_calculator\complex_calculator\packages.conf via NuGET herunterladen
- NuGET via Rechtsklick auf Projektmappe im Projektmappenexplorer -> NuGET Pakete Wiederherstellen oder NuGET Pakete für Projektmappe verwalten

Projekt via Github:
- Clonen des Projekts mit `git clone https://github.com/iMazze/Informatik_4_Projekt.git`
- Öffnen der Datei Source/complex_calculator/complex_calculator.sln mit Visual Studio (2017)

Beide:
- Compilieren mit `Erstellen -> Projektmappe Erstellen`
- Debugging mit `Lokaler Windows-Debugger`

## Ordnerstruktur
Informatik_4_Projekt
- README.md: Aktuelles File mit allen Infos zum Programm
- doxygen
  - Doxyfile: Doxygen Konfiguration
  - html/index.html: Gerenderte Dokumentation
- Source/complex_calculator
  - complex_calculator.sln: Visual Studio Projektdatei
  - Debug: compilierte *.exe Files
  - complex_calculator: Ordner mit C++ und H Dateien
  - packages: Abhängigkeiten von Libraries
- UML
  - diagrams.EAP: Enterprise Architect Projekt der Diagramme
  - export: Ordner mit allen gerenderten PDF Dateien

## Kurzanleitung zur Software Complex_Calculator
### Ausführung des Programms
text
- Wo ist exe datei?
- Ausgabe der XML in Source\complex_calculator\complex_calculator\Berechnungen_Complex_2020-06-05_11-57.xml
### Abstrahierung der Layer
text
### Lebenszeit der Objekte
text
### Errorhandling
Alle möglichen auftretenden Fehler (unseres Wissenstands entsprechend) werden als std::Exception ausgegeben. Bedeutet dass bei auftreten dieser Fehler via `throw` ausgelöst wird. 
Zur Laufzeit erkennt dann die Klasse Calculator_Logic (welche auch die komplette Aufrufhierarchie beinhaltet), falls so ein Fehler auftritt. 
Darauf wird die aktuelle Operation abgebrochen sowie ein Fehler wie in der Datei "Messages.h" beschrieben an den User ausgegeben.
### Unit - Tests
Unsere Testcases sind alle via dem Framework Catch2 welches sich als eine einzige *.hpp Datei ins Projekt einbinden lässt.
Die Testcases decken folgende Klassen ab: complex, calculation (einmal mit std::int, einmal mit complex), XML_Writer, UI_Communication, Calculator_Logic.
Wir haben versucht alle möglichen Grenzfälle sowie Spezial-Fälle abzudecken. 


# Nur für Autoren relevant
## push Files with size>100Mbits:
$ git rm --cached your_giant_file
$ git commit --amend -CHEAD
$ git push

## Todoooo for Johannes
- throw exceptions
- text Ausführung des Programms
- text Abstrahierung der Layer
- text Lebenszeit der Objekte