all : output copyf touch ls

output :
	mkdir output

copyf : output copyf/copyf.c
	gcc -o output/copyf copyf/copyf.c

touch : output touch/touch.c
	gcc -o output/touch touch/touch.c

ls : output ls/ls.c
	gcc -o output/ls ls/ls.c