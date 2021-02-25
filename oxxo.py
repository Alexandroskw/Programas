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
    Clientes = input("Introducir cuantos clientes seran despachados>> ")
    if (Clientes >= maxClientes):
        