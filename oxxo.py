from threading import Semaphore
from time import sleep
import random, os

#variables globales
maxClientes = 4         #maximo de clientes en UNA caja
Clientes = []         #clientes dados por el usuario 


#mutexes a usar
caja1 = Semaphore(maxClientes)          #Un mutex de la caja 1, se usa el máximo de clientes
caja2 = Semaphore(maxClientes)
tramites = Semaphore(0)                 #Mutex por si se hace algún deposito o pago de servicio
pago = Semaphore(1)                     #Mutex de pago realizado por el cliente

def numClientes():
    global Clientes
    #Se introduce manualmente el número de clientes para ser despachados
    Clientes = int(input("Introducir cuantos clientes seran despachados>> "))
    caja1.acquire()
    if (round(Clientes) >= 4):       #si el numero de clientes es mayor o igual al número de clientes se adquieren ambas cajas
        os.system("clear")
        print("El numero de clientes es mayor al permitido. Habilitando la caja 2...")
        caja2.acquire()
        sleep(3)
        

numClientes()