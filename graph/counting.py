import numpy as np
import math
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

b = open('D:/ConsoleApplication3/bubble.txt', 'r')
i = open('D:/ConsoleApplication3/insert.txt', 'r')
s = open('D:/ConsoleApplication3/select.txt', 'r')
m = open('D:/ConsoleApplication3/merge.txt', 'r')
ss = open('D:/ConsoleApplication3/shell.txt', 'r')
q = open('D:/ConsoleApplication3/quick.txt', 'r')


bubble = np.array([float(i) for i in b.read().split()])
insert = np.array([float(i) for i in i.read().split()])
select = np.array([float(i) for i in s.read().split()])
merge = np.array([float(i) for i in m.read().split()])
shell = np.array([float(i) for i in ss.read().split()])
quick = np.array([float(i) for i in q.read().split()])

plt.semilogx([(i * 500) for i in range(0, len(bubble))], bubble, label='bubble')
plt.semilogx([(i * 500) for i in range(0, len(insert))], insert, label='inset')
plt.semilogx([(i * 500) for i in range(0, len(select))], select, label='select')
plt.semilogx([(i * 500) for i in range(0, len(merge))], merge, label='merge')
plt.semilogx([(i * 500) for i in range(0, len(shell))], shell, label='shell')
plt.semilogx([(i * 500) for i in range(0, len(quick))], quick, label='quick')
plt.legend()

plt.title('sortings')
plt.xlabel('размер массива')
plt.ylabel('time')
plt.grid()
plt.show()

