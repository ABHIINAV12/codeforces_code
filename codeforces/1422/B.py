def prime(a):
	if a<0:
		a*=-1
	if a<2:
		return 0
	if a==2:
		return 1
	if a%2==0:
		return 0
	curr=3
	while (curr*curr<=a):
		if a%curr==0:
			return 0
		curr+=1
	return 1

def circular_prime(a):
	b=str(a)
	for i in range(0,len(b)):
		left=b[0:i]
		right=b[i:]
		right+=left
		c=int(right)
		if not prime(c):
			return False
	return True

def digit_cancel(a,b):
	c=str(a)
	d=str(b)


def pandigital(a):
	curr=1
	while (curr*curr<=a):
		if (a%curr==0):
			ano=a//curr
			c1=curr
			c2=ano
			c3=a
			l=[]
			for i in range(0,10):
				l.append(0)
			while(c1!=0):
				l[c1%10]+=1
				c1//=10
			while(c2!=0):
				l[c2%10]+=1
				c2//=10
			while(c3!=0):
				l[c3%10]+=1
				c3//=10
			fp=True
			for i in range(1,10):
				if l[i]!=1:
					fp=False
			if l[0]!=0:
				fp=False

			if fp:
				return True
		curr+=1
	return False

def digit_cancell():
	numerator=[]
	denominator=[]

def fun(i,j):
	res=""
	for k in range(1,j+1):
		res+=str(i*k)
	return res

def truncable():
	curr=1


def solve():
	a=input()
	r=a.split(" ")
	temp=[]
	for i in range (0,int(r[0])):
		a=input()
		b=a.split(" ")
		temp.append(b)
	l=[]
	for item in temp:
		add=[]
		for iden in item:
			add.append(int(iden))
		l.append(add)
	ans=0
	for i in range(0,int(r[0])):
		for j in range(0,int(r[1])):
			nums=[]
			nums.append(l[i][j])
			if (i!=int(r[0])-1-i):
				pass
			nums.append(l[int(r[0])-1-i][j])
			if (j!=int(r[1])-1-j):
				pass
			nums.append(l[i][int(r[1])-1-j])
			if (i!=int(r[0])-1-i) and (j!=int(r[1])-1-j):
				pass
			nums.append(l[int(r[0])-1-i][int(r[1])-1-j])
			add=10000000000000
			for k in range (0,len(nums)):
				th=0
				for k2 in range(0,len(nums)):
					th+=abs(nums[k]-nums[k2])
				add=min(add,th)
			ans+=add
	ans//=4
	print(ans)

def main():
	t=int(input())
	while (t>0):
		t-=1
		solve()
main()