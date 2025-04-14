from move import Move

# start = (1 ,2 ,5 ,3 ,4,  0, 6 ,7 ,8)
# start = (3,1,2, 0,4, 5, 6 ,7 ,8)
# start = (3,1,2, 4,5,0, 6 ,7 ,8)
# start = (1,2,5,0,3,4,6,7,8)

goal=(0, 1, 2, 3, 4, 5, 6, 7, 8)
depth, node_counter ,ok,g , num= 0, 1,1,0,1

# state=start
visited= ()
# dict_state= {start:10}
main_depth=0 
visit=[]
expend=[]
class IDAStar():
    global g,expend
    def __init__(self,state,h):
        self.visited = ()
        self.expand=[]
        self.state = state
        self.node_counter = 0
        self.depth = 0
        self.end=(0, 1, 2, 3, 4, 5, 6, 7, 8)
        self.move =Move()
        self.ok = 1
        self.h = h
        
    def Manhattan(dict_stat,new):
        sum=0
        goal=(0, 1, 2, 3, 4, 5, 6, 7, 8)
        for item in new:
            a=new.index(item)-goal.index(item)
            if a>=0:
                a=a
            else:
                a*=(-1)
            if a==1:a=1
            if a==2:a=2
            if a==3:
                a= int(a/3)
            elif a==4:
                a=int(a/3+1)
            elif a ==5:
                a= int(a/3+2)
            elif a==6:
                b=a%3
                a= a-b
            elif a==7:
                a=int(a/3+1)
            elif a==8:
                b=a%3
                a= a-b
                a+=2
            sum+=a
        # print("sum = ",sum)
        dict_stat[new]=(sum+g,g)
        return dict_stat
    def Misplaced(dict_stat,new):
        diff = 0
        goal=(0, 1, 2, 3, 4, 5, 6, 7, 8)
        for item_t1, item_t2 in zip(new,goal):
            if item_t1 != item_t2:
                diff +=1
        
        dict_stat[new]=(diff+g,g)
        return dict_stat
    def ID(self):
        global dict_state
        dict_state= {self.state:10}
        depth=-1
        while True:
            depth+=1
            result = IDAStar.DLS(self.state,self.end,depth,self.h)

            if result!=None:
                if result[0] == self.end:
                    return result
    def DLS(state, end, depth,h):
        
        global  num,visit,dict_state,visited,node_counter,g
        move= Move()

        node_counter+=1
        global main_depth
        if depth ==0 and state ==end:
            return [state,expend,node_counter,main_depth]
        elif depth >0:
            global ok
        while ok !=0 :
            num=1
            main_depth+=1
            if move.can_up(state) :
                new = move.up(state)
                if h == "Misplaced tiles":

                    dict_state=IDAStar.Misplaced(dict_state, new)
                elif h == "Manhattan distance":
                    dict_state=IDAStar.Manhattan(dict_state, new)
                node_counter+=1 
            if move.can_left(state):
                new =move.left(state)
                if h == "Misplaced tiles":

                    dict_state=IDAStar.Misplaced(dict_state, new)
                elif h == "Manhattan distance":
                    dict_state=IDAStar.Manhattan(dict_state, new)
                node_counter+=1 

            if move.can_down(state):
                new = move.down(state)
                if h == "Misplaced tiles":

                    dict_state=IDAStar.Misplaced(dict_state, new)
                elif h == "Manhattan distance":
                    dict_state=IDAStar.Manhattan(dict_state, new)
                node_counter+=1 
            
            if move.can_right(state):
                new =  move.right(state)
                if h == "Misplaced tiles":
                    dict_state=IDAStar.Misplaced(dict_state, new)
                elif h == "Manhattan distance":
                    dict_state=IDAStar.Manhattan(dict_state, new)
                node_counter+=1 
            if state == goal:
                ok=0
                num =  0
                expend.append([0,1,2,3,4,5,6,7,8])
                break 
            expend.append(state)
            visit.append(tuple(state))
            del dict_state[state]

            state = min(dict_state,key=dict_state.get)
            minimum_dict=state
            value_in_dict =0
            for key, value in list(dict_state.items()):
                for i in visit:
                    if key == i: 
                        del dict_state[key]
                if minimum_dict ==key:
                    value_in_dict = value

            g=value_in_dict[1]+1

            if ok!=0:
                IDAStar.DLS(state,end,depth-1,h)
            else:
                break
            node_counter+=len(visit)
        if ok ==0 :
            return [end,expend,node_counter,main_depth]

