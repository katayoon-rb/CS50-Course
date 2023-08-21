# TODO
from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 8 or height < 1:
        continue
    else:
        break
for i in range(height):
    print((" " * (height - (i + 1))) + ("#" * (i + 1)) + "  " + ("#" * (i + 1)))
