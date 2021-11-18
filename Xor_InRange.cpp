long long f(long long a) {
     long long res[] = {a,1,a+1,0};
     return res[a%4];
}

long long getXor(long long a, long long b) {
     return f(b)^f(a-1);
}
/*it exploits the fact that there is a pattern of results in the running XORs.
The f() function calculates the XOR total run from [0, a].
 Take a look at this table for 4-bit numbers:

0000 <- 0  [a] 			#0
0001 <- 1  [1] 			#1
0010 <- 3  [a+1]		#2
0011 <- 0  [0]			#3
0100 <- 4  [a]			#4
0101 <- 1  [1]			#5
0110 <- 7  [a+1]		#6
0111 <- 0  [0]			#7
1000 <- 8  [a]			....
1001 <- 1  [1]
1010 <- 11 [a+1]
1011 <- 0  [0]
1100 <- 12 [a]
1101 <- 1  [1]
1110 <- 15 [a+1]
1111 <- 0  [0]
*/