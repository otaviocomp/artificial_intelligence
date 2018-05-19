import numpy as np
import random
from keras.models import Sequential
from keras.layers.core import Dense

def inter(x,y):
	i = 0
	if(((x+1)**2 + y**2) <= 1):
		i += 1
	if(((x-1)**2 + y**2) <= 1):
		i += 1
	if((x**2 + (y-1)**2) <= 1):
		i += 1
	if((x**2 + (y+1)**2) <= 1):
		i += 1
	if(i > 1):
		return 1
	else:
		return -1

x = np.random.random(-1,1,10000).reshape(5000,2)
y = np.empty((5000,))

for i in range(5000):
	y[i] = inter{x[i][0], x[i][1])

model = Sequential()	
model.add(Dense(10, input_dim=2, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(1, activation='tanh'))

model.compile(loss='mean_squared_error',
 			  optimizer='adam',
			  metrics=['accuracy'])

model.fit(x, y, nb_epoch=5000, verbose=2)

with open("resultado3.txt", "w") as text_file:
	print(x, file=text_file)
	print(model.predict_classes(x), file=text_file)
