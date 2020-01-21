from cs50 import get_float


def main():

    f = get_input("Change owed: ")

    count = 0

    while (f > 0):

        if f >= 25:
            f -= 25
            count += 1
        elif f >= 10:
            f -= 10
            count += 1
        elif f >= 5:
            f -= 5
            count += 1
        elif f >= 1:
            f -= 1
            count += 1

    print(count)


def get_input(x):

    while (True):

        f = get_float(x)

        f *= 100

        if f > 0:
            break

    return f


main()