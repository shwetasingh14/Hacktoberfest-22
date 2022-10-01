from random import randint

logo = """
  / _ \_   _  ___  ___ ___  /__   \ |__   ___    /\ \ \_   _ _ __ ___ | |__   ___ _ __ 
 / /_\/ | | |/ _ \/ __/ __|   / /\/ '_ \ / _ \  /  \/ / | | | '_ ` _ \| '_ \ / _ \ '__|
/ /_\\| |_| |  __/\__ \__ \  / /  | | | |  __/ / /\  /| |_| | | | | | | |_) |  __/ |   
\____/ \__,_|\___||___/___/  \/   |_| |_|\___| \_\ \/  \__,_|_| |_| |_|_.__/ \___|_|  
"""

EASY_LEVEL_TURNS = 10
HARD_LEVEL_TURNS = 5


def choose_level():
    level = input("Choose a difficulty. Type 'easy' or 'hard': ")
    if level == "easy":
        turns = EASY_LEVEL_TURNS
    elif level == "hard":
        turns = HARD_LEVEL_TURNS

    return turns

def make_a_guess():
    while True:
        usr_guess = int(input("Make a guess: "))
        if 1 < usr_guess < 100:
            return usr_guess
        else:
            print("Please enter a valid guess.")


print(logo)
print("Welcome to the Number Guessing Game!\n")

play_again = True
while play_again:
    
    turns = choose_level()
    high = "Too high."
    low  = "Too low."

    print("I am thinking of a number between 1 and 100.")
    guess_num = randint(1, 100)


    while turns:
        print(f"\nYou have {turns} attempts remaining to guess the number.")
        usr_guess = make_a_guess()

        if usr_guess > guess_num:
            print(high)
        elif usr_guess < guess_num:
            print(low)
        elif usr_guess == guess_num:
            print("You guessed correctly")
            break
        turns -= 1
        if turns == 0:
            print(f"The number was {guess_num}. You lose.")

    ask_user = input("Do you want to play again? Press 'y' for yes or 'n' for no.\n").lower()
    if ask_user == "y":
        play_again = True
    elif ask_user == "n":
        play_again = False