#!/usr/bin/python3
import time as tm
import random as rd
import string

rd.seed(tm.clock())

N = 1000
MAXTEST = 50
for i in range(1, N + 1):
    entr = []
    nome = './in/entrada' + str(i) + '.txt'
    nint = rd.randint(1, MAXTEST)
    arq = open(nome, 'w')
###############################################################################
    ops = "IIIIIMBBOO"
    for j in range(nint):
        x = rd.randint(0, 9)
        op = ops[x]
        if op == 'I':
            a = rd.randint(1, 99)
            entr.append(a)
            b = ''.join(rd.choice("ASDAFEWASDW") for i in range(3))
            c = rd.randint(1, 99)
            arq.write(op + ' ' + str(a) + ' ' + b + ' ' + str(c) + '\n')
        elif op == 'B':
            b = rd.randint(0, 3)
            if b != 1 and len(entr) > 0:
                a = entr[rd.randint(0, len(entr) - 1)]
            else :
                a = rd.randint(1, 99)
            arq.write(op + ' ' + str(a) + '\n')
        elif op == 'O':
            a = rd.randint(1, 2)
            b = rd.randint(1, 2)
            entr.append(a)
            arq.write(op + ' ' + str(a) + ' ' + str(b) + '\n')
        else:
            arq.write(op + '\n')
    arq.write('P' + '\n')
################################################################################
    arq.close()