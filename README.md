﻿# Informatik_4_Projekt
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

## Conventions
Documentation Style: http://doxygen.nl/manual/docblocks.html

## Diagramme
<object data="http://yoursite.com/the.pdf" type="application/pdf" width="700px" height="700px">
    <embed src="http://yoursite.com/the.pdf">
        <p>This browser does not support PDFs. Please download the PDF to view it: <a href="http://yoursite.com/the.pdf">Download PDF</a>.</p>
    </embed>
</object>

test 
![alt text](UML/export/test.png)

## push Files with size>100Mbits:
$ git rm --cached your_giant_file
$ git commit --amend -CHEAD
$ git push

## Todo for Johannes
- overwrite & Operator in Complex
- const    statement 
- buzzi added const Complex& für alle operatoren!
- // magnitude shoud not be negative! i = ui.stringToNumber("-7.1e^(-i81.8)"); REQUIRE_FALSE(i.getMag() == Approx(-7.1)); REQUIRE(i.getPhi() == Approx(-81.8));

## Todoooo for all
- throw exceptions
- Tests auf allen ebenen
- Schichten -> UML