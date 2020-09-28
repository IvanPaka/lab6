import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return 2*x[0]*x[0] + 4*x[0] + 3*x[1]*x[1] - 39*x[1] + 129.75

data = []
with open("data.dat") as file:
    for line in file:
        data.append([float(line.split(',')[0]), float(line.split(',')[1])])


data = np.array(data)

x, y = np.mgrid[-10:10:0.1, -10:10:0.1]

fig, ax = plt.subplots()
cs = ax.contour(x, y, f([x, y]), levels=50)

ax.clabel(cs)

ax.plot(data[:, 0], data[:, 1], "ro:")
ax.grid()

fig.set_figwidth(16)
fig.set_figheight(9)

plt.show()
