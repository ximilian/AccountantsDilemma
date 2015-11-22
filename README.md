# AccountantsDilemma
Simple Subset Sum solver for Knapsack problem

## Description ##
Let assume we have a list of positive double, with value between 0 and 10000.
Given a number *T*, between 0 and 10000, there exist a set of value in the list whose sum is no greater than *T*?

So, in the end, this is a simple solver for the well-known [Knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem).

Assumption:
* values are between 0 and 10000
* precision required is up to second decimal digit (2.123 -> 2.12)

## History ##
This problem was gave to me while I was interviewed for a position in a bank as software developer.
The problem goes like this:

> Danielle, the accountant of your company, needs help with a problem she is facing. She needs to
> deal with a document containing a ‘Bank Transfer’ and a list of ‘Due Payments’ represented as 
> decimal numbers with 2 decimal places.

> An entry in the ‘Due Payments’ list represents the amount the company should receive either as 
> payment for a given product which is recently sold.
> The ‘Bank Transfer’ value represents the amount of a bank transfer which sums up payments of sold 
> items in a specific period of time (as they appear in the company’s account statement).

> Danielle tells you that the ‘Bank Transfer’ amount represents the sum of a part of the amounts 
> in the ‘Due Payments’ list. This is because the amount transferred in the company’s account is 
> necessarily the sum of part of the due payments of recently sold items.

> The problem is that Danielle does not know the payments to which the bank transfer corresponds. 
> She is currently doing the mapping by hand and it is very time consuming. Can you build a small 
> application/tool for Danielle so she could use it to speed up her day to day work?

> Example
```
Due Payments | Bank Transfer
----------------------------
   22.75     |    74.06
   59.33     |
   34.22     |
   27.21     |
   17.09     |
  100.99     |
```
> In the example above, the solution Danielle found is:
> 74.06 corresponds to 22.75 + 34.22 + 17.09

> Some remarks:
> There are no bank transfers greater than $10,000

In the end, I did not take the offer, but it was fun solving it.

## How to compile ##
```
mkdir build
cd build
cmake ..
make
```

## How to run ##
```
cd build
./acc_dilemma -i ../data/input.txt -o ../data/output.txt
```

### Input File Format ###
The input is a list of positive double. The first line is the total sum we are looking for.
Example:
```
9999.99 <- Total
23.13
2344.54
12
12.009
...
```
Numbers are rounded to second decimal digit.
