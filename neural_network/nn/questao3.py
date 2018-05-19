import numpy as np
import pandas as pd
import random
from keras.models import Sequential
from keras.layers.core import Dense
from sklearn.metrics import confusion_matrix

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
		return 0

samples = np.random.uniform(-1,1,1000).reshape(500,2)
x = np.empty([450,2])
v = np.empty([50,2])
y = np.empty([450,1])

for i in range(50):
	v[i][0] = samples[450 + i][0]
	v[i][1] = samples[450 + i][1]

for i in range(450):
	x[i][0] = samples[i][0]
	x[i][1] = samples[i][1]
	y[i] = inter(x[i][0], x[i][1])

model = Sequential()	
model.add(Dense(10, input_dim=2, activation='tanh'))
model.add(Dense(10, activation='tanh'))
model.add(Dense(1, activation='sigmoid'))

model.compile(loss='mean_squared_error',
 			  optimizer='adam',
			  metrics=['accuracy'])

model.fit(x, y, nb_epoch=1000, verbose=1)

result = np.empty([50,1])
for i in range(50):
	result[i] = inter(v[i][0],v[i][1])

print("confusion matrix:\n", pd.crosstab(result, model.predict_classes(v),
						     rownames=['Real'], colnames=['Predict'], 
							 margins=True))

with open("resultado3.txt", "w") as text_file:
	print("\nvalidation data:\n", v, file=text_file)
	print("\npredictions:\n", model.predict_classes(v), file=text_file)
