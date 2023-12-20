import numpy as np
import math
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

b = open('D:/ConsoleApplication3/bubble.txt', 'r')
i = open('D:/ConsoleApplication3/insert.txt', 'r')
s = open('D:/ConsoleApplication3/select.txt', 'r')
m = open('D:/ConsoleApplication3/merge.txt', 'r')
q = open('D:/ConsoleApplication3/shell.txt', 'r')
ss = open('D:/ConsoleApplication3/quick.txt', 'r')

#b = open('D:/ConsoleApplication3/save_1/bubble.txt', 'r')
#i = open('D:/ConsoleApplication3/save_1/insert.txt', 'r')
#s = open('D:/ConsoleApplication3/save_1/select.txt', 'r')
#m = open('D:/ConsoleApplication3/save_1/merge.txt', 'r')
#ss = open('D:/ConsoleApplication3/save_1/shell.txt', 'r')
#q = open('D:/ConsoleApplication3/save_1/quick.txt', 'r')


step_b = int(b.readline())
step_i = int(i.readline())
step_s = int(s.readline())
step_m = int(m.readline())
step_ss = int(ss.readline())
step_q = int(q.readline())


bubble = [float(i) for i in b.read().split()]
insert = [float(i) for i in i.read().split()]
select = [float(i) for i in s.read().split()]
merge = [float(i) for i in m.read().split()]
shell = [float(i) for i in ss.read().split()]
quick = [float(i) for i in q.read().split()]

plt.plot([(i * step_b) for i in range(0, len(bubble))], bubble, label='bubble')
plt.plot([(i * step_i) for i in range(0, len(insert))], insert, label='inset')
plt.plot([(i * step_s) for i in range(0, len(select))], select, label='select')
plt.plot([(i * step_m) for i in range(0, len(merge))], merge, label='merge')
plt.plot([(i * step_ss) for i in range(0, len(shell))], shell, label='shell')
plt.plot([(i * step_q) for i in range(0, len(quick))], quick, label='quick')
plt.legend()

plt.title('sortings')
plt.xlabel('размер массива')
plt.ylabel('time')
plt.grid()
plt.show()

