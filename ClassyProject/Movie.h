#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>

class Movie
{
private:
	//attrs
	std::string name;
	int watchedCount;
	std::string rating;
	
public:
	//methods outside the class
	Movie(std::string name, int watchedCount, std::string rating);
	std::string get_name();
	std::string get_rating();
	int get_watchedCount();
	void display();
    ~Movie();

};

#endif // MOVIE_H
