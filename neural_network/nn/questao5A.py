import math
import numpy as np
from keras.models import Sequential
from keras.layers.core import Dense

#exemplos de treinamento
t = np.arange(0,20,0.2)
x1 = []
y1 = []
x2 = []
y2 = []
for x in t:
	x1.append((x/4)*math.cos(x))
	y1.append((x/4)*math.sin(x))
	x2.append((x/4 + 0.8)*math.cos(x))
	y2.append((x/4 + 0.8)*math.sin(x))

entrada = []
desejada = []
for x in range(len(t)):
	entrada.append([[x1[x],y1[x]],[x2[x],y2[x]]])
	desejada.append([[1],[2]])

model = Sequential()
model.add(Dense(10, input_dim=2, activation='relu'))
model.add(Dense(1, activation='sigmoid'))

model.compile(loss='mean_squared_error',
 			  optimizer='adam',
			  metrics=['binary_accuracy'])

model.fit(np.array(entrada),
		  np.array(desejada),
		  nb_epoch=500,
		  verbose=2)

model = summary()
score = model.evaluate(x1, y1, verbose=0)
print('Test loss:', score[0])
print('Test accuracy:', score[1])
