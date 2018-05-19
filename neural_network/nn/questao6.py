from keras.models import Sequential
from keras.layers import Dense
import matplotlib.pyplot as plt
import random
import numpy as np
from math import sin

def function(n):
	return sin(n + sin(n)**2)

x = np.empty((10000,))
t = np.random.uniform(0,10,10000)
t = np.sort(t)

for i in range(10000):
	x[i] = function(t[i])

model = Sequential()
model.add(Dense(units=10, activation='tanh', input_dim=1))
model.add(Dense(units=10, activation='tanh'))
model.add(Dense(units=10, activation='tanh'))
model.add(Dense(units=1, activation='linear'))

model.compile(loss='mse', optimizer='adam')

model.fit(t, x, epochs=50, steps_per_epoch=128)

val = np.array([10.05])
print(model.predict(val))

plt.plot(t, x)
plt.plot(t, model.predict(t))
plt.show()
