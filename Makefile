run: asn03
	./asn03
	
asn03: asn03.o Drawable.o EnemyTank.o Camera.o Game.o EnemyAI.o Plane.o Shell.o
	g++ -g -std=c++0x -o asn03 asn03.o Drawable.o EnemyTank.o Camera.o Game.o EnemyAI.o Plane.o Shell.o -lGL -lGLU -lglut
	
asn03.o: asn03.cpp Drawable.h EnemyTank.h
	g++ -c asn03.cpp -o asn03.o
	
Drawable.o: Drawable.cpp Drawable.h
	g++ -c Drawable.cpp -o Drawable.o
	
EnemyTank.o: EnemyTank.cpp Drawable.h EnemyTank.h
	g++ -c EnemyTank.cpp -o EnemyTank.o

Camera.o: Camera.cpp Camera.h
	g++ -c Camera.cpp -o Camera.o
	
Game.o: Game.cpp Game.h Drawable.h EnemyAI.h
	g++ -std=c++0x -c Game.cpp -o Game.o

EnemyAI.o: EnemyAI.cpp EnemyTank.h
	g++ -c EnemyAI.cpp -o EnemyAI.o
	
Plane.o: Plane.cpp Plane.h Drawable.h
	g++ -c Plane.cpp -o Plane.o
	
Shell.o: Shell.cpp Shell.h Drawable.h
	g++ -c Shell.cpp -o Shell.o
	
clean:
	rm -f asn03 *.o *~
