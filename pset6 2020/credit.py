def main():

    number = []
    number = get_input()

    # check the number is valid or not
    state = valid_or_not(number)

    if state == 0:
        print("INVALID")
        return 1

    # if the number is valid determine the type of credit
    credit = type_of_credit(number)

    print(credit)

# function to get input from the user


def get_input():

    number = []

    # loop until you get a valid input
    while (True):
        count = 0
        # get a number from user
        number = input("Number: ")
        # check if the number contain only digits
        for i in range(len(number)):
            # check if there is anythine other than a digit
            if number[i].isdigit() == False:
                count += 1
                break
        # if the number is valid
        if count == 0:
            break

    # return the number
    return number


# function to check the input is valid or not
def valid_or_not(number):

    sum = 0
    # Multiply every other digit by 2, starting with the number’s second-to-last digit
    # and then add those products’ digits together.
    for i in range(len(number) - 2, -1, -2):

        temp = 2 * int(number[i])

        while (temp > 0):

            sum += int(temp % 10)
            temp = int(temp / 10)

    # dd the sum to the sum of the digits that weren’t multiplied by 2.
    for i in range(len(number) - 1, -1, -2):

        sum += int(number[i])

    # check the number is valid or not
    # the number is valid if the last digit is 0
    if sum % 10 == 0:
        return 1
    else:
        return 0


# function to determine the type of credit
def type_of_credit(number):

    # check the type of Credit Card
    if number[0] == '4':
        credit = "VISA"
    elif number[0] == '3' and number[1] == '4':
        credit = "AMEX"
    elif number[0] == '3' and number[1] == '7':
        credit = "AMEX"
    elif number[0] == '5' and number[1] == '1':
        credit = "MASTERCARD"
    elif number[0] == '5' and number[1] == '2':
        credit = "MASTERCARD"
    elif number[0] == '5' and number[1] == '3':
        credit = "MASTERCARD"
    elif number[0] == '5' and number[1] == '4':
        credit = "MASTERCARD"
    elif number[0] == '5' and number[1] == '5':
        credit = "MASTERCARD"
    else:
        credit = "INVALID"

    return credit


main()