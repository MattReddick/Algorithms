'''

The Fibonacci sequence can be defined as follows:

fib1 = 1 fib2 = 1 fib𝑛 = fib𝑛−2 + fib𝑛−1
We get the sequence 1,1,2,3,5,8,13,21,…. But there are many generalizations of 
the Fibonacci sequence. One of them is to start with other numbers, like:

𝑓1 = 5 𝑓2 = 4 𝑓𝑛 = 𝑓𝑛−2 + 𝑓𝑛−1
And we get the sequence 5,4,9,13,22,35,57,…. But what if we start with something
other than numbers? Let us define the Batmanacci sequence in the following manner:

𝑠1 = N 𝑠2 = A 𝑠𝑛 = 𝑠𝑛−2 + 𝑠𝑛−1
where + is string concatenation. Now we get the sequence N, A, NA, ANA, NAANA, ….

Given 𝑁 and 𝐾, what is the 𝐾-th letter in the 𝑁-th string in the Batmanacci sequence?

Input
Input consists of a single line containing two integers 𝑁 (1≤𝑁≤105) and 𝐾 (1≤𝐾≤1018). 
It is guaranteed that 𝐾 is at most the length of the 𝑁-th string in the Batmanacci sequence.

Output
Output the 𝐾-th letter in the 𝑁-th string in the Batmanacci sequence.

'''

N,K= map(int,input().split())


fib = [0,1,1]

for i in range(N+1):
  fib.append(fib[len(fib)-2] + fib[len(fib)-1])

while N > 2:
  if K > fib[N-2]:
    K-= fib[N-2]
    N-=1
  else:
    N-=2

if N == 1:
  print('N')
else:
  print('A')

