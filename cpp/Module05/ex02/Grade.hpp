#ifndef GRADE_HPP
# define GRADE_HPP

# include <iostream>

class Grade {
private:
	int 		grade;
	
public: 
	static int	highestGrade;
	static int	lowestGrade;

public:
	Grade();
	Grade(const Grade& obj);
	Grade& operator= (const Grade& obj);
	~Grade();

	Grade(int grade);
	Grade& operator++(void);
	Grade& operator--(void);
	Grade operator++(int);
	Grade operator--(int);

	int getGrade() const;

	bool isTooHigh() const;
	bool isTooLow() const;
};

#endif