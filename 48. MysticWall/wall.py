def solve():
    t = int(input().strip())
    for _ in range(t):
        dominoes = input().strip()
        n = len(dominoes)
        symbols = [(i, c) for i, c in enumerate(dominoes) if c != '.']
        symbols = [(-1, 'L')] + symbols + [(n, 'R')]
        dominoes = list(dominoes)

        for (i, x), (j, y) in zip(symbols, symbols[1:]):
            if x == y:
                for k in range(i + 1, j):
                    dominoes[k] = x
            elif x == 'R' and y == 'L':
                l, r = i + 1, j - 1
                while l < r:
                    dominoes[l] = 'R'
                    dominoes[r] = 'L'
                    l += 1
                    r -= 1
        print("".join(dominoes))


if __name__ == "__main__":
    solve()
