# TODO
from cs50 import get_string

text = get_string("Text: ")
letters = 0

for l in text:
    if l.isalpha():
        letters += 1

words = len(text.split())
sents = 0

for w in text:
    if w == "." or w == "?" or w == "!":
        sents += 1

L = 100 * (letters / words)
S = 100 * (sents / words)
grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade > 0 and grade < 16:
    print(f"Grade {grade}")
elif grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Error")
