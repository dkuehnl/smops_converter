#Lib-Import
from qtpy import QtWidgets 
import sys
import os  
import easygui
import csv


#QT-Window ImportP
from UI.mainwindow import Ui_MainWindow
app = QtWidgets.QApplication(sys.argv)

#Window definieren 
class MainWindow(QtWidgets.QMainWindow): 
    def __init__(self, parent = None): 
        super().__init__(parent)
        
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self) 
        self.setWindowTitle("SMOPS-Konverter v2.2")

        self.ui.btn_File_Browse.clicked.connect(self.file_browse)
        self.ui.le_Dateipfad.returnPressed.connect(self.extract_first_line)
        self.ui.btn_chg_delim.clicked.connect(self.extract_first_line)
        self.ui.btn_convert.clicked.connect(self.convert)
        self.ui.lbl_statusmeldung.hide()
        self.ui.btn_reset.clicked.connect(self.reset)
        self.ui.btn_Path_Browse.clicked.connect(self.path_browse)
        self.ui.btn_exit.clicked.connect(self.exit)
        self.ui.lbl_ergebnis.hide()

    def file_browse(self): 
        file = easygui.fileopenbox() 
        self.ui.lbl_statusmeldung.hide()
        self.ui.le_Dateipfad.setText(file)
        self.extract_first_line() 

    def path_browse(self): 
        dir = easygui.diropenbox()
        self.ui.le_new_Path.setText(dir)
    
    def extract_first_line(self): 
        file_path = self.ui.le_Dateipfad.text()
        self.ui.lbl_statusmeldung.hide()
        delim = self.ui.cb_Delim.currentText()

        #ComBox clearen
        cb_length = self.ui.cb_Spaltenwahl.count() 
        for i in range(0, cb_length): 
            self.ui.cb_Spaltenwahl.removeItem(i)
        self.ui.cb_Spaltenwahl.setItemText(0, "")

        #CSV einlesen + Spaltenbeschriftung als Auswahl setzen
        if file_path.endswith(".csv"): 
            with open(file_path, newline="", encoding="UTF-8") as oldfile: 
                reader = csv.reader(oldfile, delimiter=delim, quotechar='"', dialect="unix")
                for line in reader: 
                    if len(line) == 1: 
                        self.ui.lbl_statusmeldung.setText(".csv-Datei korrupt, Spalten konnte nicht erkannt werden.")
                        self.ui.lbl_statusmeldung.show()
                        return 
                    else: 
                        value_list = line
                        break
                for i in range(0, len(value_list)): 
                    self.ui.cb_Spaltenwahl.addItem(value_list[i])
        else: 
            self.ui.lbl_statusmeldung.setText("Achtung! Keine oder falsche Quell-Datei ausgewählt. .csv erforderlich")
            self.ui.lbl_statusmeldung.show()
            return

    def convert(self): 
        filepath = self.ui.le_Dateipfad.text() 
        
        ergebnis_fehler = self.fehlerschleife(filepath)
        if "Fehler 1" in ergebnis_fehler: 
            self.ui.lbl_statusmeldung.setText("Achtung! Keine oder falsche Quell-Datei ausgewählt. .csv erforderlich")
            self.ui.lbl_statusmeldung.show()
            return 
        elif "Feler 2" in ergebnis_fehler: 
            self.ui.lbl_statusmeldung.setText("Achtung! Keine Quell-Spalte ausgewählt")
            self.ui.lbl_statusmeldung.show()
            return
        elif "Fehler 3" in ergebnis_fehler: 
            self.ui.lbl_statusmeldung.setText("Achtung! keine Ziel-Konvertierung ausgewählt")
        else: 
            pass

        #Convert-Routine / Match-Phrases suchen und zwischenspeichern 
        old_match_phrase = self.ui.cb_Spaltenwahl.currentText() 
        if self.ui.tbw_programm.currentIndex() == 0: 
            result = self.convert_smops(filepath, old_match_phrase)
            if result is None: 
                self.ui.lbl_statusmeldung.setText("Fehler bei Convertierung.")
                self.ui.lbl_statusmeldung.show()
                return
            else: 
                old_value_count, other_count, duplicate_count, new_value_count, empty_line = result

        elif self.ui.tbw_programm.currentIndex() == 1: 
            result = self.convert_eosight(filepath, old_match_phrase)
            if result is None:
                self.ui.lbl_statusmeldung.setText("Fehler bei Convertierung.")
                self.ui.lbl_statusmeldung.show()
                return
            else: 
                old_value_count, other_count, duplicate_count, new_value_count, empty_line = result
        
        elif self.ui.tbw_programm.currentIndex() == 2: 
            result = self.convert_eoLive(filepath, old_match_phrase)
            if result is None: 
                self.ui.lbl_statusmeldung.setText("Fehler bei Convertierung.")
                self.ui.lbl_statusmeldung.show()
                return
            else:
                old_value_count, other_count, duplicate_count, new_value_count, empty_line = result
        else: 
            self.ui.lbl_statusmeldung.setText("Undefinierter Fehler.")
            self.ui.lbl_statusmeldung.show()
    

        self.ui.lbl_statusmeldung.setText("Konvertierung erfolgreich abgeschlossen.")
        self.ui.lbl_statusmeldung.show()
        self.ui.lbl_ergebnis.setText("Es wurden " + str(old_value_count) + " Zeilen eingelesen. \nDavon " + str(other_count) + " Other-Zeilen entfernt, " + str(duplicate_count) + " als Duplikate erkannt, " + str(empty_line) + " Leerzeilen und " + str(new_value_count) + " in den neuen Filter überschrieben.")
        self.ui.lbl_ergebnis.show()

    def convert_smops(self, filepath, old_match_phrase):
        new_match_phrase = ""

        if self.ui.cb_number.currentText() != "": 
            new_match_phrase = self.ui.cb_number.currentText() 
        elif self.ui.cb_ne.currentText() != "": 
            new_match_phrase = self.ui.cb_ne.currentText()
        elif self.ui.cb_reg_ne.currentText() != "": 
            new_match_phrase = self.ui.cb_reg_ne.currentText() 
        elif self.ui.le_alternativer_Filter_SMOPS.text() != "": 
            new_match_phrase = self.ui.le_alternativer_Filter_SMOPS.text() 
        else: 
            self.ui.lbl_statusmeldung.setText("Fehler! Keine Zielkonvertierung ausgewählt!")
            self.ui.lbl_statusmeldung.show()
            return
            
        #Convert-Routine / Ursprungsdatei einlesen
        result = self.get_unique_value_list(filepath, old_match_phrase)
        if result is None: 
            return None
        else: 
            unique_value_list, old_value_count, other_count, duplicate_count, empty_line = result
        
        #Ziel-Dateipfad und -namen generieren
        new_path = self.get_new_filepath("SMOPS")
    
        #Should or must not Auswahl + entsprechenden Filter bauen
        new_value_count = 0
        with open(new_path, "x") as newfile:
            if self.ui.rb_isoneof.isChecked() == True: 
                newfile.write("{\n" + '"query": {\n' + '"bool": {\n' + '"should": [\n')
                for i in range(0, len(unique_value_list)-1): 
                    new_value_count += 1
                    newfile.write("{\n" + '"match_phrase": {\n' + '"' + new_match_phrase + '": "' + unique_value_list[i] + '"\n' + "}\n" + "},\n")
                newfile.write("{\n" + '"match_phrase": {\n' + '"' + new_match_phrase + '": "' + unique_value_list[-1] + '"\n' + "}\n" + "}\n")
                new_value_count += 1
                newfile.write("],\n" + '"minimum_should_match": 1\n' + "}\n" + "}\n" + "}")

            elif self.ui.rb_isnotoneof.isChecked() == True: 
                newfile.write("{\n" + '"query": {\n' + '"bool": {\n' + '"must_not": [\n')
                for i in range(0, len(unique_value_list)-1): 
                    new_value_count += 1
                    newfile.write("{\n" + '"match_phrase": {\n' + '"' + new_match_phrase + '": "' + unique_value_list[i] + '"\n' + "}\n" + "},\n")
                newfile.write("{\n" + '"match_phrase": {\n' + '"' + new_match_phrase + '": "' + unique_value_list[-1] + '"\n' + "}\n" + "}\n")
                new_value_count += 1
                newfile.write("],\n" + '"minimum_should_match": 1\n' + "}\n" + "}\n" + "}")

        return old_value_count, other_count, duplicate_count, new_value_count, empty_line


    def convert_eosight(self, filepath, old_match_phrase):

        if self.ui.cb_number_eoSight.currentText() != "":
            new_match_phrase = self.ui.cb_number_eoSight.currentText()
        elif self.ui.le_alternativer_Filter_eoSight.text() != "": 
            new_match_phrase = self.ui.le_alternativer_Filter_eoSight.text() 
        else: 
            self.ui.lbl_statusmeldung.setText("Fehler! Keine Zielkonvertierung ausgewählt!")
            self.ui.lbl_statusmeldung.show()
            return 

        #Convert-Routine / Ursprungsdatei einlesen
        result = self.get_unique_value_list(filepath, old_match_phrase)
        if result is None: 
            return None
        else: 
            unique_value_list, old_value_count, other_count, duplicate_count, empty_line = result            
        #Ziel-Dateipfad und -namen generieren
        new_path = self.get_new_filepath("eoSight")

        #Should or must not Auswahl + entsprechenden Filter bauen
        new_value_count = 0
        with open(new_path, "x") as newfile:
            if self.ui.rb_eoSight_contains.isChecked() == True: 
                for i in range(0, len(unique_value_list)-1): 
                    new_value_count += 1
                    newfile.write("CONTAINS(["+ new_match_phrase + '], "' + unique_value_list[i] + '") or ')
                newfile.write("CONTAINS([" + new_match_phrase + '], "' + unique_value_list[-1] + '")')
                new_value_count += 1
            elif self.ui.rb_eoSight_equal.isChecked() == True: 
                for i in range(0, len(unique_value_list)-1): 
                    new_value_count += 1
                    newfile.write("[" + new_match_phrase + '] = "' + unique_value_list[i] + '" or ')
                newfile.write("[" + new_match_phrase + '] = "' + unique_value_list[-1] + '"')
                new_value_count += 1
            
        return old_value_count, other_count, duplicate_count, new_value_count, empty_line

    def convert_eoLive(self, filepath, old_match_phrase):

        if self.ui.cb_number_eoLive.currentText() != "":
            new_match_phrase = self.ui.cb_number_eoSight.currentText()
        elif self.ui.le_alternativer_Filter_eoLive.text() != "": 
            new_match_phrase = self.ui.le_alternativer_Filter_eoLive.text() 
        else: 
            self.ui.lbl_statusmeldung.setText("Fehler! Keine Zielkonvertierung ausgewählt!")
            self.ui.lbl_statusmeldung.show()
            return 

        #Convert-Routine / Ursprungsdatei einlesen
        result = self.get_unique_value_list(filepath, old_match_phrase)
        if result is None: 
            return None
        else: 
            unique_value_list, old_value_count, other_count, duplicate_count, empty_line = result            
        #Ziel-Dateipfad und -namen generieren
        new_path = self.get_new_filepath("eoLive")

        #Should or must not Auswahl + entsprechenden Filter bauen
        new_value_count = 0
        with open(new_path, "x") as newfile:
            if self.ui.rb_eoLive_begin.isChecked() == True:
                newfile.write("[" + new_match_phrase + "] begins (")
                for i in range(0, len(unique_value_list)-1):
                    new_value_count += 1
                    newfile.write('"' + unique_value_list[i] + '",')
                newfile.write('"' + unique_value_list[-1] + '")')
                new_value_count += 1
        return old_value_count, other_count, duplicate_count, new_value_count, empty_line
    
    def get_unique_value_list(self, filepath, old_match_phrase): 
        search_list = []
        search_counter = 0
        delim = self.ui.cb_Delim.currentText() 
        with open(filepath, newline="", encoding="UTF-8") as oldfile: 
            reader = csv.reader(oldfile, delimiter=delim, quotechar='"', dialect="unix")
            for line in reader:
                if len(line) == 1: 
                    self.ui.lbl_statusmeldung.setText(".csv-Datei korrupt, Spalten konnte nicht erkannt werden.")
                    self.ui.lbl_statusmeldung.show()
                    return 
                else: 
                    for element in line: 
                        search_list.append(element) 
                    break             
            #Search-Counter finden für Match-Phrase
            for element in search_list: 
                if old_match_phrase in element: 
                    break
                else: 
                    search_counter += + 1
            
            #Convertierungs-Routine 
            old_value_count = 0
            set_counter = 0
            empty_line = 0
            value_list = []
            with open(filepath, newline="", encoding="UTF-8") as oldfile: 
                reader = csv.reader(oldfile, delimiter=delim, quotechar='"', dialect="unix")
                for line in reader:
                    if len(line) == 1: 
                        self.ui.lbl_statusmeldung.setText(".csv-Datei korrupt, Spalten konnte nicht erkannt werden.")
                        self.ui.lbl_statusmeldung.show()
                        return 
                    else: 
                        if set_counter == 0: 
                            set_counter += + 1
                            continue
                        else: 
                            if len(line) != 0:
                                old_value_count +=+ 1
                                value_list.append(line[search_counter])   
                            else: 
                                empty_line +=1

            #value_list aufräumen -entfernen von Other-Einträgen
            other_count = 0
            for element in value_list: 
                if "Other" in element: 
                    other_count += + 1
                    value_list.remove(element)
                else: 
                    continue

            #Duplikate in value_list entfernen 
            unique_value_list = []
            duplicate_count = 0
            for value in value_list: 
                if value not in unique_value_list: 
                    unique_value_list.append(value)
                else: 
                    duplicate_count += + 1
                    continue

        return unique_value_list, old_value_count, other_count, duplicate_count, empty_line

    def get_new_filepath(self, kind): 
        #Wahl des Pfades anhand der Eingaben
        if self.ui.le_new_Path.text() == "Bitte Dateipfad einfügen ": 
            filepath = self.ui.le_Dateipfad.text() 
        else: 
            filepath = self.ui.le_new_Path
        
        #Filepath für neue Datei 
        new_dir = os.path.join(os.path.dirname(filepath))

        #Ursprungsdatei aus new_dir exrahieren
        for element in os.listdir(new_dir): 
            if element in filepath: 
                file = element.strip(".csv")
            else: 
                continue


        #filename generieren
        filename = file + "_" + kind + "_Converted.txt"
        file_number = 0 
        for i in range(0, len(os.listdir(new_dir))): 
            if filename in os.listdir(new_dir): 
                filename = filename.replace("(" + str(file_number) + ")", "")
                file_number = file_number + 1
                replace = "(" + str(file_number) + ").txt"
                filename = filename.replace(".txt", replace)     
            else: 
                continue
                
        #Dateipfad bauen
        new_path = new_dir + "\\" + filename
        return new_path 
         
    def fehlerschleife(self, filepath): 
        #Fehlerabfrage
        if not filepath.endswith(".csv"): 
            return "Fehler 1"
        else: 
            if self.ui.cb_Spaltenwahl.itemText(0) == "": 
                return "Fehler 2" 
            else: 
                if self.ui.cb_ne.currentText() == "" and self.ui.cb_reg_ne.currentText() == "" and self.ui.cb_number.currentText() == "" and (self.ui.le_alternativer_Filter_SMOPS.text() == "" or self.ui.le_alternativer_Filter_eoSight.text() == "" or self.ui.le_alternativer_Filter_eoLive.text() == ""): 
                    return "Fehler 3" 
                else: 
                    return "Alles gut"

    def reset(self): 
        #Reset-Routine
        self.ui.le_Dateipfad.setText("Bitte Dateipfad einfügen ")
        cb_length = self.ui.cb_Spaltenwahl.count() 
        for i in range(0, cb_length): 
            self.ui.cb_Spaltenwahl.removeItem(i)
        self.ui.cb_Spaltenwahl.setItemText(0, "")
        self.ui.le_alternativer_Filter_SMOPS.setText("")
        self.ui.le_alternativer_Filter_eoSight.setText("")
        self.ui.le_alternativer_Filter_eoLive.setText("")
        self.ui.le_new_Path.setText("Bitte Dateipfad einfügen ")  
        self.ui.cb_ne.setCurrentIndex(0)
        self.ui.cb_number.setCurrentIndex(0)
        self.ui.cb_reg_ne.setCurrentIndex(0)
        self.ui.lbl_statusmeldung.hide()
        self.ui.lbl_ergebnis.hide()

    def exit(self): 
        window.close()

#Window aufbauen
window = MainWindow() 
window.show() 

sys.exit(app.exec_())



    

