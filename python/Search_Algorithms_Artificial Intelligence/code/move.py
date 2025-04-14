depth = 0
node_counter= 0
class Move:
    LENGTH = 3

    @staticmethod
    def can_up(state):
        return state.index(0) >= Move.LENGTH

    LAST_ROW_INDEX = LENGTH * (LENGTH - 1)
    @staticmethod
    def can_down(state):

        return state.index(0) < Move.LAST_ROW_INDEX

    @staticmethod
    def can_left(state):

        return state.index(0) % Move.LENGTH != 0

    @staticmethod
    def can_right(state):
        global last_state

        return (state.index(0) + 1) % Move.LENGTH != 0

    @staticmethod
    def up(state):
        new_state = list(state)
        index = new_state.index(0)
        new_state[index - Move.LENGTH], new_state[index] = new_state[index], new_state[index - Move.LENGTH]
        
        return tuple(new_state)

    @staticmethod
    def down(state):
        new_state = list(state)
        index = new_state.index(0)
        new_state[index + Move.LENGTH], new_state[index] = new_state[index], new_state[index + Move.LENGTH]
        return tuple(new_state)

    @staticmethod
    def left(state):
        new_state = list(state)
        index = new_state.index(0)
        new_state[index - 1], new_state[index] = new_state[index], new_state[index - 1]
        return tuple(new_state)
    @staticmethod
    def right(state):
        new_state = list(state)
        index = new_state.index(0)
        new_state[index + 1], new_state[index] = new_state[index], new_state[index + 1]
        return tuple(new_state)