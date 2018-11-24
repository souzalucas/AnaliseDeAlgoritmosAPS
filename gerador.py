from random import randint

name = "file"

with open(name + "-1000", "w+") as file:
    for i in range(1000):
        file.write("%d," % (randint(-999, 1000)))

with open(name + "-10000", "w+") as file:
    for i in range(10000):
        file.write("%d," % (randint(-9999, 10000)))

with open(name + "-100000", "w+") as file:
    for i in range(100000):
        file.write("%d," % (randint(-99999, 100000)))
