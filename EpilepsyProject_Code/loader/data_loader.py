from config import config
import pickle
import pydicom as dicom
import os
import numpy as np
from tensorflow.data.experimental import load
import tensorflow as tf
import numpy as  np
from sklearn.model_selection import train_test_split
import pydicom
from pydicom.pixel_data_handlers.util import apply_voi_lut

class ReadImages():
    def __init__(self,types):
        self.numrical_path  = config.NUMRICAL_DIR
        self.prep_path  = config.PREP_DIR
        self.batch_size = config.BATCH_SIZE
        self.types= types
        # Path of all data 
    def read_images_from_folder(self,PathFodler):
        labels = []
        images = []
        for pathdicom in PathFodler:
            paths = list(os.walk(pathdicom))
            for dirNames in  paths[0][1]:
                lstFilesDCM = []   # create an empty list
                for dirName, subdirList, fileList in os.walk(pathdicom+dirNames):
                    for filename in fileList:
                        if "" in filename.lower():  # check whether the file's DICOM
                            lstFilesDCM.append(os.path.join(dirName,filename))
                            
                if len(lstFilesDCM) <160:
                    continue
                
                lstFilesDCM=lstFilesDCM[:160]
                # Get ref file
                RefDs = dicom.read_file(lstFilesDCM[0])

                # Load dimensions based on the number of rows, columns, and slices (along the Z axis)
                ConstPixelDims = (int(256), int(256), len(lstFilesDCM))

                # Load spacing values (in mm)
                ConstPixelSpacing = (float(RefDs.PixelSpacing[0]), float(RefDs.PixelSpacing[1]), float(RefDs.SliceThickness))

                # The array is sized based on 'ConstPixelDims'
                ArrayDicom = np.zeros(ConstPixelDims, dtype=RefDs.pixel_array.dtype)
                # loop through all the DICOM files
                for filenameDCM in lstFilesDCM:
                    # read the file
                    ds =  dicom.read_file(filenameDCM)
                    # print(ds.pixel_array.shape)
                    pixel_array = apply_voi_lut(ds.pixel_array, ds)
                    
                    if pixel_array.shape < (256,256):
                        column , row = pixel_array.shape
                        padd_column = 0
                        padd_row =0
                        if column<256:
                            padd_column= 256- column
                        if row <256:
                            padd_row= 256-row
                        pixel_array = np.pad(pixel_array, ((padd_column, 0), (0, padd_row)))
                    elif pixel_array.shape > (256,256):
                        row_start = (pixel_array.shape[0] - (256,256)[0])
                        col_start = (pixel_array.shape[1] - (256,256)[1])
                        row_end = row_start + pixel_array.shape[0]
                        col_end = col_start + pixel_array.shape[1]
                        pixel_array = pixel_array[row_start:row_end, col_start:col_end]

                    ArrayDicom[:, :, lstFilesDCM.index(filenameDCM)] = pixel_array


                if pathdicom==PathFodler[0]:
                    labels.append(0)# 0 or 1  0 is equal to the images do not have epilepsy and 1 means that the images have epilepsy
                else:
                    labels.append(1)# 0 or 1  0 is equal to the images do not have epilepsy and 1 means that the images have epilepsy
                images.append(ArrayDicom)

        print(len(images))
        return  images,labels
    
        

    def load_images(self):
        print('Loading data...')
        with open(self.numrical_path +f'{self.types}/images.pkl','rb') as f:
            images = pickle.load(f)
        with open(self.numrical_path +f'{self.types}/labels.pkl','rb') as f:
            labels = pickle.load(f)
                
        print('Image reading was done successfully...')
        return images, labels

    def load_prep_images(self):
        print('Loading data...')
        with open(f'./data/prepData/{self.types}/images.pkl','rb') as f:
            images = pickle.load(f)
        with open(f'./data/prepData{self.types}/labels.pkl','rb') as f:
            labels = pickle.load(f)
        print('Image reading was done successfully...')
        original_order = np.arange(len(images))
            
        if self.types != "/test":

            images = np.stack(images)
            labels = np.stack(labels)

            np.random.shuffle(original_order)
    
            labels = labels[original_order]
            X_train, X_test, y_train, y_test = train_test_split(images, labels, test_size=0.25, random_state=123)

            dataset = tf.data.Dataset.from_tensor_slices((X_train, y_train))
            dataset = dataset.batch(self.batch_size).prefetch(6)
            print('Data is loading...')
            return dataset,(X_test,y_test)

        else: return np.stack(images),labels
         
            # return images, labels
        
def find_folder_names(path):
        folder_path = config.DATA_DIR+path 
        files_and_folders = os.listdir(folder_path)
        PathFodler = [folder_path+f+'/' for f in files_and_folders]
        return PathFodler  
    
def read(types):
    PathFodler =find_folder_names(types+'/')
    images , labels = ReadImages(types).read_images_from_folder(PathFodler)
    return images, labels

