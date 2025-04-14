import pickle
import pydicom as dicom
from config import config
from tensorflow.data.experimental import save
class SaveData():
    def __init__(self,images=None,labels=None,types='/train'):
        self.numrical_path  = config.NUMRICAL_DIR
        self.prep_path  = config.PREP_DIR
        self.images = images
        self.labels = labels
        self.types = types    
    
    def save_numrical_images(self):

        with open(self.numrical_path+f'{self.types}/images.pkl','wb') as f:
            pickle.dump(self.images, f)
        print('save images succesful...')
        with open(self.numrical_path+f'{self.types}/labels.pkl','wb') as f:
            pickle.dump(self.labels, f)  
        
    def save_prep_images(self):

        with open(f'./data/prepData/{self.types}/images.pkl','wb') as f:
            pickle.dump(self.images, f)
        print('save images succesful...')
        with open(f'./data/prepData/{self.types}/labels.pkl','wb') as f:
            pickle.dump(self.labels, f) 
             
        print('Data is saving...')
