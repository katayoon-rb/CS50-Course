# TODO
from cs50 import get_float
from math import floor

while True:
    owned = get_float("Change owed: ") * 100
    if owned < 0:
        continue
    else:
        break

quarters = floor(owned / 25)
dimes = floor((owned - (quarters * 25)) / 10)
nickels = floor((owned - (quarters * 25) - (dimes * 10)) / 5)
pennies = floor((owned - (quarters * 25) - (dimes * 10) - (nickels * 5)))

print(quarters + dimes + nickels + pennies)
