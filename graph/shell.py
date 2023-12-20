import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

ss = open('D:/ConsoleApplication3/shell.txt', 'r')
ss_step = int(ss.readline())

shell = np.array([float(i) for i in ss.read().split()])
plt.plot([(i * ss_step) for i in range(0, len(shell))], shell)
plt.title('shell')
plt.xlabel('размер массива')
plt.ylabel('time')
plt.grid()
plt.show()

