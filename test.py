# import os 

# filepath = "C:\\Users\\dkueh\\OneDrive\\Dokumente\\Programming\\TSOV Filter-Konverter\\Dokumente\\numberlist.csv"

# #Filepath für neue Datei 
# new_dir = os.path.join(os.path.dirname(filepath))

# #Ursprungsdatei aus new_dir exrahieren
# for element in os.listdir(new_dir): 
#     if element in filepath: 
#         file = element.strip(".csv")
#     else: 
#         continue


# #filename generieren
# filename = file + "_Converted.txt"
# file_number = 0 
# for i in range(0, len(os.listdir(new_dir))): 
#     if filename in os.listdir(new_dir): 
#         filename = filename.replace("(" + str(file_number) + ")", "")
#         file_number = file_number + 1
#         replace = "(" + str(file_number) + ").txt"
#         filename = filename.replace(".txt", replace)     
#     else: 
#         continue

# print(filename)
import csv 

filepath = "D:\\Untitled discover search\\test.csv" 
old_match_phrase = "reg_common_calling_party_number" 

def dasd(): 
    search_list = []
    search_counter = 0
    with open(filepath, newline="", encoding="UTF-8") as oldfile: 
        reader = csv.reader(oldfile, delimiter=";", quotechar='"', dialect="unix")
        for line in reader:
            # if len(line) == 1 : 
            #     print("Spalten konnten nicht erkannt werden, .csv-Datei korrupt") 
            #     return 
            # else: 
                for element in line: 
                    search_list.append(element)
                break 


    #Search-Counter finden für Match-Phrase
    for element in search_list: 
        if old_match_phrase in element: 
            break
        else: 
            search_counter = search_counter + 1
    print(search_counter)
    print(search_list[0])

dasd() 