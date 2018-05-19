import matplotlib.pyplot as plt

cicle1 = plt.Circle((-1,0), 1, color='r')
cicle2 = plt.Circle((0,1), 1, color='b')
cicle3 = plt.Circle((1,0), 1, color='g')
cicle4 = plt.Circle((0,-1), 1, color='y')

ax = plt.gca()
ax.cla() 

ax.set_xlim((-1, 1))
ax.set_ylim((-1, 1))

ax.add_artist(cicle1)
ax.add_artist(cicle2)
ax.add_artist(cicle3)
ax.add_artist(cicle4)

plt.axis([-1, 1, -1, 1])
plt.show()
