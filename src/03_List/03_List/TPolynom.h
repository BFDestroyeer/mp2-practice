#pragma once

#include <string>
#include <iostream>

#include "TList.h"
#include "TException.h"

class TPolynom
{
public:
	TList<unsigned, double>* list;

public:
	TPolynom();
	TPolynom(const TList<unsigned, double>& list_);
	TPolynom(const TPolynom& temp);
	~TPolynom();

	TPolynom& operator=(const TPolynom& temp);
	TPolynom operator+(const TPolynom& temp);
	TPolynom& operator+=(const TPolynom& temp);
	TPolynom operator+(const TNode<unsigned, double>& node);
	TPolynom& operator+=(const TNode<unsigned, double>& node);
	TPolynom operator-(const TPolynom& temp);
	TPolynom& operator-=(const TPolynom& temp);
	TPolynom operator-(const TNode<unsigned, double>& node);
	TPolynom& operator-=(const TNode<unsigned, double>& node);
	TPolynom operator*(const TPolynom& temp);
	TPolynom operator*(const TNode<unsigned, double>& node);
	TPolynom& operator*=(const TNode<unsigned, double>& node);

	friend std::ostream& operator<<(std::ostream& out, const TPolynom& polynom);
	friend std::istream& operator>>(std::istream& in, TPolynom& polynom);

	friend TPolynom operator-(TPolynom temp);
};

TPolynom::TPolynom()
{
	list = new TList<unsigned, double>;
}

TPolynom::TPolynom(const TList<unsigned, double>& list_)
{
	list = new TList<unsigned, double>;
	TNode<unsigned, double>* iter = list_.pFirst;
	while (iter != nullptr)
	{

		if (iter->key >= 1000) throw TException(NotInSystem);
		*this += *iter;
		iter = iter->pNext;
	}
}

TPolynom::TPolynom(const TPolynom& temp)
{
	list = new TList<unsigned, double>(*(temp.list));
}

TPolynom::~TPolynom()
{
	delete list;
}

TPolynom& TPolynom::operator=(const TPolynom& temp)
{
	if (this == &temp) return *this;
	delete list;
	list = new TList<unsigned, double>(*(temp.list));
	return *this;
}

TPolynom TPolynom::operator+(const TPolynom& temp)
{
	TPolynom out;
	TNode<unsigned, double>* first = list->pFirst;
	TNode<unsigned, double>* second = temp.list->pFirst;
	while (first != nullptr || second != nullptr)
	{
		if (first == nullptr)
		{
			out.list->InsertBackward(second->key, second->pData);
			second = second->pNext;
		}
		else if (second == nullptr)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (first->key > second->key)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (first->key < second->key)
		{
			out.list->InsertBackward(second->key, second->pData);
			second = second->pNext;
		}
		else
		{
			if (*(first->pData) != -*(second->pData))
			{
				out.list->InsertBackward(first->key, *(first->pData) + *(second->pData));
			}
			first = first->pNext;
			second = second->pNext;
		}
	}
	return out;
}

TPolynom& TPolynom::operator+=(const TPolynom& temp)
{
	TNode<unsigned, double>* first = list->pFirst;
	TNode<unsigned, double>* second = temp.list->pFirst;
	if (first == nullptr)
	{
		delete list;
		list = new TList<unsigned, double>(*(temp.list));
		return *this;
	}
	if (second == nullptr)
	{
		return *this;
	}
	if (first->key < second->key)
	{
		list->InsertForward(second->key, second->pData);
		first = list->pFirst;
		second = second->pNext;
	}
	while (second != nullptr)
	{
		if (first->pNext == nullptr)
		{
			first->pNext = new TNode<unsigned, double>(*(second));
			first = first->pNext;
			second = second->pNext;
		}
		else if (first->pNext->key > second->key)
		{
			first = first->pNext;
		}
		else if (first->pNext->key < second->key)
		{
			TNode<unsigned, double>* temp = new TNode<unsigned, double>(*(second));
			temp->pNext = first->pNext;
			first->pNext = temp;
			first = first->pNext;
			second = second->pNext;
		}
		else
		{
			if (*(first->pNext->pData) != -*(second->pData))
				*(first->pNext->pData) += *(second->pData);
			else
				list->Remove(first->pNext->key);
			second = second->pNext;
		}
	}
	return *this;
}

