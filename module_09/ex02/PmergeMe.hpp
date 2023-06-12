#pragma once

# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <string>
# include <limits>
# include <algorithm>
# include <ctime>

# define MERGE_THRESHOLD 32

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double 				_vector_start_t;
		double				_vector_total_t;
		double				_deque_start_t;
		double				_deque_total_t;

		PmergeMe();
		
	public:
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe & src);
		PmergeMe operator = (const PmergeMe & rhs);


		void 				setup_vector(char **av);
		void 				setup_deque(char **av);
		bool 				isDigit(const std::string &str);
		void				insertionSort(std::vector<int> &array);
		void				insertionSort(std::deque<int> &array);
		void				mergeInsertionSort(std::vector<int> &rray);
		void				mergeInsertionSort(std::deque<int> &rray);

		void				displayVector();
		void				displayDeque();
		double				vectorTime();
		double				dequeTime();




		class InvalidCharacterException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NonPositiveIntException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};