import random
import itertools
def nhanBinhPhuongColap(a,k,n):
    b =1 
    A = a
    if(k%2 == 1):
        b = a 
    k//=2
    while(k>0):
        A = A**2 % n
        if (k%2==1):
            b = (A*b)%n
        k//=2
    return b

def checkPrimeFermat(n):
    if n<=1:
        return False
    if n==2 or n==3:
        return True
    if n%2==0 or n%3==0:
        return False
    t = 5
    for i in range(1,t+1):
        a = random.randint(2,n-2 +1)
        r = nhanBinhPhuongColap(a,n-1,n)
        if r != 1:
            return False
    return True

def main():
    n = int(input("Nhap N: "))
    m = int(input("Nhap M: "))
    if (n<1 or n>10000 or m<=2 or m>100):
        print("Nhap lai 1<=N<=10000; 2<M<=100")
        return
    # tìm các snt <=n và lưu vào mảng a[]
    a = []
    for i in range (1,n+1):
        if checkPrimeFermat(i) == True:
            a.append(i)
    #lọc ra tất cả các bộ m phần tử trong mảng a[]
    combination = list(itertools.combinations(a,m))
    for i in combination:
        if sum(i) == n:
            print(i)
        
    
if __name__ == "__main__":
    main()
