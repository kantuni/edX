import math


def number_of_divisors(n):
    counter = 0

    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            if n / i == i:
                # perfect square
                counter += 1
            else:
                counter += 2

    return counter


def solve(k):
    primes = [True] * (k + 1)
    primes[0] = False
    primes[1] = False

    # sieve of Eratosthenes
    for i in range(2, int(math.sqrt(k)) + 1):
        if primes[i]:
            j = 0
            while i * i + j * i < k + 1:
                primes[i * i + j * i] = False
                j += 1

    divisors = [2] * (k + 1)
    divisors[0] = 0
    divisors[1] = 1

    maximum = 0
    maximum_index = 0

    for i in range(2, k + 1):
        if primes[i]:
            counter = 2
        else:
            counter = number_of_divisors(i)

        if maximum < counter:
            maximum = counter
            maximum_index = i

        divisors[i] = counter

    return k - maximum_index + 1


if __name__ == "__main__":
    with open("generate_tests_answer.txt", "w") as file:
        for i in range(2, 180):
            answer = solve(i)
            if answer == 1 and i != 2:
                file.write("\n")
            file.write(str(answer) + " ")
