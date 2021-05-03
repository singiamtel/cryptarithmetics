# Cryptarithmetics

> Verbal arithmetic, also known as alphametics, cryptarithmetic, cryptarithm or word addition, is a type of mathematical game consisting of a mathematical equation among unknown numbers, whose digits are represented by letters of the alphabet.

_Via [Wikipedia](https://en.wikipedia.org/wiki/Verbal_arithmetic)_

This small program intends to demonstrate how you could solve any alphametics problem using backtracking. (This is not the most efficient way to solve them, Diophantine equations would outperform this method)

# Example problem

```
	  CP
	  IS
+	 FUN
-------------
	TRUE
```

One solution to this problem would be:

```
	  23
	  78
+	 945
-------------
	1046
```

The program will solve for every possible solution

# Problem constraints

A solution will be considered valid when:
- Every letter has a value in the interval [0,9]
- No two letters share the same value
- The equation is true

No input can be over 10 unknowns, as we're solving only for [0,9]
