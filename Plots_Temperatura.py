#Este es python de las graficas
#Importamos los paquetes necesarios para realizar las graficas
import numpy as np
import matplotlib.pyplot as plt
#Leemos los datos y los guardamos en listas
data1 = open('data1.dat', 'r')
data1 = data1.readlines()
data2 = open('data2.dat','r')
data2 = data2.readlines()
data3 = open('data3.dat','r')
#Organizamos los datos de forma que nos queden en listas de forma que queden sin espacios
d1 = []
d2 = []
d3 = []
for i in range(data1):
	d1.append(data1[i].split())

