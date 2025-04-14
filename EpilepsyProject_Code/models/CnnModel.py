
from  tensorflow import math,cast,reduce_mean
import numpy as np
import pandas as pd

import matplotlib.pyplot as plt
from tensorflow.keras.layers import (Conv2D,LeakyReLU,Dense,Flatten,MaxPool2D,
                                     Dropout,BatchNormalization,UpSampling2D,GlobalAveragePooling2D,
                                     GlobalMaxPooling2D,Reshape,Conv2DTranspose)
from tensorflow.keras.models import Sequential
from tensorflow.keras import Model, callbacks,losses, metrics
import pickle
from tensorflow.keras.optimizers import Adam
from config import config
from tensorflow.keras.models import load_model



import os 
os.path.expanduser('~/.keras/models')
from tensorflow.keras.applications.vgg16 import VGG16


class Create_Model():
    def __init__(self,):
        self.conv2d16 = Conv2D(16,(7,7),strides=1, activation = 'relu', padding = 'same')
        self.conv16d32 = Conv2D(32,(5,5),strides=2, activation = 'relu', padding = 'same')
        self.conv32d64 = Conv2D(64,(3,3), strides=1,activation = 'relu', padding = 'same',)
        self.conv64d128 = Conv2D(128,(3,3), strides=1,activation = 'relu', padding = 'same',)
        self.maxPool2D = MaxPool2D(pool_size=(3,3))
        self.dropout = Dropout(.4)
        self.flatten = Flatten()
        self.dense16 = Dense(units=16, activation='relu')
        self.dense8 = Dense(units=8, activation='relu')
        self.dense1 = Dense(units=1, activation='sigmoid')

    def build_model(self):
        model = Sequential()
        model.add(self.conv2d16)
        model.add(self.conv16d32)
        model.add(self.maxPool2D)
        model.add(self.conv32d64)
        model.add(self.conv64d128)
        model.add(self.maxPool2D)
        model.add(self.dropout)
        model.add(self.flatten)
        model.add(self.dense16)
        model.add(self.dense8)
        model.add(self.dense1)

        return model 
    
class Training():
    def __init__(self,model,dataset):
        self.model = model
        self.dataset = dataset
        self.loss_object = losses.BinaryCrossentropy(from_logits=True, reduction='none')
        self.checkpoint = callbacks.ModelCheckpoint(filepath=config.CHECKPOINT_DIR+'checkpoints', save_weights_only=True)
        self.tensorboard_callback = callbacks.TensorBoard(log_dir=config.TENSORBOARD_DIR, histogram_freq=1)
        self.acc = metrics.BinaryAccuracy(name='accuracy')
        self.optimizer=  Adam(learning_rate=0.01,beta_1=0.5)
        self.history = None
        self.history_path = config.TRAIN_HISTORY_DIR


    
    def train_(self):
        def lr_schedule(epoch):
            lr = 0.1
            if epoch > 30:
                lr = 0.01
            if epoch > 60:
                lr = 0.001
            if epoch > 90:
                lr = 0.0001
            return lr
        
        def loss_function(real, pred):
            mask = math.logical_not(math.equal(real, 0))
            loss_ = self.loss_object(real, pred)
            mask = cast(mask, dtype=loss_.dtype)
            loss_ *= mask
            return reduce_mean(loss_)   
           
        
        lr_callback = callbacks.LearningRateScheduler(lr_schedule)
        self.model.compile(optimizer=self.optimizer, loss=loss_function, metrics =[self.acc])

        self.history =self.model.fit(self.dataset,epochs=110,callbacks=[lr_callback,self.checkpoint,self.tensorboard_callback])
        return self.history, self.model


def creator():
    create_model = Create_Model()
    model= create_model.build_model()
    model.build(config.INPUT_SHAPE)
    model.summary()
    model.save(config.MODEL_SAVER_DIR+'my_model.h5')
    return model

def loader():
    model = load_model(config.MODEL_SAVER_DIR+'my_model.h5')
    return model