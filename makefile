all: exec

exec: customer.o jamTree.o item.o main.cpp fileReader.o customerBST.o
	g++ -Wall -Wextra -g *.o main.cpp -o exec

customer.o: customer.cpp
	g++ -Wall -Wextra -g -c customer.cpp -o customer.o

jamTree.o: jamTree.cpp
	g++ -Wall -Wextra -g -c jamTree.cpp -o jamTree.o

item.o: item.cpp
	g++ -Wall -Wextra -g -c item.cpp -o item.o


fileReader.o: fileReader.cpp
	g++ -Wall -Wextra -g -c fileReader.cpp -o fileReader.o

customerBST.o: customerBST.cpp
	g++ -Wall -Wextra -g -c customerBST.cpp -o customerBST.o

clean:
	rm -f *.o
	rm exec
