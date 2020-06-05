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
Ziel des Informatik 4 Projekt war es, ein Rechner für komplexe Zahlen zu entwicklen. Dabei soll sowohl die Eingabe als Polar- oder kartesische Koordinaten möglich sein. Zum Schluss soll die Rechnung als XML-Datei gespeichert werden. 
Nach dem complilieren des Projekts stehen den Anwender 4 Möglichkeiten zur Verfügung. Er kann 0) das Programm schließen, 1) den Complex Rechner ausführen, 2) eine XML Datei erstellen oder 3) die Tascases einsehen. Verdeutlicht wird dieses Verhalten durch das aufgeführte Activity Diagramm. 
Wählt der Nutzer 1) Complex Rechner, kann er die gewünschte Rechnung durchführen in dem er die erste komplexe Zahle in polar xe^i(phi) oder kartesischer (a+bi) Form gefolgt von einem Operator (+,-,*,/) une einer zweiten komplexen Zahl in karteischer oder polar Form über Konsole eingibt. 
Nach der Durchführung der Rechnung gelangt der Nutzer wieder zum Ausgangspunkt des Programms und kann sich nun wieder entscheiden 0) das Programm zu schließen, 1) eine weitere Rechnung durchzuführen 2) die durchgeführte Rechung in einer XML-Datei zu speichern oder 3) die Test durchzuführen. Lässt der Nutzer eine XML Datei erstellen, liegt diese unter:
- Ausgabe der XML in \Informatik_4_Projekt\Source\complex_calculator\complex_calculator\Berechnungen_Complex_2020-06-05_11-57.xml
In der XML Datei ist sowohl die Rechnung als auch das Ergebnis in polar UND kartesischen Koordianten gespeichert. 

### Abstrahierung der Layer
In unserem Prgrammentwurf war es uns wichtig nach dem ISO-OSI Schichtmodell eine sinnvolle Softwarabstahierung zu genereieren. Durch die Abstahierung ist eine verbesserte Lesbarkeit und Widerverwendbarkeit der Klassen gewährleistet. Das Klassen Diagramm kann unter \Informatik_4_Projekt\UML\export eingesehen werden. Als abstarhierteste Schicht stellt die Calculator_Logic Klasse die Anwednung dem Nutzer zur Verfügung. Sie erbt von XML_Write und UI_Communication. In XML_ Write wird der ganze Prozess zum Erstellen der XML Datei gehandelt. UI_Communication dagegen händelt sämtliche Nutzer In/Outputs in der Console. Es war uns wichtig die Kommunikation mit dem Nutzer smart zugestallten und wollte nicht mit sämtlichen Abfragen der z.B. Darstellung arbeiten. Nach dem KISS Prinzip (Keep it simple and stupid) soll der nutzer so intutiv wie möglich den Rechner nutzen können. Um dies zuermöglichen arbeiten wir mit String Manipulationen und suchen nach Merkmalen in der Nutzereingabe um auf die jeweilige Darstellung zu schließen.Als Basis dient die Klasse Complex, in welcher sämtliche Operationen mit komplexen Zahlen (+,-,*,/) implementiert sind. Intern nutzt die Klasse die karteische Darstellung (a+bi) einer komplexen Zahl. Um wiederrum polar Koordinaten verwenden zu können wurden gewissen Transformationsfunktionen implementiert. Um die Rechnung mit komplexen Zahlen durchzuführen haben wir die Template Klasse Calculation implementiert. Der Vorteil einer Template Klasse ist, dass sie für verschiedene Datentypen eingesetzt werden können. In unserem Rechner wird bsp. der komplexe Datentyp verwendet andereseits können durch die Template Klasse auch andere Rechner mit z.B. dem Double Datentyp implemntiert werden. 

### Lebenszeit der Objekte
Zur Optimierung der Laufzeit haben wir darauf geachtet, dass Objekte der verschiedenen Klassen nur zu dem benötigten Zeitpunkt erstellt werden und für die notwendige Dauer leben. Im Sequenzdiagramm sieht man z.B. das ein Objekt der Klasse Calculator_Logic für über die gesamte Programmlaufzeit lebt. Dies ist nötig da der Programmablauf in ihr definiert ist. Als anderes Beispiel ist ein Objekt von Rechnung nur dann aktiv wenn zwei komplexe Zahlen und ein Operator über die Konsole eingeben wurde. Gleichermaßen ist der XML_Witer nicht dann aktiv wenn der Nutzer sich entscheidet seine Rechnungen als XML Datei zu speichern. 

### Errorhandling
Alle möglichen auftretenden Fehler (unseres Wissenstands entsprechend) werden als std::Exception ausgegeben. Bedeutet dass bei auftreten dieser Fehler via `throw` ausgelöst wird. 
Zur Laufzeit erkennt dann die Klasse Calculator_Logic (welche auch die komplette Aufrufhierarchie beinhaltet), falls so ein Fehler auftritt. 
Darauf wird die aktuelle Operation abgebrochen sowie ein Fehler wie in der Datei "Messages.h" beschrieben an den User ausgegeben.
### Unit - Tests
Unsere Testcases sind alle via dem Framework Catch2 implementiert, welches sich als eine einzige *.hpp Datei ins Projekt einbinden lässt.
Die Testcases decken folgende Klassen ab: complex, calculation (einmal mit std::int, einmal mit complex), XML_Writer, UI_Communication, Calculator_Logic.
Wir haben versucht alle möglichen Grenzfälle sowie Spezial-Fälle abzudecken. 


# Nur für Autoren relevant
## push Files with size>100Mbits:
$ git rm --cached your_giant_file
$ git commit --amend -CHEAD
$ git push

## Todoooo for Johannes
- throw exceptions
