m=1000000007
def fibPow(M,expo):
    if (expo == 0 or expo == 1):        #Base Case
        return M
    elif (expo % 2 == 0):
        return fibPow(matrix_multiplication(M, M), expo//2)     # if expo is even,  M^(n/2) * M^(n/2) = M
    elif (expo % 2 != 0):
        R = fibPow(matrix_multiplication(M, M), expo//2)        # if expo is odd,  M^2 * M = M^3
        return matrix_multiplication(M,R)


def fibo(n):
    M = [[1, 1], [1, 0]]
    K = [[1, 0], [0, 0]]
    return matrix_multiplication(fibPow(M, n-1), K)[0][0]%m   # returns first element in the first column


def matrix_multiplication(A, B):
    u = A[0][0] * B[0][0] + A[0][1] * B[1][0]

    v = A[0][0] * B[0][1] + A[0][1] * B[1][1]

    w = A[1][0] * B[0][0] + A[1][1] * B[1][0]

    x = A[1][0] * B[0][1] + A[1][1] * B[1][1]

    return [[u, v], [w, x]]


def main():
    fibo_input = int(input("Enter a number : "))
    inp=[]
    for i in range (fibo_input):
        s=int(input())
        inp.append(s)
    for i in range (fibo_input):
        print(fibo(inp[i]))

if __name__=='__main__':
    main()
