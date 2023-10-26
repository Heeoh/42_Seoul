#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>


class PmergeMe {
	unsigned int 		numCount;
	std::vector<int>    vec;
	std::list<int>		list;
	std::deque<int>		deq;
	double				vecSortingTime;
	double				listSortingTime;
	double				deqSortingTime;

	PmergeMe();

	struct Pair {
		int larger;
		int smaller;

		Pair(int n1, int n2);
		bool operator<(const Pair & x) const;
	};

public:
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe & obj);
	PmergeMe & operator=(const PmergeMe & obj);
	~PmergeMe();
	
	void sortVec();
	void sortList();
	void sortDeq();
	void printNums();
	void printExecutionTimes();
	
private:
	
	int toInt(char *input);
	
	double getExecutionTime(clock_t startTime);

};



#endif
