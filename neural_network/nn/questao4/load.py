from keras.models import load_model
from keras.preprocessing import image
from PIL import Image
import numpy as np
import os, os.path

# load the model we saved
model = load_model('cnn.h5')
model.compile(loss='binary_crossentropy',
              optimizer='rmsprop',
              metrics=['accuracy'])

# predicting images
imgs = []
path = "data/validation"
valid_images = [".jpeg",".png"]
for f in os.listdir(path):
    ext = os.path.splitext(f)[1]
    if ext.lower() not in valid_images:
        continue
    imgs.append(Image.open(os.path.join(path,f))

images = np.array(imgs)
print(model.predict_classes(images, batch_size=10))
