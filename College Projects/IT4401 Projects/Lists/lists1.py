def display_list(label, items):
    print(label)
    for food in items:
        print(food)

def main():
    foods = ["pizza", "salad", "hamburger", "steak", "apple", "orange"]
    display_list("Foods in original order: ", foods)
    foods.sort()
    display_list("Foods in ascending alphabetical order", foods)
    foods.sort(reverse = True)
    display_list("Foods in descending alphabetical order", foods)
    foods2 = sorted(foods)
    display_list("Foods2 in ascending alphabetical order", foods2)
    display_list("Foods still in descending alphabetical order", foods)
    foods.reverse()
    display_list("Foods in ascending alphabetical order", foods)
    foods.append("carrots")
    foods.append("milk")
    display_list("Sorted foods with carrots and milk appended", foods)
    foods.sort()
    display_list("Foods in ascending alphabetical order", foods)
    pizza_index = foods.index("pizza")
    print("Pizza is at " + str(pizza_index))
    foods.insert(pizza_index, "fries")
    pizza_index = foods.index("pizza")
    print("Pizza is now at " + str(pizza_index))
main()
