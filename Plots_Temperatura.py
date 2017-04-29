from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import numpy as np
c = 0
D1, A1 = open('surface_no_forcing.txt','r').readlines(), open('Averages_no_forcing.dat','r').readlines()
t = []
a = []
S = []
for i in range(len(A1)):
    line = A1[i].split()
    t.append(float(line[0]))
    a.append(float(line[1]))
for i in range(len(D1)):
    try:
        line = np.array(D1[i].split()).astype(float)
        S.append(line)
    except ValueError: 
        c+=1
        fig = plt.figure()
        ax = fig.gca(projection='3d')
        X = np.arange(0, 1, 0.01)
        Y = np.arange(0, 1, 0.01)
        X, Y = np.meshgrid(X, Y)
        surf = ax.plot_surface(X, Y, S, cmap=cm.coolwarm,linewidth=0, antialiased=False)
        ax.zaxis.set_major_locator(LinearLocator(10))
        ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
        fig.colorbar(surf, shrink=0.5, aspect=5)
        ax.set_zlabel("Temperatura (C)")
        if(D1[i]=="t=100\n"):ax.set_title("t=0")
        if(D1[i]=="t=2500\n"):ax.set_title("t=100")
        if(D1[i]=="ENDENDENDENDEND"):ax.set_title("t=2500")
        link = "surface_plot"+str(c)+".png"
        plt.savefig(link)
        plt.close()
        S=[]


        
D1, A1 = open('surface_forcing.txt','r').readlines(), open('Averages_forcing.dat','r').readlines()
t1 = []
a1 = []
S = []
for i in range(len(A1)):
    line = A1[i].split()
    t1.append(float(line[0]))
    a1.append(float(line[1]))

for i in range(len(D1)):
    try:
        line = np.array(D1[i].split()).astype(float)
        S.append(line)
    except ValueError: 
        c+=1
        fig = plt.figure()
        ax = fig.gca(projection='3d')
        X = np.arange(0, 1, 0.01)
        Y = np.arange(0, 1, 0.01)
        X, Y = np.meshgrid(X, Y)
        surf = ax.plot_surface(X, Y, S, cmap=cm.coolwarm,linewidth=0, antialiased=False)
        ax.zaxis.set_major_locator(LinearLocator(10))
        ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
        fig.colorbar(surf, shrink=0.5, aspect=5)
        ax.set_zlabel("Temperatura (C)")
        if(D1[i]=="t=100\n"):ax.set_title("t=0")
        if(D1[i]=="t=2500\n"):ax.set_title("t=100")
        if(D1[i]=="ENDENDENDENDEND"):ax.set_title("t=2500")
        link = "surface_plot"+str(c)+".png"
        plt.savefig(link)
        plt.close()
        S=[]

D1, A1 = open('surface_no_forcing_periodic.txt','r').readlines(), open('Averages_no_forcing_periodic.dat','r').readlines()
t2 = []
a2 = []
S = []
for i in range(len(A1)):
    line = A1[i].split()
    t2.append(float(line[0]))
    a2.append(float(line[1]))

for i in range(len(D1)):
    try:
        line = np.array(D1[i].split()).astype(float)
        S.append(line)
    except ValueError: 
        c+=1
        fig = plt.figure()
        ax = fig.gca(projection='3d')
        X = np.arange(0, 1, 0.01)
        Y = np.arange(0, 1, 0.01)
        X, Y = np.meshgrid(X, Y)
        surf = ax.plot_surface(X, Y, S, cmap=cm.coolwarm,linewidth=0, antialiased=False)
        ax.zaxis.set_major_locator(LinearLocator(10))
        ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
        fig.colorbar(surf, shrink=0.5, aspect=5)
        ax.set_zlabel("Temperatura (C)")
        if(D1[i]=="t=100\n"):ax.set_title("t=0")
        if(D1[i]=="t=2500\n"):ax.set_title("t=100")
        if(D1[i]=="ENDENDENDENDEND"):ax.set_title("t=2500")
        link = "surface_plot"+str(c)+".png"
        plt.savefig(link)
        plt.close()
        S=[]        


D1, A1 = open('surface_forcing_periodic.txt','r').readlines(), open('Averages_forcing_periodic.dat','r').readlines()
t3 = []
a3 = []
S = []
for i in range(len(A1)):
    line = A1[i].split()
    t3.append(float(line[0]))
    a3.append(float(line[1]))

