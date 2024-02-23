# utils-for-me
some basic utils in C that im writing to practice

# why
i dont want to memorize how to do these things on windows lol

# building
`make <name>` for any util you want to build

`make` if you want to build all of them

# utils
`ls` and `touch` do the same thing as in linux, but simpler

## copyf
copies a file

usage: `copyf <file path> <to copy path>`

example: `copyf test.txt ../test.txt`

this would copy test.txt to the parent directory

## ls
lists all directories and files in the current directory

usage: `ls`

## touch
creates an empty file with a specified name

usage `touch test.txt`

this would create an empty file with the name test.txt

## soulcalc
this is useless to pretty much anyone but souls players

tells you how many souls/runes/echoes you need to earn to be able to level up from level x to level y in demons souls, dark souls 1, 2, 3, elden ring and bloodborne

usage: `soulcalc <des/ds1/ds2/ds3/er/bb> <start lvl> <end lvl>`

example: `soulcalc des 115 120`

output: `to get from level 1 to level 120 in des, you'll need 435271 souls/runes/echoes`