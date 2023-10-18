deck:
	gcc -g -Wall -o deck deck.c deck.h

hash_table: hash_table.c
	gcc -g -Wall -o hash_table hash_table.c

clean:
	rm -f hash_table && rm -f deck && rm -f rsa && rm -f two && rm -f double && rm -f sock
