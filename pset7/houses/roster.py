from sys import argv, exit
import cs50

# check if the number of arguments is correct
if len(argv) != 2:
    print("wrong argument number")
    exit(1)

# create database
db = cs50.SQL("sqlite:///students.db")

# print out each student’s full name and birth year
names = db.execute(f"SELECT first, middle, last, birth FROM students WHERE house = '{argv[1]}' ORDER BY last , first")

for row in names:
    first = row["first"]
    middle = row["middle"]
    last = row["last"]
    birth = row["birth"]

    if middle == None:
        print(f"{first} {last}, born {birth}")
    else:
        print(f"{first} {middle} {last}, born {birth}")
