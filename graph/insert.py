import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt


i = open('D:/ConsoleApplication3/insert.txt', 'r')
i_step = int(i.readline())
insert = np.array([float(i) for i in i.read().split()])
plt.semilogx([(i * i_step) for i in range(0, len(insert))], insert)
plt.title('insert')
plt.xlabel('размер массива')
plt.ylabel('time')
plt.grid()
plt.show()

