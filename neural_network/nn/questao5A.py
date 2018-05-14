from math import cos
from math import sin
import numpy as np
from keras.models import Sequential
from keras.layers.core import Dense

#exemplos de treinamento
t = np.arange(0,20,0.2)
x1 = np.zeros(100) 
y1 = np.zeros(100)
x2 = np.zeros(100)
y2 = np.zeros(100)

for i in range(100):
	x1[i] = (i*0.2/4)*cos(i*0.2)
	y1[i] = (i*0.2/4)*sin(i*0.2)
	x2[i] = (i*0.2/4 + 0.8)*cos(i*0.2)
	y2[i] = (i*0.2/4 + 0.8)*sin(i*0.2)

entrada = np.zeros(400).reshape(200,2)
classe = np.zeros(200)

for i in range(200):
	if(i < 100):
		entrada[i][0] = x1[i]
		entrada[i][1] = y1[i]
		classe[i] = -1
	else:
		entrada[i][0] = x2[i - 100]
		entrada[i][1] = y2[i - 100]
		classe[i] = 1

model = Sequential()
model.add(Dense(20, activation='tanh', input_dim=2))
model.add(Dense(15, activation='tanh'))
model.add(Dense(15, activation='tanh'))
model.add(Dense(15, activation='tanh'))
model.add(Dense(15, activation='tanh'))
model.add(Dense(15, activation='tanh'))
model.add(Dense(15, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(1, activation='linear'))

model.compile(loss='mean_squared_error',
 			  optimizer='adam')

model.fit(entrada,
		  classe,
		  nb_epoch=1000,
		  verbose=2,
		  batch_size=32)

with open("resultado5A.txt", "w") as text_file:
	print(model.predict_classes(entrada), file=text_file)