for i in range(len(D1)):
    try:
        line = np.array(D1[i].split()).astype(float)
        S.append(line)
    except ValueError: 
        c+=1
        fig = plt.figure()
        ax = fig.gca(projection='3d')
        X = np.arange(0, 1, 0.01)
        Y = np.arange(0, 1, 0.01)
        X, Y = np.meshgrid(X, Y)
        surf = ax.plot_surface(X, Y, S, cmap=cm.coolwarm,linewidth=0, antialiased=False)
        ax.zaxis.set_major_locator(LinearLocator(10))
        ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
        fig.colorbar(surf, shrink=0.5, aspect=5)
        ax.set_zlabel("Temperatura (C)")
        if(D1[i]=="t=100\n"):ax.set_title("t=0")
        if(D1[i]=="t=2500\n"):ax.set_title("t=100")
        if(D1[i]=="ENDENDENDENDEND"):ax.set_title("t=2500")
        link = "surface_plot"+str(c)+".png"
        plt.savefig(link)
        plt.close()
        S=[]
        
D1, A1 = open('surface_no_forcing_open.txt','r').readlines(), open('Averages_no_forcing_open.dat','r').readlines()
t4 = []
a4 = []
S = []
for i in range(len(A1)):
    line = A1[i].split()
    t4.append(float(line[0]))
    a4.append(float(line[1]))

for i in range(len(D1)):
    try:
        line = np.array(D1[i].split()).astype(float)
        S.append(line)
    except ValueError: 
        c+=1
        fig = plt.figure()
        ax = fig.gca(projection='3d')
        X = np.arange(0, 1, 0.01)
        Y = np.arange(0, 1, 0.01)
        X, Y = np.meshgrid(X, Y)
        surf = ax.plot_surface(X, Y, S, cmap=cm.coolwarm,linewidth=0, antialiased=False)
        ax.zaxis.set_major_locator(LinearLocator(10))
        ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
        fig.colorbar(surf, shrink=0.5, aspect=5)
        ax.set_zlabel("Temperatura (C)")
        if(D1[i]=="t=100\n"):ax.set_title("t=0")
        if(D1[i]=="t=2500\n"):ax.set_title("t=100")
        if(D1[i]=="ENDENDENDENDEND"):ax.set_title("t=2500")
        link = "surface_plot"+str(c)+".png"
        plt.savefig(link)
        plt.close()
        S=[]        


D1, A1 = open('surface_forcing_open.txt','r').readlines(), open('Averages_forcing_open.dat','r').readlines()
t5 = []
a5 = []
S = []
for i in range(len(A1)):
    line = A1[i].split()
    t5.append(float(line[0]))
    a5.append(float(line[1]))

for i in range(len(D1)):
    try:
        line = np.array(D1[i].split()).astype(float)
        S.append(line)
    except ValueError: 
        c+=1
        fig = plt.figure()
        ax = fig.gca(projection='3d')
        X = np.arange(0, 1, 0.01)
        Y = np.arange(0, 1, 0.01)
        X, Y = np.meshgrid(X, Y)
        surf = ax.plot_surface(X, Y, S, cmap=cm.coolwarm,linewidth=0, antialiased=False)
        ax.zaxis.set_major_locator(LinearLocator(10))
        ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
        fig.colorbar(surf, shrink=0.5, aspect=5)
        ax.set_zlabel("Temperatura (C)")
        if(D1[i]=="t=100\n"):ax.set_title("t=0")
        if(D1[i]=="t=2500\n"):ax.set_title("t=100")
        if(D1[i]=="ENDENDENDENDEND"):ax.set_title("t=2500")
        link = "surface_plot"+str(c)+".png"
        plt.savefig(link)
        plt.close()
        S=[]
        
plt.plot(t,a,label="Fijas")
plt.plot(t2,a2,label="Periodicas")
plt.plot(t4,a4,label="Abiertas")
plt.title("Promedio de temperatura sin forzamiento")
plt.ylabel("Temperatura (C)")
plt.xlabel("Tiempo (s)")
plt.legend(loc=0)
plt.savefig("Averages1.png")
plt.close()
plt.plot(t1,a1,label="Fijas")
plt.plot(t3,a3,label="Periodicas")
plt.plot(t5,a5,label="Abiertas")
plt.title("Promedio de temperatura con forzamiento")
plt.ylabel("Temperatura (C)")
plt.xlabel("Tiempo (s)")
plt.legend(loc=0)
plt.savefig("Averages2.png")       
        
        
        
        
        
        
        
