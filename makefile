all : copyf touch ls

copyf : copyf/copyf.c
	gcc -o copyf copyf/copyf.c

touch : touch/touch.c
	gcc -o touch touch/touch.c

ls : ls/ls.c
	gcc -o ls ls/ls.c