all: test

test: cpp_base
	./cpp_base < input.txt > foo.txt
	diff output.txt foo.txt
