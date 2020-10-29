from cs50 import get_string
from sys import argv


def main():
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    
    fp = open(argv[1], 'r')
    banned = set()

    for word in fp.readlines():
        banned.add(word.strip('\n'))

    message = get_string("What message would you like to censor?\n")
    tokens = message.split(' ')

    for i, token in enumerate(tokens):
        if token.lower() in banned:
            tokens[i] = len(token) * '*'

    print(' '.join(tokens))


if __name__ == "__main__":
    main()