TPolynom TPolynom::operator+(const TNode<unsigned, double>& node)
{
	TPolynom out;
	TNode<unsigned, double>* first = list->pFirst;
	bool isInserted = false;
	while (first != nullptr || !isInserted)
	{
		if (first == nullptr)
		{
			out.list->InsertBackward(node.key, node.pData);
			isInserted = true;
		}
		else if (first->key > node.key)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (!isInserted && first->key < node.key)
		{
			out.list->InsertBackward(node.key, node.pData);
			isInserted = true;
		}
		else if (!isInserted)
		{
			if (*(first->pData) != -*(node.pData))
			{
				out.list->InsertBackward(first->key, *(first->pData) + *(node.pData));
			}
			first = first->pNext;
			isInserted = true;
		}
		else
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
	}
	return out;
}

TPolynom& TPolynom::operator+=(const TNode<unsigned, double>& node)
{
	TNode<unsigned, double>* first = list->pFirst;
	if (first == nullptr || node.key > first->key)
	{
		list->InsertForward(node.key, node.pData);
		return *this;
	}
	while ((first->pNext != nullptr) && (first->pNext->key > node.key))
		first = first->pNext;
	if ((first->pNext != nullptr) && (first->pNext->key == node.key))
	{
		if (*(first->pNext->pData) != -*(node.pData))
			*(first->pNext->pData) += *(node.pData);
		else
			list->Remove(first->pNext->key);
		return *this;
	}
	TNode<unsigned, double>* temp = new TNode<unsigned, double>(node);
	temp->pNext = first->pNext;
	first->pNext = temp;
	return *this;
}

TPolynom TPolynom::operator-(const TPolynom& temp)
{
	return *this + (-temp);
}

TPolynom& TPolynom::operator-=(const TPolynom& temp)
{
	return *this += (-temp);
}

TPolynom TPolynom::operator-(const TNode<unsigned, double>& node)
{
	TPolynom out;
	TNode<unsigned, double>* first = list->pFirst;
	bool isInserted = false;
	while (first != nullptr || !isInserted)
	{
		if (first == nullptr)
		{
			out.list->InsertBackward(node.key, -*(node.pData));
			isInserted = true;
		}
		else if (first->key > node.key)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (!isInserted && first->key < node.key)
		{
			out.list->InsertBackward(node.key, -*(node.pData));
			isInserted = true;
		}
		else if (!isInserted)
		{
			if (*(first->pData) != *(node.pData))
			{
				out.list->InsertBackward(first->key, *(first->pData) - *(node.pData));
			}
			first = first->pNext;
			isInserted = true;
		}
		else
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
	}
	return out;
}

TPolynom& TPolynom::operator-=(const TNode<unsigned, double>& node)
{
	TNode<unsigned, double>* first = list->pFirst;
	if (first == nullptr || node.key > first->key)
	{
		list->InsertForward(node.key, -*(node.pData));
		return *this;
	}
	while ((first->pNext != nullptr) && (first->pNext->key > node.key))
		first = first->pNext;
	if ((first->pNext != nullptr) && (first->pNext->key == node.key))
	{
		if (*(first->pNext->pData) != *(node.pData))
			*(first->pNext->pData) -= *(node.pData);
		else
			list->Remove(first->pNext->key);
	}
	TNode<unsigned, double>* temp = new TNode<unsigned, double>(node.key, -*(node.pData));
	temp->pNext = first->pNext;
	first->pNext = temp;
	return *this;
}

TPolynom TPolynom::operator*(const TPolynom& temp)
{
	TPolynom out;
	TNode<unsigned, double>* second = temp.list->pFirst;
	while (second != nullptr)
	{
		out += *this * *second;
		second = second->pNext;
	}
	return out;
}

TPolynom TPolynom::operator*(const TNode<unsigned, double>& node)
{
	TPolynom out;
	TNode<unsigned, double>* first = list->pFirst;
	while (first != nullptr)
	{
		if ((first->key / 100 + node.key / 100) >= 10) throw TException(NotInSystem);
		if ((first->key % 100 / 10 + node.key % 100 / 10) >= 10) throw TException(NotInSystem);
		if ((first->key % 10 + node.key % 10) >= 10) throw TException(NotInSystem);
		out.list->InsertBackward(first->key + node.key, *(first->pData) * *(node.pData));
		first = first->pNext;
	}
	return out;
}

