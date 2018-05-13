import numpy as np
from math import sin
from keras.models import Sequential
from keras.layers.core import Dense
from keras.utils.vis_utils import plot_model

def function(n):
	return sin(n + (sin(n))**2)

t = np.arange(100)
x = np.zeros(100)
for i in range(100):
	x[i] = function(t[i])

model = Sequential()
model.add(Dense(10, input_dim=1, activation='tanh'))
model.add(Dense(1, activation='sigmoid'))

model.compile(loss='mean_squared_error',
 			  optimizer='adam',
			  metrics=['accuracy'])

model.fit(t, x, nb_epoch=1500, verbose=2)

plot_model(model, 
		   to_file='model_questao6.png', 
		   show_shapes=True, 
		   show_layer_names=True)

val = np.array([[100],[101],[102],[103]])
print(model.summary())	#print the model
print(model.predict_proba(val))
