#Importar bibliotecas

import serial
import numpy as np
import matplotlib.pyplot as plt
from drawnow import *

Vol = []  # cria uma lista vazia para guardar os valores de voltagem

arduinoData = serial.Serial(port='com10', baudrate = 9600) # cria um objeto serial (arduinoData) na porta de comunicação 'com3'
plt.ion()       #Configura o matplotlib no modo interativo para atualizar automatico


def makeFig(): # Criar uma função para o gráfico
    plt.ylim(0, 5)
    plt.title('Voltagem')
    plt.grid(True)
    plt.ylabel('V')
    plt.plot(Vol, 'ro-')

#Função para checar se o valor lido pode ser convertido a float
def check_float(potential_float):
    try:
        float(potential_float)
        return True
    except ValueError:
        return False


while True:
    arduinoString = arduinoData.readline() #ler uma linha da porta serial
    dataArray = arduinoString[:3]  #ler os 3 primeiros caracteres (valor da voltagem)
    if check_float(dataArray):   # se o valor lido pode ser convertido para float'
        voltage = float(dataArray)     # converte em float e guarda em voltage
        Vol.append(voltage)            # cria um array adicionando as leituras de Vol
        drawnow(makeFig)          # chamar função do gráfico
        print(voltage)            # mostra valor da voltagem no terminal
