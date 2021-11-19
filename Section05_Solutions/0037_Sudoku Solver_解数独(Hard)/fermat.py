def solve():
    for i in range(11, 100):
        eq = False
        for j in range(0, 9):
            for k in range(j + 1, 9):
                if (2**j) % i == (2**k) % i:
                    eq = True
                    break
            if eq:
                break
        if not eq:
            print(i)
            ans = [0 for i in range(11)]
            for pwr in range(9):
                ans[(2**pwr) % i] = pwr+1
            print(ans)
            break

solve()