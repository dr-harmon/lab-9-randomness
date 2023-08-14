# Lab 9: Randomness

Imagine you work at a factory and your job is to inspect products coming off an assembly line. Inspecting takes time so you can't inspect every product, perhaps just 10%. But which 10% do you choose? Every tenth one? If some assembly problem made every odd-numbered product defective, you'd miss them all.

A better approach is to select products randomly. But how? You might think you can pick numbers yourself at random, but the techniques you might use, like "I haven't picked 7 in awhile so it should come next", actually make the sequence _less_ random. A true random number sequence has no pattern or predicability.

The problem of generating random numbers is not just a theoretical or philosophical one. For centuries, random numbers have been crucial for scientific experiments, lotteries, jury and military draft selection, and so on. Today, computer software relies on randomness for simulations, cryptography, games, and many other applications.

So how does one generate random numbers? The best sources of randomness come from nature: thermal noise in the atmosphere, cosmic background radiation, and radioactive decay. But these sources are difficult and expensive to collect. Nobody wants to carry around radioactive material just to have a lottery, for example.

Historically, scientists and engineers relied on random number tables derived from census registers or specialized machines. There were even entire [books](https://en.wikipedia.org/wiki/Random_number_book) filled with nothing but random numbers. Although these materials were inexpensive and easy to distribute, they could not be readily used in computer software.

## Psuedorandom number generators

To solve this problem, computer scientists developed mathematical techniques for generating random numbers. Every technique follows the same basic algorithm:

1. Select a starting number called the "seed".
2. Apply a formula on the seed to generate a new number.
3. The new number becomes the seed and the algorithm repeats from step 1.

Eventually, the algorithm will repeat the same sequence of numbers, so it is not truly random. The technique is therefore known as a "fake" or "psuedo" random number generator ([PRNG](https://en.m.wikipedia.org/wiki/Pseudorandom_number_generator)). However, PRNGs are very useful because they are easy to implement in software, they compute new numbers quickly, and their output is sufficiently random for most practical purposes. No radioactive substances needed!

One of the first software-based PRNGs was invented by [John von Neumann](https://en.m.wikipedia.org/wiki/John_von_Neumann) in 1946 and is known as the [middle-square method](https://en.m.wikipedia.org/wiki/Middle-square_method). It is quite simple: Start with any number, square it, take the middle digits of the square as the next random number, then use that number as the seed for the next iteration. For example, if the seed is 1111, squaring it gives 1234321. When written with 8 digits (01234321), the "random" number would be 2343. The process repeats by squaring 2343 and taking its middle digits, and so on. The sequence produced by this algorithm will repeat, sometimes very quickly, but it was hundreds of times faster than reading "true" random numbers from punched cards.

Today, PRNGs employ more sophisticated algorithms such as the [linear congruential generator](https://en.m.wikipedia.org/wiki/Linear_congruential_generator) but the concept is the same. Keep in mind that all of them are predictable or repetitive in some way, so they are not recommended for serious random-number generation needs such as cryptography.

## PRNGs in C++

In C++, we can access the system's PRNG by invoking the [`rand`](https://en.cppreference.com/w/c/numeric/random/rand) function, which is part of the standard C library.

Try this:

1. In `main.cpp`, write a loop to call `rand` five times and print out the random number that it generates.
2. Run the program three times.

Compare the output of the runs. Is the output random or predictable?

By default, `rand()` uses the same seed every time. To get a more "random" random sequence, you need to give `rand` a different seed by calling its companion function [`srand`](https://en.cppreference.com/w/c/numeric/random/srand).

Try this:

1. Before the loop, add a call to `srand` and pass it your favorite number as the seed.
2. Run the program three times.

Compare the output of the runs. Is the output random or predictable?

Since the seed is fixed, the "random" sequence is also fixed. Ideally, on each run we should pick a new seed that is truly random, but since true sources of randomness are difficult to come by, we can fake it by using the current system time as the seed.

Try this:

1. Change the `srand` call to `srand(time(nullptr))`.
2. Run the program three times.

Compare the output of the runs. What do you observe? How would you judge the quality of the randomness?

## Shuffle Algorithm from Psuedocode

Let's apply a PRNG to a real-world problem: shuffling a finite sequence. Many applications, such as card games, quiz programs, and music players, need to shuffle a list of something. The problem may seem simple at first glance, but shuffling efficiently and without bias requires careful consideration.

Luckily, an algorithm that has been proven correct, unbiased, and efficient already exists. It is called the [Fisher–Yates shuffle](https://en.wikipedia.org/wiki/Fisher–Yates_shuffle):

    -- To shuffle an array a of n elements (indices 0..n-1):
    for i from n−1 down to 1 do
        j ← random integer such that 0 ≤ j ≤ i
        exchange a[j] and a[i]

Your next task in this lab is to translate the above pseudocode into C++. Put the code in a function called `shuffle` with its declaration in `shuffle.h` and its implementation in `shuffle.cpp`. Write a simple test for it in `main.cpp` that replaces the previous `rand` and `srand` code.

Note that `rand` always returns a number in the range 0 to `RAND_MAX` (inclusive). To get random numbers in a different range, use one of the techniques described in [comp.lang.c FAQ Question 13.16](https://c-faq.com/lib/randrange.html).
