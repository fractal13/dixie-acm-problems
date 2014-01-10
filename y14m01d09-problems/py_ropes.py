#!/usr/bin/env python

lengths = [ 50, 60, 70 ]

while True:
    line = raw_input()
    tmp = line.strip().split()
    nums = []
    for n in tmp:
        nums.append(int(n))
    N = nums[0]
    if N == 0:
        break
    pitches = nums[1:]
    total = sum(pitches)

    line = ""
    space = ""
    for l in lengths:
        line += space
        space = " "
        m = l
        if 2*total > m:
            m = 0
        else:
            for p in pitches:
                n = 1 + int(l/p)
                if n < 2: n = 0
                if n < m: m = n
        line += str(m)
    print line
    

    
