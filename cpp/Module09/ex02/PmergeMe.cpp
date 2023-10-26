#include "PmergeMe.hpp"

#include <algorithm> //min, max
#include <cstdlib> // strtod()
#include <cmath> // isnan(), isinf()
#include <ctime> // clock()

// PmergeMe::Pair
PmergeMe::Pair::Pair(int n1, int n2) {
	larger = std::max(n1, n2);
	smaller = std::min(n1, n2);
}

bool PmergeMe::Pair::operator<(const Pair & x) const {
	return this->larger < x.larger;
}

// PmergeMe OCCF
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) {
	this->numCount = 0;
	this->vecSortingTime = 0;
	this->listSortingTime = 0;
	this->deqSortingTime = 0;

	for (int i=1; i<ac; i++) {
		int num = toInt(av[i]);
		this->vec.push_back(num);
		this->list.push_back(num);
		this->deq.push_back(num);
		this->numCount++;
	}
}

PmergeMe::PmergeMe(const PmergeMe & obj) {
	*this = obj;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & obj) {
	if (this == &obj)
		return *this;

	this->vec.clear();
	this->vec = obj.vec;

	this->list.clear();
	this->list = obj.list;

	this->numCount = obj.numCount;

	return *this;
}

PmergeMe::~PmergeMe() {}

// PmergeMe public functions
void PmergeMe::sortVec() {
	std::vector<int> sorted;
	std::vector<Pair> pairs;

	sorted.reserve(this->numCount);
	pairs.reserve((this->numCount + 1) / 2);

	clock_t startTime = clock();

	// 정렬해야 하는 배열을 2개씩 짝을 지어 pair 배열을 만든다.
	// 서로 짝지어진 원소의 크기를 비교하여 큰 수와 작은 수를 구분한다.
	for (unsigned int i = 1; i < this->numCount; i += 2) {
		pairs.push_back(Pair(this->vec[i - 1], this->vec[i]));
	}
	if (this->numCount % 2)
		pairs.push_back(Pair(this->vec.back(), -1));


	// pair 중에서 큰수를 기준으로 pair 배열을 정렬한다.
	std::sort(pairs.begin(), pairs.end());

	// pair들을 순서에 맞게 merge하여 정렬한다.
	// pair.larger는 정렬되어 있으며, 
	// pair.smaller를 이진탐색을 통해 올바른 위치를 찾은 후 삽입하여 정렬한다.
	for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->smaller > 0) {
			std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), it->smaller);
			sorted.insert(pos, it->smaller);
		}
		sorted.push_back(it->larger);
	}

	this->vecSortingTime = this->getExecutionTime(startTime);
	this->vec = sorted;
}

void PmergeMe::sortList() {
	std::list<int> sorted;
	std::list<Pair> pairs;

	clock_t startTime = clock();

	for (std::list<int>::iterator it = this->list.begin(); it != this->list.end(); it++) {
		pairs.push_back(Pair(*it, ++it != this->list.end() ? *it : -1));
		if (it == this->list.end())
			break;
	}

	pairs.sort();

	for (std::list<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->smaller > 0) {
			std::list<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), it->smaller);
			sorted.insert(pos, it->smaller);
		}
		sorted.push_back(it->larger);
	}

	this->listSortingTime = this->getExecutionTime(startTime);
	this->list = sorted;
}

void PmergeMe::sortDeq() {
	std::deque<int> sorted;
	std::deque<Pair> pairs;

	clock_t startTime = clock();

	for (std::deque<int>::iterator it = this->deq.begin(); it != this->deq.end(); it++) {
		pairs.push_back(Pair(*it, ++it != this->deq.end() ? *it : -1));
		if (it == this->deq.end())
			break;
	}

	std::sort(pairs.begin(), pairs.end());

	for (std::deque<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->smaller > 0) {
			std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), it->smaller);
			sorted.insert(pos, it->smaller);
		}
		sorted.push_back(it->larger);
	}

	this->deqSortingTime = this->getExecutionTime(startTime);
	this->deq = sorted;
}

void PmergeMe::printNums() {
	for (std::list<int>::iterator it = this->list.begin(); it != this->list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printExecutionTimes() {
	std::cout << "Time to process a range of " 
			  << this->numCount << " elements with std::vector : " 
			  << this->vecSortingTime << "ms" << std::endl;

	std::cout << "Time to process a range of " 
			  << this->numCount << " elements with std::list : " 
			  << this->listSortingTime << "ms" << std::endl;

	std::cout << "Time to process a range of " 
			  << this->numCount << " elements with std::deque : " 
			  << this->deqSortingTime << "ms" << std::endl;
}


// PmergeMe private functions
int PmergeMe::toInt(char *input) {
	double val = 0.0;
	char *endPtr = NULL;

	val = std::strtod(input, &endPtr);

	if (!endPtr || *endPtr != '\0')
		throw std::invalid_argument("Invalid Input");
	else if (std::isnan(val) || std::isinf(val)
			|| val < -2147483648 || val > 2147483647
			|| val != static_cast<int64_t>(val)
			|| val < 0)
		throw std::invalid_argument("Invalid Input");

	return static_cast<int>(val);
}

double PmergeMe::getExecutionTime(clock_t startTime) {
	clock_t endTime = clock();
	double res = (double)(endTime - startTime);

	return res;
}