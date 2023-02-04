import random, sys

def list_generator(start: int, end: int) -> list:
    array = list(range(start, end + 1))
    random.shuffle(array)
    return (array)

if __name__ == "__main__":
    array = list_generator(int(sys.argv[1]), int(sys.argv[2]))
    #print('"', end='')
    [print(f"{i} ", end='') for i in array]
    #print('"')
