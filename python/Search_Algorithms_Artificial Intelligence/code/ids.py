from move import Move


g=[0,1, 2, 3, 4, 5, 6, 7, 8]
node_counter= 0

main_depth=0 
num=1
visit=[]
ok=1
node_counter=0
new_states=[]
expend = []
class IDS:
    def __init__(self,start):
        self.visited = []

        self.start = start
        self.ok =1
        self.end=[0,1, 2, 3, 4, 5, 6, 7, 8]
    def id(self):
        global depth
        depth=-1
        while True:
        
        
            depth+=1
            result = IDS.dls(self.start,self.end,depth)
            if result!=None:
                if result[0] == self.end:
                    return result
    

    def dls(states, end, depth):
        global ok, num,visit,expend
        global main_depth
        new_states=[]
        move= Move()
        global node_counter
        if depth ==0 and states ==end:
            return  [states,expend,node_counter,main_depth]
        elif depth >0:
            while ok !=0 :
                main_depth+=1

                for state in states:
                    if move.can_up(state) :
                        new_states.append(move.up(state))
                    if move.can_left(state) :
                        new_states.append(move.left(state))
                    if move.can_down(state) :
                        new_states.append(move.down(state))
                    if move.can_right(state) :
                        new_states.append(move.right(state))
            
                for item in new_states:
                    for t in visit:
                        if t ==item:
                            new_states.remove(t)
                visit=states
                states = new_states
                node_counter+=len(states)

                for state in states:
                    expend.append(state)
                    if state == tuple(end):
                        ok=0
                        num = 0
                        break   
                if num ==0 :
                    ok=0
                    return [end,expend,node_counter,main_depth] 
                new_states=[]
                IDS.dls(states,end,depth-1)
        




g=[0,1, 2, 3, 4, 5, 6, 7, 8]

