import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt


s = open('D:/ConsoleApplication3/select.txt', 'r')

s_step = int(s.readline())
select = np.array([float(i) for i in s.read().split()])
plt.plot([(i * s_step) for i in range(0, len(select))], select)
plt.title('select')
plt.xlabel('размер массива')
plt.ylabel('time')
plt.grid()
plt.show()