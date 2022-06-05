def maximise(n, m, k, arr):

	itter_left = k
	test = 1
	count = 0

	# ------- count initial multiples of 'm' -------
	for x in arr:
		if(abs(x % m) == 0):
			count = count + 1

	# ------- itterate till 'k' is completly consumed -------
	while(itter_left):
		for x in arr :

			# ------- check if i can add small 'test' portion to array-item to make it multiple of 'm' -------
			if(m - abs(x % m) == test):

				# ------- iff k ! completly consumed -------
				if(itter_left):
					count = count + 1
					itter_left = itter_left - test
		test = test + 1

	return count

def main():

	n = int(input('Enter array size : '))
	m = int(input('Multiple of : '))
	k = int(input('limit to : '))

	arr = []

	print('\nEnter {} array values you specified'.format(n))
	for i in range(n):
		arr.append(int(input(' : ')))

	multiples = maximise(n, m, k, arr)

	# ------- print what has been enter -------

	print('\n[ ', end=' ')
	for x in arr:
		print('{}'.format(x), end=' ')
	print(']')

	# ------- result count -------
	print("\nTotal number of multiples of '{}' is {}".format(m, multiples))

main()
