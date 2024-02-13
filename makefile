all : copyf touch

copyf : copyf/copyf.c
	gcc -o copyf copyf/copyf.c

touch : touch/touch.c
	gcc -o touch touch/touch.c