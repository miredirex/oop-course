#include <IntRange.h>

int IntRange::GetFirst() const
{
    return m_start;
}

int IntRange::GetLast() const
{
    return m_endInclusive;
}

bool IntRange::Contains(int value) const
{
    return (m_start <= value && value <= m_endInclusive);
}