a=int(input("enter the first number : "))
b=int(input("enter the first number : "))
c=int(input("enter the first number : "))
d=int(input("enter the first number : "))
if (a>b)and(a>c)and(a>d) :
     greatest=a
if (b>a)and(b>c)and(b>d) :
    greatest=b
if (c>b)and(c>a)and(c>d) :
    greatest=c 
if (d>b)and(d>c)and(a<d) :
    greatest =d
    print(greatest)