TPolynom& TPolynom::operator*=(const TNode<unsigned, double>& node)
{
	TNode<unsigned, double>* first = list->pFirst;
	while (first != nullptr)
	{
		if ((first->key / 100 + node.key / 100) >= 10) throw TException(NotInSystem);
		if ((first->key % 100 / 10 + node.key % 100 / 10) >= 10) throw TException(NotInSystem);
		if ((first->key % 10 + node.key % 10) >= 10) throw TException(NotInSystem);
		first->key += node.key;
		*(first->pData) *= *(node.pData);
		first = first->pNext;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const TPolynom& polynom)
{
	out << *(polynom.list);
	return out;
}

std::istream& operator>>(std::istream& in, TPolynom& polynom)
{
	delete polynom.list;
	polynom.list = new TList<unsigned, double>;
	std::string line, buffer;
	std::getline(in, line);
	int coef = 0, mul = 1, mode = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ' && !buffer.empty())
		{
			if (mul == 0) throw UnexpectedChar;
			if (stof(buffer) != 0)
			{
				polynom += TNode<unsigned, double>(coef, mul * std::stof(buffer));
			}
			buffer.clear();
			mul = 0;
			coef = 0;
			mode = 0;
		}
		else if (line[i] == '+')
		{
			if (mode == 1) throw TException(UnexpectedChar);
			mul = 1;
		}
		else if (line[i] == '-')
		{
			if (mode == 1) throw TException(UnexpectedChar);
			mul = -1;
		}
		else if (line[i] > 47 && line[i] < 58)
		{
			buffer.push_back(line[i]);
			if (mode == 1) throw TException(UnexpectedChar);
		}
		else if (line[i] == 'x')
		{
			mode = 1;
			if (buffer.empty()) buffer = "1";
			if (line[i + 1] == '^')
			{
				if (line[i + 2] < 48 || line[i + 2] > 57) throw TException(UnexpectedChar);
				if ((line[i + 2] - 48) + (coef / 100) > 9) throw TException(NotInSystem);
				coef += 100 * (line[i + 2] - 48);
				i = i + 2;
				continue;
			}
			else
			{
				if (coef / 100 == 9) throw TException(NotInSystem);
				coef += 100;
				continue;
			}
		}
		else if (line[i] == 'y')
		{
			mode = 1;
			if (buffer.empty()) buffer = "1";
			if (line[i + 1] == '^')
			{
				if (line[i + 2] < 48 || line[i + 2] > 57) throw TException(UnexpectedChar);
				if ((line[i + 2] - 48) + ((coef % 100) / 10) > 9) throw TException(NotInSystem);
				coef += 10 * (line[i + 2] - 48);
				i = i + 2;
				continue;
			}
			else
			{
				if ((coef % 100) / 10 == 9) throw TException(NotInSystem);
				coef += 10;
				continue;
			}
		}
		else if (line[i] == 'z')
		{
			mode = 1;
			if (buffer.empty()) buffer = "1";
			if (line[i + 1] == '^')
			{
				if (line[i + 2] < 48 || line[i + 2] > 57) throw TException(UnexpectedChar);
				if ((line[i + 2] - 48) + (coef % 10) > 9) throw TException(NotInSystem);
				coef += (line[i + 2] - 48);
				i = i + 2;
				continue;
			}
			else
			{
				if (coef % 10 == 9) throw TException(NotInSystem);
				coef += 1;
				continue;
			}
		}
		else if (line[i] != ' ')
		{
			throw TException(UnexpectedChar);
		}
	}
	if (!buffer.empty())
	{
		polynom += TNode<unsigned, double>(coef, mul * std::stof(buffer));
		buffer.clear();
		coef = 0;
	}
	return in;
}

TPolynom operator-(TPolynom temp)
{
	TPolynom out(temp);
	TNode<unsigned, double>* iter = out.list->pFirst;
	while (iter != nullptr)
	{
		*(iter->pData) *= -1;
		iter = iter->pNext;
	}
	return out;
}