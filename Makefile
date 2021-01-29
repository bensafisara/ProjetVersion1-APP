all : tpAppFinale

 tpAppFinale :   mmm.o funcThread.o funThreadC.o displayMatrix.o initMatrix.o sequential.o VerifMatrixEqual.o gcc mmm.o funcThread.o funThreadC.o displayMatrix.o initMatrix.o sequential.o VerifMatrixEqual.o -o tpAppFinale


mmm.o : mmm.c gcc -c mmm.c -o mmm.o

initMatrix.o : initMatrix.c gcc -c initMatrix.c -o initMatrix.o


displayMatrix.o : displayMatrix.c gcc -c displayMatrix.c  -o displayMatrix.o

funcThread.o : funcThread.c gcc -c funcThread.c -pthread -o funcThread.o

funThreadC.o : funThreadC.c gcc -c funThreadC.c -pthread -o funThreadC.o

sequential.o : sequentiel.c gcc -c sequentiel.c -o sequentiel.o

VerifMatrixEqual.o : VerifMatrixEqual.c gcc -c VerifMatrixEqual.c -o VerifMatrixEqual.o

clean: 
	rm -fr tpAppFinale *.o


