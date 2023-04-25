program: main.o quiries.o sqlite3.o
	mkdir bin
	gcc -o bin/program obj/main.o obj/quiries.o obj/sqlite3.o

main.o: src/main.c include/quiries.h
	mkdir obj
	gcc -c src/main.c -o obj/main.o -lsqlite3
	
sqlite3.o: src/sqlite3.c include/sqlite3.h
	gcc -c src/sqlite3.c -o obj/sqlite3.o -lsqlite3	
	
quiries.o: src/quiries.c include/quiries.h
	gcc -c src/quiries.c -o obj/quiries.o -lsqlite3

clean:
	rm -f obj/*.o bin/Program

run: 
	./bin/program