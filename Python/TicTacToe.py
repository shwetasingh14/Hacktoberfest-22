import numpy as np
import random

# Will create the game dashboard of Tic-tac-toe
def printBoard(board):
    print("\nBOARD:")
    for i in board:
        print(' | '.join(i))

# Options to choose Game mode
def instructions(mode):
    # print('\n')
    if mode == 1:
        print("Game Mode: HUMAN VS HUMAN")
    elif mode == 2:
        print("Game Mode: HUMAN VS RANDOM BOT")
    elif mode == 3:
        print("Game Mode: HUMAN VS SMART BOT")

    print("\nRefer to the table below to mark \nat your required spot:")
    for i in range(1, 10):
        print(i,end=" ")
        if i%3==0:
            print()
        else:
            print("|", end=" ")
    rand_x=random.randint(0,1)
    if rand_x == 0:
        player1 = 'O'
        player2 = 'X'
    else:
        player1 = 'X'
        player2 = 'O'
    return player1, player2

# Winning Logic for the Game
def checkWin(board):
    # rows
    for i in board:
        if len(set(i)) == 1 and i[0]!='_':
            return i[0]
    # cols
    for i in range(3):
        if (board[0][i] == board[1][i] == board[2][i]) and board[0][i]!='_':
            return board[0][i]
    # diagonals
    if (board[0][0]==board[1][1]==board[2][2]) and board[0][0]!='_':
        return board[0][0]
    if (board[0][2]==board[1][1]==board[2][0]) and board[0][2]!='_':
        return board[0][2]
    return -1


def inpToIndex(inp):
    if inp == 1:
        return 0, 0
    elif inp == 2:
        return 0, 1
    elif inp == 3:
        return 0, 2
    elif inp == 4:
        return 1, 0
    elif inp == 5:
        return 1, 1
    elif inp == 6:
        return 1, 2
    elif inp == 7:
        return 2, 0
    elif inp == 8:
        return 2, 1
    elif inp == 9:
        return 2, 2
    
# 2 player game logic    
def vsHuman(board, player1, player2):
    available = 9
    turn = player1
    while available>0:
        print()
        win = checkWin(board)
        if win==-1:
            inp = int(input(f"{turn}'s turn: "))
            i, j = inpToIndex(inp)
            if board[i][j]!='_':
                return -2
            else:
                board[i][j] = turn
                if turn == player1:
                    turn = player2
                else:
                    turn = player1
                available-=1
        else:
            return win
        printBoard(board)
    if win==-1:
        return -3
    else: return win

# single player game logic
def vsRandomBot(board, player1, player2):
    available = 9
    availability_list = [1,2,3,4,5,6,7,8,9]
    turn = player1
    while available>0:
        win = checkWin(board)
        print()
        if win==-1:
            if turn == player1:
                inp = int(input(f"Your turn: "))
                i, j = inpToIndex(inp)
                if board[i][j]!='_':
                    return -2
                else:
                    board[i][j] = turn
                    turn = player2
                    available-=1
                availability_list.remove(inp)
            else:
                inp = random.choice(availability_list)
                print(f"Computers Turn: {inp}")
                availability_list.remove(inp)
                i, j = inpToIndex(inp)
                board[i][j] = turn
                turn = player1
                available-=1
        else:
            return win
        printBoard(board)
    if win==-1:
        return -3
    else: return win


def isMovesLeft(board) :
    for i in range(3) :
        for j in range(3) :
            if (board[i][j] == '_') :
                return True
    return False


def evaluate(b):
    for row in range(3) :    
        if (b[row][0] == b[row][1] and b[row][1] == b[row][2]) :       
            if (b[row][0] == player1) :
                return 10
            elif (b[row][0] == player2) :
                return -10
    for col in range(3) :
        if (b[0][col] == b[1][col] and b[1][col] == b[2][col]) :         
            if (b[0][col] == player1) :
                return 10
            elif (b[0][col] == player2) :
                return -10
    if (b[0][0] == b[1][1] and b[1][1] == b[2][2]) :
        if (b[0][0] == player1) :
            return 10
        elif (b[0][0] == player2) :
            return -10
    if (b[0][2] == b[1][1] and b[1][1] == b[2][0]) :     
        if (b[0][2] == player1) :
            return 10
        elif (b[0][2] == player2) :
            return -10
    return 0


def minimax(board, depth, isMax) :
    score = evaluate(board)
    if (score == 10) :
        return score
    if (score == -10) :
        return score
    if (isMovesLeft(board) == False) :
        return 0
    if (isMax) :    
        best = -1000
        for i in range(3) :        
            for j in range(3) :
                if (board[i][j]=='_') :
                    board[i][j] = player1
                    best = max( best, minimax(board,
                                              depth + 1,
                                              not isMax) )
                    board[i][j] = '_'
        return best
    else :
        best = 1000
        for i in range(3) :        
            for j in range(3) :
                if (board[i][j] == '_') :
                    board[i][j] = player2
                    best = min(best, minimax(board, depth + 1, not isMax))
                    board[i][j] = '_'
        return best


def findBestMove(board) :
    bestVal = -1000
    bestMove = (-1, -1)
    for i in range(3) :    
        for j in range(3) :
            if (board[i][j] == '_') :
                board[i][j] = player1
                moveVal = minimax(board, 0, False)
                board[i][j] = '_'
                if (moveVal > bestVal) :               
                    bestMove = (i, j)
                    bestVal = moveVal
    return bestMove

# 1 player game with a trained bot
def vsSmartBot(board, player1, player2):
    available = 9
    turn = player1
    while available>0:
        win = checkWin(board)
        print()
        if win==-1:
            if turn == player1:
                inp = int(input(f"Your turn: "))
                i, j = inpToIndex(inp)
                if board[i][j]!='_':
                    return -2
                else:
                    board[i][j] = turn
                    turn = player2
                    available-=1
            else:
                print("Computer's Turn...")
                move = findBestMove(board)
                board[move[0]][move[1]] = turn
                turn = player1
                available-=1
        else:
            return win
        printBoard(board)
    win = checkWin(board)
    if win==-1:
        return -3
    else: return win


board = np.array([['_','_','_'],['_','_','_'],['_','_','_']])

print("1: Play vs Human\n2: Play vs Random Bot\n3: Play vs Smart Bot")
mode = int(input("Select mode (1 or 2 or 3): "))
if mode==1 or mode==2 or mode==3:
    print()

    player1, player2 = instructions(mode)

    printBoard(board)

    if mode==1:
        result = vsHuman(board, player1, player2)
    elif mode==2:
        result = vsRandomBot(board, player1, player2)
    elif mode==3:
        result = vsSmartBot(board, player1, player2)
    else:
        result=-2

    print('\n----------------------')
    if result==-2:
        print('Invalid Input')
    elif result==-3:
        print("Matck Tied")
    else:
        print(f'VICTORY FOR {result}')
    print('----------------------')
else:
    print('\nInvalid Input')
