//// DateiOperationen.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
////
//
//#include <iostream>
//#include <fstream>
//#include <sstream>
//
//using namespace std;
//
//
//bool dateiErstellen(string);
//bool dateiLesen(string);
//bool dateiKopieren(string, string);
//void dateiInfo(string);
//int getByteCount(string);
//int getWordCount(string);
//int getLineCount(string);
//
//int main()
//{
//	string dateiname, quelldatei, zieldatei;
//
//
//	// Für die Ausgabe von Programmtexten mit Umlauten auf der Konsole
//	locale::global(locale("de_DE.utf-8"));
//
//
//	// 1. Erstellen einer neuen Datei
//	cout << "Bitte neuen Dateinamen eingeben: " << endl;
//	getline(cin, dateiname);
//
//	//if (!dateiErstellen(dateiname))
//	//{
//	//    // Beenden des Programms im Fehlerfall. Ubergabe des Parameterwert an das Betriebssystem
//	//    exit(-1);
//	//}
//
//	// Wenn die Funktion dateiErstellen() eine Ausnahmebedingung wirft.
//	try
//	{
//		dateiErstellen(dateiname);
//	}
//	catch (exception ex)
//	{
//		cerr << ex.what() << endl;
//		exit(-1);
//
//	}
//
//	// 2. Lesen der neu erstellten Datei und Anzeige der Zeilen
//	if (!dateiLesen(dateiname))
//		exit(-1);
//
//	// 3. Kopieren von beliebigen Dateien (auch binären Dateien)
//	cout << "Bitte den Namen der zu kopierenden Datei eingeben: " << endl;
//	getline(cin, quelldatei);
//
//	cout << "Bitte den Namen der Zieldatei eingeben: " << endl;
//	getline(cin, zieldatei);
//
//	if (!dateiKopieren(quelldatei, zieldatei))
//		exit(-1);
//
//
//	// 4. Datei Info
//	cout << "Datei Info: Bitte den Namen der Datei eingeben: " << endl;
//	getline(cin, dateiname);
//
//	dateiInfo(dateiname);
//
//
//}
//
//bool dateiErstellen(string dateiname)
//{
//	// #include <fstream>
//
//	// Objekt für den Datei-Ausgabestrom erstellen
//	// Der openmode ist standardmäßig ios::out, auch wenn er nicht explizit angegeben wurde
//	ofstream datei(dateiname, ios::out);
//
//	// Die Klasse setzt ein fail-Bit, wenn die Datei nicht geöffnet werden konnte
//	if (datei.fail())
//	{
//		//cerr << "Die Datei '" << dateiname << "' konnte nicht erstellt werden.\nProgrammabbruch!" << endl;
//		//return false;
//
//		// Für das Abfangen des Fehlers mit einer try/catch-Anweisung
//		throw runtime_error("Die Datei '" + dateiname + "' konnte nicht erstellt werden.\nProgrammabbruch!");
//	}
//
//	datei << "1. Textzeile.\n";
//	datei << "2. Textzeile.\n";
//	datei << "3. Textzeile.\n";
//
//	datei.close();
//
//	cout << "Die Datei wurde erfolgreich erstellt." << endl;
//	return true;
//
//}
//
//bool dateiLesen(string dateiname)
//{
//	string zeile;
//
//	// Der openmode ist standardmässig ios::in, auch wenn er nicht explizit angegeben wurde.
//	ifstream datei(dateiname, ios::in);
//
//	// Die Klasse setzt ein fail-Bit, wenn die Die Datei nicht geöffnet werden konnte.
//	if (datei.fail())
//	{
//		cerr << "Die Datei '" << dateiname << "' konnte nicht geöffnet werden.\nProgrammabbruch!" << endl;
//		return false;
//	}
//
//	cout << "Alle Datensätze von '" << dateiname << "':\n";
//
//	while (!datei.eof())
//	{
//		getline(datei, zeile);
//		cout << zeile << endl;
//	}
//
//	datei.close();
//
//	return true;
//
//}
//
//bool dateiKopieren(string quelldatei, string zieldatei)
//{
//	// Ohne ios::binary wären nur Textdateien kopierbar. 
//	// Der Schalter ios::binary verhindert, dass die Umwandlung der Zeilenendekennung
//	// \n in CR/LF (= 0x0D 0x0A) automatisch beim Schreiben beziehungsweise zurück 
//	// beim Lesen erfolgen soll (nur bei Windows von Bedeutung). 
//	// Dateien beliebigen Inhalts (binäre Dateien) haben keine Zeilenstruktur.
//
//	// Der openmode ist standardmässig ios::in, auch wenn er nicht explizit angegeben wurde.
//	// ios::binary bedeuted, dass alle Operationen im Binär-Modus anstatt im Text-Modus ausgeführt werden
//	// Text-Modus ist der Standardwert.
//	ifstream quelle(quelldatei, ios::in | ios::binary);
//
//	// Die Klasse setzt ein fail-Bit, wenn die Die Datei nicht geöffnet werden konnte.
//	if (quelle.fail())
//	{
//		cerr << "Die Datei '" << quelldatei << "' konnte nicht geöffnet werden.\nProgrammabbruch!" << endl;
//		return false;
//	}
//
//	ofstream ziel(zieldatei, ios::out | ios::binary);
//
//	// Die Klasse setzt ein fail-Bit, wenn die Die Datei nicht geöffnet werden konnte.
//	if (ziel.fail())
//	{
//		cerr << "Die Datei '" << zieldatei << "' konnte nicht geöffnet werden.\nProgrammabbruch!" << endl;
//		quelle.close();
//		return false;
//	}
//
//	// Gesamte Datei kopieren
//	ziel << quelle.rdbuf();
//
//	quelle.close();
//	ziel.close();
//
//	cout << "\nKopieren erfolgreich beendet.\n";
//
//	return true;
//
//}
//
//void dateiInfo(string dateiname)
//{
//	cout << "Datei Info   : " << dateiname << endl;
//	printf("Anzahl Zeichen: %d\n", getByteCount(dateiname));
//	printf("Anzahl Wörter : %d\n", getWordCount(dateiname));
//	printf("Anzahl Zeilen : %d\n", getLineCount(dateiname));
//	cout << endl;
//
//}
//
//int getByteCount(string dateiname)
//{
//	int retValue = 0;
//	char c;
//
//	ifstream datei(dateiname, ios::in | ios::binary);
//
//	// Die Klasse setzt ein fail-Bit, wenn die Die Datei nicht geöffnet werden konnte.
//	if (datei.fail())
//	{
//		cerr << "Die Datei '" << dateiname << "' konnte nicht geöffnet werden.\nProgrammabbruch!" << endl;
//		return retValue;
//	}
//
//	//while (datei.get(c))
//	//{
//	//    retValue++;
//	//}
//
//	// Den Zeiger vom Anfang an das Ende der Datei positionieren
//	datei.seekg(0, ios::end);
//	// Liefert die aktuelle Position des Dateizeigers zurück 
//	retValue = datei.tellg();
//
//	datei.close();
//
//	return retValue;
//}
//
//int getWordCount(string dateiname)
//{
//	int retValue = 0;
//	string word;
//
//	ifstream datei(dateiname, ios::in);
//
//	// Die Klasse setzt ein fail-Bit, wenn die Die Datei nicht geöffnet werden konnte.
//	if (datei.fail())
//	{
//		cerr << "Die Datei '" << dateiname << "' konnte nicht geöffnet werden.\nProgrammabbruch!" << endl;
//		return retValue;
//	}
//
//	// Als "Wort" gilt jede Folge von Zeichen außer Leerzeichen, Tabulator und Zeilenumbruch,
//	while (!datei.eof())
//	{
//
//		datei >> word;
//
//		// Das letzte Wort endet mit CR/LF.
//		// Das Dateiende wird dadurch erst beim nächsten Schleifendurchlauf erkannt.
//		// Deshalb nach dem Zählen das Wort leeren und innerhalb der Schleife
//		// abfragen, ab die Anzahl der Zeichen des Worts grösser 0 ist.
//		if (word.length() > 0)
//			retValue++;
//
//		word = "";
//	}
//
//	datei.close();
//
//	return retValue;
//}
//
//int getLineCount(string dateiname)
//{
//	int retValue = 0;
//	string zeile;
//
//	ifstream datei(dateiname, ios::in);
//
//	// Die Klasse setzt ein fail-Bit, wenn die Die Datei nicht geöffnet werden konnte.
//	if (datei.fail())
//	{
//		cerr << "Die Datei '" << dateiname << "' konnte nicht geöffnet werden.\nProgrammabbruch!" << endl;
//		return retValue;
//	}
//
//	while (!datei.eof())
//	{
//		getline(datei, zeile);
//		retValue++;
//	}
//
//	return retValue;
//}
//
//
//
//
//// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
//// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"
//
//// Tipps für den Einstieg: 
////   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
////   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
////   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
////   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
////   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
////   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
