import math
import numpy as np
from keras.models import Sequential
from keras.layers.core import Dense
from keras.utils.vis_utils import plot_model

x = []
n = np.arange(100).reshape(100,1)
for i in n:
	x.append(math.sin(i + (math.sin(i))**2))

model = Sequential()
model.add(Dense(10, input_dim=1, activation='sigmoid'))
model.add(Dense(1, activation='softmax'))

model.compile(loss='mean_squared_error',
 			  optimizer='adam',
			  metrics=['accuracy'])

model.fit(n, x, nb_epoch=500, verbose=2)

plot_model(model, 
		   to_file='model_questao6.png', 
		   show_shapes=True, 
		   show_layer_names=True)

val = math.sin(101 + (math.sin(101))**2)
print(model.summary())	#print the model
print(model.predict_proba(np.array(val)))
