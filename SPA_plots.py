# -*- coding: utf-8 -*-
import os, sys
import itertools
from numpy import *
from math import *

import matplotlib
import matplotlib.pyplot as plt


params={
'font.size': 16,
'mathtext.default' : 'rm' # see http://matplotlib.org/users/customizing.html
}
matplotlib.rcParams.update(params)

kB=1.38*1e-23
hP=6.626*1e-34
T=50000*1e-9

def n_B(nu):
        return 1.0/(exp(hP*nu/(kB*T)) - 1)

data=[]
for i in xrange(0, 2):
        data.append([])
        with open('SPA_'+str(i)+'.dat') as file:
                for line in file:
                        data[i].append(float(line.strip().split()[0]))

T=1.0
data_t=linspace(0, T, len(data[0]))

data_1=[data[0][i] for i in xrange(len(data[0]))]
data_2=[data[1][i] for i in xrange(len(data[0]))]

numOfPlots=2
fig, ax=plt.subplots(numOfPlots, 1, sharex=True, figsize=(10,numOfPlots*4))

ax1=plt.subplot(numOfPlots, 1, 1)
ax1.plot(data_t, data_1)
ax1.grid(True, color='black')
ax1.set_xlim(0,T)
ax1.set_ylabel('$v1$')
ax1.yaxis.set_label_position("right")

ax1=plt.subplot(numOfPlots, 1, 2)
ax1.plot(data_t, data_2)
ax1.grid(True, color='black')
ax1.set_xlim(0,T)
ax1.set_ylabel('$v2$')
ax1.yaxis.set_label_position("right")


fig.tight_layout()
fig.savefig('SPA_plots.pdf')
plt.close()
