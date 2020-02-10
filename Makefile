#######################
#Makefile
#Lucas Manker
#COSC 3750 Homework 4
#2/17/20
#
#Makefile for homework 4
######################

CC=gcc
CFLAGS=-ggdb -Wall

.PHONY: clean

wycat: wycat.c
	$(CC) $(CFLAGS) wycat.c -o wycat

clean:
	/bin/rm -f wycat

