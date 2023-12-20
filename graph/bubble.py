import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt


b = open('D:/ConsoleApplication3/bubble.txt', 'r')

b_step = int(b.readline())

bubble = np.array([float(i) for i in b.read().split()])

plt.plot([(i * b_step) for i in range(0, len(bubble))], bubble, label='bubble')

plt.legend()

plt.title('bubble')
plt.xlabel('размер массива')
plt.ylabel('time')
plt.grid()
plt.show()

