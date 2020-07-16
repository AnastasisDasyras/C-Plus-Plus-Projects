#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"
#include "Movies.h"


int main(){
	
	Movies movies;
	movies.display();
	movies.add_movie("asdsa",2,"PR");
	movies.display();
	movies.add_movie("asdsa",2,"PR");
	movies.add_movie("bbb",1,"G");
	
	
	return 0;
}