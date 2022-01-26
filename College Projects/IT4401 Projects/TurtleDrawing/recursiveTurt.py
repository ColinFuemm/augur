import random
from turtle import Turtle

def left_lines(turtle, angle, length, lines):
    colors = ["red", "orange", "brown", "green", "blue", "purple"]
    color = random.choice(colors)
    turtle.color(color)
    turtle.left(angle)
    turtle.forward(length)
    lines = lines - 1
    if (lines > 0):
        left_lines(turtle, angle, length, lines)

def right_lines(turtle, angle, length, lines):
    colors = ["red", "orange", "brown", "green", "blue", "purple"]
    color = random.choice(colors)
    turtle.color(color)
    turtle.right(angle)
    turtle.forward(length)
    lines = lines - 1
    if (lines > 0):
        right_lines(turtle, angle, length, lines)

def circle_town(turtle, angle, radius, lines):
    colors = ["red", "orange", "brown", "green", "blue", "purple"]
    color = random.choice(colors)
    turtle.color(color)
    turtle.left(angle)
    turtle.circle(radius)
    lines = lines - 1
    if (lines > 0):
        circle_town(turtle, angle, radius, lines)

def main():
    ANIMATION_SPEED = 5
    leonardo = Turtle()
    leonardo.speed(ANIMATION_SPEED)
    left_lines(leonardo, 45, 175, 1)
    right_lines(leonardo, 30, 1, 1)
    right_lines(leonardo, 6, 6, 10)
    circle_town(leonardo, 180, 10, 1)
    circle_town(leonardo, 0, 3, 1)
    right_lines(leonardo, 180, 0, 1)
    right_lines(leonardo, 6, 6, 5)
    right_lines(leonardo, 50, 20, 1)
    right_lines(leonardo, 180, 20, 1)
    left_lines(leonardo, 210, 0, 1)
    right_lines(leonardo, 6, 6, 10)
    right_lines(leonardo, 45, 175, 1)

main()
