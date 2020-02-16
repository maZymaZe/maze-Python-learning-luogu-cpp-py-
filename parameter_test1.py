def power(x,n=2,m=1) :
    if n!=0 :
        return power(x,n-1,m*x)
    else :
        return m

#print(power(4),power(4,3))
#print(power(4,m=2))
nums1=[1,2,3,4,5]
def s(*nums):
    sum=0
    for i in nums:
        sum+=power(i)
    return sum
print(s(*nums1))