from curses import ascii
import curses

alpha =  "abcdefghijklmnopqrstuvwxyz"
caesar = "defghijklmnopqrstuvwxyzabc" 
atbash = "zyxwvutsrqponmlkjihgfedcba"

choice1 = input("Encrypt or decrypt a message? (e or d): ")
if choice1 == 'e' or choice1 == 'E':
    decrmessage = input("Enter message to encrypt: ")
    solvd = [None] * len(decrmessage)
    method = input("Atbash, Caesar, or N -Shift? (a, c, or s): ")
    if method == 'c' or method == 'C':
        i = 0
        j = 0
        key = input("Print cipher key? (y or n): ")
        if key == 'y' or key == 'Y':
            k = 0
            for k in range(0,87):
                print("-",end="")
            print("\nAlpha : |", end="")
            for k in range(0,26):
                print(alpha[k],"|",end="")
            k = 0
            print("\nCipher: |", end="")
            for k in range(0,26):
                print(caesar[k],"|",end="")
            print("\n")
            for k in range(0,87):
                print("-",end="")
            print("\n")
        for i in range(0,len(decrmessage)):
            for j in range(0,26):
                if decrmessage[i] == alpha[j]:
                    solvd[i] = caesar[j]
                elif decrmessage[i] == ' ':
                    solvd[i] = ' '
                elif curses.ascii.ispunct(decrmessage[i]):
                    solvd[i] = decrmessage[i]
        print("-------------CAESAR CIPHER--------------")
        print("Original message: ", decrmessage)
        print("Encrypted message: ", end="")
        for i in solvd:
            print(i,end="")
    elif method == 'a' or method == 'A':
        i = 0
        j = 0
        key = input("Print cipher key? (y or n): ")
        if key == 'y' or key == 'Y':
            k = 0
            for k in range(0,87):
                print("-",end="")
            print("\nAlpha : |", end="")
            for k in range(0,26):
                print(alpha[k],"|",end="")
            k = 0
            print("\nCipher: |", end="")
            for k in range(0,26):
                print(atbash[k],"|",end="")
            print("\n")
            for k in range(0,87):
                print("-",end="")
            print("\n")
        for i in range(0,len(decrmessage)):
            for j in range(0,26):
                if decrmessage[i] == alpha[j]:
                    solvd[i] = atbash[j]
                elif decrmessage[i] == ' ':
                    solvd[i] = ' '
                elif curses.ascii.ispunct(decrmessage[i]):
                    solvd[i] = decrmessage[i]
        print("-------------ATBASH CIPHER--------------")
        print("Original message: ", decrmessage)
        print("Encrypted message: ", end="")
        for i in solvd:
            print(i,end="")
    elif method == 's' or method == 'S':
        i = 0
        j = 0
        shift = int(input("Shift substitution how many spaces?: "))
        alpha_shift = [None] * 26
        for i in range(0,26):
            if i + shift <= 25:
                alpha_shift[i] = alpha[i + shift]
            elif i + shift > 25:
                alpha_shift[i] = alpha[i-(26-shift)]
        for i in range(0,len(decrmessage)):
            for j in range(0,26):
                if decrmessage[i] == alpha[j]:
                    solvd[i] = alpha_shift[j]
                elif decrmessage[i] == ' ':
                    solvd[i] = ' '
                elif curses.ascii.ispunct(decrmessage[i]):
                    solvd[i] = decrmessage[i]
        key = input("Print cipher key? (y or n): ")
        if key == 'y' or key == 'Y':
            k = 0
            for k in range(0,87):
                print("-",end="")
            print("\nAlpha : |", end="")
            for k in range(0,26):
                print(alpha[k],"|",end="")
            k = 0
            print("\nCipher: |", end="")
            for k in range(0,26):
                print(alpha_shift[k],"|",end="")
            print("\n")
            for k in range(0,87):
                print("-",end="")
            print("\n")
        print("-------------N SHIFT CIPHER--------------")
        print("Original message: ", decrmessage)
        print("Encrypted message: ", end="")
        for i in solvd:
            print(i,end="")
            
elif choice1 == 'd' or choice1 == 'D':
     message = input("Enter message to decrypt: ")
     decoded = [None] * len(message)
     method = input("Atbash or Caesar? (a or c): ")
     if method == 'a' or method == 'A':
        i = 0
        j = 0
        key = input("Print cipher key? (y or n): ")
        if key == 'y' or key == 'Y':
            k = 0
            for k in range(0,87):
                print("-",end="")
            print("\nAlpha : |", end="")
            for k in range(0,26):
                print(alpha[k],"|",end="")
            k = 0
            print("\nCipher: |", end="")
            for k in range(0,26):
                print(atbash[k],"|",end="")
            print("\n")
            for k in range(0,87):
                print("-",end="")
            print("\n")
        for i in range(0,len(message)):
            for j in range(0,26):
                if message[i] == atbash[j]:
                    decoded[i] = alpha[j]
                elif message[i] == ' ':
                    decoded[i] = ' '
                elif curses.ascii.ispunct(message[i]):
                    decoded[i] = message[i]
        print("\n-------------ATBASH CIPHER--------------")
        print("Encrypted message: ", message)
        print("Decrypted message: ", end="")
        for i in decoded:
            print(i,end="")
     elif method == 'c' or method == 'C':
        i = 0
        j = 0
        key = input("Print cipher key? (y or n): ")
        if key == 'y' or key == 'Y':
            k = 0
            for k in range(0,87):
                print("-",end="")
            print("\nAlpha : |", end="")
            for k in range(0,26):
                print(alpha[k],"|",end="")
            k = 0
            print("\nCipher: |", end="")
            for k in range(0,26):
                print(caesar[k],"|",end="")
            print("\n")
            for k in range(0,87):
                print("-",end="")
            print("\n")
        for i in range(0,len(message)):
            for j in range(0,26):
                if message[i] == caesar[j]:
                    decoded[i] = alpha[j]
                elif message[i] == ' ':
                    decoded[i] = ' '
                elif curses.ascii.ispunct(message[i]):
                    decoded[i] = message[i]
        print("\n-------------CAESAR CIPHER--------------")
        print("Encrypted message: ", message)
        print("Decrypted message: ", end="")
        for i in decoded:
            print(i,end="")
        
