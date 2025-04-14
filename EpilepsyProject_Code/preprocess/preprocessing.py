import pickle
import numpy as np
import tensorflow as tf
from config import config
class Preprocessing():
    def __init__(self,images, labels):
        self.images= images
        self.labels=  labels
        self.shape=  (-1,)
        self.batch_size = config.BATCH_SIZE
    def prep(self):
        
        def preproces(shape,data):
            shape += np.shape(data[0])
            if len(np.shape(data[0])) >2:
                data = [i.astype("float64") for i in data   ]#data.astype("float64") 
                
                data = [i/255.0 for i in data]
            # print( np.shape(data[0]))
            
            # data = tf.reshape(data,shape)
            
            # data= [tf.reshape(i,shape) for i in data]
            # data = data.numpy()
            # print( np.shape(data[0]),"+++++++++++++++++++++++++")
            
            return data

        images = preproces(self.shape, self.images)
        labels = preproces(self.shape, self.labels)

        
        return images, labels

        