import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

q = open('D:/ConsoleApplication3/quick.txt', 'r')

q_step = int(q.readline())
quick = np.array([float(i) for i in q.read().split()])
plt.plot([(i * q_step) for i in range(0, len(quick))], quick)

plt.title('quick')
plt.xlabel('размер массива')
plt.ylabel('time')
plt.grid()
plt.show()

