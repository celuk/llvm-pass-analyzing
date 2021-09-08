import os
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import openpyxl

folder = "C:\\Users\\shc\\Desktop\\ubuntu"
xls = "C:\\Users\\shc\\Desktop\\yf2.xlsx"
saveloc = "C:\\Users\\shc\\Desktop\\imgs\\"

sub_folders = [name for name in os.listdir(folder) if(os.path.isdir)(os.path.join(folder,name))]

for each in sub_folders:
    sub_folders = [name for name in os.listdir(folder) if(os.path.isdir)(os.path.join(folder,name))]

    df = pd.read_excel(xls, each)

    asmfile = []
    spltlist = []
    spltlistnum = []
    spltlistper = []

    #buyruk isimleri
    #buyruk sayıları
    #buyruk yüzdeleri

    counter = 0
    for (i, j, k) in zip(df[0], df[1], df[2]):
        if i != "------------":
            if ".s" in i or j != j or k != k:
                if "fft_input.s" not in i and "input.s" not in i and "input_small.s" not in i and "pm_input.s" not in i:
                    asmfile.append(i)
                    counter+=1
            else:
                spltlist.append([])
                spltlist[counter-1].append(i)
                spltlistnum.append([])
                spltlistnum[counter-1].append(float(j))
                spltlistper.append([])
                spltlistper[counter-1].append(k)

    for i in range (0, 42):
        plt.bar(spltlist[i], spltlistnum[i], color = plt.cm.Paired(np.arange(10))) #, label = asmfile[i])
        plt.title(each + "_" + asmfile[i])
        plt.xlabel("opcodes")
        plt.ylabel("number of opcodes")
        for j in range(len(spltlistnum[i])):
            plt.annotate(str(spltlistper[i][j]), xy=(spltlist[i][j], spltlistnum[i][j]), ha='center', va='bottom')
        
        if not os.path.exists(saveloc + each + "\\"):
            os.makedirs(saveloc + each + "\\")
        plt.savefig(saveloc + each + "\\" + each + "_" + asmfile[i] + ".png", dpi = 150)
        plt.clf()
