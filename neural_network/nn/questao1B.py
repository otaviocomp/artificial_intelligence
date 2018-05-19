from sklearn import svm 

training_data = [[0,0,0],[1,0,0],[1,0,1],[1,1,0],
				[0,0,1],[0,1,1],[0,1,0],[1,1,1]]

target_data = [[-1],[-1],[-1],[-1],[1],[1],[1],[1]]

clf = svm.SVC()
clf.fit(training_data, target_data)
print(clf.predict(training_data))
