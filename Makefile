LIBDIRS = -I/usr/X11R6/include/ -L/usr/X11R6/lib 

	COMPILERFLAGS = -Wall

CC = gcc
CFLAGS = $(COMPILERFLAGS)
LIBS = -lX11 -lXi -lglut -lGL -lGLU -lm -lXmu

opengl : 
	$(CC) $(CFLAGS) -o logistic $(LIBDIRS) logistic.c $(LIBS)

