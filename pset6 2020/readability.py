def main():

    text = input("Text : ")

    l = (100.0 * numOfLetters(text)) / numOfWords(text)

    s = (100.0 * numOfSentences(text)) / numOfWords(text)

    grade = round(0.0588 * l - 0.296 * s - 15.8)

    if grade >= 16:
        print("Grade 16+")

    elif grade < 1:
        print("Before Grade 1")

    else:
        print(f"Grade {grade}")


def numOfLetters(text):
    count = 0
    for i in range(len(text)):
        if checkIfLetter(text[i]) == 1:
            count += 1

    return count


def checkIfLetter(c):
    if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'):
        return 1

    return 0


def numOfWords(text):
    count = 0
    for i in range(len(text)):
        if text[i] == ' ':
            count += 1

    return count + 1


def numOfSentences(text):
    count = 0
    for i in range(len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            count += 1

    return count


main()