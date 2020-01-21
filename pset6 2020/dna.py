import csv
import re
from sys import argv


def main():

    # check if the input arguments are correct
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    # open the input file
    input_file = open(argv[2], "r")
    # get the data from the file in the form of a string
    input_data = input_file.read()
    # buffer to hold the data
    data = []
    # open the database file
    with open(argv[1], 'r') as csv_file:
        # read the csv file in a list
        csv_reader = csv.reader(csv_file)
        # calculate the number of occurance of each pattern
        for line in csv_reader:

            for i in range(1, len(line)):

                longest_pattern = longestPattern(input_data, line[i])

                data.append(longest_pattern)

            break

    # using the data from the input file search for the person name
    status = databaseSearch(data, argv[1])

    if status == 1:
        print("No match")


def databaseSearch(data, database_file):

    # open a csv file
    with open(database_file, 'r') as csv_file:
        # read the csv file in a list
        csv_reader = csv.reader(csv_file)
        # skip the first line in the list
        next(csv_reader)
        # iterate over the lines of the file
        for line in csv_reader:
            # set counter to zero
            count = 0
            # compare the given data with the data in the database
            for i in range(1, len(line)):
                if int(line[i]) == data[i - 1]:
                    count += 1
            # if you find a match print the name of the person and return 0
            if count == len(line) - 1:
                print(line[0])
                return 0
    # if you dont find a match return 1
    return 1


def longestPattern(string, pattern):

    index = 0
    count = 0
    maximum = 0
    i = 0

    while (i < len(string) - len(pattern)):

        index = i

        for j in range(len(pattern)):

            if string[index] != pattern[j]:
                i += 1
                count = 0
                break

            else:
                index += 1

        if index - i == len(pattern):
            count += 1
            i = index

        if count > maximum:
            maximum = count

    return maximum


main()