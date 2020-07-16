#include "Movie.h"

Movie::Movie(std::string name, int watchedCount, std::string rating)
{
	this->name = name;
    this->watchedCount = watchedCount;
    this->rating = rating;
}

std::string Movie::get_name()
{
    return name;
}

std::string Movie::get_rating()
{
    return rating;
}

int Movie::get_watchedCount()
{
    return watchedCount;
}

void Movie::display()
{
    std::cout << name + ", " + std::to_string(watchedCount) + ", " + rating << std::endl;
}

Movie::~Movie()
{
}

