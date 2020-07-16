#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <iostream>
#include <vector>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;

public:
    Movies();
    void add_movie(std::string name, int watchedCount, std::string rating);
    bool increment_watched(int watchedCount);
    void display();
    ~Movies();
};

#endif // MOVIES_H
