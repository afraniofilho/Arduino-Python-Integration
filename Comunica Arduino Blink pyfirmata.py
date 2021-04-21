import pyfirmata

import time


board = pyfirmata.Arduino('COM10')


it = pyfirmata.util.Iterator(board)

it.start()


board.digital[10].mode = pyfirmata.OUTPUT


while True:
    board.digital[10].write(1)

    time.sleep(0.5)

    board.digital[10].write(0)

    time.sleep(0.5)
