#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
	setup(av);
	// encore un commentaire
}

PmergeMe::~PmergeMe() {} 

PmergeMe::PmergeMe(const PmergeMe & src)
{
	_vector = src._vector;
	_deque = src._deque;
}

PmergeMe PmergeMe::operator = (const PmergeMe & rhs)
{
	_vector = rhs._vector;
	_deque = rhs._deque;

	return *this;	
}

bool PmergeMe::isDigit(const std::string &str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
	{
		if (!isdigit(*it))
			return false;
	}
	return true;
}

void PmergeMe::setup(char **av)
{
	long buffer;
	for (int i = 0; av[i]; i++)
	{
		if (!isDigit(av[i]))
			throw InvalidCharacterException();

		buffer = atol(av[i]);
		if (buffer < 0 || buffer > std::numeric_limits<int>::max())
			throw NonPositiveIntException();

		_vector.push_back(buffer);
		_deque.push_back(buffer);

 	}
}

void PmergeMe::insertionSort(std::vector<int> &array)
{
	for (size_t i = 1; i < array.size(); i++)
	{
		int tmp = array[i];
		int j = i - 1;
	while (array[j] > tmp && j >= 0)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
	}
}

void PmergeMe::mergeInsertionSort(std::vector<int> &array)
{
	if (array.size() > MERGE_THRESHOLD)
	{
		std::vector<int> l(array.begin(), array.begin() + array.size() / 2);
		std::vector<int> r(array.begin() + array.size() / 2, array.end());
		mergeInsertionSort(l);
		mergeInsertionSort(r);
		std::merge(l.begin(), l.end(), r.begin(), r.end(), array.begin());
	}
	else
		insertionSort(array);
}


void PmergeMe::insertionSort(std::deque<int> &array)
{
	for (size_t i = 1; i < array.size(); i++)
	{
		int tmp = array[i];
		int j = i - 1;
	while (array[j] > tmp && j >= 0)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
	}
}

void PmergeMe::mergeInsertionSort(std::deque<int> &array)
{
	if (array.size() > MERGE_THRESHOLD)
	{
		std::vector<int> l(array.begin(), array.begin() + array.size() / 2);
		std::vector<int> r(array.begin() + array.size() / 2, array.end());
		mergeInsertionSort(l);
		mergeInsertionSort(r);
		std::merge(l.begin(), l.end(), r.begin(), r.end(), array.begin());
	}
	else
		insertionSort(array);
}

void PmergeMe::sort()
{
	clock_t start = clock();
	mergeInsertionSort(_vector);
	clock_t end = clock();
	_vector_time = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000);

	start = clock();
	mergeInsertionSort(_deque);
	end = clock();
	_deque_time = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000);
}

void PmergeMe::displayVector()
{
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		it == _vector.begin() ? std::cout << *it : std::cout << " " << *it;
}

void PmergeMe::displayDeque()
{
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
		it == _deque.begin() ? std::cout << *it : std::cout << " " << *it;
}

double PmergeMe::vectorTime()
{
	return _vector_time;
}

double PmergeMe::dequeTime()
{
	return _deque_time;
}

const char *PmergeMe::InvalidCharacterException::what() const throw()
{
	return "invalid character";
}

const char *PmergeMe::NonPositiveIntException::what() const throw()
{
	return "non-positive int";
}