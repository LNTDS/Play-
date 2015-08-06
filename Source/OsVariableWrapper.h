#pragma once

template <typename Type>
struct OsVariableWrapper
{
public:
	explicit OsVariableWrapper(Type* storage) : m_storage(storage) { }
	OsVariableWrapper(const OsVariableWrapper&) = delete;

	OsVariableWrapper& operator =(const OsVariableWrapper&) = delete;

	OsVariableWrapper& operator =(const Type& value)
	{
		(*m_storage) = value;
		return (*this);
	}

	operator Type() const
	{
		return *m_storage;
	}

private:
	Type*		m_storage;
};