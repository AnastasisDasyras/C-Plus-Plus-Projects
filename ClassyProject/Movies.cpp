#include "Movies.h"

Movies::Movies()
{
}

void Movies::add_movie(std::string name, int watchedCount, std::string rating){
	bool found = false;
	for(int i=0;i<movies.size();i++){
		if(name==movies.at(i).get_name()){
			std::cout << "Sorry the movies already exists." << std::endl;
			found = true;
			break;
		}
	}
	
	if(!found){
		movies.push_back(Movie(name, watchedCount, rating));
	}
	
}
	
bool Movies::increment_watched(int watchedCount){
	return watchedCount++;
}

void Movies::display(){
	if(movies.size()==0){
		std::cout << "Sorry, there is no movies on your list" << std::endl;
	}
	else{
		for(auto movie: movies){
			movie.display();
		}
			
	}
}

Movies::~Movies()
{
}

