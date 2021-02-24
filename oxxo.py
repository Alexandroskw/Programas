from threading import Semaphore

#variables globales
maxClientes = 4         #maximo de clientes en UNA caja

#Mutexes a usar
clientes = Semaphore(maxClientes)   #Mutex para llegada de clientes
caja1 = Semaphore(maxClientes)      #Multiplex para cada caja
caja2 = Semaphore(0)                #"      "       "       "
espera = Semaphore(0)               #Mutex de espera por si hay algún deposito o pago de servicio
exceso = Semaphore(1)               #Mutex de para determinar si hay exceso o no en una caja

#Función de las cajas
def cajas():
    while(True):
        caja1.acquire()             #Las cajas también se inician
        caja2.acquire()
        clientes.acquire()          #Adquiriendo clientes
