#House of Cards
import sys

cache = {}

def story(num):
	for i in range(num):
		total = l_to_c(i+1)
		if total >num:
			return i

def l_to_c(n):
	if n in cache:
		return cache[n]
	if n<1:
		return 0
	rv = 2*n+n-1
	
	rv += l_to_c(n-1)
	print rv
	cache[n] = rv
	return rv

def get_line():
	return int(sys.stdin.readline())

def main():
	while True:
		num = get_line()
		if num == -1:
			return 

		count = story(num)
		print num, count

if __name__ == "__main__":
	main()
