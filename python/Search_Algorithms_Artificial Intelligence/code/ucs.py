from turtle import st
from move import Move

class UCS:
    def __init__(self,start,states):
        self.states=states
        self.start = start
        self.visit = []
        self.expend = []
        self.node_counter = 0
        self.depth = 0
        self.move =Move()
        self.ok = 1

    def u(self):

        while self.ok!=0:
            self.depth +=1

            newstates=[]

            for state in self.states:
                if self.move.can_up(state) :
                    newstates.append(self.move.up(state))
                if self.move.can_left(state) :
                    newstates.append(self.move.left(state))
                if self.move.can_down(state):
                    newstates.append(self.move.down(state))
                if self.move.can_right(state):
                    newstates.append( self.move.right(state))

 
            for state in newstates:
                self.expend.append(state)
                if state == tuple(g):
                    self.ok=0

                    break

            for item in newstates:
                for t in self.visit:
                    if t ==item:
                        newstates.remove(t)
            self.visit=self.states

            self.node_counter+=len(self.states)
            self.states = newstates
            newstates = []

        return (self.node_counter,self.depth,self.expend)


g=(0, 1, 2, 3, 4, 5, 6, 7, 8)
