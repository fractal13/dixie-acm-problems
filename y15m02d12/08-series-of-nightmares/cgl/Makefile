all: test

test: cpp_series
	./cpp_series < input.txt > foo.txt
	diff output.txt foo.txt
