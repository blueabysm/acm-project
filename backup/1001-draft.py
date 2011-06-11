#!/usr/bin/python
import string

def times (left, right):
    result = ""
    for i in range (0, len (left)):
        for j in range (0, len (right)):
            print left[i] + " * " + right[j] + " = " + str (int (left[i]) * int (right[j]))

if __name__ == '__main__':
    times ("12345", "67890")
