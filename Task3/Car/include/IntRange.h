#pragma once

struct IntRange
{
public:
    IntRange(int start, int endInclusive) : m_start(start), m_endInclusive(endInclusive)
    {};

    [[nodiscard]] int GetFirst() const;

    [[nodiscard]] int GetLast() const;

    [[nodiscard]] bool Contains(int value) const;

private:
    int m_start;
    int m_endInclusive;
};