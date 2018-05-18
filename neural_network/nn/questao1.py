import numpy as np
from keras.models import Sequential
from keras.layers.core import Dense
from keras.utils.vis_utils import plot_model

#XOR inputs
training_data = np.array([[0,0,0],[1,0,0],[1,0,1],[1,1,0],
						  [0,0,1],[0,1,1],[0,1,0],[1,1,1]], "float32")

#the four expected results in the same order
target_data = np.array([[-1],[-1],[-1],[-1],[1],[1],[1],[1]], "float32")

#create the model of the neural network
model = Sequential()	

#output layer with 1 neuron and sigmoid activation
model.add(Dense(1, input_dim=3, activation='tanh'))

#cofigure the learning process 
model.compile(loss='mean_squared_error',
 			  optimizer='adam',
			  metrics=['binary_accuracy'])

#training the neural network
model.fit(training_data,
		  target_data,
		  nb_epoch=5000,
		  verbose=1)

#plot the model of the neural network
plot_model(model, 
		   to_file='model_plot.png', 
		   show_shapes=True, 
		   show_layer_names=True)

print(model.evaluate(training_data, target_data))
print(model.summary())	#print the model
print(model.summary())	#print the model
print(model.summary())	#print the model
print(model.predict_classes(training_data)) #print the result
