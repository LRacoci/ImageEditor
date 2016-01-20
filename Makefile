all: conversor

Arqs = *.cpp *.h
Flags = -ansi -pedantic -Wall

conversor: $(Arqs) clean
	g++ $(Arqs) $(FLags) -o conversor -g

png2:
	./conversor 1.png 2.png

.PHONY : clean
clean:
	rm -f conversor
