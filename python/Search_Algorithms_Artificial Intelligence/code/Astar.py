from move import Move

start = (1 ,2 ,5 ,3 ,4, 0, 6 ,7 ,8)
# start = (3,1,2, 0,4, 5, 6 ,7 ,8)
# start = (3,1,2, 4,5,0, 6 ,7 ,8)
# start = (1,2,5,0,3,4,6,7,8)

goal=(0, 1, 2, 3, 4, 5, 6, 7, 8)
depth, node_counter = 0, 0
g=1
state=start
visited= ()
ok=1
dict_state= {start:10}
class AStar():
    def __init__(self,state,dict_state,h):
        self.dict_state=dict_state
        self.visited = ()
        self.state = state
        self.node_counter = 0
        self.depth = 0
        self.move =Move()
        self.ok = 1
        self.h = h
        self.g=1
    global g, depth,node_counter
    def Manhattan(dict_stat,new):
        sum=0
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
        for item_t1, item_t2 in zip(new,goal):
            if item_t1 != item_t2:
                diff +=1
        
        dict_stat[new]=(diff+g,g)
        return dict_stat
    def A(self):
        global g
        ok=1
        while ok!=0:
            newstates=[]
            if self.move.can_up(self.state):
                new = self.move.up(self.state)
                if self.h == "Misplaced tiles":

                    self.dict_state=AStar.Misplaced(self.dict_state, new)
                elif self.h == "Manhattan distance":
                    self.dict_state=AStar.Manhattan(self.dict_state, new)
            # h2(new)
                if new not in visited:
                    newstates.append(new)

            if self.move.can_left(self.state):
                new =self.move.left(self.state)
                if self.h == "Misplaced tiles":
                    self.dict_state=AStar.Misplaced(self.dict_state, new)
                elif self.h == "Manhattan distance":
                    self.dict_state=AStar.Manhattan(self.dict_state, new)
                if new not in visited:
                    newstates.append(new)
            # h2(new)

            if self.move.can_down(self.state):
                new = self.move.down(self.state)
                if self.h == "Misplaced tiles":

                    self.dict_state=AStar.Misplaced(self.dict_state, new)
                elif self.h == "Manhattan distance":
                    self.dict_state=AStar.Manhattan(self.dict_state, new)

                if new not in visited:

                    newstates.append(new)
            # h2(new)

            if self.move.can_right(self.state):
                new =  self.move.right(self.state)
                if self.h == "Misplaced tiles":

                    self.dict_state=AStar.Misplaced(self.dict_state, new)
                elif self.h == "Manhattan distance":
                    self.dict_state=AStar.Manhattan(self.dict_state, new)

                if new not in visited:

                    newstates.append(new)
            # h2(new)

            self.visited= list(self.visited)
            self.visited.append(self.state)
            self.visited= tuple(self.visited)

            del self.dict_state[self.state]
            if self.state == goal:
                    ok=0
            self.state = min(self.dict_state,key=self.dict_state.get)
            m=min(self.dict_state,key=self.dict_state.get)
            v =0
            for key, value in self.dict_state.items():
                if m ==key:
                    v = value
            g1 = v[1]+1
            g=g1
            self.node_counter=len(self.dict_state)+self.depth
            if ok !=0:
                self.depth +=1
        return (self.visited,len(self.dict_state),self.depth)
