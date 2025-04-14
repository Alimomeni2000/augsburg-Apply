from loader import data_loader
from saver import data_saver
from preprocess import preprocessing
from models import CnnModel
import numpy as np
from config import config
from sklearn import metrics

# from preprocessing import prep
def remove(images=None, labels=None, dataset=None):
    if images !=None:
        del images
    if labels !=None:
        del labels
    if dataset!= None:
        del dataset
    
    
def train(path):

    
        # images,labels= data_loader.read(path)
        # data_saver.SaveData(images=images, labels=labels,types='train').save_numrical_images()
        # remove(images,labels)ایmymodel = CnnModel.creator()
        tra =CnnModel.Training(mymodel,dataset)

        a= tra.train_()

        pred=a[1].predict(X_test)
        pred = np.array(pred) >= 0.5
        pred = pred.astype(int)

        print(metrics.classification_report(y_test, pred))

def test():

        
        images,labels= data_loader.read('test')
        data_saver.SaveData(images=images, labels=labels,types= 'test').save_numrical_images()
        remove(images,labels)
        
        images,labels= data_loader.ReadImages("/test").load_images()
        images,labels = preprocessing.Preprocessing(images,labels).prep()

        data_saver.SaveData(images=images, labels=labels,types= '/test').save_prep_images()
        
        images,labels = data_loader.ReadImages("/test").load_prep_images()
    
        mymodel = CnnModel.loader()
        pred=mymodel.predict(images)
        print(pred)
        
        pred = np.array(pred) >= 0.5
        pred = pred.astype(int)
        if pred ==0:
            
            print('He/she has not epilepsy')
        else:
            print("He/she has epilepsy")

if __name__ == '__main__':
    # execute only if run as the entry point into the program
    checking = input('Are training data or test data(tr/te)? ')
    if checking == 'tr':
        
        train('train')
    elif checking == 'te':
        test()