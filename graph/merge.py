import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

m = open('D:/ConsoleApplication3/merge.txt', 'r')

m_step = int(m.readline())
merge = np.array([float(i) for i in m.read().split()])
plt.plot([(i * m_step) for i in range(0, len(merge))], merge)
plt.title('merge')
plt.xlabel('размер массива')
plt.ylabel('time')
plt.grid()
plt.show()

