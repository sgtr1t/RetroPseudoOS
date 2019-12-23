CC = gcc
all: run OS.out user_manual user_manual_zh main.save
run:
	mkdir ../run
OS.out: src/main.c
	$(CC) -o ../run/OS.out src/main.c
user_manual: etc/user_manual
	cp etc/user_manual ../run/user_manual
user_manual_zh: etc/user_manual_zh
	cp etc/user_manual_zh ../run/user_manual_zh
main.save:
	touch ../run/main.save
