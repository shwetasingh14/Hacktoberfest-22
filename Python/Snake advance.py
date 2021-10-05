score = 0
high_score = 0

# Set up the Screen 
wn = turtle.Screen()
wn.title("Snake Game By Sachin")
wn.bgcolor("teal")
wn.setup(width=600,height=600)
wn.tracer(0) # Turns off the screen updates

# Snake head
head = turtle.Turtle()
head.speed(0)
head.shape("square")
head.color("black")
head.penup()
head.goto(0,0)
head.direction = "stop"

# Snake Food 
Food = turtle.Turtle()
Food.speed(0)
Food.shape("circle")
Food.color("red")
Food.penup()
Food.goto(0,100)

