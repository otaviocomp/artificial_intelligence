import numpy as np
import pandas as pd
import random
from sklearn import svm 
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
v = np.empty([100,1])
y = np.empty([450,1])

z = 0
for i in range(50):
	v[z] = samples[450 + i][0]
	v[z+1] = samples[450 + i][1]
	z += 2

for i in range(450):
	x[i][0] = samples[i][0]
	x[i][1] = samples[i][1]
	y[i] = inter(x[i][0], x[i][1])

clf = svm.SVC()
clf.fit(x, y)

result = np.empty([50,1])
z = 0
for i in range(50):
	result[i] = inter(v[z],v[z+1])
	z += 2

print("confusion matrix:\n\n", pd.crosstab(result, clf.predict(v),
						       rownames=['Real'], colnames=['Predict'], 
							   margins=True))
