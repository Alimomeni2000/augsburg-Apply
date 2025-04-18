import numpy as np
from functools import reduce
import time

# size_sudoku = input("enter size sudoku:")
size_sudoku=int(9)
base = "1 0 0 0 3 0 0 1 0"
# base="0 8 0 0 4 0 0 9 0 0 0 0 0 0 0 0 0 0 0 4 0 3 5 7 0 1 0 6 0 0 0 0 0 0 0 8 8 5 0 7 0 2 0 6 4 0 9 4 0 8 0 1 3 0 0 0 8 0 1 0 3 0 0 0 1 0 0 0 0 0 4 0 0 0 0 9 2 3 0 0 0" 
# base = "8 0 0 0 0 2 0 3 4 0 0 2 10 0 0 7 8 0 0 0 4 0 1 0 0 0 0 10 8 0 0 8 0 2 10 0 0 5 0 0 0 0 0 6 8 9 0 0 0 4 0 9 4 5 1 3 0 6 0 0 10 7 0 0 0 0 0 0 0 0 1 0 0 0 6 5 0 7 0 0 6 0 0 0 3 1 7 0 9 0 0 0 0 7 9 0 6 4 0 0"
base = "3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0"

sudoku =np.arange(size_sudoku*size_sudoku).reshape(size_sudoku,size_sudoku)
base = base.split()
m=0
for i in range(0,len(base)):
    base[m]=int(base[i])
    m+=1
np.putmask(sudoku,sudoku>-1,base)

F = np.array(range(1,size_sudoku+1)) 

def unique_rows(sudoku):
    for row in sudoku:
        if not np.array_equal(np.unique(row),np.array(range(1,size_sudoku+1))) :
            return False
    return True

def unique_columns(sudoku):
    for row in sudoku.T: #transpose sudoku to get columns
        if not np.array_equal(np.unique(row),np.array(range(1,size_sudoku+1))) :
            return False
    return True

def  isComplete(sudoku):
    if 0 in sudoku:
        return False
    else:
        return True

def checkCorrect(sudoku):
    return unique_columns(sudoku) and unique_rows(sudoku)


def getDomain(var, sudoku):
    row,col = var
    used_d = reduce(np.union1d,(sudoku[row,:], sudoku[:,col]))
    avail_d = np.setdiff1d(F, used_d)
    return avail_d 

def get_degree(var, sudoku):
    row,col = var
    all_row = list(sudoku[row,:])
    all_col= list(sudoku[:,col])

    degree = 0
    for i in all_row:
        if i ==0:
            degree+=1
    for i in all_col:
        if i ==0:
            degree+=1       

    return degree 

def getDomainSize(var, sudoku):
    row,col = var
    used_d = reduce(np.union1d, (sudoku[row,:], sudoku[:,col]))
    list_ = np.sum(used_d)
  
    return  list_

def selectMRVvar(vars, sudoku):
    avail_domains = [getDomain(var,sudoku) for var in vars]
    avail_sizes = [len(avail_d) for avail_d in avail_domains]
    mrv_squares = []

    minimum = min( avail_sizes )
    degree_list = []
    for i in range(len(avail_sizes)):
        value = avail_sizes[i]
        if value == minimum:
            mrv_squares.append( vars[i] )
    if len( mrv_squares ) == 1:
        square = mrv_squares[0]
    else:
        for cell in mrv_squares:
         
            degree = get_degree( cell, sudoku )
            degree_list.append( degree )
            max_degree = max( degree_list )
            max_degree_squares = []
            for i in range(len(degree_list)):      
                value = degree_list[i]
                if value == max_degree:
                    max_degree_squares.append( mrv_squares[i] )
            square = max_degree_squares[0]

    index = np.argmin(avail_sizes)
    return (vars[index], avail_domains[index], square)
    

def forward_check( vars, value, square ):    
    row, col = square
    x= []
    dom =[getDomain(var,sudoku) for var in vars]
    for i in range(size_sudoku):
        if i == col:
            continue    
        for j in range(len(vars)):
            if square == vars[j]:
                x = dom[j]
        x1= list(x)
        
        if len(x1) == 1:
            if x1[0] == value:
                return 0
     
    for i in range(size_sudoku):
        if i == row:
            continue
        for j in range(len(vars)):
            if square == vars[j]:
                x = dom[j]
        x2= list(x)

        if len(x2) == 1:
            if x2[0] == value:
                return 0                          
    return 1                          

count =0 
selected=0
def BT(sudoku):
    global count,selected
    "Backtracking search to solve sudoku"
    # If sudoku is complete return it.
    if isComplete(sudoku):
        return sudoku
    # Select the MRV variable to fill
    vars = [tuple(e) for e in np.transpose(np.where(sudoku==0))]

    var, avail_d,square = selectMRVvar(vars, sudoku)

    for value in avail_d:
        
        sudoku[var] = value
        if forward_check( vars, sudoku[var],square):
            count+=1
            result = BT(sudoku)
            if np.any(result):
                return result
            else:
                sudoku[var] = 0

    return False

# Solve
one_time = time.time()
print(sudoku)
print("solved:\n", BT(sudoku))
print("correct:", checkCorrect(sudoku))
end_time= time.time()-one_time
print(end_time)
print(count)
