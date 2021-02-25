from threading import Semaphore
from time import sleep
import random

#variables globales
maxClientes = 4         #maximo de clientes en UNA caja
Clientes = []           #clientes dados por el usuario 


#mutexes a usar
caja1 = Semaphore(maxClientes)          #Un mutex de la caja 1, se usa el máximo de clientes
caja2 = Semaphore(maxClientes)
tramites = Semaphore(0)                 #Mutex por si se hace algún deposito o pago de servicio
pago = Semaphore(1)                     #Mutex de pago realizado por el cliente

def numClientes():
    global Clientes, maxClientes
    #Se introduce manualmente el número de clientes para ser despachados
    Clientes = input("Introducir cuantos clientes seran despachados>> ")
    caja1.acquire()
    if (Clientes >= maxClientes):       #si el numero de clientes es mayor o igual al número de clientes se adquieren ambas cajas
        print("\t El numeo de clientes es mayor al permitido. Habilitando la caja 2")
        caja2.acquire()
    
