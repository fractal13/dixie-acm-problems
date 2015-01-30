all: py_test cpp_test

py_test: py_ropes.py input01.txt output01.txt
	./py_ropes.py < input01.txt > output.txt
	diff output.txt output01.txt

cpp_test: cpp_ropes
	cpp_ropes < input01.txt > output.txt
	diff output.txt output01.txt
