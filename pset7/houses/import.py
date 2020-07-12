from sys import argv, exit
import cs50
import csv


# check if the number of arguments is correct
if len(argv) != 2:
    print("wrong argument number")
    exit(1)

# create database
db = cs50.SQL("sqlite:///students.db")

# open the input file
with open(argv[1], "r") as characters:

    # Create Reader
    reader_csv = csv.reader(characters)

    # skip the first line in the file
    next(reader_csv)

    # Iterate over csv
    for row in reader_csv:

        # get the name of the character
        name = row[0]

        # counter for the number of words in the name
        count = 0

        # check if the name is three words or two
        for c in name:
            if c == ' ':
                count += 1

        # if the name contain three words
        if count == 2:
            # split the name into three words
            name_list = name.split(' ', 3)
            first = name_list[0]
            middle = name_list[1]
            last = name_list[2]
        # if the name contain two words
        if count == 1:
            # split the name into two words
            name_list = name.split(' ', 2)
            first = name_list[0]
            middle = None
            last = name_list[1]

        # get the name of house
        house = row[1]

        # get the year of birth
        birth = int(row[2])

        # insert the data into the table
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)
