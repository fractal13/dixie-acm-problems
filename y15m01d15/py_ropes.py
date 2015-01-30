#!/usr/bin/env python


def main():
    line = raw_input("")
    values = line.split()
    N = int(values[0])
    while N > 0:
        Ps = values[1:]
        Ls = [ 50, 60, 70 ]
        s = ""
        total_height = 0
        for P in Ps:
            total_height += int(P)
        for L in Ls:
            if 2*total_height > L:
                s += str(0) + " "
            else:
                C = L
                for P in Ps:
                    x = L / int(P) + 1
                    if x < C:
                        C = x
                s += str(C) + " "
        print s[:-1]
        
        line = raw_input("")
        values = line.split()
        N = int(values[0])
    return

main()
