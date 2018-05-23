import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm 
import plotly.plotly as py
import plotly.graph_objs as go

X_test = [[0,0,0],[1,0,0],[1,0,1],[1,1,0],
				[0,0,1],[0,1,1],[0,1,0],[1,1,1]]

Y_test = [[-1],[-1],[-1],[-1],[1],[1],[1],[1]]

clf = svm.SVC(kernel='linear')
clf.fit(X_test, Y_test)
print(clf.predict(X_test))

# get the separating hyperplane
w = clf.coef_[0]
a = -w[0] / w[1]
xx = X_test
yy = Y_test

# plot the parallels to the separating hyperplane that pass through the
# support vectors
b = clf.support_vectors_[0]
yy_down = int(a * xx + (b[1] - a * b[0]))
b = clf.support_vectors_[-1]
yy_up = a * xx + (b[1] - a * b[0])

# plot the line, the points, and the nearest vectors to the plane
plt.plot(xx, yy, 'k-')
plt.plot(xx, yy_down, 'k--')
plt.plot(xx, yy_up, 'k--')

plt.scatter(clf.support_vectors_[:, 0], clf.support_vectors_[:, 1],
			s=80, facecolors='none')
plt.scatter(X[:, 0], X[:, 1], c=Y, cmap=plt.cm.Paired)

plt.axis('tight')
plt.show()
