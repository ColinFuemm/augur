import random

class Animal:
    def __init__(self, name, type):
        self.__name = name
        self.__animal_type = type
        n = random.randrange(1, 4)
        if n == 1:
            self.__mood = "happy"
        if n == 2:
            self.__mood = "hungry"
        if n == 3:
            self.__mood = "sleepy"

    def get_animal_type(self):
        return self.__animal_type

    def get_name(self):
        return self.__name

    def check_mood(self):
        return self.__mood

class Mammal(Animal):
    def __init__(self, name, type, hair_color):
        self.__hair_color = hair_color
        super().__init__(name, type)

    def get_hair_color(self):
        return self.__hair_color

class Bird(Animal):
    def __init__(self, name, type, can_fly):
        self.__can_fly = can_fly
        super().__init__(name, type)
        
    def get_can_fly(self):
        return self.__can_fly
    
