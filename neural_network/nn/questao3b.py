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

samples = np.random.uniform(-1,1,1000)
x = np.empty([900,1])
v = np.empty([100,1])
y = np.empty([450,1])

z = 0
for i in range(50):
	v[z] = samples[900 + z]
	v[z+1] = samples[900 + z + 1]
	z += 2

z = 0
for i in range(450):
	x[z] = samples[z]
	x[z + 1] = samples[z + 1]
	y[i] = inter(x[z], x[z + 1])
	z += 2

clf = svm.SVC()
clf.fit(x, y)

result = np.empty([50,1])
z = 0
for i in range(50):
	result[i] = inter(v[z],v[z+1])
	z += 2

print("confusion matrix:\n\n", result, clf.predict(v))
#print("confusion matrix:\n\n", pd.crosstab(result, clf.predict(v),
#						       rownames=['Real'], colnames=['Predict'], 
#							   margins=True))
