F=[1 for i in range (1,93)]
def fibonacci(n):
    F[1]=1
    F[2]=1
    for i in range (3,n+1):
        F[i]=F[i-2]+F[i-1]
    return F[n]
def find(n,k):
    m=fibonacci(n-2)
    if (n==1 and k==1):
        return 'A'
    if (n==2 and k==1):
        return 'B'
    if (k<=m):
        return find(n-2,k)
    if (k>m):
        return find(n-1,k-m)
T=int(input())
G=[0 for i in range (T)]
H=[0 for i in range (T)]
for i in range (T):
    G[i], H[i]=input().split(" ")
    G[i]=int(G[i])
    H[i]=int(H[i])
for i in range (T):
    print (find(G[i],H[i]))
