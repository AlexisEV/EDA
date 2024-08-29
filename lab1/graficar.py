import matplotlib.pyplot as plt 
import pandas as pd
dim = [10,50,100,500,1000,2000,5000]
archivos = ["dim_10.csv","dim_50.csv","dim_100.csv","dim_500.csv","dim_1000.csv","dim_2000.csv","dim_5000.csv"]

for i,archivo in enumerate(archivos):
    data = pd.read_csv(archivo,header=None).squeeze("columns")
    plt.figure(figsize=(10,6))
    plt.hist(data,edgecolor='black')
    plt.title(f"Histograma de las distancias entre puntos con dimension {dim[i]}")
    plt.xlabel("Distancia")
    plt.ylabel("Frecuencia")
    plt.xlim(left=0)
    plt.show()
