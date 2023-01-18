#include "Scalar.hpp"

/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */

Scalar::Scalar() {}

Scalar::Scalar(std::string litteral)
{
	_litteral = (litteral);
	
	if (litteral.empty())
		throw Scalar::ImpossibleConversionException();
	
	// If litteral contains 1 element
	if (litteral.size() < 2)
	{
		if (!isdigit(litteral[0]))
			_type = eChar;
		else
			_type = eInt;
		return;
	}

	// If litteral is litteral values
	if (litteral == "nan" || litteral == "NaN" || litteral == "nanf" || litteral == "NaNf")
	{
		_type = eNan;
		return ;
	}

	if (litteral == "-inff" || litteral == "+inff" || litteral == "inff")
	{
		_type = eFloat;
		return ;
	}

	if (litteral == "-inf" || litteral == "+inf" || litteral == "inf")
	{
		_type = eDouble;
		return ;
	}

	char *endptr;

	// If litteral can be converted to a long integer
	strtol(litteral.c_str(), &endptr, 10);
	if (!*endptr)
	{
		_type = eInt;
		return ;
	}

	// If litteral can be converted to a double, or looks like a float
	strtof(litteral.c_str(), &endptr);
	if (!*endptr)
		_type = eDouble;
	else if (
		*endptr == 'f'
		&& *endptr == litteral.c_str()[litteral.length() - 1]
		&& litteral.find(".") != std::string::npos
		&& litteral.find(".") < litteral.length() - 2
	)
		_type = eFloat;
	else
		_type = eNan;
}


Scalar::~Scalar() { }


Scalar::Scalar(const Scalar &src)
{
	*this = src;
}


Scalar & Scalar::operator = (const Scalar &rhs)
{
	_litteral = rhs._litteral;
	_type = rhs._type;

	return *this;
}
/* ========================================================================== */
/*                                                                            */
/*                             ~ member functions ~                           */
/*                                                                            */
/* ========================================================================== */

std::string Scalar::litteral(void) const
{
	return _litteral;
}


Scalar::Type Scalar::type(void) const
{
	return _type;
}



char Scalar::toChar(void) const
{
	long int 	tmpLong = atol(_litteral.c_str());
	double		tmpDouble = strtof(_litteral.c_str(), NULL);

	switch(_type)
	{
		case eChar:
			if (tmpLong < 32 || tmpLong > 126)
				throw NonDisplayableException();
			return static_cast<char>(tmpLong);

		case eInt:
			if (tmpLong < std::numeric_limits<char>::min() || tmpLong > std::numeric_limits<char>::max())
				throw ImpossibleConversionException();
			else if (tmpLong < 32 || tmpLong > 126)
				throw NonDisplayableException();
			return static_cast<char>(tmpLong);

		case eFloat:
			if (tmpDouble < std::numeric_limits<char>::min() || tmpDouble > std::numeric_limits<char>::max())
				throw ImpossibleConversionException();
			else if ( tmpDouble < 32 || tmpDouble > 126)
				throw NonDisplayableException();
			return static_cast<char>(tmpDouble);

		case eDouble:
			if (tmpDouble < std::numeric_limits<char>::min() || tmpDouble > std::numeric_limits<char>::max())
				throw ImpossibleConversionException();
			else if (tmpDouble < 32 || tmpDouble > 126)
				throw NonDisplayableException();
			return static_cast<char>(tmpDouble);

		case eNan:

			throw ImpossibleConversionException();

		default: 

			throw ImpossibleConversionException();
	}
}


int Scalar::toInt(void) const
{
	long int tmpLong = atol(_litteral.c_str());
	double tmpDouble = strtof(_litteral.c_str(), NULL); 

	switch(_type)
	{
		case eChar:
			return static_cast<int>(tmpLong);

		case eInt:
			if (tmpLong < std::numeric_limits<int>::min() || tmpLong > std::numeric_limits<int>::max())
				throw ImpossibleConversionException();
			return tmpLong;

		case eFloat:
			if (tmpDouble < std::numeric_limits<int>::min() || tmpDouble > std::numeric_limits<int>::max())
				throw ImpossibleConversionException();
			return static_cast<int>(tmpDouble);

		case eDouble:
			if (tmpDouble < std::numeric_limits<int>::min() || tmpDouble > std::numeric_limits<int>::max())
				throw ImpossibleConversionException();
			return static_cast<int>(tmpDouble);

		case eNan:
			throw ImpossibleConversionException();

		default:
			throw ImpossibleConversionException();	
	}
}


float Scalar::toFloat(void) const
{
	long int tmpLong = atol(_litteral.c_str());
	long double tmpDouble = strtof(_litteral.c_str(), NULL); 

	switch(_type)
	{
		case eChar:
			return static_cast<float>(tmpLong);

		case eInt:
			return static_cast<float>(tmpLong);

		case eFloat:
			if (_litteral == "+inff" || _litteral == "inff")
				return std::numeric_limits<float>::infinity();
			else if (_litteral == "-inff")
				return -std::numeric_limits<float>::infinity();
			if ( tmpDouble > std::numeric_limits<float>::max())
				throw ImpossibleConversionException();
			return static_cast<float>(tmpDouble);

		case eDouble:
			if (_litteral == "+inf" || _litteral == "inf")
				return std::numeric_limits<float>::infinity();
			else if (_litteral == "-inf")
				return -std::numeric_limits<float>::infinity();
			if (tmpDouble > std::numeric_limits<float>::max())
				throw ImpossibleConversionException();
			return static_cast<float>(tmpDouble);

		case eNan:
			throw NotANumberFloatException();

		default:
			throw ImpossibleConversionException();	
	}
}


double Scalar::toDouble(void) const
{
	long int tmpLong = atol(_litteral.c_str());
	long double tmpDouble = strtof(_litteral.c_str(), NULL); 

	switch(_type)
	{
		case eChar:
			return static_cast<double>(tmpLong);

		case eInt:
			return static_cast<double>(tmpLong);

		case eFloat:
			if (_litteral == "+inff" || _litteral == "inff")
				return std::numeric_limits<double>::infinity();
			else if (_litteral == "-inff")
				return -std::numeric_limits<double>::infinity();
			if ( tmpDouble > std::numeric_limits<double>::max())
				throw ImpossibleConversionException();
			return static_cast<double>(tmpDouble);

		case eDouble:
			if (_litteral == "+inf" || _litteral == "inf")
				return std::numeric_limits<double>::infinity();
			else if (_litteral == "-inf")
				return -std::numeric_limits<double>::infinity();
			if (tmpDouble > std::numeric_limits<double>::max())
				throw ImpossibleConversionException();
			return static_cast<double>(tmpDouble);

		case eNan:
			throw NotANumberException();

		default:
			throw ImpossibleConversionException();	
	}
}
/* ========================================================================== */
/*                                                                            */
/*                                ~ exceptions ~                              */
/*                                                                            */
/* ========================================================================== */

const char *Scalar::ImpossibleConversionException::what() const throw()
{
	return "impossible";
}


const char *Scalar::NonDisplayableException::what() const throw()
{
	return "non displayable";
}


const char *Scalar::NotANumberFloatException::what() const throw()
{
	return "nanf";
}


const char *Scalar::NotANumberException::what() const throw()
{
	return "nan";
}