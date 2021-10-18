from random import randint
import math
num = randint(1,100)
new_guess, prev_guess, turn = 0, 0, 0
while new_guess != num:
    new_guess = int(input("ENTER A NUMBER: "))
    turn += 1
    if new_guess < 1 or new_guess > 100:
        print('OUT OF BOUNDS')
        continue
    if new_guess == num:
        print("CONGRATULATIONS! YOU GUESS THE RIGHT NUMBER IN {} TURN..".format(turn))
        break
    if (turn == 1):
        if math.fabs(num - new_guess) < 10:
            print("WARM!")
        else:
            print("COLD!")
        prev_guess = new_guess
        continue
    if(math.fabs(num - new_guess)) < (math.fabs(num - prev_guess)):
        print("WARMER!")
    else:
        print("COLDER!")
    prev_guess = new_guess
