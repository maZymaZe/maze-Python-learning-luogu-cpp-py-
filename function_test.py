#print(hex(34567645356))
import math
def quadratic(a,b,c):
    if b*b-4*a*c<0 :
        print("no answer in R")
    elif abs(b*b-4*a*c)<1e-6 :
        print("one root:%f"%(-b/2/a))
    else :
        print("two roots:%f %f"%((((-b+math.sqrt(b*b-4*a*c))/2/a),((-b-math.sqrt(b*b-4*a*c))/2/a))))

a=float(input("a="))
b=float(input("b="))
c=float(input("c="))
quadratic(a,b,c)