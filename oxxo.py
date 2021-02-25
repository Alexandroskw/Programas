from threading import Semaphore
from time import sleep
import random, os

#variables globales
maxClientes = 4         #maximo de clientes en UNA caja
#Clientes = []          #clientes dados por el usuario
atendidos = []          #auxiliar
tiempo = 90


#mutexes a usar
caja1 = Semaphore(maxClientes)          #Un mutex de la caja 1, se usa el máximo de clientes
caja2 = Semaphore(maxClientes)
tramites = Semaphore(0)                 #Mutex por si se hace algún deposito o pago de servicio
pago = Semaphore(1)                     #Mutex de pago realizado por el cliente

def cajas():
    caja1.acquire()
    pago.acquire()
    #si el numero de clientes es mayor o igual al número de clientes se adquieren ambas cajas
    if ((round(Clientes)) > maxClientes):
        while(True):
            os.system("clear")
            print("El numero de clientes es mayor al permitido. Habilitando la caja 2...")
            caja2.acquire()
            sleep(3)
            #cuantos clientes han sido despachados
            despachados = atendidos.pop(0)
            caja = atendidos.pop(0)
            print("\tLa caja %d ha despachado al cliente %d" % (caja, despachados))
            #liberando las cajas
            caja1.release()
            caja2.release()
            break
    elif ((round(Clientes)) == 0):
        os.system("clear")
        print("No puede no haber ningún cliente")
    else:
        while(True):
            os.system("clear")
            despachados = atendidos.pop(0)
            caja = atendidos.pop(0)
            print("\La caja ha atendido al cliente %d", despachados)
            break

    caja1.release()
    pago.release()

def clientes(despachados):
   pago.acquire()           #procediendo al pago
   print("El cliente %d ha realizado el pago", despachados)
   tramites.acquire()
   tramite = randfloat(1, tiempo)
   while(True):
        if(tramite >= 5):
            os.system("clear")
            print("El cliente %d está realizando un trámite", despachados)




os.system("clear")
Clientes = int(input("Introducir cuantos clientes serán atendidos>> "))