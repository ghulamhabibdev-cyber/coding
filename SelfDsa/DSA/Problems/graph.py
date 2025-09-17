from math import comb

def binomial_distribution(n, p):
    q = 1 - p
    print(f"{'X':<3} {'P(X=x)':<10}")
    print("-" * 20)
    for x in range(n + 1):
        probability = comb(n, x) * (p ** x) * (q ** (n - x))
        print(f"{x:<3} {probability:.5f}")

# Example usage:
n = 5         # number of trials
p = 0.40      # probability of success
binomial_distribution(n, p)
