# single line comment
# target:dependency object(.o) files need to provide  then press enter
#	cc all_object_files -o exe_name(target)		
#target(.o)file : dependency(.c) file
#	cc -c dependency.c file

target=main.o insert.o delete.o print.o file.o reverse.o other.o
CC=cc
exe: $(target)
	$(CC) $(target) -o exe
debug: $(target)
	$(CC) $(target) -o exedebug -g
main.o:main.c
	$(CC) -c main.c
insert.o:insert.c
	$(CC) -c insert.c
delete.o:delete.c
	$(CC) -c delete.c
print.o:print.c
	$(CC) -c print.c
file.o:file.c
	$(CC) -c file.c
reverse.o:reverse.c
	$(CC) -c reverse.c
other.o:other.c
	$(CC) -c other.c
clear:
	@echo "cleaning up...."
	@rm -rv *.o	
run:./exe
	@./exe
		
	
	
	
	
	
	



















